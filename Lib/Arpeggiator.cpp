#include <algorithm>
#include <fstream>
#include <iostream>  // for debugging

#include "Arpeggiator.h"
#include "MutexLocker.h"

#define SYNCHRONIZED MutexLocker locker(&mMutex);

using namespace std;

Arpeggiator::Note::Note(int p, float v)
:	pitch(p),
	velocity(v)
{
}

bool Arpeggiator::Note::operator==(const Arpeggiator::Note& other)
{
	return pitch == other.pitch;
}

const float Arpeggiator::DefaultTickRate = SAMPLE_RATE / 64.0f;
const float Arpeggiator::MininumGateTime = 0.0f;
const float Arpeggiator::DefaultGateTime = 0.2f;
const float Arpeggiator::MaximumGateTime = 0.99f;
const float Arpeggiator::DefaultTempo = 120.0f;
const NoteStep Arpeggiator::DefaultNoteStep = QuarterNote;

Arpeggiator::Arpeggiator(ArpeggiatorListener *pListener)
:	mpListener(pListener),
	mCurNote(mNotes.end()),
	mCurStep(mPattern.end()),
	mEnabled(false),
	mPhase(0.0f),
	mCurNoteKilled(false)
{
	pthread_mutex_init(&mMutex, NULL);

	SetDefaultPattern();
	SetTickRate(DefaultTickRate);
	SetTempo(DefaultTempo);
	SetGateTime(DefaultGateTime);
}

Arpeggiator::~Arpeggiator()
{
	pthread_mutex_destroy(&mMutex);
}

void Arpeggiator::NoteOn(int pitch, float velocity)
{
	SYNCHRONIZED
	
	bool passthru = ( !mEnabled || 0 == mPattern.size() );
	
	if ( passthru )
	{
		// Pass the event directly to the synth
		mpListener->NoteOn(pitch, velocity);
	}
	
	// Even if not enabled, we still need to keep track of which notes are active
	// so we can properly handle them when re-activated.
	mNotes.push_back( Note(pitch, velocity) );
}

void Arpeggiator::NoteOff(int pitch)
{
	SYNCHRONIZED
	
	bool passthru = ( !mEnabled || 0 == mPattern.size() );
	
	if ( passthru )
	{
		// Pass the event directly to the synth
		mpListener->NoteOff(pitch);
	}
	
	if ( !passthru && mCurNote != mNotes.end() && pitch == (*mCurNote).pitch )
	{
		// If the note is playing, wait until it's finished, then remove it
		mDeadNotes.push_back( *mCurNote );
	}
	else
	{
		// Find the note with matching pitch and remove it
		NoteList::iterator it = find( mNotes.begin(), mNotes.end(), Note(pitch, 0.0f) );
		if ( it != mNotes.end() ) mNotes.erase(it);
	}
}

void Arpeggiator::Tick()
{
	SYNCHRONIZED
	
	if ( !mEnabled || 0 == mNotes.size() || 0 == mPattern.size() )
	{
		// Don't have what we need to do our thing
		return;
	}
	
	// This check handles the case where we got more than one NoteOn event in
	// the same tick and nothing was playing previously.
	if (mNotes.end() == mCurNote)
	{
		FirstNote();
		mpListener->NoteOn( (*mCurNote).pitch, (*mCurNote).velocity );
	}

	if (mPattern.end() == mCurStep)
	{
		mCurStep = mPattern.begin();
	}
	
	mPhase += mPhaseDelta;
	
	// Calculate note duration in seconds, with and without gate
	float noteDur = NoteStepToSeconds(*mCurStep, mTempo);
	float noteDurGate = noteDur * (1.0f - mGateTime);
	
	// If we pass noteDurGate, turn the current note off
	if ( mPhase > noteDurGate && !mCurNoteKilled )
	{
		//cout << "Note " << (*mCurNote).pitch << " off" << endl;
		if ( !IsRestStep(*mCurStep) )
		{
			mpListener->NoteOff( (*mCurNote).pitch );
		}
		mCurNoteKilled = true;
	}
	
	// If we pass noteDur, go to the next note and turn it on
	if (mPhase > noteDur)
	{
		// Check if this note is "dead" and remove it if so
		NoteList::iterator it = find(mDeadNotes.begin(), mDeadNotes.end(), *mCurNote);
		if ( it != mDeadNotes.end() )
		{
			mCurNote = mNotes.erase(mCurNote);
			if ( mCurNote == mNotes.end() )
			{
				mCurNote = mNotes.begin();
			}
			mDeadNotes.erase(it);
		}
		
		NextNote();
		
		if ( !IsRestStep(*mCurStep) && mCurNote != mNotes.end() )
		{
			//cout << "Note " << (*mCurNote).pitch << " on" << endl;
			mpListener->NoteOn( (*mCurNote).pitch, (*mCurNote).velocity );
		}
	}
}

void Arpeggiator::SetEnabled(bool enabled)
{
	SYNCHRONIZED
	
	mEnabled = enabled;
	
	if (enabled && mNotes.size()) {
		// Turn all notes off except for the first one
		NoteList::iterator it = mNotes.begin();
		while (++it != mNotes.end()) {
			mpListener->NoteOff( (*it).pitch );
		}
	}
	else {
		if (mNotes.size()) {
			// Turn on notes that are not already playing
			for (NoteList::iterator it = mNotes.begin(); it != mNotes.end(); ++it) {
				if (it == mCurNote) continue;
				
				// Make sure it's not dead
				NoteList::iterator itd = find(mDeadNotes.begin(), mDeadNotes.end(), *it);
				if (itd == mDeadNotes.end()) mpListener->NoteOn( (*it).pitch, (*it).velocity );
			}
			
			mDeadNotes.clear();
		}
	
		mCurNote = mNotes.end();
		mCurStep = mPattern.end();
	}
}

bool Arpeggiator::IsEnabled()
{
	return mEnabled;
}

void Arpeggiator::SetTickRate(float rate)
{
	SYNCHRONIZED
	
	mTickRate = rate;
	mPhaseDelta = 1.0f / rate;
}

float Arpeggiator::GetTickRate()
{
	return mTickRate;
}

void Arpeggiator::SetTempo(float tempo)
{
	SYNCHRONIZED
	
	mTempo = tempo;
}

float Arpeggiator::GetTempo()
{
	return mTempo;
}

void Arpeggiator::SetPatternSize(size_t size)
{
	SYNCHRONIZED
	
	size_t oldSize = mPattern.size();
	
	mPattern.resize(size, DefaultNoteStep);
	
	if ( size < oldSize ) mCurStep = mPattern.begin();
}

size_t Arpeggiator::GetPatternSize()
{
	return mPattern.size();
}

void Arpeggiator::SetPatternStep(size_t index, NoteStep step)
{
	SYNCHRONIZED
	
	if (index < mPattern.size()) {
		PatternList::iterator it = mPattern.begin();
		advance(it, index);
		*it = step;
	}
}

NoteStep Arpeggiator::GetPatternStep(size_t step)
{
	if (step < mPattern.size()) {
		PatternList::iterator it = mPattern.begin();
		advance(it, step);
		return *it;
	}

	return static_cast<NoteStep>(0);
}

void Arpeggiator::SetDefaultPattern()
{
	SYNCHRONIZED
	
	mPattern.clear();
	mPattern.push_back(DefaultNoteStep);
}

void Arpeggiator::SaveSettings(const char *pPath)
{
	ofstream file( pPath );
	if ( !file ) return;

	file.precision( 8 );
	
	// write format version
	file << SETTING_FILE_FORMAT_VERSION << endl;
	
	file << mTempo << endl;
	file << mGateTime << endl;
	
	for ( PatternList::iterator it = mPattern.begin(); it != mPattern.end(); ++it )
	{
		file << *it << endl;
	}
	
	file.close();
}

void Arpeggiator::LoadSettings(const char *pPath)
{
	ifstream file( pPath );
	if ( !file ) return;

	file.precision( 8 );
	
	// read format version
	unsigned int formatVersion;
	file >> formatVersion;
	
	file >> mTempo;
	file >> mGateTime;
	
	size_t stepIndex = 0;
	
	while ( !file.eof() )
	{
		unsigned int step = 0;
		file >> step;
		
		if ( 0 == step ) break;  // didn't find any more steps
		
		SetPatternSize( stepIndex + 1 );
		SetPatternStep( stepIndex, static_cast<NoteStep>(step) );
		
		++stepIndex;
	}
	
	file.close();
}

void Arpeggiator::SetGateTime(float gate)
{
	if (gate < MininumGateTime) gate = MininumGateTime;
	else if (gate > MaximumGateTime) gate = MaximumGateTime;
	
	SYNCHRONIZED
	
	mGateTime = gate;
}

float Arpeggiator::GetGateTime()
{
	return mGateTime;
}

void Arpeggiator::FirstNote()
{
	mCurNote = mNotes.begin();
	mCurStep = mPattern.begin();
	mPhase = 0.0f;
	mCurNoteKilled = false;
}

void Arpeggiator::NextNote()
{
	if ( ++mCurStep == mPattern.end() ) {
		mCurStep = mPattern.begin();
	}
	
	if ( !IsRestStep(*mCurStep) && ++mCurNote == mNotes.end() ) {
		mCurNote = mNotes.begin();
	}
	
	mPhase = 0.0f;
	mCurNoteKilled = false;
}

