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

#ifndef __JUCER_HEADER_MAINCOMPONENT_MAINCOMPONENT_D0F6CD31__
#define __JUCER_HEADER_MAINCOMPONENT_MAINCOMPONENT_D0F6CD31__

//[Headers]     -- You can add your own extra header files here --
#include <vector>
#include "juce_Include.h"
//[/Headers]

enum eEnvelopeADSR
{
	Attack,
	Decay,
	Sustain,
	Release
};
static const unsigned int eEnvelopeADSR_Count = 4;

//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent :
	public Component,
	public MidiKeyboardStateListener,
	public SliderListener,
	public ComboBoxListener,
	public ButtonListener,
	public ChangeListener,
	public MidiInputCallback
{
public:
    //==============================================================================
    MainComponent ();
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

	void handleNoteOn (MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity);
	void handleNoteOff (MidiKeyboardState *source, int midiChannel, int midiNoteNumber);

	void sliderValueChanged (Slider *slider);

	void comboBoxChanged (ComboBox *comboBoxThatHasChanged);
	
	void buttonClicked (Button *button);
	
	virtual void changeListenerCallback (void *objectThatHasChanged);
	
	void handleIncomingMidiMessage (MidiInput *source, const MidiMessage &message);

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]
	
	static const unsigned int mArpPatternSize = 4;
	
	void CreateOscControls( ComboBox*& typeSelect, Slider*& volSlider, Slider*& semitoneSlider, Slider*& centSlider, Slider*& pwSlider, ComboBox*& sampleSelect );

    //==============================================================================
    MidiKeyboardComponent* mKeyboard;
	MidiKeyboardState mMidiKeyboardState;

	// envelope
	Slider* mEnvelopeSlider[eEnvelopeADSR_Count];
	Label* mEnvelopeLabel[eEnvelopeADSR_Count];
	
	// objects used by both oscillators
	WildcardFileFilter* mSampleFileFilter;
	TimeSliceThread* mTimeSliceThread;
	DirectoryContentsList* mSampleDirList;
	std::vector<String> mSampleFilePaths;
	std::vector<float> mSampleFileFrequencies;
	
	// oscillator 1
	Label* mOsc1Label;
	Label* mOsc1VolumeLabel;
	Label* mOsc1SemitoneLabel;
	Label* mOsc1CentLabel;
	Label* mOsc1PulseWidthLabel;
	ComboBox* mOsc1TypeSelectBox;
	ComboBox* mOsc1SampleSelectBox;
	Slider* mOsc1VolumeSlider;
	Slider* mOsc1SemitoneSlider;
	Slider* mOsc1CentSlider;
	Slider* mOsc1PulseWidthSlider;
	
	// oscillator 2
	ComboBox* mOsc2TypeSelectBox;
	ComboBox* mOsc2SampleSelectBox;
	Slider* mOsc2VolumeSlider;
	Slider* mOsc2SemitoneSlider;
	Slider* mOsc2CentSlider;
	Slider* mOsc2PulseWidthSlider;
	
	// filter
	Slider* mCutoffSlider;
	Slider* mCutoffLFOFreqSlider;
	Slider* mCutoffLFORangeSlider;
	Slider* mResonanceSlider;
	
	// delay
	Label* mDelayLabel;
	ToggleButton* mDelayEnabledButton;
	Slider* mDelayTimeSlider;
	Slider* mDelayLevelSlider;
	
	// flange
	Label* mFlangeLabel;
	ToggleButton* mFlangeEnabledButton;
	Slider* mModDelayRateSlider;
	Slider* mModDelayMinSlider;
	Slider* mModDelayDepthSlider;
	Slider* mModDelayBlendSlider;
	Slider* mModDelayFFSlider;
	Slider* mModDelayFBSlider;
	
	// arpeggiator
	Label* mArpLabel;
	ToggleButton* mArpEnabledButton;
	Slider* mArpGateTimeSlider;
	ComboBox* mArpPatternSelect[mArpPatternSize];

	// saturation
	Label* mSaturationLabel;
	ToggleButton* mSaturationEnabledButton;
	Slider* mSaturationValueSlider;
	
	MidiInput* mMidiInput;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    MainComponent (const MainComponent&);
    const MainComponent& operator= (const MainComponent&);
};


#endif   // __JUCER_HEADER_MAINCOMPONENT_MAINCOMPONENT_D0F6CD31__
