
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "effects.h"

static void ResetDelayLine( DelayLine* delayLine )
{
	uint j = 0;
	for ( j=0; j<delayLine->delayBufSize; j++ )
	{
		delayLine->pDelayBuf[j] = ZERO_SAMPLE;
	}
	delayLine->pRecCursor = delayLine->pDelayBuf;
}

static void InitDelayLine( DelayLine* delayLine, unsigned int sampleRate, float maxDelayTime )
{
	unsigned int numBufSamples;
	numBufSamples = (uint)(maxDelayTime * sampleRate * 2 + 2); // round up to nearest frame
	delayLine->pDelayBuf = (SynSample*)malloc(numBufSamples * sizeof(SynSample));
	delayLine->delayBufSize = numBufSamples;
	ResetDelayLine( delayLine );
}

void InitDelayEffect(DelayEffectData *pData, unsigned int sampleRate, float maxDelayTime)
{
	uint i = 0;
	pData->sampleRate = sampleRate;
	
	for ( i=0; i<numDelayLines; i++ )
	{
		InitDelayLine(&pData->delay[i], sampleRate, maxDelayTime);
	}
}

void DelayEffect(float blend, 
				 float delayTime1, float feedForward1, float feedBack1, 
				 float delayTime2, float feedForward2, float feedBack2, 
				 SynSample *pBuf, unsigned int size, DelayEffectData *pData)
{
	float alpha;
	uint i, j, n;
	SynSample *p, *pMix, sample, dsamp;
	
	float delay[2] = { delayTime1, delayTime2 };
	float feedForward[2] = { feedForward1, feedForward2 };
	float feedBack[2] = { feedBack1, feedBack2 };
	
	assert(blend >= 0.0f && blend <= 1.0f);
	
	for ( i=0; i<numDelayLines; i++ )
	{
		// process each delay line
		if ( delay[i] == 0 ) {
			continue;
		}
		
		delay[i] *= (float)pData->sampleRate;  // tap1 delay time in frames
		
		assert(delay[i] > 0 && delay[i] * 2 <= pData->delay[i].delayBufSize );
		assert(feedBack[i] >= 0.0f && feedBack[i] <= 1.0f);
		assert(feedForward[i] >= 0.0f && feedForward[i] <= 1.0f);
		
		p = pBuf;
		
		for ( j=0; j<size; j++ )
		{
			if (pData->delay[i].pRecCursor >= pData->delay[i].pDelayBuf + pData->delay[i].delayBufSize) {
				pData->delay[i].pRecCursor = pData->delay[i].pDelayBuf;
			}
			
			n = (unsigned int)delay[i];
			alpha = delay[i] - (float)n;
			n = n << 1;  /* floor of delay time in samples */
			pMix = pData->delay[i].pRecCursor - n;
			if (pMix < pData->delay[i].pDelayBuf) pMix += pData->delay[i].delayBufSize;
			n = pMix - pData->delay[i].pDelayBuf;
			
			/* left */
			if (n >= pData->delay[i].delayBufSize - 2) {
				dsamp = pData->delay[i].pDelayBuf[0] - pData->delay[i].pDelayBuf[n];
			}
			else {
				dsamp = pData->delay[i].pDelayBuf[n + 2] - pData->delay[i].pDelayBuf[n];
			}
			sample = pData->delay[i].pDelayBuf[n] + dsamp * alpha;
			*pData->delay[i].pRecCursor++ = *p + sample * feedBack[i];
			*p++ = *p * blend + (sample * feedForward[i]);
			
			/* right */
			if (n >= pData->delay[i].delayBufSize - 2) {
				dsamp = pData->delay[i].pDelayBuf[1] - pData->delay[i].pDelayBuf[n + 1];
			}
			else {
				dsamp = pData->delay[i].pDelayBuf[n + 3] - pData->delay[i].pDelayBuf[n + 1];
			}
			sample = pData->delay[i].pDelayBuf[n + 1] + dsamp * alpha;
			*pData->delay[i].pRecCursor++ = *p + sample * feedBack[i];
			*p++ = *p * blend + (sample * feedForward[i]);
		}
	}
}

void ResetDelayEffect(DelayEffectData *pData)
{
	uint i;
	for ( i=0; i<numDelayLines; i++ )
	{
		ResetDelayLine( &pData->delay[i] );
	}
}

void InitModDelayEffect(ModDelayEffectData *pData, unsigned int sampleRate, float maxDelayTime)
{
	pData->sampleRate = sampleRate;
	InitDelayLine(&pData->delay, sampleRate, maxDelayTime);
	InitOsc(&pData->lfo, sampleRate);
}

void ModDelayEffect(float rate, float modMin, float modDepth, float blend, float ff, float fb, SynSample *pBuf, unsigned int size, ModDelayEffectData *pData)
{
	float center, delay, alpha;
	unsigned int n;
	SynSample *p, *pMix, sample, dsamp;
	
	assert(rate > 0.0f);
	assert(modMin >= 0.0f);
	assert(modDepth >= 0.0f);
	assert(blend >= -1.0f && blend <= 1.0f);
	assert(fb >= -1.0f && fb <= 1.0f);
	assert(ff >= -1.0f && ff <= 1.0f);
	
	center = modMin + modDepth / 2.0f;
	p = pBuf;
	
	while (size--) {
		delay = RandomLFO(rate, center, modDepth, &pData->lfo);                                     
		if (delay < 0.0f) delay = 0.0f;
		delay *= (float)pData->sampleRate;  /* delay time in frames */
		
		assert((unsigned int)delay <= (pData->delay.delayBufSize >> 1));  /* delay time too long */
		
		if (pData->delay.pRecCursor >= pData->delay.pDelayBuf + pData->delay.delayBufSize) {
			pData->delay.pRecCursor = pData->delay.pDelayBuf;
		}
		
		n = (unsigned int)delay;
		alpha = delay - (float)n;
		n = n << 1;  /* floor of delay time in samples */
		pMix = pData->delay.pRecCursor - n;
		if (pMix < pData->delay.pDelayBuf) pMix += pData->delay.delayBufSize;
		n = pMix - pData->delay.pDelayBuf;
		
		/* left */
		if (n >= pData->delay.delayBufSize - 2) {
			dsamp = pData->delay.pDelayBuf[0] - pData->delay.pDelayBuf[n];
		}
		else {
			dsamp = pData->delay.pDelayBuf[n + 2] - pData->delay.pDelayBuf[n];
		}
		sample = pData->delay.pDelayBuf[n] + dsamp * alpha;
		*pData->delay.pRecCursor++ = *p + sample * fb;
		*p++ = *p * blend + (sample * ff);
		
		/* right */
		if (n >= pData->delay.delayBufSize - 2) {
			dsamp = pData->delay.pDelayBuf[1] - pData->delay.pDelayBuf[n + 1];
		}
		else {
			dsamp = pData->delay.pDelayBuf[n + 3] - pData->delay.pDelayBuf[n + 1];
		}
		sample = pData->delay.pDelayBuf[n + 1] + dsamp * alpha;
		*pData->delay.pRecCursor++ = *p + sample * fb;
		*p++ = *p * blend + (sample * ff);
	}
}

void ResetModDelayEffect(ModDelayEffectData *pData)
{
	ResetDelayLine( &pData->delay );
}

void InitDistortionEffect( DistortionData* pData, unsigned int sampleRate )
{
	InitMoogVCFFilter( &pData->FilterData, sampleRate );
	MoogVCFFilter_Set(&pData->FilterData, pData->FilterData.sampleRate / 4.0f, 0.0f);
	//BiQuad_Init( LPF, 0, sampleRate / 2.0, sampleRate, bandwidth, BiQuadData)
}

//static float atanh(float x)
//{
//	return (float)(0.5 * log((1+x) / (1-x)));
//}

void DistortionEffect( float a, SynSample *pBuf, unsigned int size, DistortionData* pData )
{
	uint i, j;
	SynSample absx;
	SynSample* x;
	//float k;
	
	//k = (2*a)/(1-a);

	x = pBuf;
	
	for (i=0; i<size; i++)
	{
		for (j=0; j<2; j++)
		{
			//pBuf[i+j] *= a; // gain
			
			
			*x = MoogVCFFilter( *x, &pData->FilterData );
			//x = pBuf[i+j];
			absx = ( *x >= 0 ? *x : *x * -1 );

			//if ( x > 0.0 ) {
			//	assert( 0 );
			//}

			//if ( x > 1 ) x = 1.0f;
			//if ( x < -1 ) x = -1.0f;
			
			//pBuf[i+j] = atanh( x );

			// a = 1 -> inf
			*x = (*x) * (absx + a)/((*x)*(*x) + (a-1) * absx + 1);

			// a = -1 -> 1
			//pBuf[i+j] = (1+k)*x/(1+k*absx);
			
			// simple third degree polynomial Distortion
			//pBuf[i+j] = 1.5f * x - 0.5f * x * x * x;
			
			// soft Distortion
			// a = 0 -> 1
			/*if ( x > 1 )
			{
			pBuf[i+j] = (a+1)/2;
			}
			else if ( x > a )
			{
			pBuf[i+j] = a + (x-a)/(1+pow((x-a)/(1-a), 2));
			}*/

			x++;
		}
	}
}

void InitOctaveEffect( OctaveEffectData *pData )
{
	pData->zeroCrossingCount = 0;
	pData->lastSample = ZERO_SAMPLE;
}

void OctaveEffect( float oct, float sub, float dry, SynSample *pBuf, uint numFrames, OctaveEffectData *pData )
{
	uint chan;
	SynSample octSamp, subSamp;
	
	while ( numFrames-- )
	{
		chan = 2;
		
		while ( chan-- )
		{
			/* Full wave rectification for harmonic (octave) signal */
			octSamp = *pBuf < ZERO_SAMPLE ? ZERO_SAMPLE : *pBuf;
			
			/* Count zero crossings */
			if ( pData->lastSample < ZERO_SAMPLE && *pBuf >= ZERO_SAMPLE ||
				 pData->lastSample >= ZERO_SAMPLE && *pBuf < ZERO_SAMPLE )
			{
				if ( ++pData->zeroCrossingCount > 4 )
				{
					pData->zeroCrossingCount = 1;
				}
			}
			
			/* Octave division for subharmonic signal */
			if ( *pBuf > ZERO_SAMPLE && pData->zeroCrossingCount < 3 )
			{
				subSamp = *pBuf;
			}
			else
			{
				subSamp = ZERO_SAMPLE;
			}
			
			pData->lastSample = *pBuf;
			
			/* Compute output */
			*pBuf++ = (*pBuf * dry) + (octSamp * oct) + (subSamp * sub);
		}
	}
}
