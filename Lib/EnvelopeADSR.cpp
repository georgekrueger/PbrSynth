
#include "EnvelopeADSR.h"
#include "assert.h"
#include "synglobal.h"
#include <math.h>

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define CLAMP(MINVAL, X, MAXVAL) MAX(MIN(X,MAXVAL),MINVAL)
#define ZERO 0.0

EnvelopeADSR::EnvelopeADSR() : mState(ATTACK)
{
}

void EnvelopeADSR::Init( Type Type, unsigned long SampleRate, float AttackTime, float AttackValue, float DecayTime, float SustainValue, float ReleaseTime )
{
	assert( mAttackValue >= mSustainValue );
	mType = Type;
	mSampleRate = SampleRate;
	mAttack = AttackTime * SampleRate;
	mDecay = DecayTime * SampleRate;
	mRelease = ReleaseTime * SampleRate;
	mAttackValue = AttackValue;
	mSustainValue = SustainValue;
}

float EnvelopeADSR::Next()
{
	float Value;
	
	switch ( mState )
	{
	case ATTACK:
		{
			if (mType == EXP) {
				mVel += mAccel;
			}
			mValue += mVel;
			Value = mValue;
			
			if ( mValue >= mAttackValue || mVel <= 0 ) {
				mState = DECAY;
				Value = mValue = mAttackValue;
				if (mType == LINEAR) {
					mVel = ( mSustainValue - mAttackValue ) / mDecay;
				}
				else {
					float Accel = ( 2 * (mAttackValue - mSustainValue) ) / ( mDecay * mDecay );
					mAccel = Accel;
					mVel = -Accel * mDecay;
				}
			}
		}
		break;
	case DECAY:
		{
			if (mType == EXP) {
				mVel += mAccel;
			}
			mValue += mVel;
			Value = mValue;
			
			if ( mValue <= mSustainValue || mVel >= 0 ) {
				mState = SUSTAIN;
				Value = mValue = mSustainValue;
			}
		}
		break;
	case SUSTAIN:
		{
			Value = mValue = mSustainValue;
		}
		break;
	case RELEASE:
		{
			if (mType == EXP) {
				mVel += mAccel;
			}
			mValue += mVel;
			Value = mValue;
			
			if ( mValue <= 0 || mVel >= 0 ) {
				mState = DONE;
				Value = mValue = 0;
			}
		}
		break;
	case DONE:
		Value = 0;
		break;
	}
	
	return Value;
}

void  EnvelopeADSR::Start()
{
	mState = ATTACK;
	mValue = 0;
	if (mType == LINEAR) {
		mVel = mAttackValue / mAttack;
		mAccel = 0;
	}
	else {
		float Accel = ( 2 * mAttackValue ) / ( mAttack * mAttack );
		mAccel = -Accel;
		mVel = Accel * mAttack;
	}
}

void  EnvelopeADSR::Release()
{
	mState = RELEASE;
	if (mType == LINEAR) {
		mVel = -mValue / mRelease;
	}
	else {
		float Accel = ( 2 * mValue ) / ( mRelease * mRelease );
		mAccel = Accel;
		mVel = -Accel * mRelease;
	}
}

bool EnvelopeADSR::IsDone()
{
	return (mState == DONE);
}

float EnvelopeADSR::GetLatestValue()
{
	return mValue;
}