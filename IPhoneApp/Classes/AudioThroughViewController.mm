//
//  AudioThroughViewController.m
//  AudioThrough
//
//  Created by Pat O'Keefe on 2/18/09.
//  Copyright __MyCompanyName__ 2009. All rights reserved.
//

#import "AudioThroughViewController.h"



@implementation AudioThroughViewController

@synthesize appDelegateReference;
@synthesize button1;
@synthesize button2;
@synthesize button3;
@synthesize button4;
@synthesize button5;
@synthesize button6;
@synthesize button7;
@synthesize button8;
@synthesize button9;
@synthesize button10;
@synthesize button11;
@synthesize button12;
@synthesize button13;
@synthesize button14;
@synthesize label;
@synthesize octave;

static const int Scale[7] = 
{
	0, 2, 4, 5, 7, 9, 11
};

- (void)viewDidLoad {
    
	//Create a reference to the app Delegate so we can control all of the audio stuff going on in there...
	self.appDelegateReference = (AudioThroughAppDelegate *)[[UIApplication sharedApplication] delegate];
	self.octave = 4;
	
	[super viewDidLoad];
}

#define NoteOn(p) GetArpeggiator()->NoteOn(p, 100)
#define NoteOff(p) GetArpeggiator()->NoteOff(p)

- (IBAction)buttonDown:(UIButton*)sender 
{
	int N = self.octave * 12;
	
	if ( sender == self.button1 )       NoteOn( N + Scale[0] );
	else if ( sender == self.button2 )  NoteOn( N + Scale[1] );
	else if ( sender == self.button3 )  NoteOn( N + Scale[2] );
	else if ( sender == self.button4 )  NoteOn( N + Scale[3] );
	else if ( sender == self.button5 )  NoteOn( N + Scale[4] );
	else if ( sender == self.button6 )  NoteOn( N + Scale[5] );
	else if ( sender == self.button7 )  NoteOn( N + Scale[6] );
	else if ( sender == self.button8 )  NoteOn( N + 12 + Scale[0] );
	else if ( sender == self.button9 )  NoteOn( N + 12 + Scale[1] );
	else if ( sender == self.button10 ) NoteOn( N + 12 + Scale[2] );
	else if ( sender == self.button11 ) NoteOn( N + 12 + Scale[3] );
	else if ( sender == self.button12 ) NoteOn( N + 12 + Scale[4] );
	else if ( sender == self.button13 ) NoteOn( N + 12 + Scale[5] );
	else if ( sender == self.button14 ) NoteOn( N + 12 + Scale[6]);
}

- (IBAction)buttonUp:(UIButton*)sender 
{
	int N = self.octave * 12;
	
	if ( sender == self.button1 )       NoteOff( N + Scale[0]);
	else if ( sender == self.button2 )  NoteOff( N + Scale[1]);
	else if ( sender == self.button3 )  NoteOff( N + Scale[2] );
	else if ( sender == self.button4 )  NoteOff( N + Scale[3] );
	else if ( sender == self.button5 )  NoteOff( N + Scale[4] );
	else if ( sender == self.button6 )  NoteOff( N + Scale[5] );
	else if ( sender == self.button7 )  NoteOff( N + Scale[6] );
	else if ( sender == self.button8 )  NoteOff( N + 12 + Scale[0] );
	else if ( sender == self.button9 )  NoteOff( N + 12 + Scale[1] );
	else if ( sender == self.button10 ) NoteOff( N + 12 + Scale[2] );
	else if ( sender == self.button11 ) NoteOff( N + 12 + Scale[3] );
	else if ( sender == self.button12 ) NoteOff( N + 12 + Scale[4] );
	else if ( sender == self.button13 ) NoteOff( N + 12 + Scale[5] );
	else if ( sender == self.button14 ) NoteOff( N + 12 + Scale[6] );
}

- (IBAction)octaveUp:(UIButton*)sender
{
	if ( self.octave < 7 ) {
		self.octave++;
	}
	printf("Octave: %d\n", self.octave);
}

- (IBAction)octaveDown:(UIButton*)sender
{
	if ( self.octave > 3 ) {
		self.octave--;
	}
	printf("Octave: %d\n", self.octave);
}

- (IBAction)oscType:(UISegmentedControl*)sender
{
	switch(sender.selectedSegmentIndex)
	{
		case 0:
			GetSynth()->SetSetting(Synth::Osc1Type, Synth::Sine);
			break;
		case 1:
			GetSynth()->SetSetting(Synth::Osc1Type, Synth::Triangle);
			break;
		case 2:
			GetSynth()->SetSetting(Synth::Osc1Type, Synth::BlepSaw);
			break;
		case 3:
			GetSynth()->SetSetting(Synth::Osc1Type, Synth::BlepSquare);
			break;
	}
}

- (IBAction)testButtonPressed:(UIButton*)sender
{
	[self.appDelegateReference toggleTest];
}

- (void)updateTestLabel:(const char*) text
{
	self.label.text = [NSString stringWithCString: text encoding: NSUTF8StringEncoding];
}

- (void)dealloc
{
	[super dealloc];
}



/*
 // Override to allow orientations other than the default portrait orientation.
 - (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
 // Return YES for supported orientations
 return (interfaceOrientation == UIInterfaceOrientationPortrait);
 }
 */


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning]; // Releases the view if it doesn't have a superview
    // Release anything that's not essential, such as cached data
}


@end
