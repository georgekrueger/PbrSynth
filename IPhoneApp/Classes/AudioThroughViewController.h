//
//  AudioThroughViewController.h
//  AudioThrough
//
//  Created by Pat O'Keefe on 2/18/09.
//  Copyright __MyCompanyName__ 2009. All rights reserved.
//

#import <UIKit/UIKit.h>

//Necessary for right now. Not ideal...
#import "AudioThroughAppDelegate.h"


@interface AudioThroughViewController : UIViewController {
	AudioThroughAppDelegate* appDelegateReference;	
}

@property (nonatomic, retain) AudioThroughAppDelegate *appDelegateReference;
@property (nonatomic, retain) IBOutlet UIButton *button1;
@property (nonatomic, retain) IBOutlet UIButton *button2;
@property (nonatomic, retain) IBOutlet UIButton *button3;
@property (nonatomic, retain) IBOutlet UIButton *button4;
@property (nonatomic, retain) IBOutlet UIButton *button5;
@property (nonatomic, retain) IBOutlet UIButton *button6;
@property (nonatomic, retain) IBOutlet UIButton *button7;
@property (nonatomic, retain) IBOutlet UIButton *button8;
@property (nonatomic, retain) IBOutlet UIButton *button9;
@property (nonatomic, retain) IBOutlet UIButton *button10;
@property (nonatomic, retain) IBOutlet UIButton *button11;
@property (nonatomic, retain) IBOutlet UIButton *button12;
@property (nonatomic, retain) IBOutlet UIButton *button13;
@property (nonatomic, retain) IBOutlet UIButton *button14;
@property (nonatomic, retain) IBOutlet UILabel* label;
@property int octave;

- (IBAction)buttonDown:(UIButton*)sender;
- (IBAction)buttonUp:(UIButton*)sender;
- (IBAction)oscType:(UISegmentedControl*)sender;
- (IBAction)testButtonPressed:(UIButton*)sender;
- (IBAction)octaveUp:(UIButton*)sender;
- (IBAction)octaveDown:(UIButton*)sender;

- (void) updateTestLabel:(const char*)text;

@end

