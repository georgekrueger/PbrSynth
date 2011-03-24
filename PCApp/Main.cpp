#include <iostream>

#include "UI_Main.h"
#include "Synth.h"
#include "Arpeggiator.h"
#include "portaudio.h"
#include "effects.h"
#include "wavfile.h"

static const int FRAMES_PER_BUFFER = 64;

Synth Synth1;
Arpeggiator Arp1(&Synth1);

FILE *outfile = 0;
long bytesWritten = 0;
bool doneWriting = false;

// Portaudio callbacks
static int PortAudioCallback( const void *inputBuffer, void *outputBuffer,
                            unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo* timeInfo,
                            PaStreamCallbackFlags statusFlags,
                            void *userData );

static void StreamFinished( void* userData );

#if defined (_WIN32)
int __stdcall WinMain (int, int, const char*, int)
#else
int main(int argc, char *argv[])
#endif
{
	// Initialize Synth
	Synth1.SetSampleRate( SAMPLE_RATE );

	// Initialize Portaudio
	PaStreamParameters outputParameters;
    PaStream *stream;
	PaError err = Pa_Initialize();
    assert( err == paNoError );
	
	// see which devices are available
	PaDeviceIndex NumDevices = Pa_GetDeviceCount();
	for ( PaDeviceIndex i = 0; i<NumDevices; i++ ) {
		const PaDeviceInfo* DeviceInfo = Pa_GetDeviceInfo( i );
		printf("Device %d: %s\n", i, DeviceInfo->name );
	}

	outputParameters.device = 2;
	//outputParameters.device = Pa_GetDefaultOutputDevice(); /* default output device */
    outputParameters.channelCount = 2;       /* stereo output */
    outputParameters.sampleFormat = paFloat32; /* 32 bit floating point output */
    outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

	err = Pa_OpenStream(
              &stream,
              NULL, /* no input */
              &outputParameters,
              SAMPLE_RATE,
              FRAMES_PER_BUFFER,
              0,
              PortAudioCallback,
              NULL );
	assert( err == paNoError );

	err = Pa_SetStreamFinishedCallback( stream, &StreamFinished );
	assert( err == paNoError );

	err = Pa_StartStream( stream );
	assert( err == paNoError );

	// Initialize UI
#if defined( _WIN32)
	JUCE_NAMESPACE::String commandLineString (JUCE_NAMESPACE::PlatformUtilities::getCurrentCommandLineParams());
    int JuceAppMainReturn = JUCE_NAMESPACE::JUCEApplication::main (commandLineString, new JUCEHelloWorldApplication());
#else
    int JuceAppMainReturn = JUCE_NAMESPACE::JUCEApplication::main (argc, argv, new JUCEHelloWorldApplication());
#endif

	// Cleanup Portaudio
	err = Pa_StopStream( stream );
    assert( err == paNoError );

    err = Pa_CloseStream( stream );
    assert( err == paNoError );

    Pa_Terminate();

	return JuceAppMainReturn;
}

float writeBuf[FRAMES_PER_BUFFER*2];
#define FILE_GAIN_FACTOR (10.0f);

static int PortAudioCallback( const void *inputBuffer, void *outputBuffer,
                            unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo* timeInfo,
                            PaStreamCallbackFlags statusFlags,
                            void *userData )
{
	Arp1.Tick();
	Synth1.Generate( (float*)outputBuffer, framesPerBuffer );
	
#if 0
	if (0 == outfile) {
		outfile = fopen("out.wav", "w");
		WriteWavHeader(outfile,   );
	}
	
	// Record output for 20 seconds
	if (bytesWritten < SAMPLE_RATE * 8 * 20) {
		float *pf = writeBuf;
		float *pd = (float*)outputBuffer;
		unsigned long samples = framesPerBuffer * 2;
		for (int i = 0; i < samples; ++i) {
			*pf++ = *pd++ * FILE_GAIN_FACTOR;
		}
		fwrite(writeBuf, framesPerBuffer * 8, 1, outfile);
		bytesWritten += framesPerBuffer * 8;
	}
	else if (!doneWriting) {
		WriteWavDataSize(outfile, bytesWritten);
		fclose(outfile);
		doneWriting = true;
		std::cout << "Done writing output" << std::endl;
	}
#endif
	
	return paContinue;
}

/*
 * This routine is called by portaudio when playback is done.
 */
static void StreamFinished( void* userData )
{
}
