
#ifndef ENVELOPE_H
#define ENVELOPE_H

class Envelope
{
public:
	virtual void  Start() = 0;
	virtual float Next() = 0;
	virtual bool  IsDone() = 0;
};

#endif