#include <stdlib.h>
#include "synglobal.h"

float NoteStepToSeconds(NoteStep step, float tempo)
{
	static const float duration[] = { 0.0f, 4.0f, 2.0f, 4.0f / 3.0f, 1.0f, 4.0f / 6.0f, 4.0f / 8.0f, 4.0f / 16.0f, 4.0f / 32.0f };
	int index = IsRestStep(step) ? step - 8 : step;
	return duration[index] * ( 60.0f / tempo );
}

int IsRestStep(NoteStep step)
{
	return step >= WholeNoteRest;
}

float clamp( float min, float num, float max )
{
	if ( num < min ) return min;
	else if ( num > max ) return max;
	else return num;
}