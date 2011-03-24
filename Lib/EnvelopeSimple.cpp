
#include "EnvelopeSimple.h"
#include "assert.h"

void EnvelopeSimple::Init( unsigned long SampleRate, float Time, float StartValue, float EndValue )
{
	mCursor = 0;
	mTime = Time * SampleRate;
	mIncrement = ( EndValue - StartValue ) / ( mTime - 1 );
	mValue = StartValue;
	mEndValue = EndValue;
}

float EnvelopeSimple::Next()
{
	float Value;
	if ( mCursor < mTime ) {
		Value = mValue;
		mValue += mIncrement;
		mCursor++;
	}
	else {
		Value = mEndValue;
	}
	return Value;
}

void EnvelopeSimple::Start()
{
	mCursor = 0;
}

bool EnvelopeSimple::IsDone()
{
	return ( mCursor == mTime );
}