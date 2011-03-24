#ifndef SYNGLOBAL_H
#define SYNGLOBAL_H

typedef float SynSample;
typedef unsigned int uint;

static const int SAMPLE_RATE = 44100;

#define ZERO_SAMPLE		((SynSample)0.0f)

#define SHORT_TO_SYNSAMPLE(A)		( (float)(A) / 32767.0f )

// defines
#ifndef M_PI
#define M_PI  (3.14159265)
#endif

typedef enum {
	None = 0,
	WholeNote,
	HalfNote,
	ThirdNote,
	QuarterNote,
	SixthNote,
	EighthNote,
	SixteenthNote,
	ThirtySecondNote,
	WholeNoteRest,
	ThirdNoteRest,
	HalfNoteRest,
	QuarterNoteRest,
	SixthNoteRest,
	EighthNoteRest,
	SixteenthNoteRest,
	ThirtySecondNoteRest
} NoteStep;

int IsRestStep(NoteStep step);
float NoteStepToSeconds(NoteStep step, float tempoBpm );

float clamp( float min, float num, float max );

#endif  /* SYNGLOBAL_H */
