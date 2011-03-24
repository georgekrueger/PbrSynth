/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  21 Nov 2010 8:02:45 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_NEWJUCERCOMPONENT_NEWJUCERCOMPONENT_D67BBB3D__
#define __JUCER_HEADER_NEWJUCERCOMPONENT_NEWJUCERCOMPONENT_D67BBB3D__

//[Headers]     -- You can add your own extra header files here --
#include "juce_Include.h"
#include <vector>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class NewJucerComponent  : public Component,
                           public MidiKeyboardStateListener,
                           public ChangeListener,
                           public MidiInputCallback,
                           public SliderListener,
                           public ComboBoxListener,
                           public ButtonListener
{
public:
    //==============================================================================
    NewJucerComponent ();
    ~NewJucerComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void handleNoteOn (MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity);
	void handleNoteOff (MidiKeyboardState *source, int midiChannel, int midiNoteNumber);
	virtual void changeListenerCallback (void *objectThatHasChanged);
	virtual void handleIncomingMidiMessage (MidiInput *source, const MidiMessage &message);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	String getSynthSettingsFilePath(bool save);
	void applySynthSettingsToUI();
	void applyArpSettingsToUI();
	void updateArpPatternFromUI();

	// objects used by both oscillators
	WildcardFileFilter* mSampleFileFilter;
	TimeSliceThread* mTimeSliceThread;
	DirectoryContentsList* mSampleDirList;
	std::vector<String> mSampleFilePaths;
	std::vector<float> mSampleFileFrequencies;

	MidiKeyboardState mMidiKeyboardState;
	MidiInput* mMidiInput;
	std::vector<ComboBox*> mArpComboBoxes;
    //[/UserVariables]

    //==============================================================================
    Slider* mAttackSlider;
    Label* label;
    Slider* mDecaySlider;
    Label* label2;
    Slider* mSustainSlider;
    Label* label3;
    Slider* mReleaseSlider;
    Label* label4;
    Slider* mOsc1VolumeSlider;
    Label* label5;
    Slider* mOsc1SemitoneSlider;
    Label* label6;
    Slider* mOsc1CentSlider;
    Label* label7;
    Slider* mOsc1PulseWidthSlider;
    Label* label8;
    ComboBox* mOsc1TypeSelectBox;
    Label* label9;
    Slider* mOsc2VolumeSlider;
    Label* label10;
    Slider* mOsc2SemitoneSlider;
    Label* label11;
    Slider* mOsc2CentSlider;
    Label* label12;
    Slider* mOsc2PulseWidthSlider;
    Label* label13;
    ComboBox* mOsc2TypeSelectBox;
    Label* label14;
    Slider* mCutoffSlider;
    Label* label15;
    Slider* mCutoffLFOFreqSlider;
    Label* label16;
    Slider* mCutoffLFORangeSlider;
    Label* label17;
    Slider* mResonanceSlider;
    Label* label18;
    Slider* mModDelayMinSlider;
    Slider* mModDelayDepthSlider;
    Slider* mModDelayRateSlider;
    Slider* mModDelayFFSlider;
    Slider* mModDelayFBSlider;
    Label* label22;
    Slider* mModDelayBlendSlider;
    Label* label23;
    Label* label24;
    Label* label25;
    Label* label26;
    Label* label27;
    ComboBox* mOsc1SampleSelectBox;
    ComboBox* mOsc2SampleSelectBox;
    Label* label19;
    Label* label28;
    Label* label29;
    Label* label30;
    Label* label31;
    ComboBox* mArpPatternSelect1;
    ComboBox* mArpPatternSelect2;
    ComboBox* mArpPatternSelect3;
    ComboBox* mArpPatternSelect4;
    Label* label32;
    Label* label33;
    Slider* mDistortionValueSlider;
    ToggleButton* mDelayEnabledButton;
    ToggleButton* mModDelayEnabledButton;
    ToggleButton* mArpEnabledButton;
    ToggleButton* mDistortionEnabledButton;
    Label* label34;
    Slider* mArpGateTimeSlider;
    MidiKeyboardComponent* mKeyboardComponent;
    Slider* mGlobalVolumeSlider;
    Label* label35;
    TextButton* mLoadButton;
    TextButton* mSaveButton;
    ComboBox* mFilter1ComboBox;
    ComboBox* mFilter2ComboBox;
    ComboBox* mFilter3ComboBox;
    ComboBox* mFilter4ComboBox;
    Label* label36;
    Slider* mDelayBlendSlider;
    Label* label37;
    Slider* mDelayTimeSlider1;
    Label* label38;
    Slider* mDelayFFSlider1;
    Label* label39;
    Slider* mDelayFBSlider1;
    Label* label20;
    Slider* mDelayTimeSlider2;
    Label* label21;
    Slider* mDelayFFSlider2;
    Label* label40;
    Slider* mDelayFBSlider2;
    Label* mClippingLabel;
    ComboBox* mDelayTimeStep1;
    ComboBox* mDelayTimeStep2;
    Slider* mGlobalTempoSlider;
    Label* label41;
    ToggleButton* mOscillatorSyncEnabled;
    Label* label42;
    Slider* mCutoffAttackSlider;
    Label* label43;
    Slider* mCutoffDecaySlider;
    Label* label44;
    Slider* mCutoffReleaseSlider;
    Label* label45;
    Slider* mCutoffSustainSlider;
    Label* label46;
    Slider* mCutoffEnvelopeAmount;
    Label* label47;
    Label* label48;
    Label* label49;
    Slider* mOctaveHarmonicSlider;
    ToggleButton* mOctaveEnabledButton;
    Label* label50;
    Slider* mOctaveSubharmonicSlider;
    Label* label51;
    Slider* mOctaveDrySlider;
    Label* label52;
    ToggleButton* mMonoEnabledButton;
    Label* label53;
    ToggleButton* mGlideEnabledButton;
    Label* label54;
    Slider* mGlideTimeSlider;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    NewJucerComponent (const NewJucerComponent&);
    const NewJucerComponent& operator= (const NewJucerComponent&);
};


#endif   // __JUCER_HEADER_NEWJUCERCOMPONENT_NEWJUCERCOMPONENT_D67BBB3D__
