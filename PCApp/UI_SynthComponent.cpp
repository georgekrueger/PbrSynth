/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  14 Apr 2008 11:28:13 am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.11

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]
#include <iostream>

#include "UI_SynthComponent.h"
#include "Synth.h"
#include "Arpeggiator.h"

extern Synth Synth1;
extern Arpeggiator Arp1;

#define MAKE_SLIDER( NAME, MIN, MAX, STEP, INIT_VAL ) \
	NAME = new Slider( String::empty ); \
	NAME->setSliderStyle( Slider::RotaryVerticalDrag ); \
	NAME->addListener( this ); \
	NAME->setRange( MIN, MAX, STEP ); \
	NAME->setValue( INIT_VAL, false ); \
	addAndMakeVisible( NAME );

#define MAKE_TOGGLE_BUTTON( NAME, LABEL, INIT_VAL ) \
	NAME = new ToggleButton( LABEL ); \
	NAME->setToggleState( INIT_VAL, false ); \
	NAME->addButtonListener( this ); \
	addAndMakeVisible( NAME );

#define MAKE_LABEL( NAME, TEXT ) \
	NAME = new Label( String::empty, String(TEXT) ); \
	addAndMakeVisible( NAME );

//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
    : mKeyboard (0)
{
	unsigned int i;
	
	mKeyboard = new MidiKeyboardComponent (mMidiKeyboardState, MidiKeyboardComponent::horizontalKeyboard);
	mKeyboard->setAlwaysRecieveKeyboardEvents(true);
	addAndMakeVisible ( mKeyboard );
	mMidiKeyboardState.addListener( this );

	Synth1.LoadSettings( "autosave.syn" );

	MAKE_LABEL( mEnvelopeLabel[Attack], "Attack" );
	MAKE_LABEL( mEnvelopeLabel[Decay], "Decay" );
	MAKE_LABEL( mEnvelopeLabel[Sustain], "Sustain" );
	MAKE_LABEL( mEnvelopeLabel[Release], "Release" );
	for ( i=0; i<eEnvelopeADSR_Count; i++ )
	{
		mEnvelopeSlider[i] = new Slider( String::empty );
		mEnvelopeSlider[i]->setSliderStyle( Slider::RotaryVerticalDrag );
		mEnvelopeSlider[i]->addListener( this );
		addAndMakeVisible( mEnvelopeSlider[i] );
	}
	mEnvelopeSlider[Attack]->setRange( 0.001, 10, 0.001 );
	mEnvelopeSlider[Attack]->setValue( Synth1.GetSetting( Synth::Attack ) );
	mEnvelopeSlider[Attack]->setSkewFactorFromMidPoint( 2.0 );
	mEnvelopeSlider[Decay]->setRange( 0.001, 10, 0.001 );
	mEnvelopeSlider[Decay]->setValue( Synth1.GetSetting( Synth::Decay ) );
	mEnvelopeSlider[Decay]->setSkewFactorFromMidPoint( 2.0 );
	mEnvelopeSlider[Sustain]->setRange( 0, 1, 0.001 );
	mEnvelopeSlider[Sustain]->setValue( Synth1.GetSetting( Synth::Sustain ) );
	mEnvelopeSlider[Release]->setRange( 0.001, 10, 0.001 );
	mEnvelopeSlider[Release]->setValue( Synth1.GetSetting( Synth::Release ) );
	mEnvelopeSlider[Release]->setSkewFactorFromMidPoint( 2.0 );
	
	mSampleFileFilter = new WildcardFileFilter( String("*.wav"), String("Samples") );
	mTimeSliceThread = new TimeSliceThread( String::empty );
	mTimeSliceThread->startThread();
	mSampleDirList = new DirectoryContentsList( mSampleFileFilter, *mTimeSliceThread );
	mSampleDirList->addChangeListener( this );
	mSampleDirList->setDirectory( File::getCurrentWorkingDirectory().getChildFile("samples"), false, true );
	
	MAKE_LABEL( mOsc1Label, "Osc Type" );
	MAKE_LABEL( mOsc1VolumeLabel, "Volume" );
	MAKE_LABEL( mOsc1SemitoneLabel, "Semitones" );
	MAKE_LABEL( mOsc1CentLabel, "Cents" );
	MAKE_LABEL( mOsc1PulseWidthLabel, "PW" );
	CreateOscControls( mOsc1TypeSelectBox, mOsc1VolumeSlider, mOsc1SemitoneSlider, mOsc1CentSlider, mOsc1PulseWidthSlider, mOsc1SampleSelectBox );
	mOsc1TypeSelectBox->setSelectedItemIndex( Synth1.GetSetting( Synth::Osc1Type ).toInt() - 1, false );
	mOsc1VolumeSlider->setValue( Synth1.GetSetting( Synth::Osc1Volume ), false );
	mOsc1SemitoneSlider->setValue( Synth1.GetSetting( Synth::Osc1DetuneSemitones ), false );
	mOsc1CentSlider->setValue( Synth1.GetSetting( Synth::Osc1DetuneCents ), false );
	mOsc1PulseWidthSlider->setValue( Synth1.GetSetting( Synth::Osc1PulseWidth ), false );
	
	CreateOscControls( mOsc2TypeSelectBox, mOsc2VolumeSlider, mOsc2SemitoneSlider, mOsc2CentSlider, mOsc2PulseWidthSlider, mOsc2SampleSelectBox );
	mOsc2TypeSelectBox->setSelectedItemIndex( Synth1.GetSetting( Synth::Osc2Type ).toInt() - 1, false );
	mOsc2VolumeSlider->setValue( Synth1.GetSetting( Synth::Osc2Volume ), false );
	mOsc2SemitoneSlider->setValue( Synth1.GetSetting( Synth::Osc2DetuneSemitones ), false );
	mOsc2CentSlider->setValue( Synth1.GetSetting( Synth::Osc2DetuneCents ), false );
	mOsc2PulseWidthSlider->setValue( Synth1.GetSetting( Synth::Osc2PulseWidth ), false );
	
	MAKE_SLIDER( mCutoffSlider, 100.0, 10000.0, 10.0, Synth1.GetSetting( Synth::Cutoff ) );
	MAKE_SLIDER( mCutoffLFOFreqSlider, 0.0, 10.0, 0.01, Synth1.GetSetting( Synth::CutoffLFOFreq ) );
	MAKE_SLIDER( mCutoffLFORangeSlider, 0.0, 1000.0, 1.0, Synth1.GetSetting( Synth::CutoffLFORange ) );
	MAKE_SLIDER( mResonanceSlider, 0.0, 1.0, 0.01, Synth1.GetSetting( Synth::Resonance ) );
	
	MAKE_LABEL( mDelayLabel, "Delay" );
	MAKE_TOGGLE_BUTTON( mDelayEnabledButton, "Enable", Synth1.GetSetting( Synth::DelayEnabled ) );
	MAKE_SLIDER( mDelayTimeSlider, 0.01, 1.0, 0.01, Synth1.GetSetting( Synth::DelayTime ) );
	MAKE_SLIDER( mDelayLevelSlider, 0.0, 1.0, 0.01, Synth1.GetSetting( Synth::DelayLevel ) );
	
	MAKE_LABEL( mFlangeLabel, "Flange" );
	MAKE_TOGGLE_BUTTON( mFlangeEnabledButton, "Enable", Synth1.GetSetting( Synth::ModDelayEnabled ) );
	MAKE_SLIDER( mModDelayRateSlider, 0.01, 5.0, 0.01, Synth1.GetSetting( Synth::ModDelayRate ) );
	MAKE_SLIDER( mModDelayMinSlider, 0.001, 0.1, 0.001, Synth1.GetSetting( Synth::ModDelayMin ) );
	MAKE_SLIDER( mModDelayDepthSlider, 0.001, 0.1, 0.001, Synth1.GetSetting( Synth::ModDelayDepth ) );
	MAKE_SLIDER( mModDelayBlendSlider, 0.0, 1.0, 0.001, Synth1.GetSetting( Synth::ModDelayBlend ) );
	MAKE_SLIDER( mModDelayFFSlider, 0.0, 1.0, 0.001, Synth1.GetSetting( Synth::ModDelayFF ) );
	MAKE_SLIDER( mModDelayFBSlider, 0.0, 1.0, 0.001, Synth1.GetSetting( Synth::ModDelayFB ) );
	
	MAKE_LABEL( mArpLabel, "Arpeggiator" );
	MAKE_TOGGLE_BUTTON( mArpEnabledButton, "Enable", Arp1.IsEnabled() );
	MAKE_SLIDER( mArpGateTimeSlider, 0.00, 0.99, 0.01, Arp1.GetGateTime() );

	MAKE_LABEL( mSaturationLabel, "Saturation" );
	MAKE_TOGGLE_BUTTON( mSaturationEnabledButton, "Enable", Synth1.GetSetting( Synth::SaturationEnabled ) );
	MAKE_SLIDER( mSaturationValueSlider, -1.0, 1.0, 0.01, Synth1.GetSetting( Synth::SaturationValue ) );
	
	Arp1.SetPatternSize( mArpPatternSize );
	
	for ( i=0; i<mArpPatternSize; ++i )
	{
		mArpPatternSelect[i] = new ComboBox( String::empty );
		mArpPatternSelect[i]->addItem( String("1"), Arpeggiator::WholeNote );
		mArpPatternSelect[i]->addItem( String("1/2"), Arpeggiator::HalfNote );
		mArpPatternSelect[i]->addItem( String("1/4"), Arpeggiator::QuarterNote );
		mArpPatternSelect[i]->addItem( String("1/8"), Arpeggiator::EighthNote );
		mArpPatternSelect[i]->addItem( String("1/16"), Arpeggiator::SixteenthNote );
		mArpPatternSelect[i]->addItem( String("1/32"), Arpeggiator::ThirtySecondNote );
		mArpPatternSelect[i]->setEditableText( false );
		mArpPatternSelect[i]->setSelectedItemIndex( 2, true );
		mArpPatternSelect[i]->addListener( this );
		addAndMakeVisible( mArpPatternSelect[i] );
	}
	
	mMidiInput = MidiInput::openDevice( MidiInput::getDefaultDeviceIndex(), this );
	if ( mMidiInput ) mMidiInput->start();

    setSize (640, 500);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]
	
	Synth1.SaveSettings( "autosave.syn" );
	
	unsigned int i;

    deleteAndZero ( mKeyboard );
	for ( i=0; i<eEnvelopeADSR_Count; i++ )
	{
		deleteAndZero( mEnvelopeSlider[i] );
	}
	
	deleteAndZero( mOsc1TypeSelectBox );
	deleteAndZero( mOsc1VolumeSlider );
	deleteAndZero( mOsc1CentSlider );
	deleteAndZero( mOsc1PulseWidthSlider );
	
	deleteAndZero( mOsc2TypeSelectBox );
	deleteAndZero( mOsc2VolumeSlider );
	deleteAndZero( mOsc2CentSlider );
	deleteAndZero( mOsc2PulseWidthSlider );
	
	deleteAndZero( mCutoffSlider );
	deleteAndZero( mCutoffLFOFreqSlider );
	deleteAndZero( mCutoffLFORangeSlider );
	deleteAndZero( mResonanceSlider );
	
	deleteAndZero( mDelayLabel );
	deleteAndZero( mDelayEnabledButton );
	deleteAndZero( mDelayTimeSlider );
	deleteAndZero( mDelayLevelSlider );
	
	deleteAndZero( mFlangeLabel );
	deleteAndZero( mFlangeEnabledButton );
	deleteAndZero( mModDelayRateSlider );
	deleteAndZero( mModDelayMinSlider );
	deleteAndZero( mModDelayDepthSlider );
	deleteAndZero( mModDelayBlendSlider );
	deleteAndZero( mModDelayFFSlider );
	deleteAndZero( mModDelayFBSlider );
	
	deleteAndZero( mArpLabel );
	deleteAndZero( mArpEnabledButton );
	deleteAndZero( mArpGateTimeSlider );

	deleteAndZero( mSaturationLabel );
	deleteAndZero( mSaturationEnabledButton );
	deleteAndZero( mSaturationValueSlider );
	
	for ( i=0; i<mArpPatternSize; ++i )
	{
		deleteAndZero( mArpPatternSelect[i] );
	}

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
	mKeyboard->setBounds( 20, getHeight() - 100, getWidth() - 40, 100 );
	
	static const int SLIDER_WIDTH = 70;
	static const int SLIDER_HEIGHT = 50;
	int x = 10;
	int y = 10;
	unsigned int i;

	for ( i=0; i<eEnvelopeADSR_Count; i++ )
	{
		mEnvelopeLabel[i]->setBounds( x, y, 100, 15);
		mEnvelopeSlider[i]->setBounds( x, y, SLIDER_WIDTH, SLIDER_HEIGHT );
		x += SLIDER_WIDTH+10;
	}
	
	mOsc1Label->setBounds( 10, 60, 100, 20 );
	mOsc1TypeSelectBox->setBounds( 10, 80, 100, 20 );
	mOsc1VolumeLabel->setBounds( 120, 60, 100, 20 );
	mOsc1VolumeSlider->setBounds( 120, 65, SLIDER_WIDTH, SLIDER_HEIGHT );
	mOsc1SemitoneLabel->setBounds( 200, 60, 100, 20 );
	mOsc1SemitoneSlider->setBounds( 200, 65, SLIDER_WIDTH, SLIDER_HEIGHT );
	mOsc1CentLabel->setBounds( 280, 60, 100, 20 );
	mOsc1CentSlider->setBounds( 280, 65, SLIDER_WIDTH, SLIDER_HEIGHT );
	mOsc1PulseWidthLabel->setBounds( 360, 60, 100, 20 );
	mOsc1PulseWidthSlider->setBounds( 360, 65, SLIDER_WIDTH, SLIDER_HEIGHT );
	mOsc1SampleSelectBox->setBounds( 440, 76, 180, 24 );
	
	mOsc2TypeSelectBox->setBounds( 10, 120, 100, 20 );
	mOsc2VolumeSlider->setBounds( 120, 105, SLIDER_WIDTH, SLIDER_HEIGHT );
	mOsc2SemitoneSlider->setBounds( 200, 105, SLIDER_WIDTH, SLIDER_HEIGHT );
	mOsc2CentSlider->setBounds( 280, 105, SLIDER_WIDTH, SLIDER_HEIGHT );
	mOsc2PulseWidthSlider->setBounds( 360, 105, SLIDER_WIDTH, SLIDER_HEIGHT );
	mOsc2SampleSelectBox->setBounds( 440, 117, 180, 24 );
	
	mCutoffSlider->setBounds( 10, 144, SLIDER_WIDTH, SLIDER_HEIGHT );
	mCutoffLFOFreqSlider->setBounds( 90, 144, SLIDER_WIDTH, SLIDER_HEIGHT );
	mCutoffLFORangeSlider->setBounds( 170, 144, SLIDER_WIDTH, SLIDER_HEIGHT );
	mResonanceSlider->setBounds( 250, 144, SLIDER_WIDTH, SLIDER_HEIGHT );
	
	mDelayLabel->setBounds( 10, 190, 100, 20 );
	mDelayEnabledButton->setBounds( 70, 184, 100, 30 );
	mDelayTimeSlider->setBounds( 10, 200, SLIDER_WIDTH, SLIDER_HEIGHT );
	mDelayLevelSlider->setBounds( 90, 200, SLIDER_WIDTH, SLIDER_HEIGHT );
	
	mFlangeLabel->setBounds( 10, 244, 100, 20 );
	mFlangeEnabledButton->setBounds( 70, 240, 100, 30 );
	x = 10;
	y = 255;
	mModDelayRateSlider->setBounds( x, y, SLIDER_WIDTH, SLIDER_HEIGHT );
	mModDelayMinSlider->setBounds( x += SLIDER_WIDTH + 10, y, SLIDER_WIDTH, SLIDER_HEIGHT );
	mModDelayDepthSlider->setBounds( x += SLIDER_WIDTH + 10, y, SLIDER_WIDTH, SLIDER_HEIGHT );
	mModDelayBlendSlider->setBounds( x += SLIDER_WIDTH + 10, y, SLIDER_WIDTH, SLIDER_HEIGHT );
	mModDelayFFSlider->setBounds( x += SLIDER_WIDTH + 10, y, SLIDER_WIDTH, SLIDER_HEIGHT );
	mModDelayFBSlider->setBounds( x += SLIDER_WIDTH + 10, y, SLIDER_WIDTH, SLIDER_HEIGHT );
	
	mArpLabel->setBounds( 200, 190, 100, 20 );
	mArpEnabledButton->setBounds( 310, 185, 100, 30 );
	mArpGateTimeSlider->setBounds( 200, 200, SLIDER_WIDTH, SLIDER_HEIGHT );
	
	static const int ARP_PATTERN_BOX_WIDTH = 50;
	static const int ARP_PATTERN_BOX_HEIGHT = 20;
	x = 280;
	y = 215;
	
	for ( i=0; i<mArpPatternSize; ++i )
	{
		mArpPatternSelect[i]->setBounds( x, y, ARP_PATTERN_BOX_WIDTH, ARP_PATTERN_BOX_HEIGHT );
		x += ARP_PATTERN_BOX_WIDTH;
	}

	mSaturationLabel->setBounds( 200, 300, 100, 20 );
	mSaturationEnabledButton->setBounds( 310, 300, 100, 30 );
	mSaturationValueSlider->setBounds( 200, 300, SLIDER_WIDTH, SLIDER_HEIGHT );
}

void MainComponent::handleNoteOn (MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity)
{
	Arp1.NoteOn( midiNoteNumber, velocity );
}

void MainComponent::handleNoteOff (MidiKeyboardState *source, int midiChannel, int midiNoteNumber)
{
	Arp1.NoteOff( midiNoteNumber );
}

void MainComponent::sliderValueChanged (Slider *slider)
{
	if ( slider == mEnvelopeSlider[Attack] )
	{
		Synth1.SetSetting( Synth::Attack, (float)slider->getValue() );
	}
	else if ( slider == mEnvelopeSlider[Decay] )
	{
		Synth1.SetSetting( Synth::Decay, (float)slider->getValue() );
	}
	else if ( slider == mEnvelopeSlider[Sustain] )
	{
		Synth1.SetSetting( Synth::Sustain, (float)slider->getValue() );
	}
	else if ( slider == mEnvelopeSlider[Release] )
	{
		Synth1.SetSetting( Synth::Release, (float)slider->getValue() );
	}
	else if ( slider == mOsc1VolumeSlider )
	{
		Synth1.SetSetting( Synth::Osc1Volume, (float)slider->getValue() );
	}
	else if ( slider == mOsc1SemitoneSlider )
	{
		Synth1.SetSetting( Synth::Osc1DetuneSemitones, (int)slider->getValue() );
	}
	else if ( slider == mOsc1CentSlider )
	{
		Synth1.SetSetting( Synth::Osc1DetuneCents, (float)slider->getValue() );
	}
	else if ( slider == mOsc1PulseWidthSlider )
	{
		Synth1.SetSetting( Synth::Osc1PulseWidth, (float)slider->getValue() );
	}
	else if ( slider == mOsc2VolumeSlider )
	{
		Synth1.SetSetting( Synth::Osc2Volume, (float)slider->getValue() );
	}
	else if ( slider == mOsc2SemitoneSlider )
	{
		Synth1.SetSetting( Synth::Osc2DetuneSemitones, (int)slider->getValue() );
	}
	else if ( slider == mOsc2CentSlider )
	{
		Synth1.SetSetting( Synth::Osc2DetuneCents, (float)slider->getValue() );
	}
	else if ( slider == mOsc2PulseWidthSlider )
	{
		Synth1.SetSetting( Synth::Osc2PulseWidth, (float)slider->getValue() );
	}
	else if ( slider == mCutoffSlider )
	{
		Synth1.SetSetting( Synth::Cutoff, (float)slider->getValue() );
	}
	else if ( slider == mCutoffLFOFreqSlider )
	{
		Synth1.SetSetting( Synth::CutoffLFOFreq, (float)slider->getValue() );
	}
	else if ( slider == mCutoffLFORangeSlider )
	{
		Synth1.SetSetting( Synth::CutoffLFORange, (float)slider->getValue() );
	}
	else if ( slider == mResonanceSlider )
	{
		Synth1.SetSetting( Synth::Resonance, (float)slider->getValue() );
	}
	else if ( slider == mDelayTimeSlider )
	{
		Synth1.SetSetting( Synth::DelayTime, (float)slider->getValue() );
	}
	else if ( slider == mDelayLevelSlider )
	{
		Synth1.SetSetting( Synth::DelayLevel, (float)slider->getValue() );
	}
	else if ( slider == mModDelayRateSlider )
	{
		Synth1.SetSetting( Synth::ModDelayRate, (float)slider->getValue() );
	}
	else if ( slider == mModDelayMinSlider )
	{
		Synth1.SetSetting( Synth::ModDelayMin, (float)slider->getValue() );
	}
	else if ( slider == mModDelayDepthSlider )
	{
		Synth1.SetSetting( Synth::ModDelayDepth, (float)slider->getValue() );
	}
	else if ( slider == mModDelayBlendSlider )
	{
		Synth1.SetSetting( Synth::ModDelayBlend, (float)slider->getValue() );
	}
	else if ( slider == mModDelayFFSlider )
	{
		Synth1.SetSetting( Synth::ModDelayFF, (float)slider->getValue() );
	}
	else if ( slider == mModDelayFBSlider )
	{
		Synth1.SetSetting( Synth::ModDelayFB, (float)slider->getValue() );
	}
	else if ( slider == mArpGateTimeSlider )
	{
		Arp1.SetGateTime( (float)slider->getValue() );
	}
	else if ( slider == mSaturationValueSlider )
	{
		Synth1.SetSetting( Synth::SaturationValue, (float)slider->getValue() );
	}
}

void MainComponent::comboBoxChanged (ComboBox *comboBox)
{
	if ( comboBox == mOsc1TypeSelectBox )
	{
		Synth1.SetSetting( Synth::Osc1Type, (Synth::OscillatorType)comboBox->getSelectedId() );
	}
	else if ( comboBox == mOsc2TypeSelectBox )
	{
		Synth1.SetSetting( Synth::Osc2Type, (Synth::OscillatorType)comboBox->getSelectedId() );
	}
	else if ( comboBox == mOsc1SampleSelectBox )
	{
		int index = comboBox->getSelectedId() - 1;
		Synth1.SetSetting( Synth::Osc1WavetablePath, std::string( mSampleFilePaths[index].toUTF8() ) );
		Synth1.SetSetting( Synth::Osc1WavetableFreq, mSampleFileFrequencies[index] );
	}
	else if ( comboBox == mOsc2SampleSelectBox )
	{
		int index = comboBox->getSelectedId() - 1;
		Synth1.SetSetting( Synth::Osc2WavetablePath, std::string( mSampleFilePaths[index].toUTF8() ) );
		Synth1.SetSetting( Synth::Osc2WavetableFreq, mSampleFileFrequencies[index] );
	}
	else {
		for ( unsigned int i = 0; i < mArpPatternSize; ++i )
		{
			if ( comboBox == mArpPatternSelect[i] )
			{
				Arp1.SetPatternStep( i, static_cast<Arpeggiator::NoteDuration>( comboBox->getSelectedId() ) );
			}
		}
	}
}

void MainComponent::buttonClicked (Button *button)
{
	if ( button == mDelayEnabledButton )
	{
		Synth1.SetSetting( Synth::DelayEnabled, button->getToggleState() );
	}
	else if ( button == mFlangeEnabledButton )
	{
		Synth1.SetSetting( Synth::ModDelayEnabled, button->getToggleState() );
	}
	else if ( button == mArpEnabledButton )
	{
		Arp1.SetEnabled( button->getToggleState() );
	}
	else if ( button == mSaturationEnabledButton )
	{
		Synth1.SetSetting( Synth::SaturationEnabled, button->getToggleState() );
	}
}

void MainComponent::changeListenerCallback (void *objectThatHasChanged)
{
	DirectoryContentsList *dirList = static_cast<DirectoryContentsList*>( objectThatHasChanged );
	
	//mSampleFilePaths.clear();
	for (int i = 0; i < dirList->getNumFiles(); ++i)
	{
		File file = dirList->getFile( i );
		String fileName = file.getFileName();
		mSampleFilePaths.push_back( file.getFullPathName() );
		mOsc1SampleSelectBox->addItem( fileName, i + 1 );
		mOsc2SampleSelectBox->addItem( fileName, i + 1 );
		
		// Look for sample frequency appended after dash
		int dashPos = fileName.lastIndexOfChar( '-' );
		int dotPos = fileName.lastIndexOfChar( '.' );
		float freq = 440.0f;
		if ( dashPos != -1 && dashPos < dotPos - 1 )
		{
			String freqString = fileName.substring( dashPos + 1, dotPos );
			float f = freqString.getFloatValue();
			if ( f > 0.0f ) freq = f;
		}
		mSampleFileFrequencies.push_back( freq );

		if ( 0 == mOsc1SampleSelectBox->getSelectedId() &&
			file.getFullPathName() == String( Synth1.GetSetting( Synth::Osc1WavetablePath ).toString().c_str() ) )
		{
			mOsc1SampleSelectBox->setSelectedItemIndex( i );
		}
		if ( 0 == mOsc2SampleSelectBox->getSelectedId() &&
			file.getFullPathName() == String( Synth1.GetSetting( Synth::Osc2WavetablePath ).toString().c_str() ) )
		{
			mOsc2SampleSelectBox->setSelectedItemIndex( i );
		}
	}
	
	// If the synth does not have a matching wavetable path set, just select the first item.
	if ( 0 != mSampleFilePaths.size() )
	{
		if ( 0 == mOsc1SampleSelectBox->getSelectedId() )
		{
			mOsc1SampleSelectBox->setSelectedItemIndex( 0 );
		}
		if ( 0 == mOsc2SampleSelectBox->getSelectedId() )
		{
			mOsc2SampleSelectBox->setSelectedItemIndex( 0 );
		}
	}
}

void MainComponent::handleIncomingMidiMessage (MidiInput *source, const MidiMessage &message)
{
	if ( message.isNoteOn() ) {
		Arp1.NoteOn( message.getNoteNumber(), message.getVelocity() / 255.0f );
	}
	else if ( message.isNoteOff() ) {
		Arp1.NoteOff( message.getNoteNumber() );
	}
}

//const unsigned int MainComponent::mArpPatternSize;

void MainComponent::CreateOscControls( ComboBox*& typeSelect, Slider*& volSlider, Slider*& semitoneSlider, Slider*& centSlider, Slider*& pwSlider, ComboBox*& sampleSelect )
{
	typeSelect = new ComboBox( String::empty );
	typeSelect->addItem( String("Sine"), Synth::Sine );
	typeSelect->addItem( String("Pulse"), Synth::Pulse );
	typeSelect->addItem( String("Saw"), Synth::Saw );
	typeSelect->addItem( String("Triangle"), Synth::Triangle );
	typeSelect->addItem( String("White Noise"), Synth::WhiteNoise );
	typeSelect->addItem( String("Wavetable"), Synth::Wavetable );
	typeSelect->addItem( String("One Shot"), Synth::OneShot );
	typeSelect->setEditableText( false );
	typeSelect->addListener( this );
	addAndMakeVisible( typeSelect );

	volSlider = new Slider( String::empty );
	volSlider->setSliderStyle( Slider::RotaryVerticalDrag );
	volSlider->addListener( this );
	volSlider->setRange( 0.0, 1.0, 0.01 );
	addAndMakeVisible( volSlider );

	semitoneSlider = new Slider( String::empty );
	semitoneSlider->setSliderStyle( Slider::RotaryVerticalDrag );
	semitoneSlider->addListener( this );
	semitoneSlider->setRange( -24, 24, 1 );
	addAndMakeVisible( semitoneSlider );

	centSlider = new Slider( String::empty );
	centSlider->setSliderStyle( Slider::RotaryVerticalDrag );
	centSlider->addListener( this );
	centSlider->setRange( -15.0, 15.0, 0.1 );
	addAndMakeVisible( centSlider );

	pwSlider = new Slider( String::empty );
	pwSlider->setSliderStyle( Slider::RotaryVerticalDrag );
	pwSlider->addListener( this );
	pwSlider->setRange( 0.01, 0.99, 0.01 );
	addAndMakeVisible( pwSlider );
	
	sampleSelect = new ComboBox( String::empty );
	sampleSelect->addListener( this );
	addAndMakeVisible( sampleSelect );
}

//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="600" initialHeight="300">
  <BACKGROUND backgroundColour="ffc1d0ff">
    <PATH pos="0 0 100 100" fill="solid: ffffffff" hasStroke="1" stroke="5.19999981, mitered, butt"
          strokeColour="solid: ff6f6f6f" nonZeroWinding="1">s 136 80 q 176 24 328 32 q 472 40 472 104 q 472 192 232 176 l 184 216 l 200 168 q 96 136 136 80 x</PATH>
  </BACKGROUND>
  <LABEL name="" id="be4f6f2e5725a063" memberName="helloWorldLabel" virtualName=""
         explicitFocusOrder="0" pos="152 80 296 48" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Hello World!" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="40" bold="1" italic="0" justification="36"/>
  <TEXTBUTTON name="" id="bcf4f7b0888effe5" memberName="quitButton" virtualName=""
              explicitFocusOrder="0" pos="176R 60R 120 32" buttonText="Quit"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
