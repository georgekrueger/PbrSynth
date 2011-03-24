/*
 *  oscillators.c
 *  test
 *
 *  Created by Judah Menter on 10/13/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#include "oscillators.h"
#include "sinetable.h"

#define PUT_SAMPLE() *p++ = sample; *p++ = sample;
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

void InitOsc(OscData *pData, unsigned int sampleRate)
{
	pData->sampleRate = sampleRate;
	pData->phase = 0.0f;
	pData->randSeed = 2771;
}

static const float SineTableSizeDivBySampleRate = (float)SINE_TABLE_SIZE / SAMPLE_RATE;

void SineOsc(float freq, bool& phaseReset, SynSample *pBuf, unsigned int numFrames, OscData *pData)
{
	unsigned int n;
	float alpha, sample;
	float dphase = SineTableSizeDivBySampleRate * freq;
	SynSample *p = pBuf;
	
	if ( phaseReset ) {
		pData->phase = 0;
	}
	
	while (numFrames--) {
		n = (unsigned int)pData->phase;
		alpha = pData->phase - (float)n;
		sample = sine[n] + alpha * dsine[n];
		*p++ = sample;
		
		pData->phase += dphase;
		
		if (pData->phase >= (float)SINE_TABLE_SIZE) {
			pData->phase -= (float)SINE_TABLE_SIZE;
			phaseReset = true;
		}
	}
}

void PulseOsc(float freq, float width, bool& phaseReset, SynSample *pBuf, unsigned int numFrames, OscData *pData)
{
	float sample;
	float dphase = freq / pData->sampleRate;
	SynSample *p = pBuf;

	if ( phaseReset ) {
		pData->phase = 0;
	}
	
	while (numFrames--) {
		sample = (pData->phase < width) ? 1.0f : -1.0f;
		*p++ = sample;
		
		pData->phase += dphase;
		
		if (pData->phase >= 1.0f) {
			pData->phase -= 1.0f;
			phaseReset = true;
		}
	}
}

void SawOsc(float freq, bool& phaseReset, SynSample *pBuf, unsigned int numFrames, OscData *pData)
{
	float sample;
	float dphase = freq / pData->sampleRate;
	SynSample *p = pBuf;

	if ( phaseReset ) {
		pData->phase = 0;
	}
	
	while (numFrames--) {
		sample = (2.0f * pData->phase) - 1.0f;
		*p++ = sample;
		
		pData->phase += dphase;
		
		if (pData->phase >= 1.0f) {
			pData->phase -= 1.0f;
			phaseReset = true;
		}
	}
}

void TriangleOsc(float freq, bool& phaseReset, SynSample *pBuf, unsigned int numFrames, OscData *pData)
{
	float sample;
	float dphase = freq / pData->sampleRate;
	SynSample *p = pBuf;

	if ( phaseReset ) {
		pData->phase = 0;
	}
	
	while (numFrames--) {
		if (pData->phase < 0.5f) {
			sample = (4.0f * pData->phase) - 1.0f;
		}
		else {
			sample = (4.0f * (1.0f - pData->phase)) - 1.0f;
		}
		*p++ = sample;
		
		pData->phase += dphase;
		
		if (pData->phase >= 1.0f) {
			pData->phase -= 1.0f;
			phaseReset = true;
		}
	}
}

void WhiteNoiseOsc(SynSample *pBuf, unsigned int numFrames, OscData *pData)
{
	float sample;
	SynSample *p = pBuf;
	
	while (numFrames--) {
		sample = (float)(pData->randSeed = pData->randSeed * 214013L + 2531011L) / 0x7FFFFFFF * 2.0f - 1.0f;
		*p++ = sample;
	}
}

void InitWavetableOsc(WavetableOscData *pData, float freq, unsigned int sampleRate, 
					  SynSample *pBuf, unsigned int numFrames)
{
	assert(pBuf != NULL);
	assert(numFrames > 1);
	assert(freq > 0.0f);
	
	InitOsc(&pData->oscData, sampleRate);
	pData->pBuffer = pBuf;
	pData->numFrames = numFrames;
	pData->waveFreq = freq;
}

void WavetableOsc(float freq, bool& phaseReset, SynSample *pBuf, unsigned int numFrames, WavetableOscData *pData)
{
	unsigned int frameIndex, sampleIndex, nextSampleIndex;
	float alpha, dsamp;
	float dphase = (freq * (pData->oscData.sampleRate / pData->waveFreq)) / pData->oscData.sampleRate;
	SynSample *p = pBuf;
	SynSample sample = ZERO_SAMPLE;

	if ( phaseReset ) {
		pData->oscData.phase = 0;
	}

	while (numFrames--) {
		frameIndex = (unsigned int)pData->oscData.phase;
		alpha = pData->oscData.phase - (float)frameIndex;
		sampleIndex = frameIndex; // * pData->numChannels;  /* frame index to sample index */
		
		// output left channel
		nextSampleIndex = (frameIndex >= pData->numFrames - 1) ? 0 : sampleIndex; // + pData->numChannels;
		dsamp = pData->pBuffer[nextSampleIndex] - pData->pBuffer[sampleIndex];
		sample = pData->pBuffer[sampleIndex] + alpha * dsamp;
		*p++ = sample;
		
		// output right channel 
		/*if ( pData->numChannels == 1 )
		{
			// only one channel in the wavetable buffer, mirror the same sample on the right
			// output channel
			*p++ = sample;
		}
		else if ( pData->numChannels == 2 )
		{
			// get next channel in wavetable data
			sampleIndex++;
			nextSampleIndex++;
			dsamp = pData->pBuffer[nextSampleIndex] - pData->pBuffer[sampleIndex];
			*p++ = pData->pBuffer[sampleIndex] + alpha * dsamp;
		}
		else
		{
			// only mono and stereo wave tables are supported
			assert( 0 );
		}*/
		
		pData->oscData.phase += dphase;
		
		if (pData->oscData.phase >= (float)pData->numFrames) {
			pData->oscData.phase -= (float)pData->numFrames;
			phaseReset = true;
		}
	}
}

void WavetableOneShot(float freq, SynSample *pBuf, unsigned int numFrames, WavetableOscData *pData)
{
	unsigned int n;
	float alpha, dsamp;
	float dphase = (freq * (pData->oscData.sampleRate / pData->waveFreq)) / pData->oscData.sampleRate;
	SynSample *p = pBuf;
	SynSample sample = ZERO_SAMPLE;
	
	while (numFrames--) {
		if (pData->oscData.phase >= (float)pData->numFrames) {
			*p++ = ZERO_SAMPLE;
			*p++ = ZERO_SAMPLE;
		}
		else {
			n = (unsigned int)pData->oscData.phase;
			alpha = pData->oscData.phase - (float)n;
			//n = n * pData->numChannels;  /* convert to stereo frame index */
			
			/* left channel */
			dsamp = (n >= pData->numFrames - 2) ? 0.0f : pData->pBuffer[n + 2] - pData->pBuffer[n];
			sample = pData->pBuffer[n] + alpha * dsamp;
			*p++ = sample;
			
			/* right channel */
			/*if ( pData->numChannels == 1 )
			{
				*p++ = sample;
			}
			else if ( pData->numChannels == 2 )
			{
				dsamp = (n >= pData->numFrames - 2) ? 0.0f : pData->pBuffer[n + 3] - pData->pBuffer[n + 1];
				*p++ = pData->pBuffer[n + 1] + alpha * dsamp;
			}
			else
			{
				assert( 0 );
			}*/
			
			pData->oscData.phase += dphase;
		}
	}
}

enum BlepOscType
{
	Saw,
	Square,
};

#define LERP(A,B,F) ((B-A)*F+A)

// add step into buffer
void BlepAddStep(BlepOscData *osc, double offset, double amp)
{
	float BlepTableOffset = MinBlepTableOversampleFactor * offset;
	float BlepTableOffsetFrac = fmod( BlepTableOffset, 1.0 );
	float* BufferOut = osc->buffer + osc->bufferPos;
	float* BufferIn = GetMinBlepTable() + (int)( BlepTableOffset );
	int cBLEP = ( MinBlepTableCount / MinBlepTableOversampleFactor ) - 1;
	float *BufferOutEnd = osc->buffer + osc->bufferCount;
	int i;
	
	// add
	for ( i=0; i<osc->bufferNumInited; i++, BufferIn += MinBlepTableOversampleFactor, BufferOut++ )
	{
		if ( BufferOut >= BufferOutEnd ) BufferOut = osc->buffer;
		float f = LERP( BufferIn[0], BufferIn[1], BlepTableOffsetFrac );
		*BufferOut += amp * ( 1 - f );
	}
	
	// copy
	for (; i<cBLEP; i++, BufferIn += MinBlepTableOversampleFactor, BufferOut++ )
	{
		if ( BufferOut >= BufferOutEnd ) BufferOut = osc->buffer;
		float f = LERP( BufferIn[0], BufferIn[1], BlepTableOffsetFrac );
		*BufferOut = amp * ( 1 - f );
	}
	
	osc->bufferNumInited = cBLEP;
}

static SynSample BlepOsc(BlepOscType oscType, float freq, float pulseWidth, bool& phaseReset, BlepOscData* osc)
{
	SynSample v;
	float phaseInc = freq / SAMPLE_RATE;
	
	// create waveform
	osc->oscData.phase += phaseInc;
	
	// add BLEP at end of waveform
	if (osc->oscData.phase >= 1 || phaseReset)
	{
		osc->oscData.phase = MAX( osc->oscData.phase - 1.0, 0 );
		osc->accum = 0.0f;
		BlepAddStep(osc, osc->oscData.phase / phaseInc, 1.0f);
		phaseReset = true;
	}
	
	// add BLEP in middle of wavefor for squarewave
	if (!osc->accum && osc->oscData.phase > pulseWidth && oscType == Square)
	{
		osc->accum = 1.0f;
		BlepAddStep(osc, (osc->oscData.phase - pulseWidth) / phaseInc, -1.0f);
	}
	
	// sample value
	if (oscType == Saw) {
		v = osc->oscData.phase;
	}
	else {
		v = osc->accum;
	}
	
	// add BLEP buffer contents
	if (osc->bufferNumInited)
	{
		v += osc->buffer[osc->bufferPos];
		osc->bufferNumInited--;
		if (++osc->bufferPos >= osc->bufferCount) osc->bufferPos=0;
	}
	
	v -= 0.5; // shift down
	v *= 1.5; // scale
	
	return v;
}

void InitBlepSawOsc( BlepOscData* osc, unsigned int sampleRate )
{
	InitOsc(&osc->oscData, sampleRate);
	osc->accum = 0;
	osc->bufferPos = 0;
	osc->bufferNumInited = 0;
	memset( osc->buffer, 0, sizeof(osc->buffer) );
}

SynSample BlepSawOsc(float freq, bool& phaseReset, BlepOscData* osc)
{
	return BlepOsc( Saw, freq, 0, phaseReset, osc );
}

void InitBlepSquareOsc( BlepOscData* osc, unsigned int sampleRate )
{
	InitOsc(&osc->oscData, sampleRate);
	osc->accum = 0;
	osc->bufferPos = 0;
	osc->bufferNumInited = 0;
	memset( osc->buffer, 0, sizeof(osc->buffer) );
}

SynSample BlepSquareOsc(float freq, float pulseWidth, bool& phaseReset, BlepOscData* osc)
{
	return BlepOsc( Square, freq, pulseWidth, phaseReset, osc );
}

float SineLFO(float freq, float center, float range, OscData *pData)
{
	int n;
	float alpha, val;
	float dphase = (SINE_TABLE_SIZE * freq) / pData->sampleRate;
	
	n = (int)pData->phase;
	alpha = pData->phase - (float)n;
	val = center + range / 2.0f * (sine[n] + alpha * dsine[n]);
	
	pData->phase += dphase;
	
	if (pData->phase >= (float)SINE_TABLE_SIZE) {
		pData->phase -= (float)SINE_TABLE_SIZE;
	}
	
	return val;
}

#if 0
#include "wavfile.h"
static FILE *file = NULL;
static int done = 0;
static unsigned int bytesWritten = 0;
#endif

float RandomLFO(float rate, float center, float range, OscData *pData)
{
	float val, delta;
	float min = center - range / 2.0f;
	float max = min + range;
	
	/* TODO: Don't use libc rand, use our own so we can better predict it's behavior */
	pData->randSeed = rand();
	
	/* Here, phase is used to store the last calculated value */
	if (0.0f == pData->phase) pData->phase = center;
	
	val = pData->phase;
	delta = rate / 1000000.0f;
	if (pData->randSeed & 1) delta = -delta;
	val = pData->phase + delta;
	
	if (val < min || val > max) {
		val -= 2.0f * delta;
	}
	
	pData->phase = val;
	
#if 0
	if (NULL == file) {
		file = fopen("randomlfo.wav", "w");
		WriteWavHeader(file, 44100);
	}
	if (!done) {
		temp = (val - center) / (range/2.0f);
		fwrite(&temp, sizeof(temp), 1, file);
		fwrite(&temp, sizeof(temp), 1, file);
		bytesWritten += 8;
		
		if (bytesWritten >= 441000*8) {
			printf("done writing file\n");
			WriteWavDataSize(file, bytesWritten);
			fclose(file);
			done = 1;
		}
	}
#endif
	
	return val;
}
