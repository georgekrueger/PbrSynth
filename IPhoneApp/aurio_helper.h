/*
 
 File: aurio_helper.c
 
 Abstract: Helper functions for manipulating the remote i/o audio unit
 
 */

#if !defined(__rio_helper_h__)
#define __rio_helper_h__

#include <AudioToolbox/AudioToolbox.h>

#define kNumDrawBuffers 12
#define kDefaultDrawSamples 512
#define kMinDrawSamples 64
#define kMaxDrawSamples 2048

extern int drawBufferIdx;
extern int drawBufferLen;
extern int drawBufferLen_alloced;
extern SInt8 *drawBuffers[];
extern SInt32 convertedFFTData[];


void rioInterruptionListener(void	*inUserData, UInt32	inInterruption);
int SetupRemoteIO (AudioUnit& inRemoteIOUnit, AURenderCallbackStruct inRenderProcm, AudioStreamBasicDescription& outFormat);
void SilenceData(AudioBufferList *inData);

class DCRejectionFilter
	{
	public:
		DCRejectionFilter(Float32 poleDist = DCRejectionFilter::kDefaultPoleDist);
		
		void InplaceFilter(SInt32* ioData, UInt32 numFrames, UInt32 strides);
		void Reset();
		
	protected:
		
		// Coefficients
		SInt16 mA1;
		SInt16 mGain;
		
		// State variables
		SInt32 mY1;
		SInt32 mX1;
		
		static const Float32 kDefaultPoleDist;
	};

#endif