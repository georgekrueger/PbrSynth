#ifndef EFFECTS_H
#define EFFECTS_H

#include "synglobal.h"
#include "oscillators.h"
#include "filters.h"
/*#include "BiQuadFilter.h"*/

typedef struct {
	SynSample*   pDelayBuf;
	unsigned int delayBufSize;
	SynSample*   pRecCursor;
} DelayLine;

static const unsigned int numDelayLines = 2;

typedef struct {
	unsigned int sampleRate;
	DelayLine delay[2];
} DelayEffectData;

typedef struct {
	unsigned int sampleRate;
	DelayLine delay;
	OscData lfo;
} ModDelayEffectData;

typedef struct {
	MoogVCFFilterData FilterData;
	/*BiQuad BiQuadFilterData;*/
} DistortionData;

typedef struct {
	uint zeroCrossingCount;
	SynSample lastSample;
} OctaveEffectData;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize a new delay effect.
 * @param pData A pointer to the DelayEffectData to use for the effect.
 * @param sampleRate The sample rate in samples per second.
 * @param maxDelayTime The maximum delay time in seconds.
 */
void InitDelayEffect(DelayEffectData *pData, unsigned int sampleRate, float maxDelayTime);

/**
 * Apply a delay effect.
 * @param delay The delay time in seconds.
 * @param level The mixing level in the range [0, 1].
 * @param pBuf A pointer to a stereo data buffer.
 * @param size The buffer size in frames.
 * @param pData A pointer to the effect data.
 */
void DelayEffect(float blend, 
			float delayTime1, float feedForward1, float feedBack1, 
			float delayTime2, float feedForward2, float feedBack2, 
			SynSample *pBuf, unsigned int size, DelayEffectData *pData);

/**
 * Resets a delay effect by zeroing out the delay buffer.
 * @param pData A pointer to the effect data.
 */
void ResetDelayEffect(DelayEffectData *pData);

/**
 * Initialize a new modulated delay effect.
 * @param pData A pointer to the ModDelayEffectData to use for the effect.
 * @param sampleRate The sample rate in samples per second.
 * @param maxDelayTime The maximum delay time in seconds.
 */
void InitModDelayEffect(ModDelayEffectData *pData, unsigned int sampleRate, float maxDelayTime);

/**
 * Applies a modulated delay effect.
 * @param rate The delay time modulation rate in hertz.
 * @param modMin The minimum delay time in seconds (>= 0).
 * @param modDepth The delay time depth in seconds (>= 0).
 * @param blend The gain factor for the input signal in the range [0, 1].
 * @param ff The gain factor for the feedforward signal from the delay buffer in the range [0, 1].
 * @param fb The gain factor for the feedback signal from the delay buffer in the range [0, 1].
 * @param pBuf A pointer to a stereo data buffer.
 * @param size The buffer size in frames.
 * @param pData A pointer to the effect data.
 */
void ModDelayEffect(float rate, float modMin, float modDepth, float blend, float ff, float fb, SynSample *pBuf, unsigned int size, ModDelayEffectData *pData);

/**
 * Resets a modulated delay effect by zeroing out the delay buffer.
 * @param pData A pointer to the effect data.
 */
void ResetModDelayEffect(ModDelayEffectData *pData);

void InitDistortionEffect( DistortionData* pData, unsigned int sampleRate );	
void DistortionEffect( float a, SynSample *pBuf, unsigned int size, DistortionData* pData );

void InitOctaveEffect( OctaveEffectData *pData );
void OctaveEffect( float oct, float sub, float dry, SynSample *pBuf, uint numFrames, OctaveEffectData *pData );

#ifdef __cplusplus
}
#endif

#endif  /* EFFECTS_H */
