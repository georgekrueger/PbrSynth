
#include "Envelope.h"

class EnvelopeADSR : public Envelope
{
public:
	EnvelopeADSR();
	
	enum Type
	{
		LINEAR,
		EXP
	};

	void    Init( Type Type, unsigned long SampleRate, float AttackTime, float AttackValue, float DecayTime, float SustainValue, float ReleaseTime );
	void    Start();
	float   Next();
	bool	IsDone();
	float	GetLatestValue();

	void	Release();

private:
	Type          mType;
	unsigned long mAttack;
	unsigned long mDecay;
	unsigned long mRelease;
	unsigned long mSampleRate;
	float		  mValue;
	float         mAttackValue;
	float		  mSustainValue;
	float         mAccel;
	float         mVel;
	enum
	{
		ATTACK,
		DECAY,
		SUSTAIN,
		RELEASE,
		DONE
	} mState;
};
