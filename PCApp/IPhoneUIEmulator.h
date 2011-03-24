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

#ifndef __JUCER_HEADER_IPHONEUIEMULATOR_IPHONEUIEMULATOR_EE072C0B__
#define __JUCER_HEADER_IPHONEUIEMULATOR_IPHONEUIEMULATOR_EE072C0B__

//[Headers]     -- You can add your own extra header files here --
#include "juce_Include.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class IPhoneUIEmulator  : public Component,
                          public ButtonListener,
                          public SliderListener
{
public:
    //==============================================================================
    IPhoneUIEmulator ();
    ~IPhoneUIEmulator();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    TextButton* textButton;
    Slider* slider;
    Slider* slider2;
    TextButton* textButton2;
    TextButton* textButton3;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    IPhoneUIEmulator (const IPhoneUIEmulator&);
    const IPhoneUIEmulator& operator= (const IPhoneUIEmulator&);
};


#endif   // __JUCER_HEADER_IPHONEUIEMULATOR_IPHONEUIEMULATOR_EE072C0B__
