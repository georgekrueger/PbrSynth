#ifndef ARPEGGIATOR_H
#define ARPEGGIATOR_H

#include <list>
#include <pthread.h>

#include "synglobal.h"

class ArpeggiatorListener
{
public:
	virtual void NoteOn(int Pitch, float Velocity) = 0;
	virtual void NoteOff(int Pitch) = 0;
};

class Arpeggiator
{
public:
	static const float DefaultTickRate;
	static const float MininumGateTime;
	static const float DefaultGateTime;
	static const float MaximumGateTime;
	static const float DefaultTempo;
	static const NoteStep DefaultNoteStep;
	
	Arpeggiator(ArpeggiatorListener *pListener);
	virtual ~Arpeggiator();
	
	void NoteOn(int pitch, float velocity);
	void NoteOff(int pitch);
	void Tick();
	
	void SetEnabled(bool enabled);
	bool IsEnabled();
	
	void SetTickRate(float rate);
	float GetTickRate();
	
	void SetTempo(float tempo);
	float GetTempo();
	
	void SetGateTime(float gate);
	float GetGateTime();
	
	void SetPatternSize(size_t size);
	size_t GetPatternSize();

	void SetPatternStep(size_t index, NoteStep step);
	NoteStep GetPatternStep(size_t step);

	void SetDefaultPattern();
	
	void SaveSettings(const char *pPath);
	void LoadSettings(const char *pPath);
	
private:
	struct Note {
		Note(int p, float v);
		bool operator==(const Note& other);
		
		int pitch;
		float velocity;
	};
	
	static const unsigned int SETTING_FILE_FORMAT_VERSION = 1;
	
	void FirstNote();
	void NextNote();
	
	typedef std::list<Arpeggiator::Note> NoteList;
	typedef std::list<NoteStep> PatternList;
	
	ArpeggiatorListener*	mpListener;
	NoteList				mNotes;
	NoteList				mDeadNotes;
	NoteList::iterator		mCurNote;
	PatternList				mPattern;
	PatternList::iterator	mCurStep;
	bool					mEnabled;
	float					mTickRate;
	float					mTempo;
	float					mGateTime;
	float					mPhase;
	float					mPhaseDelta;
	bool					mCurNoteKilled;
	pthread_mutex_t			mMutex;
};

#endif  // ARPEGGIATOR_H
