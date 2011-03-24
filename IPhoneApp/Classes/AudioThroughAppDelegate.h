//
//  AudioThroughAppDelegate.h
//  AudioThrough
//
//  Created by Pat O'Keefe on 2/18/09.
//  Copyright __MyCompanyName__ 2009. All rights reserved.
//

#import <UIKit/UIKit.h>
#include <CoreFoundation/CFURL.h>

#import "aurio_helper.h"
#include <libkern/OSAtomic.h>
#include "Synth.h"

#ifndef CLAMP
#define CLAMP(min,x,max) (x < min ? min : (x > max ? max : x))
#endif

Synth* GetSynth();
Arpeggiator* GetArpeggiator();

@class AudioThroughViewController;

inline double linearInterp(double valA, double valB, double fract)
{
	return valA + ((valB - valA) * fract);
}

@interface AudioThroughAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow*                   window;
    AudioThroughViewController* viewController;
	
	AudioUnit					rioUnit;
	int							unitIsRunning;
	Float64						hwSampleRate;
	
	AURenderCallbackStruct		audioCallbackInfo;
	AudioStreamBasicDescription audioFormat;
	
	float Gain;
	float Frequency;
	
	bool     IsTestRunning;
	bool     IsTestNoteOn;
	NSTimer* TestTimer;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet AudioThroughViewController *viewController;

@property AudioUnit					rioUnit;
@property int						unitIsRunning;
@property AURenderCallbackStruct	audioCallbackInfo;
@property AudioStreamBasicDescription audioFormat;
@property float Gain;
@property float Frequency;

- (void) timerCallback;
- (void) toggleTest;

@end

