/*
  ==============================================================================

   Demonstration "Hello World" application in JUCE
   Copyright 2008 by Julian Storer.

  ==============================================================================
*/

#include "juce_Include.h"

class HelloWorldWindow;
class IPhoneUIEmulatorWindow;

//==============================================================================
/** This is the application object that is started up when Juce starts. It handles
    the initialisation and shutdown of the whole application.
*/
class JUCEHelloWorldApplication : public JUCEApplication
{
    /* Important! NEVER embed objects directly inside your JUCEApplication class! Use
       ONLY pointers to objects, which you should create during the initialise() method
       (NOT in the constructor!) and delete in the shutdown() method (NOT in the
       destructor!)

       This is because the application object gets created before Juce has been properly
       initialised, so any embedded objects would also get constructed too soon.
   */
    HelloWorldWindow* helloWorldWindow;
	IPhoneUIEmulatorWindow* emulatorWindow;

public:
	juce_UseDebuggingNewOperator

    //==============================================================================
    JUCEHelloWorldApplication();

    ~JUCEHelloWorldApplication();

    //==============================================================================
    void initialise (const String& commandLine);

    void shutdown();

    //==============================================================================
    const String getApplicationName();

    const String getApplicationVersion();

    bool moreThanOneInstanceAllowed();

    void anotherInstanceStarted (const String& commandLine);
};
