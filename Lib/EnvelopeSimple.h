
#include "Envelope.h"

class EnvelopeSimple : public Envelope
{
public:
	void Init( unsigned long SampleRate, float Time, float StartValue, float EndValue );

	void	Start();
	float   Next();
	bool	IsDone();

private:
	unsigned long mCursor;
	unsigned long mTime;
	float         mIncrement;
	float         mValue;
	float         mEndValue;
};