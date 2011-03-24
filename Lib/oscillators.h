#ifndef OSCILLATORS_H
#define OSCILLATORS_H
/*
 *  oscillators.h
 *
 *  Created by Judah Menter on 10/8/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "synglobal.h"
#include "MinBlepTable.h"

typedef struct {
	unsigned int sampleRate;
	float phase;
	int randSeed;
} OscData;

typedef struct {
	OscData oscData;
	SynSample *pBuffer;
	unsigned int numFrames;
	float waveFreq;
} WavetableOscData;

typedef struct {
	OscData oscData;
	float accum;
	static const int bufferCount = MinBlepTableCount / MinBlepTableOversampleFactor;
	float buffer[bufferCount];  // circular output buffer
	int bufferPos;	            // current buffer position
	int bufferNumInited;		// amount of initialized entries
} BlepOscData;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initializes a new oscillator. This method must be called before the OscData is passed to the oscillator functions.
 */
void InitOsc(OscData *pData, unsigned int sampleRate);

/**
 * Generates a sine wave.
 * @param freq The frequency in hertz.
 * @param amp The amplitude in the range [0, 1].
 * @param pBuf A pointer to a stereo data buffer. The buffer must be an even number of samples in size.
 * @param numFrames The buffer size in frames.
 * @param pData A pointer to an OscData structure.
 */
void SineOsc(float freq, bool& phaseReset, SynSample *pBuf, unsigned int numFrames, OscData *pData);

/**
 * Generates a pulse wave.
 * @param freq The frequency in hertz.
 * @param amp The amplitude in the range [0, 1].
 * @param width The pulse width in the range [0, 1].
 * @param pBuf A pointer to a stereo data buffer. The buffer must be an even number of samples in size.
 * @param numFrames The buffer size in frames.
 * @param pData A pointer to an OscData structure.
 */
void PulseOsc(float freq, float width, bool& phaseReset, SynSample *pBuf, unsigned int numFrames, OscData *pData);

/**
 * Generates a saw wave.
 * @param freq The frequency in hertz.
 * @param amp The amplitude in the range [0, 1].
 * @param pBuf A pointer to a stereo data buffer. The buffer must be an even number of samples in size.
 * @param numFrames The buffer size in frames.
 * @param pData A pointer to an OscData structure.
 */
void SawOsc(float freq, bool& phaseReset, SynSample *pBuf, unsigned int numFrames, OscData *pData);

/**
 * Generates a triangle wave.
 * @param freq The frequency in hertz.
 * @param amp The amplitude in the range [0, 1].
 * @param pBuf A pointer to a stereo data buffer. The buffer must be an even number of samples in size.
 * @param numFrames The buffer size in frames.
 * @param pData A pointer to an OscData structure.
 */
void TriangleOsc(float freq, bool& phaseReset, SynSample *pBuf, unsigned int numFrames, OscData *pData);

/**
 * Generates white noise.
 * @param amp The amplitude in the range [0, 1].
 * @param pBuf A pointer to a stereo data buffer. The buffer must be an even number of samples in size.
 * @param numFrames The buffer size in frames.
 * @param pData A pointer to an OscData structure.
 */
void WhiteNoiseOsc(SynSample *pBuf, unsigned int numFrames, OscData *pData);

/**
 * Initializes a new wavetable oscillator. This method must be called before the OscData is passed to the
 * wavetable oscillator functions.
 * @param pData A pointer to the WavetableOscData to use for this oscillator.
 * @param freq The fundamental frequency of the wavetable.
 * @param pBuf A pointer to stereo wavetable sample buffer.
 * @param numFrames The buffer size in frames.
 */
void InitWavetableOsc(WavetableOscData *pData, float freq, unsigned int sampleRate, SynSample *pBuf, unsigned int numFrames);

/**
 * Generates a signal from a wavetable.
 * @param freq The frequency in hertz.
 * @param amp The amplitude in the range [0, 1].
 * @param pBuf A pointer to a stereo audio data buffer.
 * @param numFrames The buffer size in frames.
 * @param pData A pointer to a WavetableOscData structure.
 */
void WavetableOsc(float freq, bool& phaseReset, SynSample *pBuf, unsigned int numFrames, WavetableOscData *pData);

/**
 * Plays a one-shot sample from a wavetable.
 * @param freq The frequency in hertz.
 * @param amp The amplitude in the range [0, 1].
 * @param pBuf A pointer to a stereo audio data buffer.
 * @param numFrames The buffer size in frames.
 * @param pData A pointer to a WavetableOscData structure.
 */
void WavetableOneShot(float freq, SynSample *pBuf, unsigned int numFrames, WavetableOscData *pData);

void InitBlepSawOsc( BlepOscData* osc, unsigned int sampleRate );
float BlepSawOsc(float freq, bool& phaseReset, BlepOscData* osc);
	
void InitBlepSquareOsc( BlepOscData* osc, unsigned int sampleRate );
float BlepSquareOsc(float freq, float pulseWidth, bool& phaseReset, BlepOscData* osc);

	
/**
 * Low frequency sine oscillator.
 */
float SineLFO(float freq, float center, float range, OscData *pData);

/**
 * Low frequency random oscillator.
 */
float RandomLFO(float rate, float center, float range, OscData *pData);

#ifdef __cplusplus
}
#endif

#endif  /* OSCILLATORS_H */
