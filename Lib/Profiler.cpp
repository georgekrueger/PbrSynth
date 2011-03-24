/*
 *  Profiler.cpp
 *  PbrSynthLib
 *
 *  Created by George Krueger on 10/19/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Profiler.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

const double LARGE=1.e30;

int Profiler::mNumProfilersInPool = 0;
Profiler* Profiler::mProfilerPool[mMaxProfilersInPool];

Profiler::Profiler(const char* Name)
{
	assert( strlen(Name) < mMaxNameLengthInChars );
	if ( strlen(Name) >= mMaxNameLengthInChars ) return;
	strcpy( mName, Name );
	mProfilerPool[mNumProfilersInPool++] = this;
	Reset();
}

void Profiler::Reset()
{
	mStartTime = 0;
	mTotalTime = 0;
	mNumTimes = 0;
	mMaxTime = 0;
	mMinTime = LARGE;
}

void Profiler::Start(double Time)
{
	mStartTime = Time;
}

void Profiler::Stop(double Time)
{
	double TimePassed = Time - mStartTime;
	mTotalTime += TimePassed;
	mNumTimes++;
	if (TimePassed > mMaxTime ) {
		mMaxTime = TimePassed;
	}
	if ( TimePassed < mMinTime ) {
		mMinTime = TimePassed;
	}
}

void Profiler::DumpProfileInfo(char* OutString, int OutStringLength)
{
	char* origStr = OutString;
	char* s = OutString;
	const char* strFormat = "[%s] Total: %f, Average: %f, Min: %f, Max: %f\n";
	for (int i=0; i<mNumProfilersInPool && (s - origStr + strlen(strFormat) + 1) < OutStringLength; i++ )
	{
		Profiler* p = mProfilerPool[i];
		sprintf(s, strFormat, p->mName, p->mTotalTime, p->mTotalTime / p->mNumTimes, p->mMinTime, p->mMaxTime);
		s += strlen(s) + 1;
	}
}

void Profiler::ResetAll()
{
	for (int i=0; i<mNumProfilersInPool; i++ )
	{
		Profiler* p = mProfilerPool[i];
		p->Reset();		
	}
}


