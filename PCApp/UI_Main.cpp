/*
  ==============================================================================

   Demonstration "Hello World" application in JUCE
   Copyright 2008 by Julian Storer.

  ==============================================================================
*/

#include "juce_Include.h"
#include "UI_Main.h"
#include "UI_SynthComponent.h"
#include "NewJucerComponent.h"
#include "IPhoneUIEmulator.h"

//==============================================================================
/** 
    This is the top-level window that we'll pop up. Inside it, we'll create and
    show a component from the MainComponent.cpp file (you can open this file using
    the Jucer to edit it).
*/
class HelloWorldWindow  : public DocumentWindow
{
public:
	juce_UseDebuggingNewOperator

    //==============================================================================
    HelloWorldWindow() 
        : DocumentWindow (T("PBR Synth"),
                          Colours::lightgrey, 
                          DocumentWindow::allButtons,
                          true)
    {
        // Create an instance of our main content component, and add it 
        // to our window.

        //MainComponent* const contentComponent = new MainComponent();
		NewJucerComponent* const contentComponent = new NewJucerComponent();

        setContentComponent (contentComponent, true, true);

        centreWithSize (getWidth(), getHeight());

        setVisible (true);
    }

    ~HelloWorldWindow()
    {
        // (the content component will be deleted automatically, so no need to do it here)
    }

    //==============================================================================
    void closeButtonPressed()
    {
        // When the user presses the close button, we'll tell the app to quit. This 
        // window will be deleted by our HelloWorldApplication::shutdown() method
        // 
        JUCEApplication::quit();
    }
};

class IPhoneUIEmulatorWindow  : public DocumentWindow
{
public:
	juce_UseDebuggingNewOperator
	
	//==============================================================================
	IPhoneUIEmulatorWindow() 
	: DocumentWindow (T("Emulator"),
					  Colours::lightgrey, 
					  DocumentWindow::allButtons,
					  true)
	{
		// Create an instance of our main content component, and add it 
		// to our window.
		
		//MainComponent* const contentComponent = new MainComponent();
		IPhoneUIEmulator* const contentComponent = new IPhoneUIEmulator();
		
		setContentComponent (contentComponent, true, true);
		
		centreWithSize (getWidth(), getHeight());
		
		setVisible (true);
	}
	
	~IPhoneUIEmulatorWindow()
	{
		// (the content component will be deleted automatically, so no need to do it here)
	}
	
	//==============================================================================
	void closeButtonPressed()
	{
	}
};

JUCEHelloWorldApplication::JUCEHelloWorldApplication()
    : helloWorldWindow (0)
{
    // NEVER do anything in here that could involve any Juce function being called
    // - leave all your startup tasks until the initialise() method.
}

JUCEHelloWorldApplication::~JUCEHelloWorldApplication()
{
    // Your shutdown() method should already have done all the things necessary to
    // clean up this app object, so you should never need to put anything in
    // the destructor.

    // Making any Juce calls in here could be very dangerous...
}

//==============================================================================
void JUCEHelloWorldApplication::initialise (const String& commandLine)
{
    // just create the main window...
    helloWorldWindow = new HelloWorldWindow();
	emulatorWindow = new IPhoneUIEmulatorWindow();

    /*  ..and now return, which will fall into to the main event
        dispatch loop, and this will run until something calls
        JUCEAppliction::quit().

        In this case, JUCEAppliction::quit() will be called by the
        hello world window being clicked.
    */
}

void JUCEHelloWorldApplication::shutdown()
{
    // clear up..

    if (helloWorldWindow != 0)
        delete helloWorldWindow;
	
	delete emulatorWindow;
}

//==============================================================================
const String JUCEHelloWorldApplication::getApplicationName()
{
    return T("Hello World for JUCE");
}

const String JUCEHelloWorldApplication::getApplicationVersion()
{
    return T("1.0");
}

bool JUCEHelloWorldApplication::moreThanOneInstanceAllowed()
{
    return true;
}

void JUCEHelloWorldApplication::anotherInstanceStarted (const String& commandLine)
{
}
