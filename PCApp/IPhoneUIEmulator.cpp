/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  16 Mar 2011 9:50:45 pm

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
//[/Headers]

#include "IPhoneUIEmulator.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
IPhoneUIEmulator::IPhoneUIEmulator ()
    : textButton (0),
      slider (0),
      slider2 (0),
      textButton2 (0),
      textButton3 (0)
{
    addAndMakeVisible (textButton = new TextButton (T("new button")));
    textButton->addButtonListener (this);

    addAndMakeVisible (slider = new Slider (T("new slider")));
    slider->setRange (0, 10, 0);
    slider->setSliderStyle (Slider::LinearVertical);
    slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider->addListener (this);

    addAndMakeVisible (slider2 = new Slider (T("new slider")));
    slider2->setRange (0, 10, 0);
    slider2->setSliderStyle (Slider::LinearVertical);
    slider2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider2->addListener (this);

    addAndMakeVisible (textButton2 = new TextButton (T("new button")));
    textButton2->addButtonListener (this);

    addAndMakeVisible (textButton3 = new TextButton (T("new button")));
    textButton3->addButtonListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (480, 320);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

IPhoneUIEmulator::~IPhoneUIEmulator()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (textButton);
    deleteAndZero (slider);
    deleteAndZero (slider2);
    deleteAndZero (textButton2);
    deleteAndZero (textButton3);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void IPhoneUIEmulator::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void IPhoneUIEmulator::resized()
{
    textButton->setBounds (112, 16, 64, 48);
    slider->setBounds (16, 8, 24, 184);
    slider2->setBounds (48, 8, 24, 184);
    textButton2->setBounds (184, 16, 64, 48);
    textButton3->setBounds (256, 16, 64, 48);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void IPhoneUIEmulator::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == textButton3)
    {
        //[UserButtonCode_textButton3] -- add your button handler code here..
        //[/UserButtonCode_textButton3]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void IPhoneUIEmulator::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        //[/UserSliderCode_slider2]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="IPhoneUIEmulator" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="480" initialHeight="320">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="new button" id="b1cb11797ddf28f8" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="112 16 64 48" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="36177e1f77d8b43e" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="16 8 24 184" min="0" max="10" int="0"
          style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="3ad9e44ed29f26c3" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="48 8 24 184" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="new button" id="296e25053849ba6f" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="184 16 64 48" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="55faf333d41f633d" memberName="textButton3"
              virtualName="" explicitFocusOrder="0" pos="256 16 64 48" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
