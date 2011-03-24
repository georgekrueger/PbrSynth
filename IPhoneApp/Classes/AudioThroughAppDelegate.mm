//
//  AudioThroughAppDelegate.m
//  AudioThrough
//
//  Created by Pat O'Keefe on 2/18/09.
//  Copyright __MyCompanyName__ 2009. All rights reserved.
//

#import "AudioThroughAppDelegate.h"
#import "AudioThroughViewController.h"
#import "AudioUnit/AudioUnit.h"
#import "CAXException.h"
#include "QuartzCore/QuartzCore.h"
#include "Profiler.h"

Synth synth;
Arpeggiator arp(&synth);

Synth* GetSynth()
{
	return &synth;
}

Arpeggiator* GetArpeggiator()
{
	return &arp;
}

@implementation AudioThroughAppDelegate

// FYI: The file extension is .mm
// Why is that? Because the compiler recognizes .mm for a C++ file that uses Objective-C...brilliant


@synthesize window;
@synthesize viewController;
@synthesize rioUnit;
@synthesize unitIsRunning;
@synthesize audioCallbackInfo;
@synthesize audioFormat;
@synthesize Gain;
@synthesize Frequency;

//OscData SineData;

void propListener(	void *                  inClientData,
				  AudioSessionPropertyID	inID,
				  UInt32                  inDataSize,
				  const void *            inData)
{
	NSLog(@"propListener");
	AudioThroughAppDelegate *THIS = (AudioThroughAppDelegate*)inClientData;
	if (inID == kAudioSessionProperty_AudioRouteChange)
	{
		try {
			// if there was a route change, we need to dispose the current rio unit and create a new one
			XThrowIfError(AudioComponentInstanceDispose(THIS->rioUnit), "couldn't dispose remote i/o unit");		
			
			SetupRemoteIO(THIS->rioUnit, THIS->audioCallbackInfo, THIS->audioFormat);
			
			UInt32 size = sizeof(THIS->hwSampleRate);
			XThrowIfError(AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareSampleRate, &size, &THIS->hwSampleRate), "couldn't get new sample rate");
			
			XThrowIfError(AudioOutputUnitStart(THIS->rioUnit), "couldn't start unit");
			
			// we need to rescale the sonogram view's color thresholds for different input
			CFStringRef newRoute;
			size = sizeof(CFStringRef);
			XThrowIfError(AudioSessionGetProperty(kAudioSessionProperty_AudioRoute, &size, &newRoute), "couldn't get new audio route");
			if (newRoute)
			{	
				CFShow(newRoute);
				if (CFStringCompare(newRoute, CFSTR("Headset"), NULL) == kCFCompareEqualTo) // headset plugged in
				{
					//Do something if you'd like
					
					
				}
				else if (CFStringCompare(newRoute, CFSTR("Receiver"), NULL) == kCFCompareEqualTo) // headset plugged in
				{
					//Do something if you'd like
					
					
				}			
				else		//Something else must be plugged in...Third party?
				{
					
					//Do something if you'd like
					
				}
			}
		} catch (CAXException e) {
			char buf[256];
			fprintf(stderr, "Error: %s (%s)\n", e.mOperation, e.FormatError(buf));
		}
		
	}
}

static unsigned long MinNumFrames = ( 1 << 31 );
static unsigned long MaxNumFrames = 0;

static OSStatus	AudioRenderCallback(
							void						*inRefCon, 
							AudioUnitRenderActionFlags 	*ioActionFlags, 
							const AudioTimeStamp 		*inTimeStamp, 
							UInt32 						inBusNumber, 
							UInt32 						inNumberFrames, 
							AudioBufferList 			*ioData)
{
	
	OSStatus Status = noErr;
	
	if ( inNumberFrames < MinNumFrames ) MinNumFrames = inNumberFrames;
	if ( inNumberFrames > MaxNumFrames ) MaxNumFrames = inNumberFrames;
	
	PROFILER_START(MainAudioRender)
	
	arp.Tick();
	
	float* data = (float*)(ioData->mBuffers[0].mData);
	synth.Generate( data, inNumberFrames );
	
	//PROFILER_START(ConvertToFixed)
	// Convert the samples to 8.24 fixed point
	static const long ScalingFactor = (1 << 24);
	for (int i=0; i<inNumberFrames*2; i++)
	{
		//assert( data[i] >= -1.0 );
		//assert( data[i] <= 1.0 );
		SInt32 fixedPointSample = data[i] * ScalingFactor;
		SInt32* IntData = (SInt32*)data;
		IntData[i] = fixedPointSample;
	}
	//PROFILER_END(ConvertToFixed)
	
	PROFILER_END(MainAudioRender)
	
	return Status;
}



- (void)applicationDidFinishLaunching:(UIApplication *)application {    
    
	
	// Setting this to YES keeps the iPhone/iPod Touch from locking (screen turning off)
	// There's no reason to do it here, but I thought I'd comment on what it does because it show up in aurioTouch
	application.idleTimerDisabled = YES;	
	
	audioCallbackInfo.inputProc = AudioRenderCallback;
	audioCallbackInfo.inputProcRefCon = self;
	
	CFURLRef url = NULL;
	try {
		
		// Initialize and configure the audio session
		XThrowIfError(AudioSessionInitialize(NULL, NULL, rioInterruptionListener, self.rioUnit), "couldn't initialize audio session");
		XThrowIfError(AudioSessionSetActive(true), "couldn't set audio session active\n");
		
		
		UInt32 audioCategory = kAudioSessionCategory_MediaPlayback;
		XThrowIfError(AudioSessionSetProperty(kAudioSessionProperty_AudioCategory, sizeof(audioCategory), &audioCategory), "couldn't set audio category");
		
		// The entire purpose of the propListener is to detect a change in signal flow (headphones w/ mic or even third party device)
		XThrowIfError(AudioSessionAddPropertyListener(kAudioSessionProperty_AudioRouteChange, propListener, self), "couldn't set property listener");
		
		// This value is in seconds!
		Float32 preferredBufferSize = .005;
		XThrowIfError(AudioSessionSetProperty(kAudioSessionProperty_PreferredHardwareIOBufferDuration, sizeof(preferredBufferSize), &preferredBufferSize), "couldn't set i/o buffer duration");
		
		// Related to our propListener. When the signal flow changes, sometimes the hardware sample rate can change. You'll notice in the propListener it checks for a new one.
		UInt32 size = sizeof(hwSampleRate);
		XThrowIfError(AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareSampleRate, &size, &hwSampleRate), "couldn't get hw sample rate");
		NSLog(@"Hardware sample rate is: %f", hwSampleRate);
		
		Float32 bufferSizeInSeconds;
		size = sizeof(bufferSizeInSeconds);
		XThrowIfError(AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareIOBufferDuration, &size, &bufferSizeInSeconds), "couldn't get i/o buffer duration");
		float bufferSizeInFrames = hwSampleRate * bufferSizeInSeconds;
		NSLog(@"Actual Buffer Size, Seconds: %f, Frames: %f", bufferSizeInSeconds, bufferSizeInFrames);
		
		synth.SetSampleRate( hwSampleRate );
		synth.SetSetting(Synth::Osc1Type, Synth::BlepSaw);
		synth.SetSetting(Synth::Cutoff, 1000);
		synth.SetSetting(Synth::Osc2Volume, 0.0f);
		
		//arp.SetEnabled(true);
		arp.SetTickRate( hwSampleRate / bufferSizeInFrames );
		
		NSBundle* bundle = [NSBundle mainBundle];
		NSString* settingsFile = [bundle pathForResource:@"autosave2" ofType:@"syn"];
		synth.LoadSettings([settingsFile UTF8String]);
		
		NSString* arpFile = [bundle pathForResource:@"autosave" ofType:@"arp"];
		arp.LoadSettings([arpFile UTF8String]);
		
		audioFormat.mSampleRate = SAMPLE_RATE;
		audioFormat.mFormatID = kAudioFormatLinearPCM;
		audioFormat.mFormatFlags = kAudioFormatFlagsAudioUnitCanonical & ~kAudioFormatFlagIsNonInterleaved;
		audioFormat.mFramesPerPacket = 1;
		audioFormat.mChannelsPerFrame = 2;
		audioFormat.mBytesPerFrame = 8;
		audioFormat.mBitsPerChannel = 32;
		audioFormat.mBytesPerPacket = audioFormat.mBytesPerFrame * audioFormat.mFramesPerPacket;
		
		// Most important call in the entire try. SetupRemoteIO is defined in aurio_helper.h
		XThrowIfError(SetupRemoteIO(rioUnit, audioCallbackInfo, audioFormat), "couldn't setup remote i/o unit");
				
		AudioOutputUnitStart(rioUnit);
		unitIsRunning = 1;
	}
	catch (CAXException &e) {
		char buf[256];
		fprintf(stderr, "Error: %s (%s)\n", e.mOperation, e.FormatError(buf));
		unitIsRunning = 0;
		if (url) CFRelease(url);
	}
	catch (...) {
		fprintf(stderr, "OHHHH NOOOOOO...An unknown error occurred!\n");
		unitIsRunning = 0;
		if (url) CFRelease(url);
	}
	
	[window addSubview:viewController.view];
	[window makeKeyAndVisible];
}

- (void) startTestNotes
{
	synth.NoteOn(60, 100);
	synth.NoteOn(64, 100);
	synth.NoteOn(67, 100);
	synth.NoteOn(71, 100);
	synth.NoteOn(72, 100);
	synth.NoteOn(76, 100);
	synth.NoteOn(79, 100);
}

- (void) stopTestNotes
{
	synth.NoteOff(60);
	synth.NoteOff(64);
	synth.NoteOff(67);
	synth.NoteOff(71);
	synth.NoteOff(72);
	synth.NoteOff(76);
	synth.NoteOff(79);
}

char ProfileDumpStr[256];

- (void) toggleTest
{
	if ( IsTestRunning ) {
		IsTestRunning = false;
		if ( IsTestNoteOn ) {
			[self stopTestNotes];
		}
		IsTestNoteOn = false;
		if ([TestTimer isValid]) {
			[TestTimer invalidate];
		}
		Profiler::DumpProfileInfo(ProfileDumpStr, 256);
		[self.viewController updateTestLabel:ProfileDumpStr];
	}
	else {
		IsTestRunning = true;
		IsTestNoteOn = false;
		TestTimer = [NSTimer scheduledTimerWithTimeInterval:1.0
									target:self
									selector:@selector(timerCallback)
									userInfo:nil
									repeats:YES];
		Profiler::ResetAll();
	}
}

- (void) timerCallback
{
	if ( !IsTestNoteOn ) {
		[self startTestNotes];
		IsTestNoteOn = true;
	}
	else {
		[self stopTestNotes];
		IsTestNoteOn = false;
	}
}

- (void)applicationWillTerminate:(UIApplication *)application
{
	AudioOutputUnitStop(rioUnit);
	char Dump[255];
	Profiler::DumpProfileInfo(Dump, 255);
	printf(Dump);
	printf("Min frames per render: %d\nMax frames per render = %d\n", MinNumFrames, MaxNumFrames);
}

- (void)dealloc {
	[viewController release];
    [window release];
    [super dealloc];
}


@end
