#ifndef FILTERS_H
#define FILTERS_H

#include "synglobal.h"

typedef struct {
	float sampleRate;
	float y1,y2,y3,y4;
	float oldx;
	float oldy1,oldy2,oldy3;
	float x;
	float r;
	float p;
	float k;
} MoogVCFFilterData;

struct TweakedButterworthFilter
{
	unsigned int sampleRate;
	float x1, x2, y1, y2;
	float a1, a2, a3, b1, b2;
};

#ifdef __cplusplus
extern "C" {
#endif

void InitMoogVCFFilter(MoogVCFFilterData *pData, unsigned int sampleRate);
void MoogVCFFilter_Set(MoogVCFFilterData *pData, float cutoff, float res);	
SynSample MoogVCFFilter(SynSample input, MoogVCFFilterData *pData);
	
void TweakedButterworth_Init( TweakedButterworthFilter* data, unsigned int sampleRate );
void TweakedButterworth_Set( TweakedButterworthFilter* data, int cutoff, float res );
SynSample TweakedButterworth_Process( TweakedButterworthFilter* data, SynSample input );

#ifdef __cplusplus
}
#endif

#endif  /* FILTERS_H */
