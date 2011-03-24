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

//[Headers] You can add your own extra header files here...
#include "Synth.h"
#include "Arpeggiator.h"
//[/Headers]

#include "NewJucerComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern Synth Synth1;
extern Arpeggiator Arp1;

//[/MiscUserDefs]

//==============================================================================
NewJucerComponent::NewJucerComponent ()
    : mAttackSlider (0),
      label (0),
      mDecaySlider (0),
      label2 (0),
      mSustainSlider (0),
      label3 (0),
      mReleaseSlider (0),
      label4 (0),
      mOsc1VolumeSlider (0),
      label5 (0),
      mOsc1SemitoneSlider (0),
      label6 (0),
      mOsc1CentSlider (0),
      label7 (0),
      mOsc1PulseWidthSlider (0),
      label8 (0),
      mOsc1TypeSelectBox (0),
      label9 (0),
      mOsc2VolumeSlider (0),
      label10 (0),
      mOsc2SemitoneSlider (0),
      label11 (0),
      mOsc2CentSlider (0),
      label12 (0),
      mOsc2PulseWidthSlider (0),
      label13 (0),
      mOsc2TypeSelectBox (0),
      label14 (0),
      mCutoffSlider (0),
      label15 (0),
      mCutoffLFOFreqSlider (0),
      label16 (0),
      mCutoffLFORangeSlider (0),
      label17 (0),
      mResonanceSlider (0),
      label18 (0),
      mModDelayMinSlider (0),
      mModDelayDepthSlider (0),
      mModDelayRateSlider (0),
      mModDelayFFSlider (0),
      mModDelayFBSlider (0),
      label22 (0),
      mModDelayBlendSlider (0),
      label23 (0),
      label24 (0),
      label25 (0),
      label26 (0),
      label27 (0),
      mOsc1SampleSelectBox (0),
      mOsc2SampleSelectBox (0),
      label19 (0),
      label28 (0),
      label29 (0),
      label30 (0),
      label31 (0),
      mArpPatternSelect1 (0),
      mArpPatternSelect2 (0),
      mArpPatternSelect3 (0),
      mArpPatternSelect4 (0),
      label32 (0),
      label33 (0),
      mDistortionValueSlider (0),
      mDelayEnabledButton (0),
      mModDelayEnabledButton (0),
      mArpEnabledButton (0),
      mDistortionEnabledButton (0),
      label34 (0),
      mArpGateTimeSlider (0),
      mKeyboardComponent (0),
      mGlobalVolumeSlider (0),
      label35 (0),
      mLoadButton (0),
      mSaveButton (0),
      mFilter1ComboBox (0),
      mFilter2ComboBox (0),
      mFilter3ComboBox (0),
      mFilter4ComboBox (0),
      label36 (0),
      mDelayBlendSlider (0),
      label37 (0),
      mDelayTimeSlider1 (0),
      label38 (0),
      mDelayFFSlider1 (0),
      label39 (0),
      mDelayFBSlider1 (0),
      label20 (0),
      mDelayTimeSlider2 (0),
      label21 (0),
      mDelayFFSlider2 (0),
      label40 (0),
      mDelayFBSlider2 (0),
      mClippingLabel (0),
      mDelayTimeStep1 (0),
      mDelayTimeStep2 (0),
      mGlobalTempoSlider (0),
      label41 (0),
      mOscillatorSyncEnabled (0),
      label42 (0),
      mCutoffAttackSlider (0),
      label43 (0),
      mCutoffDecaySlider (0),
      label44 (0),
      mCutoffReleaseSlider (0),
      label45 (0),
      mCutoffSustainSlider (0),
      label46 (0),
      mCutoffEnvelopeAmount (0),
      label47 (0),
      label48 (0),
      label49 (0),
      mOctaveHarmonicSlider (0),
      mOctaveEnabledButton (0),
      label50 (0),
      mOctaveSubharmonicSlider (0),
      label51 (0),
      mOctaveDrySlider (0),
      label52 (0),
      mMonoEnabledButton (0),
      label53 (0),
      mGlideEnabledButton (0),
      label54 (0),
      mGlideTimeSlider (0)
{
    addAndMakeVisible (mAttackSlider = new Slider (T("new slider")));
    mAttackSlider->setRange (0.001, 10, 0.001);
    mAttackSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mAttackSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mAttackSlider->addListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Attack")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mDecaySlider = new Slider (T("new slider")));
    mDecaySlider->setRange (0.001, 10, 0.001);
    mDecaySlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mDecaySlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mDecaySlider->addListener (this);

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Decay")));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mSustainSlider = new Slider (T("new slider")));
    mSustainSlider->setRange (0, 1, 0.01);
    mSustainSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mSustainSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mSustainSlider->addListener (this);

    addAndMakeVisible (label3 = new Label (T("new label"),
                                           T("Sustain")));
    label3->setFont (Font (15.0000f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mReleaseSlider = new Slider (T("new slider")));
    mReleaseSlider->setRange (0.001, 10, 0.001);
    mReleaseSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mReleaseSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mReleaseSlider->addListener (this);

    addAndMakeVisible (label4 = new Label (T("new label"),
                                           T("Release")));
    label4->setFont (Font (15.0000f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOsc1VolumeSlider = new Slider (T("new slider")));
    mOsc1VolumeSlider->setRange (0, 1, 0.01);
    mOsc1VolumeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mOsc1VolumeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mOsc1VolumeSlider->addListener (this);

    addAndMakeVisible (label5 = new Label (T("new label"),
                                           T("Volume")));
    label5->setFont (Font (15.0000f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOsc1SemitoneSlider = new Slider (T("new slider")));
    mOsc1SemitoneSlider->setRange (-24, 24, 1);
    mOsc1SemitoneSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mOsc1SemitoneSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mOsc1SemitoneSlider->addListener (this);

    addAndMakeVisible (label6 = new Label (T("new label"),
                                           T("Semitones")));
    label6->setFont (Font (15.0000f, Font::plain));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOsc1CentSlider = new Slider (T("new slider")));
    mOsc1CentSlider->setRange (-100, 100, 0.1);
    mOsc1CentSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mOsc1CentSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mOsc1CentSlider->addListener (this);

    addAndMakeVisible (label7 = new Label (T("new label"),
                                           T("Cents")));
    label7->setFont (Font (15.0000f, Font::plain));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOsc1PulseWidthSlider = new Slider (T("new slider")));
    mOsc1PulseWidthSlider->setRange (0, 0.99, 0.01);
    mOsc1PulseWidthSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mOsc1PulseWidthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mOsc1PulseWidthSlider->addListener (this);

    addAndMakeVisible (label8 = new Label (T("new label"),
                                           T("Pulse Width")));
    label8->setFont (Font (15.0000f, Font::plain));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOsc1TypeSelectBox = new ComboBox (T("new combo box")));
    mOsc1TypeSelectBox->setEditableText (false);
    mOsc1TypeSelectBox->setJustificationType (Justification::centredLeft);
    mOsc1TypeSelectBox->setTextWhenNothingSelected (String::empty);
    mOsc1TypeSelectBox->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mOsc1TypeSelectBox->addItem (T("Sine"), 1);
    mOsc1TypeSelectBox->addItem (T("Pulse"), 2);
    mOsc1TypeSelectBox->addItem (T("Saw"), 3);
    mOsc1TypeSelectBox->addItem (T("Triangle"), 4);
    mOsc1TypeSelectBox->addItem (T("Noise"), 5);
    mOsc1TypeSelectBox->addItem (T("Wavetable"), 6);
    mOsc1TypeSelectBox->addItem (T("One Shot"), 7);
    mOsc1TypeSelectBox->addItem (T("Blep Saw"), 8);
    mOsc1TypeSelectBox->addItem (T("Blep Square"), 9);
    mOsc1TypeSelectBox->addListener (this);

    addAndMakeVisible (label9 = new Label (T("new label"),
                                           T("Osc 1")));
    label9->setFont (Font (20.0000f, Font::plain));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOsc2VolumeSlider = new Slider (T("new slider")));
    mOsc2VolumeSlider->setRange (0, 1, 0.01);
    mOsc2VolumeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mOsc2VolumeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mOsc2VolumeSlider->addListener (this);

    addAndMakeVisible (label10 = new Label (T("new label"),
                                            T("Volume")));
    label10->setFont (Font (15.0000f, Font::plain));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOsc2SemitoneSlider = new Slider (T("new slider")));
    mOsc2SemitoneSlider->setRange (-24, 24, 1);
    mOsc2SemitoneSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mOsc2SemitoneSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mOsc2SemitoneSlider->addListener (this);

    addAndMakeVisible (label11 = new Label (T("new label"),
                                            T("Semitones")));
    label11->setFont (Font (15.0000f, Font::plain));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOsc2CentSlider = new Slider (T("new slider")));
    mOsc2CentSlider->setRange (-100, 100, 0.1);
    mOsc2CentSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mOsc2CentSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mOsc2CentSlider->addListener (this);

    addAndMakeVisible (label12 = new Label (T("new label"),
                                            T("Cents")));
    label12->setFont (Font (15.0000f, Font::plain));
    label12->setJustificationType (Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOsc2PulseWidthSlider = new Slider (T("new slider")));
    mOsc2PulseWidthSlider->setRange (0, 0.99, 0.01);
    mOsc2PulseWidthSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mOsc2PulseWidthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mOsc2PulseWidthSlider->addListener (this);

    addAndMakeVisible (label13 = new Label (T("new label"),
                                            T("Pulse Width")));
    label13->setFont (Font (15.0000f, Font::plain));
    label13->setJustificationType (Justification::centredLeft);
    label13->setEditable (false, false, false);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOsc2TypeSelectBox = new ComboBox (T("new combo box")));
    mOsc2TypeSelectBox->setEditableText (false);
    mOsc2TypeSelectBox->setJustificationType (Justification::centredLeft);
    mOsc2TypeSelectBox->setTextWhenNothingSelected (String::empty);
    mOsc2TypeSelectBox->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mOsc2TypeSelectBox->addItem (T("Sine"), 1);
    mOsc2TypeSelectBox->addItem (T("Pulse"), 2);
    mOsc2TypeSelectBox->addItem (T("Saw"), 3);
    mOsc2TypeSelectBox->addItem (T("Triangle"), 4);
    mOsc2TypeSelectBox->addItem (T("Noise"), 5);
    mOsc2TypeSelectBox->addItem (T("Wavetable"), 6);
    mOsc2TypeSelectBox->addItem (T("One Shot"), 7);
    mOsc2TypeSelectBox->addItem (T("Blep Saw"), 8);
    mOsc2TypeSelectBox->addItem (T("Blep Square"), 9);
    mOsc2TypeSelectBox->addListener (this);

    addAndMakeVisible (label14 = new Label (T("new label"),
                                            T("Osc 2")));
    label14->setFont (Font (20.0000f, Font::plain));
    label14->setJustificationType (Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mCutoffSlider = new Slider (T("new slider")));
    mCutoffSlider->setRange (10, 11025, 1);
    mCutoffSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mCutoffSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mCutoffSlider->addListener (this);

    addAndMakeVisible (label15 = new Label (T("new label"),
                                            T("Cutoff")));
    label15->setFont (Font (15.0000f, Font::plain));
    label15->setJustificationType (Justification::centredLeft);
    label15->setEditable (false, false, false);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mCutoffLFOFreqSlider = new Slider (T("new slider")));
    mCutoffLFOFreqSlider->setRange (0, 10, 0.01);
    mCutoffLFOFreqSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mCutoffLFOFreqSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mCutoffLFOFreqSlider->addListener (this);

    addAndMakeVisible (label16 = new Label (T("new label"),
                                            T("LFO Freq")));
    label16->setFont (Font (15.0000f, Font::plain));
    label16->setJustificationType (Justification::centredLeft);
    label16->setEditable (false, false, false);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mCutoffLFORangeSlider = new Slider (T("new slider")));
    mCutoffLFORangeSlider->setRange (0, 5000, 1);
    mCutoffLFORangeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mCutoffLFORangeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mCutoffLFORangeSlider->addListener (this);

    addAndMakeVisible (label17 = new Label (T("new label"),
                                            T("LFO Range")));
    label17->setFont (Font (15.0000f, Font::plain));
    label17->setJustificationType (Justification::centredLeft);
    label17->setEditable (false, false, false);
    label17->setColour (TextEditor::textColourId, Colours::black);
    label17->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mResonanceSlider = new Slider (T("new slider")));
    mResonanceSlider->setRange (0, 1, 0.01);
    mResonanceSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mResonanceSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mResonanceSlider->addListener (this);

    addAndMakeVisible (label18 = new Label (T("new label"),
                                            T("Resonance")));
    label18->setFont (Font (15.0000f, Font::plain));
    label18->setJustificationType (Justification::centredLeft);
    label18->setEditable (false, false, false);
    label18->setColour (TextEditor::textColourId, Colours::black);
    label18->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mModDelayMinSlider = new Slider (T("new slider")));
    mModDelayMinSlider->setRange (0.001, 0.5, 0.001);
    mModDelayMinSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mModDelayMinSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mModDelayMinSlider->addListener (this);

    addAndMakeVisible (mModDelayDepthSlider = new Slider (T("new slider")));
    mModDelayDepthSlider->setRange (0.001, 0.5, 0.001);
    mModDelayDepthSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mModDelayDepthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mModDelayDepthSlider->addListener (this);

    addAndMakeVisible (mModDelayRateSlider = new Slider (T("new slider")));
    mModDelayRateSlider->setRange (0.01, 5, 0.01);
    mModDelayRateSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mModDelayRateSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mModDelayRateSlider->addListener (this);

    addAndMakeVisible (mModDelayFFSlider = new Slider (T("new slider")));
    mModDelayFFSlider->setRange (0, 1, 0.001);
    mModDelayFFSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mModDelayFFSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mModDelayFFSlider->addListener (this);

    addAndMakeVisible (mModDelayFBSlider = new Slider (T("new slider")));
    mModDelayFBSlider->setRange (-1, 1, 0.001);
    mModDelayFBSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mModDelayFBSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mModDelayFBSlider->addListener (this);

    addAndMakeVisible (label22 = new Label (T("new label"),
                                            T("Min Time")));
    label22->setFont (Font (15.0000f, Font::plain));
    label22->setJustificationType (Justification::centredLeft);
    label22->setEditable (false, false, false);
    label22->setColour (TextEditor::textColourId, Colours::black);
    label22->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mModDelayBlendSlider = new Slider (T("new slider")));
    mModDelayBlendSlider->setRange (0, 1, 0.001);
    mModDelayBlendSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mModDelayBlendSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mModDelayBlendSlider->addListener (this);

    addAndMakeVisible (label23 = new Label (T("new label"),
                                            T("Depth")));
    label23->setFont (Font (15.0000f, Font::plain));
    label23->setJustificationType (Justification::centredLeft);
    label23->setEditable (false, false, false);
    label23->setColour (TextEditor::textColourId, Colours::black);
    label23->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label24 = new Label (T("new label"),
                                            T("Rate")));
    label24->setFont (Font (15.0000f, Font::plain));
    label24->setJustificationType (Justification::centredLeft);
    label24->setEditable (false, false, false);
    label24->setColour (TextEditor::textColourId, Colours::black);
    label24->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label25 = new Label (T("new label"),
                                            T("Feed Fwd")));
    label25->setFont (Font (15.0000f, Font::plain));
    label25->setJustificationType (Justification::centredLeft);
    label25->setEditable (false, false, false);
    label25->setColour (TextEditor::textColourId, Colours::black);
    label25->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label26 = new Label (T("new label"),
                                            T("Feedback")));
    label26->setFont (Font (15.0000f, Font::plain));
    label26->setJustificationType (Justification::centredLeft);
    label26->setEditable (false, false, false);
    label26->setColour (TextEditor::textColourId, Colours::black);
    label26->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label27 = new Label (T("new label"),
                                            T("Blend")));
    label27->setFont (Font (15.0000f, Font::plain));
    label27->setJustificationType (Justification::centredLeft);
    label27->setEditable (false, false, false);
    label27->setColour (TextEditor::textColourId, Colours::black);
    label27->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOsc1SampleSelectBox = new ComboBox (T("new combo box")));
    mOsc1SampleSelectBox->setEditableText (false);
    mOsc1SampleSelectBox->setJustificationType (Justification::centredLeft);
    mOsc1SampleSelectBox->setTextWhenNothingSelected (String::empty);
    mOsc1SampleSelectBox->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mOsc1SampleSelectBox->addListener (this);

    addAndMakeVisible (mOsc2SampleSelectBox = new ComboBox (T("new combo box")));
    mOsc2SampleSelectBox->setEditableText (false);
    mOsc2SampleSelectBox->setJustificationType (Justification::centredLeft);
    mOsc2SampleSelectBox->setTextWhenNothingSelected (String::empty);
    mOsc2SampleSelectBox->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mOsc2SampleSelectBox->addListener (this);

    addAndMakeVisible (label19 = new Label (T("new label"),
                                            T("Envelope")));
    label19->setFont (Font (20.0000f, Font::plain));
    label19->setJustificationType (Justification::centredLeft);
    label19->setEditable (false, false, false);
    label19->setColour (TextEditor::textColourId, Colours::black);
    label19->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label28 = new Label (T("new label"),
                                            T("Filter")));
    label28->setFont (Font (20.0000f, Font::plain));
    label28->setJustificationType (Justification::centredLeft);
    label28->setEditable (false, false, false);
    label28->setColour (TextEditor::textColourId, Colours::black);
    label28->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label29 = new Label (T("new label"),
                                            T("Delay")));
    label29->setFont (Font (20.0000f, Font::plain));
    label29->setJustificationType (Justification::centredLeft);
    label29->setEditable (false, false, false);
    label29->setColour (TextEditor::textColourId, Colours::black);
    label29->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label30 = new Label (T("new label"),
                                            T("Mod\nDelay")));
    label30->setFont (Font (20.0000f, Font::plain));
    label30->setJustificationType (Justification::centredLeft);
    label30->setEditable (false, false, false);
    label30->setColour (TextEditor::textColourId, Colours::black);
    label30->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label31 = new Label (T("new label"),
                                            T("Arp")));
    label31->setFont (Font (20.0000f, Font::plain));
    label31->setJustificationType (Justification::centredLeft);
    label31->setEditable (false, false, false);
    label31->setColour (TextEditor::textColourId, Colours::black);
    label31->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mArpPatternSelect1 = new ComboBox (T("new combo box")));
    mArpPatternSelect1->setEditableText (false);
    mArpPatternSelect1->setJustificationType (Justification::centredLeft);
    mArpPatternSelect1->setTextWhenNothingSelected (String::empty);
    mArpPatternSelect1->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mArpPatternSelect1->addItem (T("0"), 1);
    mArpPatternSelect1->addItem (T("1"), 2);
    mArpPatternSelect1->addItem (T("1/2"), 3);
    mArpPatternSelect1->addItem (T("1/3"), 4);
    mArpPatternSelect1->addItem (T("1/4"), 5);
    mArpPatternSelect1->addItem (T("1/6"), 6);
    mArpPatternSelect1->addItem (T("1/8"), 7);
    mArpPatternSelect1->addItem (T("1/16"), 8);
    mArpPatternSelect1->addItem (T("1/32"), 9);
    mArpPatternSelect1->addItem (T("-1"), 10);
    mArpPatternSelect1->addItem (T("-1/2"), 11);
    mArpPatternSelect1->addItem (T("-1/3"), 12);
    mArpPatternSelect1->addItem (T("-1/4"), 13);
    mArpPatternSelect1->addItem (T("-1/6"), 14);
    mArpPatternSelect1->addItem (T("-1/8"), 15);
    mArpPatternSelect1->addItem (T("-1/16"), 16);
    mArpPatternSelect1->addItem (T("-1/32"), 17);
    mArpPatternSelect1->addListener (this);

    addAndMakeVisible (mArpPatternSelect2 = new ComboBox (T("new combo box")));
    mArpPatternSelect2->setEditableText (false);
    mArpPatternSelect2->setJustificationType (Justification::centredLeft);
    mArpPatternSelect2->setTextWhenNothingSelected (String::empty);
    mArpPatternSelect2->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mArpPatternSelect2->addItem (T("0"), 1);
    mArpPatternSelect2->addItem (T("1"), 2);
    mArpPatternSelect2->addItem (T("1/2"), 3);
    mArpPatternSelect2->addItem (T("1/3"), 4);
    mArpPatternSelect2->addItem (T("1/4"), 5);
    mArpPatternSelect2->addItem (T("1/6"), 6);
    mArpPatternSelect2->addItem (T("1/8"), 7);
    mArpPatternSelect2->addItem (T("1/16"), 8);
    mArpPatternSelect2->addItem (T("1/32"), 9);
    mArpPatternSelect2->addItem (T("-1"), 10);
    mArpPatternSelect2->addItem (T("-1/2"), 11);
    mArpPatternSelect2->addItem (T("-1/3"), 12);
    mArpPatternSelect2->addItem (T("-1/4"), 13);
    mArpPatternSelect2->addItem (T("-1/6"), 14);
    mArpPatternSelect2->addItem (T("-1/8"), 15);
    mArpPatternSelect2->addItem (T("-1/16"), 16);
    mArpPatternSelect2->addItem (T("-1/32"), 17);
    mArpPatternSelect2->addListener (this);

    addAndMakeVisible (mArpPatternSelect3 = new ComboBox (T("new combo box")));
    mArpPatternSelect3->setEditableText (false);
    mArpPatternSelect3->setJustificationType (Justification::centredLeft);
    mArpPatternSelect3->setTextWhenNothingSelected (String::empty);
    mArpPatternSelect3->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mArpPatternSelect3->addItem (T("0"), 1);
    mArpPatternSelect3->addItem (T("1"), 2);
    mArpPatternSelect3->addItem (T("1/2"), 3);
    mArpPatternSelect3->addItem (T("1/3"), 4);
    mArpPatternSelect3->addItem (T("1/4"), 5);
    mArpPatternSelect3->addItem (T("1/6"), 6);
    mArpPatternSelect3->addItem (T("1/8"), 7);
    mArpPatternSelect3->addItem (T("1/16"), 8);
    mArpPatternSelect3->addItem (T("1/32"), 9);
    mArpPatternSelect3->addItem (T("-1"), 10);
    mArpPatternSelect3->addItem (T("-1/2"), 11);
    mArpPatternSelect3->addItem (T("-1/3"), 12);
    mArpPatternSelect3->addItem (T("-1/4"), 13);
    mArpPatternSelect3->addItem (T("-1/6"), 14);
    mArpPatternSelect3->addItem (T("-1/8"), 15);
    mArpPatternSelect3->addItem (T("-1/16"), 16);
    mArpPatternSelect3->addItem (T("-1/32"), 17);
    mArpPatternSelect3->addListener (this);

    addAndMakeVisible (mArpPatternSelect4 = new ComboBox (T("new combo box")));
    mArpPatternSelect4->setEditableText (false);
    mArpPatternSelect4->setJustificationType (Justification::centredLeft);
    mArpPatternSelect4->setTextWhenNothingSelected (String::empty);
    mArpPatternSelect4->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mArpPatternSelect4->addItem (T("0"), 1);
    mArpPatternSelect4->addItem (T("1"), 2);
    mArpPatternSelect4->addItem (T("1/2"), 3);
    mArpPatternSelect4->addItem (T("1/3"), 4);
    mArpPatternSelect4->addItem (T("1/4"), 5);
    mArpPatternSelect4->addItem (T("1/6"), 6);
    mArpPatternSelect4->addItem (T("1/8"), 7);
    mArpPatternSelect4->addItem (T("1/16"), 8);
    mArpPatternSelect4->addItem (T("1/32"), 9);
    mArpPatternSelect4->addItem (T("-1"), 10);
    mArpPatternSelect4->addItem (T("-1/2"), 11);
    mArpPatternSelect4->addItem (T("-1/3"), 12);
    mArpPatternSelect4->addItem (T("-1/4"), 13);
    mArpPatternSelect4->addItem (T("-1/6"), 14);
    mArpPatternSelect4->addItem (T("-1/8"), 15);
    mArpPatternSelect4->addItem (T("-1/16"), 16);
    mArpPatternSelect4->addItem (T("-1/32"), 17);
    mArpPatternSelect4->addListener (this);

    addAndMakeVisible (label32 = new Label (T("new label"),
                                            T("Distortion")));
    label32->setFont (Font (20.0000f, Font::plain));
    label32->setJustificationType (Justification::centredLeft);
    label32->setEditable (false, false, false);
    label32->setColour (TextEditor::textColourId, Colours::black);
    label32->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label33 = new Label (T("new label"),
                                            T("Level")));
    label33->setFont (Font (15.0000f, Font::plain));
    label33->setJustificationType (Justification::centredLeft);
    label33->setEditable (false, false, false);
    label33->setColour (TextEditor::textColourId, Colours::black);
    label33->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mDistortionValueSlider = new Slider (T("new slider")));
    mDistortionValueSlider->setRange (1, 20, 0.01);
    mDistortionValueSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mDistortionValueSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mDistortionValueSlider->addListener (this);

    addAndMakeVisible (mDelayEnabledButton = new ToggleButton (T("new toggle button")));
    mDelayEnabledButton->setButtonText (String::empty);
    mDelayEnabledButton->addButtonListener (this);

    addAndMakeVisible (mModDelayEnabledButton = new ToggleButton (T("new toggle button")));
    mModDelayEnabledButton->setButtonText (String::empty);
    mModDelayEnabledButton->addButtonListener (this);

    addAndMakeVisible (mArpEnabledButton = new ToggleButton (T("new toggle button")));
    mArpEnabledButton->setButtonText (String::empty);
    mArpEnabledButton->addButtonListener (this);

    addAndMakeVisible (mDistortionEnabledButton = new ToggleButton (T("new toggle button")));
    mDistortionEnabledButton->setButtonText (String::empty);
    mDistortionEnabledButton->addButtonListener (this);

    addAndMakeVisible (label34 = new Label (T("new label"),
                                            T("Gate Time")));
    label34->setFont (Font (15.0000f, Font::plain));
    label34->setJustificationType (Justification::centredLeft);
    label34->setEditable (false, false, false);
    label34->setColour (TextEditor::textColourId, Colours::black);
    label34->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mArpGateTimeSlider = new Slider (T("new slider")));
    mArpGateTimeSlider->setRange (0, 0.99, 0.01);
    mArpGateTimeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mArpGateTimeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mArpGateTimeSlider->addListener (this);

    addAndMakeVisible (mKeyboardComponent = new MidiKeyboardComponent (mMidiKeyboardState, MidiKeyboardComponent::horizontalKeyboard));
    mKeyboardComponent->setName (T("new component"));

    addAndMakeVisible (mGlobalVolumeSlider = new Slider (T("new slider")));
    mGlobalVolumeSlider->setRange (0, 1, 0.01);
    mGlobalVolumeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mGlobalVolumeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mGlobalVolumeSlider->addListener (this);

    addAndMakeVisible (label35 = new Label (T("new label"),
                                            T("Volume")));
    label35->setFont (Font (20.0000f, Font::plain));
    label35->setJustificationType (Justification::centredLeft);
    label35->setEditable (false, false, false);
    label35->setColour (TextEditor::textColourId, Colours::black);
    label35->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mLoadButton = new TextButton (T("Load Button")));
    mLoadButton->setButtonText (T("Load..."));
    mLoadButton->addButtonListener (this);

    addAndMakeVisible (mSaveButton = new TextButton (T("Save Button")));
    mSaveButton->setButtonText (T("Save..."));
    mSaveButton->addButtonListener (this);

    addAndMakeVisible (mFilter1ComboBox = new ComboBox (T("Filter 1 Combo Box")));
    mFilter1ComboBox->setEditableText (false);
    mFilter1ComboBox->setJustificationType (Justification::centredLeft);
    mFilter1ComboBox->setTextWhenNothingSelected (String::empty);
    mFilter1ComboBox->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mFilter1ComboBox->addItem (T("Delay"), 1);
    mFilter1ComboBox->addItem (T("Mod Delay"), 2);
    mFilter1ComboBox->addItem (T("Distortion"), 3);
    mFilter1ComboBox->addItem (T("Octave"), 4);
    mFilter1ComboBox->addListener (this);

    addAndMakeVisible (mFilter2ComboBox = new ComboBox (T("Filter 2 Combo Box")));
    mFilter2ComboBox->setEditableText (false);
    mFilter2ComboBox->setJustificationType (Justification::centredLeft);
    mFilter2ComboBox->setTextWhenNothingSelected (String::empty);
    mFilter2ComboBox->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mFilter2ComboBox->addItem (T("Delay"), 1);
    mFilter2ComboBox->addItem (T("Mod Delay"), 2);
    mFilter2ComboBox->addItem (T("Distortion"), 3);
    mFilter2ComboBox->addItem (T("Octave"), 4);
    mFilter2ComboBox->addListener (this);

    addAndMakeVisible (mFilter3ComboBox = new ComboBox (T("Filter 3 Combo Box")));
    mFilter3ComboBox->setEditableText (false);
    mFilter3ComboBox->setJustificationType (Justification::centredLeft);
    mFilter3ComboBox->setTextWhenNothingSelected (String::empty);
    mFilter3ComboBox->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mFilter3ComboBox->addItem (T("Delay"), 1);
    mFilter3ComboBox->addItem (T("Mod Delay"), 2);
    mFilter3ComboBox->addItem (T("Distortion"), 3);
    mFilter3ComboBox->addItem (T("Octave"), 4);
    mFilter3ComboBox->addListener (this);

    addAndMakeVisible (mFilter4ComboBox = new ComboBox (T("Filter 4 Combo Box")));
    mFilter4ComboBox->setEditableText (false);
    mFilter4ComboBox->setJustificationType (Justification::centredLeft);
    mFilter4ComboBox->setTextWhenNothingSelected (String::empty);
    mFilter4ComboBox->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mFilter4ComboBox->addItem (T("Delay"), 1);
    mFilter4ComboBox->addItem (T("Mod Delay"), 2);
    mFilter4ComboBox->addItem (T("Distortion"), 3);
    mFilter4ComboBox->addItem (T("Octave"), 4);
    mFilter4ComboBox->addListener (this);

    addAndMakeVisible (label36 = new Label (T("new label"),
                                            T("Blend")));
    label36->setFont (Font (15.0000f, Font::plain));
    label36->setJustificationType (Justification::centredLeft);
    label36->setEditable (false, false, false);
    label36->setColour (TextEditor::textColourId, Colours::black);
    label36->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mDelayBlendSlider = new Slider (T("new slider")));
    mDelayBlendSlider->setRange (0, 1, 0.01);
    mDelayBlendSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mDelayBlendSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mDelayBlendSlider->addListener (this);

    addAndMakeVisible (label37 = new Label (T("new label"),
                                            T("Time")));
    label37->setFont (Font (15.0000f, Font::plain));
    label37->setJustificationType (Justification::centredLeft);
    label37->setEditable (false, false, false);
    label37->setColour (TextEditor::textColourId, Colours::black);
    label37->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mDelayTimeSlider1 = new Slider (T("new slider")));
    mDelayTimeSlider1->setRange (0, 1, 0.01);
    mDelayTimeSlider1->setSliderStyle (Slider::RotaryVerticalDrag);
    mDelayTimeSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mDelayTimeSlider1->addListener (this);

    addAndMakeVisible (label38 = new Label (T("new label"),
                                            T("Feed Fwd")));
    label38->setFont (Font (15.0000f, Font::plain));
    label38->setJustificationType (Justification::centredLeft);
    label38->setEditable (false, false, false);
    label38->setColour (TextEditor::textColourId, Colours::black);
    label38->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mDelayFFSlider1 = new Slider (T("new slider")));
    mDelayFFSlider1->setRange (0.01, 1, 0.01);
    mDelayFFSlider1->setSliderStyle (Slider::RotaryVerticalDrag);
    mDelayFFSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mDelayFFSlider1->addListener (this);

    addAndMakeVisible (label39 = new Label (T("new label"),
                                            T("Feedback")));
    label39->setFont (Font (15.0000f, Font::plain));
    label39->setJustificationType (Justification::centredLeft);
    label39->setEditable (false, false, false);
    label39->setColour (TextEditor::textColourId, Colours::black);
    label39->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mDelayFBSlider1 = new Slider (T("new slider")));
    mDelayFBSlider1->setRange (0, 1, 0.01);
    mDelayFBSlider1->setSliderStyle (Slider::RotaryVerticalDrag);
    mDelayFBSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mDelayFBSlider1->addListener (this);

    addAndMakeVisible (label20 = new Label (T("new label"),
                                            T("Time 2")));
    label20->setFont (Font (15.0000f, Font::plain));
    label20->setJustificationType (Justification::centredLeft);
    label20->setEditable (false, false, false);
    label20->setColour (TextEditor::textColourId, Colours::black);
    label20->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mDelayTimeSlider2 = new Slider (T("new slider")));
    mDelayTimeSlider2->setRange (0, 1, 0.01);
    mDelayTimeSlider2->setSliderStyle (Slider::RotaryVerticalDrag);
    mDelayTimeSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mDelayTimeSlider2->addListener (this);

    addAndMakeVisible (label21 = new Label (T("new label"),
                                            T("Feed Fwd 2")));
    label21->setFont (Font (15.0000f, Font::plain));
    label21->setJustificationType (Justification::centredLeft);
    label21->setEditable (false, false, false);
    label21->setColour (TextEditor::textColourId, Colours::black);
    label21->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mDelayFFSlider2 = new Slider (T("new slider")));
    mDelayFFSlider2->setRange (0.01, 1, 0.01);
    mDelayFFSlider2->setSliderStyle (Slider::RotaryVerticalDrag);
    mDelayFFSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mDelayFFSlider2->addListener (this);

    addAndMakeVisible (label40 = new Label (T("new label"),
                                            T("FeedBack 2")));
    label40->setFont (Font (15.0000f, Font::plain));
    label40->setJustificationType (Justification::centredLeft);
    label40->setEditable (false, false, false);
    label40->setColour (TextEditor::textColourId, Colours::black);
    label40->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mDelayFBSlider2 = new Slider (T("new slider")));
    mDelayFBSlider2->setRange (0, 1, 0.01);
    mDelayFBSlider2->setSliderStyle (Slider::RotaryVerticalDrag);
    mDelayFBSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mDelayFBSlider2->addListener (this);

    addAndMakeVisible (mClippingLabel = new Label (T("new label"),
                                                   String::empty));
    mClippingLabel->setFont (Font (15.0000f, Font::plain));
    mClippingLabel->setJustificationType (Justification::centredLeft);
    mClippingLabel->setEditable (false, false, false);
    mClippingLabel->setColour (TextEditor::textColourId, Colours::black);
    mClippingLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mDelayTimeStep1 = new ComboBox (T("new combo box")));
    mDelayTimeStep1->setEditableText (false);
    mDelayTimeStep1->setJustificationType (Justification::centredLeft);
    mDelayTimeStep1->setTextWhenNothingSelected (String::empty);
    mDelayTimeStep1->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mDelayTimeStep1->addItem (T("0"), 1);
    mDelayTimeStep1->addItem (T("1"), 2);
    mDelayTimeStep1->addItem (T("1/2"), 3);
    mDelayTimeStep1->addItem (T("1/3"), 4);
    mDelayTimeStep1->addItem (T("1/4"), 5);
    mDelayTimeStep1->addItem (T("1/6"), 6);
    mDelayTimeStep1->addItem (T("1/8"), 7);
    mDelayTimeStep1->addItem (T("1/16"), 8);
    mDelayTimeStep1->addItem (T("1/32"), 9);
    mDelayTimeStep1->addListener (this);

    addAndMakeVisible (mDelayTimeStep2 = new ComboBox (T("new combo box")));
    mDelayTimeStep2->setEditableText (false);
    mDelayTimeStep2->setJustificationType (Justification::centredLeft);
    mDelayTimeStep2->setTextWhenNothingSelected (String::empty);
    mDelayTimeStep2->setTextWhenNoChoicesAvailable (T("(no choices)"));
    mDelayTimeStep2->addItem (T("0"), 1);
    mDelayTimeStep2->addItem (T("1"), 2);
    mDelayTimeStep2->addItem (T("1/2"), 3);
    mDelayTimeStep2->addItem (T("1/3"), 4);
    mDelayTimeStep2->addItem (T("1/4"), 5);
    mDelayTimeStep2->addItem (T("1/6"), 6);
    mDelayTimeStep2->addItem (T("1/8"), 7);
    mDelayTimeStep2->addItem (T("1/16"), 8);
    mDelayTimeStep2->addItem (T("1/32"), 9);
    mDelayTimeStep2->addListener (this);

    addAndMakeVisible (mGlobalTempoSlider = new Slider (T("new slider")));
    mGlobalTempoSlider->setRange (80, 240, 1);
    mGlobalTempoSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mGlobalTempoSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mGlobalTempoSlider->addListener (this);

    addAndMakeVisible (label41 = new Label (T("new label"),
                                            T("Tempo")));
    label41->setFont (Font (20.0000f, Font::plain));
    label41->setJustificationType (Justification::centredLeft);
    label41->setEditable (false, false, false);
    label41->setColour (TextEditor::textColourId, Colours::black);
    label41->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOscillatorSyncEnabled = new ToggleButton (T("new toggle button")));
    mOscillatorSyncEnabled->setButtonText (String::empty);
    mOscillatorSyncEnabled->addButtonListener (this);

    addAndMakeVisible (label42 = new Label (T("new label"),
                                            T("Sync")));
    label42->setFont (Font (13.0000f, Font::plain));
    label42->setJustificationType (Justification::centredLeft);
    label42->setEditable (false, false, false);
    label42->setColour (TextEditor::textColourId, Colours::black);
    label42->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mCutoffAttackSlider = new Slider (T("new slider")));
    mCutoffAttackSlider->setRange (0.001, 10, 0.001);
    mCutoffAttackSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mCutoffAttackSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mCutoffAttackSlider->addListener (this);

    addAndMakeVisible (label43 = new Label (T("new label"),
                                            T("Attack")));
    label43->setFont (Font (15.0000f, Font::plain));
    label43->setJustificationType (Justification::centredLeft);
    label43->setEditable (false, false, false);
    label43->setColour (TextEditor::textColourId, Colours::black);
    label43->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mCutoffDecaySlider = new Slider (T("new slider")));
    mCutoffDecaySlider->setRange (0.001, 10, 0.001);
    mCutoffDecaySlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mCutoffDecaySlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mCutoffDecaySlider->addListener (this);

    addAndMakeVisible (label44 = new Label (T("new label"),
                                            T("Decay")));
    label44->setFont (Font (15.0000f, Font::plain));
    label44->setJustificationType (Justification::centredLeft);
    label44->setEditable (false, false, false);
    label44->setColour (TextEditor::textColourId, Colours::black);
    label44->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mCutoffReleaseSlider = new Slider (T("new slider")));
    mCutoffReleaseSlider->setRange (0.001, 10, 0.001);
    mCutoffReleaseSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mCutoffReleaseSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mCutoffReleaseSlider->addListener (this);

    addAndMakeVisible (label45 = new Label (T("new label"),
                                            T("Release")));
    label45->setFont (Font (15.0000f, Font::plain));
    label45->setJustificationType (Justification::centredLeft);
    label45->setEditable (false, false, false);
    label45->setColour (TextEditor::textColourId, Colours::black);
    label45->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mCutoffSustainSlider = new Slider (T("new slider")));
    mCutoffSustainSlider->setRange (0, 1, 0.01);
    mCutoffSustainSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mCutoffSustainSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mCutoffSustainSlider->addListener (this);

    addAndMakeVisible (label46 = new Label (T("new label"),
                                            T("Sustain")));
    label46->setFont (Font (15.0000f, Font::plain));
    label46->setJustificationType (Justification::centredLeft);
    label46->setEditable (false, false, false);
    label46->setColour (TextEditor::textColourId, Colours::black);
    label46->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mCutoffEnvelopeAmount = new Slider (T("new slider")));
    mCutoffEnvelopeAmount->setRange (0, 1, 0.01);
    mCutoffEnvelopeAmount->setSliderStyle (Slider::RotaryVerticalDrag);
    mCutoffEnvelopeAmount->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mCutoffEnvelopeAmount->addListener (this);

    addAndMakeVisible (label47 = new Label (T("new label"),
                                            T("Env Amt")));
    label47->setFont (Font (15.0000f, Font::plain));
    label47->setJustificationType (Justification::centredLeft);
    label47->setEditable (false, false, false);
    label47->setColour (TextEditor::textColourId, Colours::black);
    label47->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label48 = new Label (T("new label"),
                                            T("Octave")));
    label48->setFont (Font (20.0000f, Font::plain));
    label48->setJustificationType (Justification::centredLeft);
    label48->setEditable (false, false, false);
    label48->setColour (TextEditor::textColourId, Colours::black);
    label48->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label49 = new Label (T("new label"),
                                            T("Harmonic")));
    label49->setFont (Font (15.0000f, Font::plain));
    label49->setJustificationType (Justification::centredLeft);
    label49->setEditable (false, false, false);
    label49->setColour (TextEditor::textColourId, Colours::black);
    label49->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOctaveHarmonicSlider = new Slider (T("new slider")));
    mOctaveHarmonicSlider->setRange (0, 1, 0.01);
    mOctaveHarmonicSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mOctaveHarmonicSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mOctaveHarmonicSlider->addListener (this);

    addAndMakeVisible (mOctaveEnabledButton = new ToggleButton (T("new toggle button")));
    mOctaveEnabledButton->setButtonText (String::empty);
    mOctaveEnabledButton->addButtonListener (this);

    addAndMakeVisible (label50 = new Label (T("new label"),
                                            T("Subharmonic")));
    label50->setFont (Font (15.0000f, Font::plain));
    label50->setJustificationType (Justification::centredLeft);
    label50->setEditable (false, false, false);
    label50->setColour (TextEditor::textColourId, Colours::black);
    label50->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOctaveSubharmonicSlider = new Slider (T("new slider")));
    mOctaveSubharmonicSlider->setRange (0, 1, 0.01);
    mOctaveSubharmonicSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mOctaveSubharmonicSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mOctaveSubharmonicSlider->addListener (this);

    addAndMakeVisible (label51 = new Label (T("new label"),
                                            T("Dry")));
    label51->setFont (Font (15.0000f, Font::plain));
    label51->setJustificationType (Justification::centredLeft);
    label51->setEditable (false, false, false);
    label51->setColour (TextEditor::textColourId, Colours::black);
    label51->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mOctaveDrySlider = new Slider (T("new slider")));
    mOctaveDrySlider->setRange (0, 1, 0.01);
    mOctaveDrySlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mOctaveDrySlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mOctaveDrySlider->addListener (this);

    addAndMakeVisible (label52 = new Label (T("new label"),
                                            T("Mono")));
    label52->setFont (Font (20.0000f, Font::plain));
    label52->setJustificationType (Justification::centredLeft);
    label52->setEditable (false, false, false);
    label52->setColour (TextEditor::textColourId, Colours::black);
    label52->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mMonoEnabledButton = new ToggleButton (T("new toggle button")));
    mMonoEnabledButton->setButtonText (String::empty);
    mMonoEnabledButton->addButtonListener (this);

    addAndMakeVisible (label53 = new Label (T("new label"),
                                            T("Glide")));
    label53->setFont (Font (20.0000f, Font::plain));
    label53->setJustificationType (Justification::centredLeft);
    label53->setEditable (false, false, false);
    label53->setColour (TextEditor::textColourId, Colours::black);
    label53->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mGlideEnabledButton = new ToggleButton (T("new toggle button")));
    mGlideEnabledButton->setButtonText (String::empty);
    mGlideEnabledButton->addButtonListener (this);

    addAndMakeVisible (label54 = new Label (T("new label"),
                                            T("Glide Time")));
    label54->setFont (Font (15.0000f, Font::plain));
    label54->setJustificationType (Justification::centredLeft);
    label54->setEditable (false, false, false);
    label54->setColour (TextEditor::textColourId, Colours::black);
    label54->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (mGlideTimeSlider = new Slider (T("new slider")));
    mGlideTimeSlider->setRange (0.01, 0.5, 0.01);
    mGlideTimeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    mGlideTimeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    mGlideTimeSlider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 700);

    //[Constructor] You can add your own custom stuff here..

	mAttackSlider->setSkewFactorFromMidPoint( 2.0 );
	mDecaySlider->setSkewFactorFromMidPoint( 2.0 );
	mReleaseSlider->setSkewFactorFromMidPoint( 2.0 );
	mCutoffAttackSlider->setSkewFactorFromMidPoint( 2.0 );
	mCutoffDecaySlider->setSkewFactorFromMidPoint( 2.0 );
	mCutoffReleaseSlider->setSkewFactorFromMidPoint( 2.0 );
	mCutoffSlider->setSkewFactorFromMidPoint( 2000 );


	mKeyboardComponent->setAlwaysRecieveKeyboardEvents(true);
	mMidiKeyboardState.addListener( this );

	// arpeggiator
	mArpComboBoxes.push_back( mArpPatternSelect1 );
	mArpComboBoxes.push_back( mArpPatternSelect2 );
	mArpComboBoxes.push_back( mArpPatternSelect3 );
	mArpComboBoxes.push_back( mArpPatternSelect4 );

	// find wavetable samples
	mSampleFileFilter = new WildcardFileFilter( String("*.wav"), String("Samples") );
	mTimeSliceThread = new TimeSliceThread( String::empty );
	mTimeSliceThread->startThread();
	mSampleDirList = new DirectoryContentsList( mSampleFileFilter, *mTimeSliceThread );
	mSampleDirList->addChangeListener( this );
	mSampleDirList->setDirectory( File::getCurrentWorkingDirectory().getChildFile("samples"), false, true );

	// Load autosaved settings and apply to UI
	Synth1.LoadSettings( "autosave.syn" );
	applySynthSettingsToUI();

	Arp1.LoadSettings( "autosave.arp" );
	applyArpSettingsToUI();

	mMidiInput = MidiInput::openDevice( MidiInput::getDefaultDeviceIndex(), this );
	if ( mMidiInput ) mMidiInput->start();

    //[/Constructor]
}

NewJucerComponent::~NewJucerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..

	Synth1.SaveSettings( "autosave.syn" );
	Arp1.SaveSettings( "autosave.arp" );

    //[/Destructor_pre]

    deleteAndZero (mAttackSlider);
    deleteAndZero (label);
    deleteAndZero (mDecaySlider);
    deleteAndZero (label2);
    deleteAndZero (mSustainSlider);
    deleteAndZero (label3);
    deleteAndZero (mReleaseSlider);
    deleteAndZero (label4);
    deleteAndZero (mOsc1VolumeSlider);
    deleteAndZero (label5);
    deleteAndZero (mOsc1SemitoneSlider);
    deleteAndZero (label6);
    deleteAndZero (mOsc1CentSlider);
    deleteAndZero (label7);
    deleteAndZero (mOsc1PulseWidthSlider);
    deleteAndZero (label8);
    deleteAndZero (mOsc1TypeSelectBox);
    deleteAndZero (label9);
    deleteAndZero (mOsc2VolumeSlider);
    deleteAndZero (label10);
    deleteAndZero (mOsc2SemitoneSlider);
    deleteAndZero (label11);
    deleteAndZero (mOsc2CentSlider);
    deleteAndZero (label12);
    deleteAndZero (mOsc2PulseWidthSlider);
    deleteAndZero (label13);
    deleteAndZero (mOsc2TypeSelectBox);
    deleteAndZero (label14);
    deleteAndZero (mCutoffSlider);
    deleteAndZero (label15);
    deleteAndZero (mCutoffLFOFreqSlider);
    deleteAndZero (label16);
    deleteAndZero (mCutoffLFORangeSlider);
    deleteAndZero (label17);
    deleteAndZero (mResonanceSlider);
    deleteAndZero (label18);
    deleteAndZero (mModDelayMinSlider);
    deleteAndZero (mModDelayDepthSlider);
    deleteAndZero (mModDelayRateSlider);
    deleteAndZero (mModDelayFFSlider);
    deleteAndZero (mModDelayFBSlider);
    deleteAndZero (label22);
    deleteAndZero (mModDelayBlendSlider);
    deleteAndZero (label23);
    deleteAndZero (label24);
    deleteAndZero (label25);
    deleteAndZero (label26);
    deleteAndZero (label27);
    deleteAndZero (mOsc1SampleSelectBox);
    deleteAndZero (mOsc2SampleSelectBox);
    deleteAndZero (label19);
    deleteAndZero (label28);
    deleteAndZero (label29);
    deleteAndZero (label30);
    deleteAndZero (label31);
    deleteAndZero (mArpPatternSelect1);
    deleteAndZero (mArpPatternSelect2);
    deleteAndZero (mArpPatternSelect3);
    deleteAndZero (mArpPatternSelect4);
    deleteAndZero (label32);
    deleteAndZero (label33);
    deleteAndZero (mDistortionValueSlider);
    deleteAndZero (mDelayEnabledButton);
    deleteAndZero (mModDelayEnabledButton);
    deleteAndZero (mArpEnabledButton);
    deleteAndZero (mDistortionEnabledButton);
    deleteAndZero (label34);
    deleteAndZero (mArpGateTimeSlider);
    deleteAndZero (mKeyboardComponent);
    deleteAndZero (mGlobalVolumeSlider);
    deleteAndZero (label35);
    deleteAndZero (mLoadButton);
    deleteAndZero (mSaveButton);
    deleteAndZero (mFilter1ComboBox);
    deleteAndZero (mFilter2ComboBox);
    deleteAndZero (mFilter3ComboBox);
    deleteAndZero (mFilter4ComboBox);
    deleteAndZero (label36);
    deleteAndZero (mDelayBlendSlider);
    deleteAndZero (label37);
    deleteAndZero (mDelayTimeSlider1);
    deleteAndZero (label38);
    deleteAndZero (mDelayFFSlider1);
    deleteAndZero (label39);
    deleteAndZero (mDelayFBSlider1);
    deleteAndZero (label20);
    deleteAndZero (mDelayTimeSlider2);
    deleteAndZero (label21);
    deleteAndZero (mDelayFFSlider2);
    deleteAndZero (label40);
    deleteAndZero (mDelayFBSlider2);
    deleteAndZero (mClippingLabel);
    deleteAndZero (mDelayTimeStep1);
    deleteAndZero (mDelayTimeStep2);
    deleteAndZero (mGlobalTempoSlider);
    deleteAndZero (label41);
    deleteAndZero (mOscillatorSyncEnabled);
    deleteAndZero (label42);
    deleteAndZero (mCutoffAttackSlider);
    deleteAndZero (label43);
    deleteAndZero (mCutoffDecaySlider);
    deleteAndZero (label44);
    deleteAndZero (mCutoffReleaseSlider);
    deleteAndZero (label45);
    deleteAndZero (mCutoffSustainSlider);
    deleteAndZero (label46);
    deleteAndZero (mCutoffEnvelopeAmount);
    deleteAndZero (label47);
    deleteAndZero (label48);
    deleteAndZero (label49);
    deleteAndZero (mOctaveHarmonicSlider);
    deleteAndZero (mOctaveEnabledButton);
    deleteAndZero (label50);
    deleteAndZero (mOctaveSubharmonicSlider);
    deleteAndZero (label51);
    deleteAndZero (mOctaveDrySlider);
    deleteAndZero (label52);
    deleteAndZero (mMonoEnabledButton);
    deleteAndZero (label53);
    deleteAndZero (mGlideEnabledButton);
    deleteAndZero (label54);
    deleteAndZero (mGlideTimeSlider);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void NewJucerComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colour (0xffcaf7f7));
    g.fillRoundedRectangle (12.0f, 8.0f, 576.0f, 52.0f, 10.0000f);

    g.setColour (Colour (0xffcaf7f7));
    g.fillRoundedRectangle (8.0f, 68.0f, 736.0f, 112.0f, 10.0000f);

    g.setColour (Colour (0xffcaf7f7));
    g.fillRoundedRectangle (8.0f, 188.0f, 520.0f, 100.0f, 10.0000f);

    g.setColour (Colour (0xffcaf7f7));
    g.fillRoundedRectangle (12.0f, 296.0f, 768.0f, 64.0f, 10.0000f);

    g.setColour (Colour (0xffcaf7f7));
    g.fillRoundedRectangle (12.0f, 368.0f, 552.0f, 64.0f, 10.0000f);

    g.setColour (Colour (0xffcaf7f7));
    g.fillRoundedRectangle (12.0f, 440.0f, 744.0f, 64.0f, 10.0000f);

    g.setColour (Colour (0xffcaf7f7));
    g.fillRoundedRectangle (596.0f, 8.0f, 232.0f, 52.0f, 10.0000f);

    g.setColour (Colour (0xffcaf7f7));
    g.fillRoundedRectangle (536.0f, 188.0f, 208.0f, 52.0f, 10.0000f);

    g.setColour (Colour (0xffcaf7f7));
    g.fillRoundedRectangle (572.0f, 368.0f, 316.0f, 64.0f, 10.0000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void NewJucerComponent::resized()
{
    mAttackSlider->setBounds (162, 30, 70, 24);
    label->setBounds (162, 11, 56, 24);
    mDecaySlider->setBounds (241, 30, 70, 24);
    label2->setBounds (241, 11, 56, 24);
    mSustainSlider->setBounds (318, 30, 70, 24);
    label3->setBounds (318, 11, 56, 24);
    mReleaseSlider->setBounds (397, 30, 70, 24);
    label4->setBounds (397, 11, 56, 24);
    mOsc1VolumeSlider->setBounds (246, 91, 70, 24);
    label5->setBounds (246, 73, 56, 24);
    mOsc1SemitoneSlider->setBounds (330, 91, 70, 24);
    label6->setBounds (330, 73, 86, 24);
    mOsc1CentSlider->setBounds (414, 91, 70, 24);
    label7->setBounds (414, 73, 78, 24);
    mOsc1PulseWidthSlider->setBounds (486, 91, 70, 24);
    label8->setBounds (486, 73, 87, 24);
    mOsc1TypeSelectBox->setBounds (126, 91, 100, 24);
    label9->setBounds (43, 91, 96, 24);
    mOsc2VolumeSlider->setBounds (246, 136, 70, 24);
    label10->setBounds (246, 118, 56, 24);
    mOsc2SemitoneSlider->setBounds (330, 136, 70, 24);
    label11->setBounds (330, 118, 86, 24);
    mOsc2CentSlider->setBounds (414, 136, 70, 24);
    label12->setBounds (414, 118, 78, 24);
    mOsc2PulseWidthSlider->setBounds (486, 136, 70, 24);
    label13->setBounds (486, 118, 87, 24);
    mOsc2TypeSelectBox->setBounds (126, 135, 100, 24);
    label14->setBounds (43, 135, 96, 24);
    mCutoffSlider->setBounds (123, 210, 70, 24);
    label15->setBounds (123, 192, 56, 24);
    mCutoffLFOFreqSlider->setBounds (202, 210, 70, 24);
    label16->setBounds (202, 192, 86, 24);
    mCutoffLFORangeSlider->setBounds (275, 210, 70, 24);
    label17->setBounds (275, 192, 78, 24);
    mResonanceSlider->setBounds (351, 210, 70, 24);
    label18->setBounds (351, 192, 87, 24);
    mModDelayMinSlider->setBounds (125, 396, 70, 24);
    mModDelayDepthSlider->setBounds (198, 396, 70, 24);
    mModDelayRateSlider->setBounds (270, 396, 70, 24);
    mModDelayFFSlider->setBounds (342, 396, 70, 24);
    mModDelayFBSlider->setBounds (414, 396, 70, 24);
    label22->setBounds (125, 372, 72, 24);
    mModDelayBlendSlider->setBounds (486, 396, 70, 24);
    label23->setBounds (198, 372, 72, 24);
    label24->setBounds (270, 372, 72, 24);
    label25->setBounds (342, 372, 96, 24);
    label26->setBounds (414, 372, 96, 24);
    label27->setBounds (486, 372, 96, 24);
    mOsc1SampleSelectBox->setBounds (576, 89, 150, 24);
    mOsc2SampleSelectBox->setBounds (576, 131, 150, 24);
    label19->setBounds (42, 26, 108, 24);
    label28->setBounds (42, 228, 84, 24);
    label29->setBounds (42, 322, 84, 24);
    label30->setBounds (42, 389, 66, 36);
    label31->setBounds (42, 468, 66, 24);
    mArpPatternSelect1->setBounds (125, 468, 50, 24);
    mArpPatternSelect2->setBounds (185, 468, 50, 24);
    mArpPatternSelect3->setBounds (245, 468, 50, 24);
    mArpPatternSelect4->setBounds (305, 468, 50, 24);
    label32->setBounds (564, 208, 110, 24);
    label33->setBounds (672, 191, 72, 24);
    mDistortionValueSlider->setBounds (672, 208, 70, 24);
    mDelayEnabledButton->setBounds (18, 322, 19, 24);
    mModDelayEnabledButton->setBounds (18, 396, 19, 24);
    mArpEnabledButton->setBounds (18, 468, 19, 24);
    mDistortionEnabledButton->setBounds (544, 208, 19, 24);
    label34->setBounds (386, 451, 72, 24);
    mArpGateTimeSlider->setBounds (386, 471, 70, 24);
    mKeyboardComponent->setBounds (24, 528, 936, 144);
    mGlobalVolumeSlider->setBounds (609, 31, 70, 24);
    label35->setBounds (608, 9, 78, 25);
    mLoadButton->setBounds (869, 12, 80, 24);
    mSaveButton->setBounds (869, 48, 80, 24);
    mFilter1ComboBox->setBounds (821, 204, 150, 24);
    mFilter2ComboBox->setBounds (821, 240, 150, 24);
    mFilter3ComboBox->setBounds (821, 276, 150, 24);
    mFilter4ComboBox->setBounds (821, 312, 150, 24);
    label36->setBounds (125, 307, 48, 24);
    mDelayBlendSlider->setBounds (125, 326, 70, 24);
    label37->setBounds (260, 307, 48, 24);
    mDelayTimeSlider1->setBounds (260, 326, 70, 24);
    label38->setBounds (330, 307, 63, 24);
    mDelayFFSlider1->setBounds (330, 326, 70, 24);
    label39->setBounds (402, 307, 63, 24);
    mDelayFBSlider1->setBounds (402, 326, 70, 24);
    label20->setBounds (551, 307, 48, 24);
    mDelayTimeSlider2->setBounds (551, 326, 70, 24);
    label21->setBounds (621, 307, 63, 24);
    mDelayFFSlider2->setBounds (621, 326, 70, 24);
    label40->setBounds (693, 307, 63, 24);
    mDelayFBSlider2->setBounds (693, 326, 70, 24);
    mClippingLabel->setBounds (948, 96, 24, 24);
    mDelayTimeStep1->setBounds (201, 325, 50, 24);
    mDelayTimeStep2->setBounds (493, 325, 50, 24);
    mGlobalTempoSlider->setBounds (694, 31, 70, 24);
    label41->setBounds (693, 11, 65, 24);
    mOscillatorSyncEnabled->setBounds (131, 157, 19, 24);
    label42->setBounds (152, 156, 56, 24);
    mCutoffAttackSlider->setBounds (203, 254, 70, 24);
    label43->setBounds (201, 236, 86, 24);
    mCutoffDecaySlider->setBounds (275, 253, 70, 24);
    label44->setBounds (275, 235, 52, 24);
    mCutoffReleaseSlider->setBounds (427, 254, 70, 24);
    label45->setBounds (427, 236, 61, 24);
    mCutoffSustainSlider->setBounds (349, 252, 70, 24);
    label46->setBounds (349, 234, 63, 24);
    mCutoffEnvelopeAmount->setBounds (123, 253, 70, 24);
    label47->setBounds (123, 235, 69, 24);
    label48->setBounds (600, 388, 72, 24);
    label49->setBounds (672, 372, 72, 24);
    mOctaveHarmonicSlider->setBounds (673, 394, 70, 24);
    mOctaveEnabledButton->setBounds (580, 388, 19, 24);
    label50->setBounds (744, 372, 72, 24);
    mOctaveSubharmonicSlider->setBounds (745, 394, 70, 24);
    label51->setBounds (828, 372, 72, 24);
    mOctaveDrySlider->setBounds (817, 394, 70, 24);
    label52->setBounds (504, 468, 72, 24);
    mMonoEnabledButton->setBounds (484, 468, 19, 24);
    label53->setBounds (592, 467, 56, 24);
    mGlideEnabledButton->setBounds (572, 467, 19, 24);
    label54->setBounds (645, 453, 72, 24);
    mGlideTimeSlider->setBounds (644, 475, 70, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void NewJucerComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == mAttackSlider)
    {
        //[UserSliderCode_mAttackSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Attack, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mAttackSlider]
    }
    else if (sliderThatWasMoved == mDecaySlider)
    {
        //[UserSliderCode_mDecaySlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Decay, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mDecaySlider]
    }
    else if (sliderThatWasMoved == mSustainSlider)
    {
        //[UserSliderCode_mSustainSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Sustain, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mSustainSlider]
    }
    else if (sliderThatWasMoved == mReleaseSlider)
    {
        //[UserSliderCode_mReleaseSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Release, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mReleaseSlider]
    }
    else if (sliderThatWasMoved == mOsc1VolumeSlider)
    {
        //[UserSliderCode_mOsc1VolumeSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Osc1Volume, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mOsc1VolumeSlider]
    }
    else if (sliderThatWasMoved == mOsc1SemitoneSlider)
    {
        //[UserSliderCode_mOsc1SemitoneSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Osc1DetuneSemitones, (int)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mOsc1SemitoneSlider]
    }
    else if (sliderThatWasMoved == mOsc1CentSlider)
    {
        //[UserSliderCode_mOsc1CentSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Osc1DetuneCents, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mOsc1CentSlider]
    }
    else if (sliderThatWasMoved == mOsc1PulseWidthSlider)
    {
        //[UserSliderCode_mOsc1PulseWidthSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Osc1PulseWidth, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mOsc1PulseWidthSlider]
    }
    else if (sliderThatWasMoved == mOsc2VolumeSlider)
    {
        //[UserSliderCode_mOsc2VolumeSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Osc2Volume, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mOsc2VolumeSlider]
    }
    else if (sliderThatWasMoved == mOsc2SemitoneSlider)
    {
        //[UserSliderCode_mOsc2SemitoneSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Osc2DetuneSemitones, (int)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mOsc2SemitoneSlider]
    }
    else if (sliderThatWasMoved == mOsc2CentSlider)
    {
        //[UserSliderCode_mOsc2CentSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Osc2DetuneCents, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mOsc2CentSlider]
    }
    else if (sliderThatWasMoved == mOsc2PulseWidthSlider)
    {
        //[UserSliderCode_mOsc2PulseWidthSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Osc2PulseWidth, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mOsc2PulseWidthSlider]
    }
    else if (sliderThatWasMoved == mCutoffSlider)
    {
        //[UserSliderCode_mCutoffSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Cutoff, (int)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mCutoffSlider]
    }
    else if (sliderThatWasMoved == mCutoffLFOFreqSlider)
    {
        //[UserSliderCode_mCutoffLFOFreqSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::CutoffLFOFreq, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mCutoffLFOFreqSlider]
    }
    else if (sliderThatWasMoved == mCutoffLFORangeSlider)
    {
        //[UserSliderCode_mCutoffLFORangeSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::CutoffLFORange, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mCutoffLFORangeSlider]
    }
    else if (sliderThatWasMoved == mResonanceSlider)
    {
        //[UserSliderCode_mResonanceSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::Resonance, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mResonanceSlider]
    }
    else if (sliderThatWasMoved == mModDelayMinSlider)
    {
        //[UserSliderCode_mModDelayMinSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::ModDelayMin, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mModDelayMinSlider]
    }
    else if (sliderThatWasMoved == mModDelayDepthSlider)
    {
        //[UserSliderCode_mModDelayDepthSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::ModDelayDepth, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mModDelayDepthSlider]
    }
    else if (sliderThatWasMoved == mModDelayRateSlider)
    {
        //[UserSliderCode_mModDelayRateSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::ModDelayRate, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mModDelayRateSlider]
    }
    else if (sliderThatWasMoved == mModDelayFFSlider)
    {
        //[UserSliderCode_mModDelayFFSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::ModDelayFF, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mModDelayFFSlider]
    }
    else if (sliderThatWasMoved == mModDelayFBSlider)
    {
        //[UserSliderCode_mModDelayFBSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::ModDelayFB, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mModDelayFBSlider]
    }
    else if (sliderThatWasMoved == mModDelayBlendSlider)
    {
        //[UserSliderCode_mModDelayBlendSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::ModDelayBlend, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mModDelayBlendSlider]
    }
    else if (sliderThatWasMoved == mDistortionValueSlider)
    {
        //[UserSliderCode_mDistortionValueSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::DistortionValue, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mDistortionValueSlider]
    }
    else if (sliderThatWasMoved == mArpGateTimeSlider)
    {
        //[UserSliderCode_mArpGateTimeSlider] -- add your slider handling code here..
		Arp1.SetGateTime( (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mArpGateTimeSlider]
    }
    else if (sliderThatWasMoved == mGlobalVolumeSlider)
    {
        //[UserSliderCode_mGlobalVolumeSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::GlobalVolume, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mGlobalVolumeSlider]
    }
    else if (sliderThatWasMoved == mDelayBlendSlider)
    {
        //[UserSliderCode_mDelayBlendSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::DelayBlend, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mDelayBlendSlider]
    }
    else if (sliderThatWasMoved == mDelayTimeSlider1)
    {
        //[UserSliderCode_mDelayTimeSlider1] -- add your slider handling code here..
		Synth1.SetSetting( Synth::DelaySecondsOffset1, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mDelayTimeSlider1]
    }
    else if (sliderThatWasMoved == mDelayFFSlider1)
    {
        //[UserSliderCode_mDelayFFSlider1] -- add your slider handling code here..
		Synth1.SetSetting( Synth::DelayFeedForward1, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mDelayFFSlider1]
    }
    else if (sliderThatWasMoved == mDelayFBSlider1)
    {
        //[UserSliderCode_mDelayFBSlider1] -- add your slider handling code here..
		Synth1.SetSetting( Synth::DelayFeedBack1, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mDelayFBSlider1]
    }
    else if (sliderThatWasMoved == mDelayTimeSlider2)
    {
        //[UserSliderCode_mDelayTimeSlider2] -- add your slider handling code here..
		Synth1.SetSetting( Synth::DelaySecondsOffset2, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mDelayTimeSlider2]
    }
    else if (sliderThatWasMoved == mDelayFFSlider2)
    {
        //[UserSliderCode_mDelayFFSlider2] -- add your slider handling code here..
		Synth1.SetSetting( Synth::DelayFeedForward2, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mDelayFFSlider2]
    }
    else if (sliderThatWasMoved == mDelayFBSlider2)
    {
        //[UserSliderCode_mDelayFBSlider2] -- add your slider handling code here..
		Synth1.SetSetting( Synth::DelayFeedBack2, (float)sliderThatWasMoved->getValue() );
		if ( sliderThatWasMoved->getValue() > 0.5 ) {
			mClippingLabel->setColour (TextEditor::backgroundColourId, Colour(255,0,0) );
			mClippingLabel->repaint();
		}
        //[/UserSliderCode_mDelayFBSlider2]
    }
    else if (sliderThatWasMoved == mGlobalTempoSlider)
    {
        //[UserSliderCode_mGlobalTempoSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::TempoBPM, (float)sliderThatWasMoved->getValue() );
		Arp1.SetTempo( (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mGlobalTempoSlider]
    }
    else if (sliderThatWasMoved == mCutoffAttackSlider)
    {
        //[UserSliderCode_mCutoffAttackSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::FilterCutoffAttack, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mCutoffAttackSlider]
    }
    else if (sliderThatWasMoved == mCutoffDecaySlider)
    {
        //[UserSliderCode_mCutoffDecaySlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::FilterCutoffDecay, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mCutoffDecaySlider]
    }
    else if (sliderThatWasMoved == mCutoffReleaseSlider)
    {
        //[UserSliderCode_mCutoffReleaseSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::FilterCutoffRelease, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mCutoffReleaseSlider]
    }
    else if (sliderThatWasMoved == mCutoffSustainSlider)
    {
        //[UserSliderCode_mCutoffSustainSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::FilterCutoffSustain, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mCutoffSustainSlider]
    }
    else if (sliderThatWasMoved == mCutoffEnvelopeAmount)
    {
        //[UserSliderCode_mCutoffEnvelopeAmount] -- add your slider handling code here..
		Synth1.SetSetting( Synth::FilterCutoffEnvelopeAmount, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mCutoffEnvelopeAmount]
    }
    else if (sliderThatWasMoved == mOctaveHarmonicSlider)
    {
        //[UserSliderCode_mOctaveHarmonicSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::OctaveHarmonic, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mOctaveHarmonicSlider]
    }
    else if (sliderThatWasMoved == mOctaveSubharmonicSlider)
    {
        //[UserSliderCode_mOctaveSubharmonicSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::OctaveSubharmonic, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mOctaveSubharmonicSlider]
    }
    else if (sliderThatWasMoved == mOctaveDrySlider)
    {
        //[UserSliderCode_mOctaveDrySlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::OctaveDry, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mOctaveDrySlider]
    }
    else if (sliderThatWasMoved == mGlideTimeSlider)
    {
        //[UserSliderCode_mGlideTimeSlider] -- add your slider handling code here..
		Synth1.SetSetting( Synth::GlideTime, (float)sliderThatWasMoved->getValue() );
        //[/UserSliderCode_mGlideTimeSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void NewJucerComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == mOsc1TypeSelectBox)
    {
        //[UserComboBoxCode_mOsc1TypeSelectBox] -- add your combo box handling code here..
		Synth1.SetSetting( Synth::Osc1Type, (Synth::OscillatorType)comboBoxThatHasChanged->getSelectedId() );
        //[/UserComboBoxCode_mOsc1TypeSelectBox]
    }
    else if (comboBoxThatHasChanged == mOsc2TypeSelectBox)
    {
        //[UserComboBoxCode_mOsc2TypeSelectBox] -- add your combo box handling code here..
		Synth1.SetSetting( Synth::Osc2Type, (Synth::OscillatorType)comboBoxThatHasChanged->getSelectedId() );
        //[/UserComboBoxCode_mOsc2TypeSelectBox]
    }
    else if (comboBoxThatHasChanged == mOsc1SampleSelectBox)
    {
        //[UserComboBoxCode_mOsc1SampleSelectBox] -- add your combo box handling code here..
		int index = comboBoxThatHasChanged->getSelectedId() - 1;
		Synth1.SetSetting( Synth::Osc1WavetablePath, std::string( mSampleFilePaths[index].toUTF8() ) );
		Synth1.SetSetting( Synth::Osc1WavetableFreq, mSampleFileFrequencies[index] );
        //[/UserComboBoxCode_mOsc1SampleSelectBox]
    }
    else if (comboBoxThatHasChanged == mOsc2SampleSelectBox)
    {
        //[UserComboBoxCode_mOsc2SampleSelectBox] -- add your combo box handling code here..
		int index = comboBoxThatHasChanged->getSelectedId() - 1;
		Synth1.SetSetting( Synth::Osc2WavetablePath, std::string( mSampleFilePaths[index].toUTF8() ) );
		Synth1.SetSetting( Synth::Osc2WavetableFreq, mSampleFileFrequencies[index] );
        //[/UserComboBoxCode_mOsc2SampleSelectBox]
    }
    else if (comboBoxThatHasChanged == mArpPatternSelect1)
    {
        //[UserComboBoxCode_mArpPatternSelect1] -- add your combo box handling code here..
		updateArpPatternFromUI();
        //[/UserComboBoxCode_mArpPatternSelect1]
    }
    else if (comboBoxThatHasChanged == mArpPatternSelect2)
    {
        //[UserComboBoxCode_mArpPatternSelect2] -- add your combo box handling code here..
		updateArpPatternFromUI();
        //[/UserComboBoxCode_mArpPatternSelect2]
    }
    else if (comboBoxThatHasChanged == mArpPatternSelect3)
    {
        //[UserComboBoxCode_mArpPatternSelect3] -- add your combo box handling code here..
		updateArpPatternFromUI();
        //[/UserComboBoxCode_mArpPatternSelect3]
    }
    else if (comboBoxThatHasChanged == mArpPatternSelect4)
    {
        //[UserComboBoxCode_mArpPatternSelect4] -- add your combo box handling code here..
		updateArpPatternFromUI();
        //[/UserComboBoxCode_mArpPatternSelect4]
    }
    else if (comboBoxThatHasChanged == mFilter1ComboBox)
    {
        //[UserComboBoxCode_mFilter1ComboBox] -- add your combo box handling code here..
		int filter = Synth::Filter_First + comboBoxThatHasChanged->getSelectedId();
		Synth1.SetSetting( Synth::Filter1, filter );
        //[/UserComboBoxCode_mFilter1ComboBox]
    }
    else if (comboBoxThatHasChanged == mFilter2ComboBox)
    {
        //[UserComboBoxCode_mFilter2ComboBox] -- add your combo box handling code here..
		int filter = Synth::Filter_First + comboBoxThatHasChanged->getSelectedId();
		Synth1.SetSetting( Synth::Filter2, filter );
        //[/UserComboBoxCode_mFilter2ComboBox]
    }
    else if (comboBoxThatHasChanged == mFilter3ComboBox)
    {
        //[UserComboBoxCode_mFilter3ComboBox] -- add your combo box handling code here..
		int filter = Synth::Filter_First + comboBoxThatHasChanged->getSelectedId();
		Synth1.SetSetting( Synth::Filter3, filter );
        //[/UserComboBoxCode_mFilter3ComboBox]
    }
    else if (comboBoxThatHasChanged == mFilter4ComboBox)
    {
        //[UserComboBoxCode_mFilter4ComboBox] -- add your combo box handling code here..
		int filter = Synth::Filter_First + comboBoxThatHasChanged->getSelectedId();
		Synth1.SetSetting( Synth::Filter4, filter );
        //[/UserComboBoxCode_mFilter4ComboBox]
    }
    else if (comboBoxThatHasChanged == mDelayTimeStep1)
    {
        //[UserComboBoxCode_mDelayTimeStep1] -- add your combo box handling code here..
		Synth1.SetSetting( Synth::DelayStep1, (NoteStep)comboBoxThatHasChanged->getSelectedId() - 1 );
        //[/UserComboBoxCode_mDelayTimeStep1]
    }
    else if (comboBoxThatHasChanged == mDelayTimeStep2)
    {
        //[UserComboBoxCode_mDelayTimeStep2] -- add your combo box handling code here..
		Synth1.SetSetting( Synth::DelayStep2, (NoteStep)comboBoxThatHasChanged->getSelectedId() - 1 );
        //[/UserComboBoxCode_mDelayTimeStep2]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void NewJucerComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == mDelayEnabledButton)
    {
        //[UserButtonCode_mDelayEnabledButton] -- add your button handler code here..
		Synth1.SetSetting( Synth::DelayEnabled, buttonThatWasClicked->getToggleState() );
        //[/UserButtonCode_mDelayEnabledButton]
    }
    else if (buttonThatWasClicked == mModDelayEnabledButton)
    {
        //[UserButtonCode_mModDelayEnabledButton] -- add your button handler code here..
		Synth1.SetSetting( Synth::ModDelayEnabled, buttonThatWasClicked->getToggleState() );
        //[/UserButtonCode_mModDelayEnabledButton]
    }
    else if (buttonThatWasClicked == mArpEnabledButton)
    {
        //[UserButtonCode_mArpEnabledButton] -- add your button handler code here..
		Arp1.SetEnabled( buttonThatWasClicked->getToggleState() );
        //[/UserButtonCode_mArpEnabledButton]
    }
    else if (buttonThatWasClicked == mDistortionEnabledButton)
    {
        //[UserButtonCode_mDistortionEnabledButton] -- add your button handler code here..
		Synth1.SetSetting( Synth::DistortionEnabled, buttonThatWasClicked->getToggleState() );
        //[/UserButtonCode_mDistortionEnabledButton]
    }
    else if (buttonThatWasClicked == mLoadButton)
    {
        //[UserButtonCode_mLoadButton] -- add your button handler code here..
		// Don't send keyboard events to file kb component when entering file name
		mKeyboardComponent->setAlwaysRecieveKeyboardEvents(false);

		String filePath( getSynthSettingsFilePath(false) );

		mKeyboardComponent->setAlwaysRecieveKeyboardEvents(true);

        if ( filePath.length() > 0 )
        {
            Synth1.LoadSettings( filePath.toUTF8() );
			applySynthSettingsToUI();
        }
        //[/UserButtonCode_mLoadButton]
    }
    else if (buttonThatWasClicked == mSaveButton)
    {
        //[UserButtonCode_mSaveButton] -- add your button handler code here..
		// Don't send keyboard events to file kb component when entering file name
		mKeyboardComponent->setAlwaysRecieveKeyboardEvents(false);

		String filePath( getSynthSettingsFilePath(true) );

		mKeyboardComponent->setAlwaysRecieveKeyboardEvents(true);

        if ( filePath.length() > 0 )
        {
            Synth1.SaveSettings( filePath.toUTF8() );
        }
        //[/UserButtonCode_mSaveButton]
    }
    else if (buttonThatWasClicked == mOscillatorSyncEnabled)
    {
        //[UserButtonCode_mOscillatorSyncEnabled] -- add your button handler code here..
		Synth1.SetSetting( Synth::OscillatorSyncEnabled, buttonThatWasClicked->getToggleState() );
        //[/UserButtonCode_mOscillatorSyncEnabled]
    }
    else if (buttonThatWasClicked == mOctaveEnabledButton)
    {
        //[UserButtonCode_mOctaveEnabledButton] -- add your button handler code here..
		Synth1.SetSetting( Synth::OctaveEnabled, buttonThatWasClicked->getToggleState() );
        //[/UserButtonCode_mOctaveEnabledButton]
    }
    else if (buttonThatWasClicked == mMonoEnabledButton)
    {
        //[UserButtonCode_mMonoEnabledButton] -- add your button handler code here..
		Synth1.SetSetting( Synth::MonoEnabled, buttonThatWasClicked->getToggleState() );
        //[/UserButtonCode_mMonoEnabledButton]
    }
    else if (buttonThatWasClicked == mGlideEnabledButton)
    {
        //[UserButtonCode_mGlideEnabledButton] -- add your button handler code here..
		Synth1.SetSetting( Synth::GlideEnabled, buttonThatWasClicked->getToggleState() );
        //[/UserButtonCode_mGlideEnabledButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void NewJucerComponent::handleNoteOn (MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity)
{
	Arp1.NoteOn( midiNoteNumber, velocity );
}

void NewJucerComponent::handleNoteOff (MidiKeyboardState *source, int midiChannel, int midiNoteNumber)
{
	Arp1.NoteOff( midiNoteNumber );
}

void NewJucerComponent::changeListenerCallback (void *objectThatHasChanged)
{
	DirectoryContentsList *dirList = static_cast<DirectoryContentsList*>( objectThatHasChanged );

	//mSampleFilePaths.clear();  // do we need this?

	for (int i = 0; i < dirList->getNumFiles(); ++i)
	{
		File file = dirList->getFile( i );
		String filePath = file.getRelativePathFrom( File::getCurrentWorkingDirectory() );
		mSampleFilePaths.push_back( filePath );

		String fileName = file.getFileName();
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
			filePath == String( Synth1.GetSetting( Synth::Osc1WavetablePath ).toString().c_str() ) )
		{
			mOsc1SampleSelectBox->setSelectedItemIndex( i, true );
		}
		if ( 0 == mOsc2SampleSelectBox->getSelectedId() &&
			filePath == String( Synth1.GetSetting( Synth::Osc2WavetablePath ).toString().c_str() ) )
		{
			mOsc2SampleSelectBox->setSelectedItemIndex( i, true );
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

void NewJucerComponent::handleIncomingMidiMessage (MidiInput *source, const MidiMessage &message)
{
	if ( message.isNoteOn() ) {
		Arp1.NoteOn( message.getNoteNumber(), message.getVelocity() / 255.0f );
	}
	else if ( message.isNoteOff() ) {
		Arp1.NoteOff( message.getNoteNumber() );
	}
}

String NewJucerComponent::getSynthSettingsFilePath(bool save)
{
	WildcardFileFilter wildcardFilter(T("*.syn"), T("Synth settings files"));
	FileBrowserComponent::FileChooserMode mode = save ? FileBrowserComponent::saveFileMode : FileBrowserComponent::loadFileMode;
	File initialDir( File::getCurrentWorkingDirectory().getFullPathName() + String("/presets") );
	FileBrowserComponent browser(mode, initialDir, &wildcardFilter, 0);
	String title, instructions;

	if (save)
	{
		title = T("Save synth settings");
		instructions = T("Enter a file name to save.");
	}
	else
	{
		title = T("Load synth settings");
		instructions = T("Select a synth settings file to load.");
	}

	FileChooserDialogBox dialogBox(title, instructions, browser, true, Colour::greyLevel(1.0f));

	if (dialogBox.show())
	{
		File selectedFile = browser.getCurrentFile();
		return selectedFile.getFullPathName();
	}

	// user cancelled
	return String();
}

void NewJucerComponent::applySynthSettingsToUI()
{
	// Suppress change messages here since we are simply reading settings to update the UI
	mGlobalVolumeSlider->setValue( Synth1.GetSetting( Synth::GlobalVolume ), true );
	mGlobalTempoSlider->setValue( Synth1.GetSetting( Synth::TempoBPM ), true );

	mAttackSlider->setValue( Synth1.GetSetting( Synth::Attack ), true );
	mDecaySlider->setValue( Synth1.GetSetting( Synth::Decay ), true );
	mSustainSlider->setValue( Synth1.GetSetting( Synth::Sustain ), true );
	mReleaseSlider->setValue( Synth1.GetSetting( Synth::Release ), true );

	mOsc1TypeSelectBox->setSelectedItemIndex( Synth1.GetSetting( Synth::Osc1Type ).toInt() - 1, true );
	mOsc1VolumeSlider->setValue( Synth1.GetSetting( Synth::Osc1Volume ), true );
	mOsc1SemitoneSlider->setValue( Synth1.GetSetting( Synth::Osc1DetuneSemitones ).toInt(), true );
	mOsc1CentSlider->setValue( Synth1.GetSetting( Synth::Osc1DetuneCents ), true );
	mOsc1PulseWidthSlider->setValue( Synth1.GetSetting( Synth::Osc1PulseWidth ), true );

	mOsc2TypeSelectBox->setSelectedItemIndex( Synth1.GetSetting( Synth::Osc2Type ).toInt() - 1, true );
	mOsc2VolumeSlider->setValue( Synth1.GetSetting( Synth::Osc2Volume ), true );
	mOsc2SemitoneSlider->setValue( Synth1.GetSetting( Synth::Osc2DetuneSemitones ).toInt(), true );
	mOsc2CentSlider->setValue( Synth1.GetSetting( Synth::Osc2DetuneCents ), true );
	mOsc2PulseWidthSlider->setValue( Synth1.GetSetting( Synth::Osc2PulseWidth ), true );
	mOscillatorSyncEnabled->setToggleState(Synth1.GetSetting( Synth::OscillatorSyncEnabled ), true );

	mCutoffSlider->setValue(Synth1.GetSetting( Synth::Cutoff ), true );
	mCutoffLFOFreqSlider->setValue(Synth1.GetSetting( Synth::CutoffLFOFreq ), true );
	mCutoffLFORangeSlider->setValue(Synth1.GetSetting( Synth::CutoffLFORange ), true );
	mResonanceSlider->setValue(Synth1.GetSetting( Synth::Resonance ), true );
	mCutoffEnvelopeAmount->setValue(Synth1.GetSetting( Synth::FilterCutoffEnvelopeAmount ), true );
	mCutoffAttackSlider->setValue(Synth1.GetSetting( Synth::FilterCutoffAttack ), true );
	mCutoffDecaySlider->setValue(Synth1.GetSetting( Synth::FilterCutoffDecay ), true );
	mCutoffSustainSlider->setValue(Synth1.GetSetting( Synth::FilterCutoffSustain ), true );
	mCutoffReleaseSlider->setValue(Synth1.GetSetting( Synth::FilterCutoffRelease ), true );

	mDelayEnabledButton->setToggleState(Synth1.GetSetting( Synth::DelayEnabled ), true );
	mDelayBlendSlider->setValue(Synth1.GetSetting( Synth::DelayBlend ), true );
	mDelayTimeStep1->setSelectedItemIndex( Synth1.GetSetting( Synth::DelayStep1 ).toInt(), true );
	mDelayTimeSlider1->setValue(Synth1.GetSetting( Synth::DelaySecondsOffset1 ), true );
	mDelayFFSlider1->setValue(Synth1.GetSetting( Synth::DelayFeedForward1 ), true );
	mDelayFBSlider1->setValue(Synth1.GetSetting( Synth::DelayFeedBack1 ), true );
	mDelayTimeStep2->setSelectedItemIndex( Synth1.GetSetting( Synth::DelayStep2 ).toInt(), true );
	mDelayTimeSlider2->setValue(Synth1.GetSetting( Synth::DelaySecondsOffset2 ), true );
	mDelayFFSlider2->setValue(Synth1.GetSetting( Synth::DelayFeedForward2 ), true );
	mDelayFBSlider2->setValue(Synth1.GetSetting( Synth::DelayFeedBack2 ), true );

	mModDelayEnabledButton->setToggleState(Synth1.GetSetting( Synth::ModDelayEnabled ), true );
	mModDelayRateSlider->setValue(Synth1.GetSetting( Synth::ModDelayRate ), true );
	mModDelayMinSlider->setValue(Synth1.GetSetting( Synth::ModDelayMin ), true );
	mModDelayDepthSlider->setValue(Synth1.GetSetting( Synth::ModDelayDepth ), true );
	mModDelayBlendSlider->setValue(Synth1.GetSetting( Synth::ModDelayBlend ), true );
	mModDelayFFSlider->setValue(Synth1.GetSetting( Synth::ModDelayFF ), true );
	mModDelayFBSlider->setValue(Synth1.GetSetting( Synth::ModDelayFB ), true );

	mDistortionEnabledButton->setToggleState(Synth1.GetSetting( Synth::DistortionEnabled ), true );
	mDistortionValueSlider->setValue(Synth1.GetSetting( Synth::DistortionValue ), true );

	mOctaveHarmonicSlider->setValue( Synth1.GetSetting( Synth::OctaveHarmonic ), true );
	mOctaveSubharmonicSlider->setValue( Synth1.GetSetting( Synth::OctaveSubharmonic ), true );
	mOctaveDrySlider->setValue( Synth1.GetSetting( Synth::OctaveDry ), true );

	mArpEnabledButton->setToggleState(Arp1.IsEnabled(), true );
	mArpGateTimeSlider->setValue(Arp1.GetGateTime(), true );

	mFilter1ComboBox->setSelectedItemIndex( Synth1.GetSetting( Synth::Filter1 ).toInt() - 1, true );
	mFilter2ComboBox->setSelectedItemIndex( Synth1.GetSetting( Synth::Filter2 ).toInt() - 1, true );
	mFilter3ComboBox->setSelectedItemIndex( Synth1.GetSetting( Synth::Filter3 ).toInt() - 1, true );
	mFilter4ComboBox->setSelectedItemIndex( Synth1.GetSetting( Synth::Filter4 ).toInt() - 1, true );

	mMonoEnabledButton->setToggleState(Synth1.GetSetting( Synth::MonoEnabled ), true );
	mGlideEnabledButton->setToggleState(Synth1.GetSetting( Synth::GlideEnabled ), true );
	mGlideTimeSlider->setValue(Synth1.GetSetting( Synth::GlideTime ), true );

	// select wavetable file paths
	String osc1WavetablePath( Synth1.GetSetting( Synth::Osc1WavetablePath ).toString().c_str() );
	String osc2WavetablePath( Synth1.GetSetting( Synth::Osc2WavetablePath ).toString().c_str() );
	int index = 0;

	for ( std::vector<String>::iterator it = mSampleFilePaths.begin(); it != mSampleFilePaths.end(); ++it )
	{
		if ( *it == osc1WavetablePath )
		{
			mOsc1SampleSelectBox->setSelectedItemIndex( index, true );
		}
		if ( *it == osc2WavetablePath )
		{
			mOsc2SampleSelectBox->setSelectedItemIndex( index, true );
		}
		++index;
	}
}

void NewJucerComponent::applyArpSettingsToUI()
{
	mArpGateTimeSlider->setValue( Arp1.GetGateTime(), true );

	for ( size_t i = 0; i < mArpComboBoxes.size(); ++i )
	{
		mArpComboBoxes[i]->setSelectedItemIndex( Arp1.GetPatternStep(i) );
	}
}

void NewJucerComponent::updateArpPatternFromUI()
{
	std::vector<int> pattern;

	// Construct the pattern from the combo boxes
	for ( std::vector<ComboBox*>::iterator it = mArpComboBoxes.begin(); it != mArpComboBoxes.end(); ++it )
	{
		// First item in the box (id = 1) is empty note and should be ignored
		int id = (*it)->getSelectedId();
		if ( id > 1 ) pattern.push_back( id - 1 );
	}

	if ( pattern.size() != Arp1.GetPatternSize() )
	{
		Arp1.SetPatternSize( pattern.size() );
	}

	// Apply the pattern to the arpeggiator
	int index = 0;
	for ( std::vector<int>::iterator it = pattern.begin(); it != pattern.end(); ++it )
	{
		Arp1.SetPatternStep( index++, static_cast<NoteStep>( *it ) );
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="NewJucerComponent" componentName=""
                 parentClasses="public Component, public MidiKeyboardStateListener, public ChangeListener, public MidiInputCallback"
                 constructorParams="" variableInitialisers="" snapPixels="12"
                 snapActive="1" snapShown="1" overlayOpacity="0.330000013" fixedSize="0"
                 initialWidth="1000" initialHeight="700">
  <BACKGROUND backgroundColour="ffffffff">
    <ROUNDRECT pos="12 8 576 52" cornerSize="10" fill="solid: ffcaf7f7" hasStroke="0"/>
    <ROUNDRECT pos="8 68 736 112" cornerSize="10" fill="solid: ffcaf7f7" hasStroke="0"/>
    <ROUNDRECT pos="8 188 520 100" cornerSize="10" fill="solid: ffcaf7f7" hasStroke="0"/>
    <ROUNDRECT pos="12 296 768 64" cornerSize="10" fill="solid: ffcaf7f7" hasStroke="0"/>
    <ROUNDRECT pos="12 368 552 64" cornerSize="10" fill="solid: ffcaf7f7" hasStroke="0"/>
    <ROUNDRECT pos="12 440 744 64" cornerSize="10" fill="solid: ffcaf7f7" hasStroke="0"/>
    <ROUNDRECT pos="596 8 232 52" cornerSize="10" fill="solid: ffcaf7f7" hasStroke="0"/>
    <ROUNDRECT pos="536 188 208 52" cornerSize="10" fill="solid: ffcaf7f7" hasStroke="0"/>
    <ROUNDRECT pos="572 368 316 64" cornerSize="10" fill="solid: ffcaf7f7" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="9416ef8f3b55c848" memberName="mAttackSlider"
          virtualName="" explicitFocusOrder="0" pos="162 30 70 24" min="0.001"
          max="10" int="0.001" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="77c00d02dd1271e0" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="162 11 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="60e0a58afb17e5da" memberName="mDecaySlider"
          virtualName="" explicitFocusOrder="0" pos="241 30 70 24" min="0.001"
          max="10" int="0.001" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="80204b02b336ea6e" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="241 11 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="263488b8b76854cd" memberName="mSustainSlider"
          virtualName="" explicitFocusOrder="0" pos="318 30 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="7f6e047f044fbda2" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="318 11 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="13aac8cc66f2be0f" memberName="mReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="397 30 70 24" min="0.001"
          max="10" int="0.001" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="a2c1005bf3bae08d" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="397 11 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="ea054149681ec753" memberName="mOsc1VolumeSlider"
          virtualName="" explicitFocusOrder="0" pos="246 91 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="f5fdeafaa8c79e40" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="246 73 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="d8e7fc54db72c2fe" memberName="mOsc1SemitoneSlider"
          virtualName="" explicitFocusOrder="0" pos="330 91 70 24" min="-24"
          max="24" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="e4e9301bd3aeeb7c" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="330 73 86 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Semitones" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="1e30868bb04006f1" memberName="mOsc1CentSlider"
          virtualName="" explicitFocusOrder="0" pos="414 91 70 24" min="-100"
          max="100" int="0.1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="5f40a71d3954c642" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="414 73 78 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Cents" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="4a8f8e5d9f2b9ac3" memberName="mOsc1PulseWidthSlider"
          virtualName="" explicitFocusOrder="0" pos="486 91 70 24" min="0"
          max="0.99" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="b7fb95b7166eb97a" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="486 73 87 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pulse Width" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="b3e1a80668efcbc4" memberName="mOsc1TypeSelectBox"
            virtualName="" explicitFocusOrder="0" pos="126 91 100 24" editable="0"
            layout="33" items="Sine&#10;Pulse&#10;Saw&#10;Triangle&#10;Noise&#10;Wavetable&#10;One Shot&#10;Blep Saw&#10;Blep Square"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="bb6068fdc6459d8a" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="43 91 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Osc 1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="e812a0774ee536bf" memberName="mOsc2VolumeSlider"
          virtualName="" explicitFocusOrder="0" pos="246 136 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="5edace9b96c10e67" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="246 118 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="eae81887bec6a1f4" memberName="mOsc2SemitoneSlider"
          virtualName="" explicitFocusOrder="0" pos="330 136 70 24" min="-24"
          max="24" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="bc0b587795611f5e" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="330 118 86 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Semitones" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="69058da8e043814e" memberName="mOsc2CentSlider"
          virtualName="" explicitFocusOrder="0" pos="414 136 70 24" min="-100"
          max="100" int="0.1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="f164884be8081aad" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="414 118 78 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Cents" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="bbe8c5d9fed07b36" memberName="mOsc2PulseWidthSlider"
          virtualName="" explicitFocusOrder="0" pos="486 136 70 24" min="0"
          max="0.99" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="aef418d011e3df74" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="486 118 87 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pulse Width" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="3b66022eca86e8c8" memberName="mOsc2TypeSelectBox"
            virtualName="" explicitFocusOrder="0" pos="126 135 100 24" editable="0"
            layout="33" items="Sine&#10;Pulse&#10;Saw&#10;Triangle&#10;Noise&#10;Wavetable&#10;One Shot&#10;Blep Saw&#10;Blep Square"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="7470022a4828e72" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="43 135 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Osc 2" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="d48eb8d786ca9f86" memberName="mCutoffSlider"
          virtualName="" explicitFocusOrder="0" pos="123 210 70 24" min="10"
          max="11025" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="b383e1ed761c906a" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="123 192 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Cutoff" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="21a98852ca204b72" memberName="mCutoffLFOFreqSlider"
          virtualName="" explicitFocusOrder="0" pos="202 210 70 24" min="0"
          max="10" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="97c100b2ba9f8971" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="202 192 86 24" edTextCol="ff000000"
         edBkgCol="0" labelText="LFO Freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="58385659fdd14de2" memberName="mCutoffLFORangeSlider"
          virtualName="" explicitFocusOrder="0" pos="275 210 70 24" min="0"
          max="5000" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="ff566e7bcfd43917" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="275 192 78 24" edTextCol="ff000000"
         edBkgCol="0" labelText="LFO Range" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="4481e9e5eaec43ac" memberName="mResonanceSlider"
          virtualName="" explicitFocusOrder="0" pos="351 210 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="3dd10a076b62dc4f" memberName="label18" virtualName=""
         explicitFocusOrder="0" pos="351 192 87 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Resonance" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="45204ebf840cf1c5" memberName="mModDelayMinSlider"
          virtualName="" explicitFocusOrder="0" pos="125 396 70 24" min="0.001"
          max="0.5" int="0.001" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="d72aa77bb816b98e" memberName="mModDelayDepthSlider"
          virtualName="" explicitFocusOrder="0" pos="198 396 70 24" min="0.001"
          max="0.5" int="0.001" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="2f323057d814a101" memberName="mModDelayRateSlider"
          virtualName="" explicitFocusOrder="0" pos="270 396 70 24" min="0.01"
          max="5" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="ebb6776f5b4f05a3" memberName="mModDelayFFSlider"
          virtualName="" explicitFocusOrder="0" pos="342 396 70 24" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="799021d7defab22" memberName="mModDelayFBSlider"
          virtualName="" explicitFocusOrder="0" pos="414 396 70 24" min="-1"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="3b171c77c17fae85" memberName="label22" virtualName=""
         explicitFocusOrder="0" pos="125 372 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Min Time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="27129d1c2b74f8a4" memberName="mModDelayBlendSlider"
          virtualName="" explicitFocusOrder="0" pos="486 396 70 24" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="f73ca13081ffe3db" memberName="label23" virtualName=""
         explicitFocusOrder="0" pos="198 372 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="2f6184a4cd2108fa" memberName="label24" virtualName=""
         explicitFocusOrder="0" pos="270 372 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="e9766ac890ce5d06" memberName="label25" virtualName=""
         explicitFocusOrder="0" pos="342 372 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Feed Fwd" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="316c753b9cd22000" memberName="label26" virtualName=""
         explicitFocusOrder="0" pos="414 372 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Feedback" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="5895c4deb620b1a3" memberName="label27" virtualName=""
         explicitFocusOrder="0" pos="486 372 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Blend" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="7bcac0ef60c590d6" memberName="mOsc1SampleSelectBox"
            virtualName="" explicitFocusOrder="0" pos="576 89 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="7feb7003fa2d0a1c" memberName="mOsc2SampleSelectBox"
            virtualName="" explicitFocusOrder="0" pos="576 131 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="120bc6e9db2c40b6" memberName="label19" virtualName=""
         explicitFocusOrder="0" pos="42 26 108 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Envelope" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f7d6364b1d50fbcd" memberName="label28" virtualName=""
         explicitFocusOrder="0" pos="42 228 84 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Filter" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="e9b438d9df658094" memberName="label29" virtualName=""
         explicitFocusOrder="0" pos="42 322 84 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Delay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="ff18b6386b8ed928" memberName="label30" virtualName=""
         explicitFocusOrder="0" pos="42 389 66 36" edTextCol="ff000000"
         edBkgCol="0" labelText="Mod&#10;Delay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="b6b8b4887bd23200" memberName="label31" virtualName=""
         explicitFocusOrder="0" pos="42 468 66 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Arp" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="b808463a1a3674d2" memberName="mArpPatternSelect1"
            virtualName="" explicitFocusOrder="0" pos="125 468 50 24" editable="0"
            layout="33" items="0&#10;1&#10;1/2&#10;1/3&#10;1/4&#10;1/6&#10;1/8&#10;1/16&#10;1/32&#10;-1&#10;-1/2&#10;-1/3&#10;-1/4&#10;-1/6&#10;-1/8&#10;-1/16&#10;-1/32"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="cf00f90057831711" memberName="mArpPatternSelect2"
            virtualName="" explicitFocusOrder="0" pos="185 468 50 24" editable="0"
            layout="33" items="0&#10;1&#10;1/2&#10;1/3&#10;1/4&#10;1/6&#10;1/8&#10;1/16&#10;1/32&#10;-1&#10;-1/2&#10;-1/3&#10;-1/4&#10;-1/6&#10;-1/8&#10;-1/16&#10;-1/32"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="1dc9b5495a0cac60" memberName="mArpPatternSelect3"
            virtualName="" explicitFocusOrder="0" pos="245 468 50 24" editable="0"
            layout="33" items="0&#10;1&#10;1/2&#10;1/3&#10;1/4&#10;1/6&#10;1/8&#10;1/16&#10;1/32&#10;-1&#10;-1/2&#10;-1/3&#10;-1/4&#10;-1/6&#10;-1/8&#10;-1/16&#10;-1/32"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="fc497fbcaf926bc6" memberName="mArpPatternSelect4"
            virtualName="" explicitFocusOrder="0" pos="305 468 50 24" editable="0"
            layout="33" items="0&#10;1&#10;1/2&#10;1/3&#10;1/4&#10;1/6&#10;1/8&#10;1/16&#10;1/32&#10;-1&#10;-1/2&#10;-1/3&#10;-1/4&#10;-1/6&#10;-1/8&#10;-1/16&#10;-1/32"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="bb9d89ba5567e849" memberName="label32" virtualName=""
         explicitFocusOrder="0" pos="564 208 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Distortion" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a0094a061f68c931" memberName="label33" virtualName=""
         explicitFocusOrder="0" pos="672 191 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Level" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="98ce98cd629369e0" memberName="mDistortionValueSlider"
          virtualName="" explicitFocusOrder="0" pos="672 208 70 24" min="1"
          max="20" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="new toggle button" id="d73cfa9c5e6f6fee" memberName="mDelayEnabledButton"
                virtualName="" explicitFocusOrder="0" pos="18 322 19 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="bb9835660b073287" memberName="mModDelayEnabledButton"
                virtualName="" explicitFocusOrder="0" pos="18 396 19 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="c8c2e7d1e42aea1a" memberName="mArpEnabledButton"
                virtualName="" explicitFocusOrder="0" pos="18 468 19 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="6e6545da5291aaf4" memberName="mDistortionEnabledButton"
                virtualName="" explicitFocusOrder="0" pos="544 208 19 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="d325227570cdd738" memberName="label34" virtualName=""
         explicitFocusOrder="0" pos="386 451 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gate Time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="98c921f12380d151" memberName="mArpGateTimeSlider"
          virtualName="" explicitFocusOrder="0" pos="386 471 70 24" min="0"
          max="0.99" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <GENERICCOMPONENT name="new component" id="c9e390bb36981e71" memberName="mKeyboardComponent"
                    virtualName="" explicitFocusOrder="0" pos="24 528 936 144" class="MidiKeyboardComponent"
                    params="mMidiKeyboardState, MidiKeyboardComponent::horizontalKeyboard"/>
  <SLIDER name="new slider" id="ff32319428c3189f" memberName="mGlobalVolumeSlider"
          virtualName="" explicitFocusOrder="0" pos="609 31 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="e7a93b7985d24ba4" memberName="label35" virtualName=""
         explicitFocusOrder="0" pos="608 9 78 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Load Button" id="9d505562fb0d6a2c" memberName="mLoadButton"
              virtualName="" explicitFocusOrder="0" pos="869 12 80 24" buttonText="Load..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Save Button" id="7af6caf7dc72a4a0" memberName="mSaveButton"
              virtualName="" explicitFocusOrder="0" pos="869 48 80 24" buttonText="Save..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="Filter 1 Combo Box" id="b5a2aeba7340393b" memberName="mFilter1ComboBox"
            virtualName="" explicitFocusOrder="0" pos="821 204 150 24" editable="0"
            layout="33" items="Delay&#10;Mod Delay&#10;Distortion&#10;Octave" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Filter 2 Combo Box" id="3933d42bc695b862" memberName="mFilter2ComboBox"
            virtualName="" explicitFocusOrder="0" pos="821 240 150 24" editable="0"
            layout="33" items="Delay&#10;Mod Delay&#10;Distortion&#10;Octave" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Filter 3 Combo Box" id="90f43e80ff97f89a" memberName="mFilter3ComboBox"
            virtualName="" explicitFocusOrder="0" pos="821 276 150 24" editable="0"
            layout="33" items="Delay&#10;Mod Delay&#10;Distortion&#10;Octave" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Filter 4 Combo Box" id="f0b33b734894df06" memberName="mFilter4ComboBox"
            virtualName="" explicitFocusOrder="0" pos="821 312 150 24" editable="0"
            layout="33" items="Delay&#10;Mod Delay&#10;Distortion&#10;Octave" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="db7b2b35a3fdc5c9" memberName="label36" virtualName=""
         explicitFocusOrder="0" pos="125 307 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Blend" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="84ff1837d9eea205" memberName="mDelayBlendSlider"
          virtualName="" explicitFocusOrder="0" pos="125 326 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="b658fcaa79de7220" memberName="label37" virtualName=""
         explicitFocusOrder="0" pos="260 307 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="b9fc3354cbb24958" memberName="mDelayTimeSlider1"
          virtualName="" explicitFocusOrder="0" pos="260 326 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="9f1c8da95cfc10ca" memberName="label38" virtualName=""
         explicitFocusOrder="0" pos="330 307 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Feed Fwd" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="53cd2b915711f2b3" memberName="mDelayFFSlider1"
          virtualName="" explicitFocusOrder="0" pos="330 326 70 24" min="0.01"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="9d2489297df5ec36" memberName="label39" virtualName=""
         explicitFocusOrder="0" pos="402 307 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Feedback" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="9ee5e3bd10690763" memberName="mDelayFBSlider1"
          virtualName="" explicitFocusOrder="0" pos="402 326 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="8257fcce13fb042d" memberName="label20" virtualName=""
         explicitFocusOrder="0" pos="551 307 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Time 2" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="1fb659063c89fa87" memberName="mDelayTimeSlider2"
          virtualName="" explicitFocusOrder="0" pos="551 326 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="4d9537ef30355586" memberName="label21" virtualName=""
         explicitFocusOrder="0" pos="621 307 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Feed Fwd 2" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="4094292770e7de44" memberName="mDelayFFSlider2"
          virtualName="" explicitFocusOrder="0" pos="621 326 70 24" min="0.01"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="3d9ee834354d081a" memberName="label40" virtualName=""
         explicitFocusOrder="0" pos="693 307 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="FeedBack 2" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="ed85db0322b6035c" memberName="mDelayFBSlider2"
          virtualName="" explicitFocusOrder="0" pos="693 326 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="218ac4c33780a435" memberName="mClippingLabel"
         virtualName="" explicitFocusOrder="0" pos="948 96 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="e85775e35174b595" memberName="mDelayTimeStep1"
            virtualName="" explicitFocusOrder="0" pos="201 325 50 24" editable="0"
            layout="33" items="0&#10;1&#10;1/2&#10;1/3&#10;1/4&#10;1/6&#10;1/8&#10;1/16&#10;1/32" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="2e0b6ed44995aa5f" memberName="mDelayTimeStep2"
            virtualName="" explicitFocusOrder="0" pos="493 325 50 24" editable="0"
            layout="33" items="0&#10;1&#10;1/2&#10;1/3&#10;1/4&#10;1/6&#10;1/8&#10;1/16&#10;1/32" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="new slider" id="15e52b03105a9ad" memberName="mGlobalTempoSlider"
          virtualName="" explicitFocusOrder="0" pos="694 31 70 24" min="80"
          max="240" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="2b16e85b4ff7b015" memberName="label41" virtualName=""
         explicitFocusOrder="0" pos="693 11 65 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Tempo" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="4768f896d978fcb8" memberName="mOscillatorSyncEnabled"
                virtualName="" explicitFocusOrder="0" pos="131 157 19 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="9dc4b2fa6f2ee310" memberName="label42" virtualName=""
         explicitFocusOrder="0" pos="152 156 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sync" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="92887f18e3eb19a8" memberName="mCutoffAttackSlider"
          virtualName="" explicitFocusOrder="0" pos="203 254 70 24" min="0.001"
          max="10" int="0.001" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="57e68e3174f303ca" memberName="label43" virtualName=""
         explicitFocusOrder="0" pos="201 236 86 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="20e3812be5308c47" memberName="mCutoffDecaySlider"
          virtualName="" explicitFocusOrder="0" pos="275 253 70 24" min="0.001"
          max="10" int="0.001" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="2a036906253a720" memberName="label44" virtualName=""
         explicitFocusOrder="0" pos="275 235 52 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="37144c7783504c33" memberName="mCutoffReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="427 254 70 24" min="0.001"
          max="10" int="0.001" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="8bdeefc75c49c442" memberName="label45" virtualName=""
         explicitFocusOrder="0" pos="427 236 61 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="bd1a4c49cf91da53" memberName="mCutoffSustainSlider"
          virtualName="" explicitFocusOrder="0" pos="349 252 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="31bc83fbf92be28a" memberName="label46" virtualName=""
         explicitFocusOrder="0" pos="349 234 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="9176692a3f0dd4a0" memberName="mCutoffEnvelopeAmount"
          virtualName="" explicitFocusOrder="0" pos="123 253 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="173ee86aff7697d2" memberName="label47" virtualName=""
         explicitFocusOrder="0" pos="123 235 69 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Env Amt" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="eea14fbd45b4cf96" memberName="label48" virtualName=""
         explicitFocusOrder="0" pos="600 388 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Octave" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="d8d9278fc5ad86ad" memberName="label49" virtualName=""
         explicitFocusOrder="0" pos="672 372 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Harmonic" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="5cc2f8b611d59394" memberName="mOctaveHarmonicSlider"
          virtualName="" explicitFocusOrder="0" pos="673 394 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="new toggle button" id="2b4207592a8b6fa0" memberName="mOctaveEnabledButton"
                virtualName="" explicitFocusOrder="0" pos="580 388 19 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="ba11e8c00aee71d8" memberName="label50" virtualName=""
         explicitFocusOrder="0" pos="744 372 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Subharmonic" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="8da46271c1ea36a5" memberName="mOctaveSubharmonicSlider"
          virtualName="" explicitFocusOrder="0" pos="745 394 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="f358e03140560909" memberName="label51" virtualName=""
         explicitFocusOrder="0" pos="828 372 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Dry" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="7a21e5a6ad5e4ff9" memberName="mOctaveDrySlider"
          virtualName="" explicitFocusOrder="0" pos="817 394 70 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="f386d7850dc41b06" memberName="label52" virtualName=""
         explicitFocusOrder="0" pos="504 468 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Mono" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="c81b6b730940dee7" memberName="mMonoEnabledButton"
                virtualName="" explicitFocusOrder="0" pos="484 468 19 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="3ce97526846b68a9" memberName="label53" virtualName=""
         explicitFocusOrder="0" pos="592 467 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Glide" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="a004bddb920d879e" memberName="mGlideEnabledButton"
                virtualName="" explicitFocusOrder="0" pos="572 467 19 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="f62e4bdbe4afefd9" memberName="label54" virtualName=""
         explicitFocusOrder="0" pos="645 453 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Glide Time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="b48113ff7544a0d0" memberName="mGlideTimeSlider"
          virtualName="" explicitFocusOrder="0" pos="644 475 70 24" min="0.01"
          max="0.5" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
