/*
 *  Profiler.h
 *  PbrSynthLib
 *
 *  Created by George Krueger on 10/19/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PROFILER_H
#define PROFILER_H

class Profiler
{
public:
	Profiler(const char* Name);
	void Start(double Time);
	void Stop(double Time);
	void Reset();
	
	static void DumpProfileInfo(char* OutString, int OutStringLength);
	static void ResetAll();
	
private:
	static const int mMaxNameLengthInChars = 100;
	char mName[mMaxNameLengthInChars];
	double mStartTime;
	double mTotalTime;
	double mMaxTime;
	double mMinTime;
	long mNumTimes;
	
	static const int mMaxProfilersInPool = 100;
	static Profiler* mProfilerPool[mMaxProfilersInPool];
	static int mNumProfilersInPool;
};

#if defined(__APPLE__)
#include "QuartzCore/QuartzCore.h"
#define PROFILER_START(Name) static Profiler Profiler_##Name(#Name); Profiler_##Name.Start(CACurrentMediaTime());
#define PROFILER_END(Name) Profiler_##Name.Stop(CACurrentMediaTime());
#else
#define PROFILER_START(Name)
#define PROFILER_END(Name)
#endif

#endif