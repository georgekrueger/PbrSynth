#include "filters.h"
//#include "synglobal.h"
#include "CutoffTable.h"
#include <assert.h>

void InitMoogVCFFilter(MoogVCFFilterData *pData, unsigned int sampleRate)
{
	pData->sampleRate = (float)sampleRate;
	pData->y1 = pData->y2 = pData->y3 = pData->y4 = 0.0f;
	pData->oldx = pData->oldy1 = pData->oldy2 = pData->oldy3 = 0.0f;
}

void MoogVCFFilter_Set( MoogVCFFilterData *pData, float cutoff, float res )
{
	float f, t, t2;
	
	f = (cutoff + cutoff) / pData->sampleRate; //[0 - 1]
	pData->p = f * (1.8f - 0.8f * f);
	pData->k = pData->p + pData->p - 1.0f;
	
	t = (1.0f - pData->p) * 1.386249f;
	t2 = 12.f + t * t;
	pData->r = res * (t2 + 6.0f * t) / (t2 - 6.0f * t);
}

SynSample MoogVCFFilter(SynSample input, MoogVCFFilterData *pData)
{
	/* process input */
	pData->x = input - pData->r * pData->y4;
	
	/* Four cascaded onepole filters (bilinear transform) */
	pData->y1 = pData->x * pData->p + pData->oldx * pData->p - pData->k * pData->y1;
	pData->y2 = pData->y1 * pData->p + pData->oldy1 * pData->p - pData->k * pData->y2;
	pData->y3 = pData->y2 * pData->p + pData->oldy2 * pData->p - pData->k * pData->y3;
	pData->y4 = pData->y3 * pData->p + pData->oldy3 * pData->p - pData->k * pData->y4;
	
	/* Clipper band limited sigmoid */
	pData->y4 -= (pData->y4 * pData->y4 * pData->y4) / 6.0f;
	
	pData->oldx = pData->x; pData->oldy1 = pData->y1; pData->oldy2 = pData->y2; pData->oldy3 = pData->y3;
	return pData->y4;
}

void TweakedButterworth_Init( TweakedButterworthFilter* data, unsigned int sampleRate )
{
	data->sampleRate = sampleRate;
	data->x1 = data->x2 = data->y1 = data->y2 = 0;
}

void TweakedButterworth_Set( TweakedButterworthFilter* data, int cutoff, float res )
{
	//float c = 1.0 / tan( PI_DIV_SR * cutoff );
	assert( cutoff >= CUTOFF_MIN && cutoff <= CUTOFF_MAX );
	float c = CutoffTable[ cutoff - CUTOFF_MIN ];
	float cc = c * c;
	float resc = res * c;
	data->a1 = 1.0 / ( 1.0 + resc + cc );
	data->a2 = data->a1 + data->a1;
	data->a3 = data->a1;
	float tmp = ( 1.0 - cc ) * data->a1;
	data->b1 = tmp + tmp;
	data->b2 = ( 1.0 - resc + cc ) * data->a1;
}

SynSample TweakedButterworth_Process( TweakedButterworthFilter* data, SynSample input )
{
	float out = data->a1 * input + data->a2 * data->x1 + data->a3 * data->x2 - data->b1 * data->y1 - data->b2 * data->y2;
	data->x2 = data->x1;
	data->x1 = input;
	data->y2 = data->y1;
	data->y1 = out;
	return out;
}