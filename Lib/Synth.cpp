
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <sstream>

#include "CutoffTable.h"
#include "Synth.h"
#include "MutexLocker.h"
#include "wavfile.h"
#include "synglobal.h"
#include "Profiler.h"

using namespace std;

#define SYNCHRONIZED MutexLocker locker(&mMutex);

// statics
static float MIDI_TO_FREQ[127];
bool TablesAreInited = false;

static const float SYNTH_VOLUME_SCALE = 3.0f;

static const float STOLEN_VOICE_FADE_TIME = 0.001f;

static const float MAX_DELAY_SIZE_SECONDS = 2.0f;

// forward declarations
void Synth_InitDataTables();

// This constant scales the volume of each voice to avoid clipping.
const float Synth::VOICE_VOL = 0.5f / (Synth::NUM_VOICES + Synth::NUM_STEAL_VOICES);

const char* Synth::SETTING_ID_STRINGS[] = {
	"GlobalVolume",
	"TempoBPM",
		
	// ADSR
	"Attack",
	"Decay",
	"Sustain",
	"Release",
	
	// oscillator 1
	"Osc1Type",
	"Osc1Volume",
	"Osc1DetuneSemitones",
	"Osc1DetuneCents",
	"Osc1PulseWidth",
	"Osc1WavetablePath",
	"Osc1WavetableFreq",
	
	// oscillator 2
	"Osc2Type",
	"Osc2Volume",
	"Osc2DetuneSemitones",
	"Osc2DetuneCents",
	"Osc2FreqMult",
	"Osc2PulseWidth",
	"Osc2WavetablePath",
	"Osc2WavetableFreq",
	
	// filter
	"Cutoff",
	"CutoffLFOFreq",
	"CutoffLFORange",
	"Resonance",

	// filter cutoff ADSR
	"FilterCutoffEnvelopeAmount",
	"FilterCutoffAttack",
	"FilterCutoffDecay",
	"FilterCutoffSustain",
	"FilterCutoffRelease",
	
	// delay
	"DelayEnabled",
	"DelayBlend",
	"DelayStep1",
	"DelaySecondsOffset1",
	"DelayFeedForward1",
	"DelayFeedBack1",
	"DelayStep2",
	"DelaySecondsOffset2",
	"DelayFeedForward2",
	"DelayFeedBack2",
	
	// modulated delay
	"ModDelayEnabled",
	"ModDelayRate",
	"ModDelayMin",
	"ModDelayDepth",
	"ModDelayBlend",
	"ModDelayFF",
	"ModDelayFB",
	
	// Distortion
	"DistortionEnabled",
	"DistortionValue",
	
	// Octave
	"OctaveEnabled",
	"OctaveHarmonic",
	"OctaveSubharmonic",
	"OctaveDry",
	
	// filters/effects
	"Filter1",
	"Filter2",
	"Filter3",
	"Filter4",
	"Filter5",
	"Filter6",
	"Filter7",
	"Filter8",
	"Filter9",
	"Filter10",

	// Oscillator Sync
	"OscillatorSyncEnabled",

	"MonoEnabled",

	"GlideEnabled",
	"GlideTime"
};

const int EnvBuffSize = 10 * 44100;
float EnvBuff[EnvBuffSize];
int   EnvBuffCount = 0;

const uint Synth::NUM_SETTING_ID_STRINGS = sizeof(SETTING_ID_STRINGS) / sizeof(char*);

Synth::Synth()
{
	unsigned int i;
	
	pthread_mutex_init( &mMutex, NULL );
	
	mSampleRate = SAMPLE_RATE;
	mNumActiveVoices = 0;
	
	for( i=0; i<NUM_VOICES; i++ )
	{
		mVoices[i].Active = false;
	}
	
	for( i=0; i<NUM_STEAL_VOICES; i++ )
	{
		mStealVoices[i].Active = false;
	}

	if ( !TablesAreInited ) 
	{
		Synth_InitDataTables();
		TablesAreInited = true;
	}

	SetSetting( GlobalVolume, 0.5f );
	SetSetting( TempoBPM, 120.0f );

	SetSetting( Attack, 0.01f );
	SetSetting( Decay, 0.25f );
	SetSetting( Sustain, 0.70f );
	SetSetting( Release, 0.8f );
	
	SetSetting( Osc1Type, Sine );
	SetSetting( Osc1Volume, 1.0f );
	SetSetting( Osc1DetuneSemitones, 0 );
	SetSetting( Osc1DetuneCents, 0 );
	SetSetting( Osc1PulseWidth, 0.5f );
	mOsc1WavetableBuf = NULL;
	mOsc1WavetableNumFrames = 0;
	
	SetSetting( Osc2Type, Sine );
	SetSetting( Osc2Volume, 1.0f );
	SetSetting( Osc2DetuneSemitones, 0 );
	SetSetting( Osc2DetuneCents, 0 );
	SetSetting( Osc2PulseWidth, 0.5f );
	mOsc2WavetableBuf = NULL;
	mOsc2WavetableNumFrames = 0;
	
	SetSetting( Cutoff, 2000 );
	SetSetting( CutoffLFOFreq, 0.0f );
	SetSetting( CutoffLFORange, 500.0f );
	SetSetting( Resonance, 0.0f );
	InitOsc( &mCutoffLFOData, mSampleRate/64 );  // TODO: determine LFO rate from FramesPerBuffer

	SetSetting( FilterCutoffEnvelopeAmount, 0.0f );
	SetSetting( FilterCutoffAttack, 0.2f );
	SetSetting( FilterCutoffDecay, 0.2f );
	SetSetting( FilterCutoffSustain, 0.2f );
	SetSetting( FilterCutoffRelease, 0.2f );
	
	SetSetting( DelayEnabled, false );
	SetSetting( DelayBlend, 1.0f );
	SetSetting( DelayStep1, EighthNote );
	SetSetting( DelaySecondsOffset1, 0.0f );
	SetSetting( DelayFeedForward1, 1.0f );
	SetSetting( DelayFeedBack1, 0.5f );
	SetSetting( DelayStep2, None );
	SetSetting( DelaySecondsOffset2, 0.0f );
	SetSetting( DelayFeedForward2, 1.0f );
	SetSetting( DelayFeedBack2, 0.5f );	
	InitDelayEffect( &mDelayData, mSampleRate, MAX_DELAY_SIZE_SECONDS );
	
	SetSetting( ModDelayEnabled, false );
	SetSetting( ModDelayRate, 0.25f );
	SetSetting( ModDelayMin, 0.001f );
	SetSetting( ModDelayDepth, 0.005f );
	SetSetting( ModDelayBlend, 0.7f );
	SetSetting( ModDelayFF, 0.7f );
	SetSetting( ModDelayFB, 0.7f );
	InitModDelayEffect( &mModDelayData, mSampleRate, 1 );
	
	SetSetting( DistortionEnabled, false );
	SetSetting( DistortionValue, 1.0f );
	InitDistortionEffect( &mDistortionData, mSampleRate );
	
	SetSetting( OctaveEnabled, false );
	SetSetting( OctaveHarmonic, 0.5f );
	SetSetting( OctaveSubharmonic, 0.5f );
	SetSetting( OctaveDry, 1.0f );
	
	SetSetting( Filter1, Octave );
	SetSetting( Filter2, Distortion );
	SetSetting( Filter3, ModDelay );
	SetSetting( Filter4, Delay );
	
	for ( i = Filter5; i <= Setting_LastFilter; ++i )
	{
		SettingID id = static_cast<SettingID>( i );
		SetSetting( id, static_cast<int>( Filter_None ) );
	}

	SetSetting( OscillatorSyncEnabled, false );

	SetSetting( MonoEnabled, false );
	SetSetting( GlideEnabled, false );
	SetSetting( GlideTime, 0.15f );

	for ( i = 0; i<MAX_ACTIVE_NOTES; i++ )
	{
		mActiveNotes[i].Pitch = INVALID_PITCH;
		mActiveNotes[i].Velocity = 0;
	}
	mNumActiveNotes = 0;

	mLastPitch = INVALID_PITCH;
	
	mResonance = sqrt(2.0);
	mFilterCutoffControlRate = 0;
}

Synth::~Synth()
{
	pthread_mutex_destroy( &mMutex );
	printf("Num Simultaneous Real Voices: %d\nNum Simultaneous Steal Voices: %d\nNum Simultaneous Active Voices: %d\n", 
		   mNumSimulRealVoices, mNumSimulStealVoices, mNumSimulActiveVoices);
	
	FILE* f = fopen("CutoffEnvelope.raw", "w");
	fwrite(EnvBuff, sizeof(float), EnvBuffSize, f);
	fclose(f);
}

static inline SynSample RenderOscillatorFrameByType( Synth::OscillatorType OscType, float Frequency, float PulseWidth, bool& PhaseReset,
										OscData* OscData, WavetableOscData* OscWavetableData, BlepOscData* BlepOscData )
{
	SynSample Sample;
	switch ( OscType )
	{
	case Synth::Sine:
		SineOsc( Frequency, PhaseReset, &Sample, 1, OscData );
		break;
	case Synth::Pulse:
		PulseOsc( Frequency, PulseWidth, PhaseReset, &Sample, 1, OscData );
		break;
	case Synth::Saw:
		SawOsc( Frequency, PhaseReset, &Sample, 1, OscData );
		break;
	case Synth::Triangle:
		TriangleOsc( Frequency, PhaseReset, &Sample, 1, OscData );
		break;
	case Synth::WhiteNoise:
		WhiteNoiseOsc( &Sample, 1, OscData );
		break;
	case Synth::Wavetable:
		WavetableOsc( Frequency, PhaseReset, &Sample, 1, OscWavetableData );
		break;
	case Synth::OneShot:
		WavetableOneShot( Frequency, &Sample, 1, OscWavetableData );
		break;
	case Synth::BlepSaw:
		Sample = BlepSawOsc( Frequency, PhaseReset, BlepOscData );
		//OutFrame[1] = OutFrame[0];
		break;
	case Synth::BlepSquare:
		Sample = BlepSquareOsc( Frequency, PulseWidth, PhaseReset, BlepOscData );
		//OutFrame[1] = OutFrame[0];
		break;
	}
	return Sample;
}

void Synth::ApplyVoiceEffects( Voice* Voice, SynSample* Frame, bool IsStealVoice )
{
	
	if ( !IsStealVoice )
	{
		// only update cutoff if this is a normal voice (not a steal voice)
		float cutoffEnvAmount = Voice->FilterCutoffEnvelope.Next();
		EnvBuff[EnvBuffCount++] = cutoffEnvAmount;
		if ( mFilterCutoffControlRate == 0 ) {
			// add filter cutoff envelope amount to base amount
			// TODO: Add back in
			//float cutoff = SineLFO( GetSetting(CutoffLFOFreq).toFloat(), GetSetting(Cutoff).toFloat(), 
			//					   GetSetting(CutoffLFORange).toFloat(), &mCutoffLFOData ) + cutoffEnvAmount;
			float cutoff = GetSetting(Cutoff).toInt() + cutoffEnvAmount * 5000.0f;
			if ( cutoff < CUTOFF_MIN ) cutoff = CUTOFF_MIN;
			if ( cutoff > CUTOFF_MAX ) cutoff = CUTOFF_MAX;
			
			//MoogVCFFilter_Set(&Voice->Filter, cutoff, GetSetting(Resonance).toFloat());
			TweakedButterworth_Set( &Voice->Filter, cutoff, mResonance );
			
			mFilterCutoffControlRate = FILTER_CUTOFF_CONTROL_RATE - 1;
		}
		else {
			mFilterCutoffControlRate--;
		}
	}
	
	// Apply filter
	*Frame = TweakedButterworth_Process( &Voice->Filter, *Frame );
}

void Synth::Generate( float* OutputFrames, unsigned long NumFrames )
{
	SYNCHRONIZED
	
	int NumSimulRealVoices = 0;
	int NumSimulStealVoices = 0;
	int NumSimulActiveVoices = 0;
		
	memset( OutputFrames, 0, NumFrames * ( sizeof(SynSample) + sizeof(SynSample) ) );
	
	unsigned int NewNumActiveVoices = mNumActiveVoices;
	
	float Osc1Vol = GetSetting(Osc1Volume).toFloat();
	float Osc2Vol = GetSetting(Osc2Volume).toFloat();
	bool IsGlideEnabled = GetSetting(GlideEnabled);
	OscillatorType osc1Type = (OscillatorType)GetSetting(Osc1Type).toInt();
	OscillatorType osc2Type = (OscillatorType)GetSetting(Osc2Type).toInt();
	float osc1PulseWidth = GetSetting(Osc1PulseWidth).toFloat();
	float osc2PulseWidth = GetSetting(Osc2PulseWidth).toFloat();

	// Iterate all the voices
	for ( unsigned int j=0; j<NUM_VOICES + NUM_STEAL_VOICES; j++ )
	{
		Voice* Voice = NULL;
		bool IsStealVoice = false;
		if ( j < NUM_VOICES ) {
			Voice = &mVoices[j];
		}
		else {
			Voice = &mStealVoices[j - NUM_VOICES];
			IsStealVoice = true;
		}

		if ( !Voice->Active ) {
			continue;
		}
		
		if (IsStealVoice) NumSimulStealVoices++;
		else NumSimulRealVoices++;
		
		NumSimulActiveVoices++;
				
		// The voice is active, render frames for it
		SynSample *pFrame = OutputFrames;
		for( unsigned long i=0; i<NumFrames; i++ )
		{
			//SynSample Osc1Frame[2], Osc2Frame[2];
			bool PhaseReset = false;
			
			float Freq1;
			float Freq2;
			if (IsGlideEnabled) { 
				Freq1 = Voice->Osc1PitchEnvelope.Next();
				Freq2 = Voice->Osc2PitchEnvelope.Next();
			} else {
				Freq1 = Voice->Osc1Frequency;
				Freq2 = Voice->Osc2Frequency;
			}

			// Render oscillator 1
			SynSample Osc1Sample = RenderOscillatorFrameByType( osc1Type, Freq1, osc1PulseWidth, PhaseReset, &Voice->Osc1Data, &Voice->Osc1WaveData, &Voice->Osc1BlepData );

			if ( !GetSetting( OscillatorSyncEnabled ) ) {
				PhaseReset = 0;
			}
			
			// Render oscillator 2
			SynSample Osc2Sample = RenderOscillatorFrameByType( osc2Type, Freq2, osc2PulseWidth, PhaseReset, &Voice->Osc2Data, &Voice->Osc2WaveData, &Voice->Osc2BlepData );
			
			// Mix the oscillators
			SynSample VoiceSample = Osc1Sample * Osc1Vol + Osc2Sample * Osc2Vol;

			ApplyVoiceEffects( Voice, &VoiceSample, IsStealVoice );
			
			// Update the voice's amplitude envelope. Keep track of voices that have ended.
			float Amp;
			bool VoiceEnded = false;
			if ( j < NUM_VOICES )
			{
				Amp = Voice->AmpEnvelope.Next();
				if ( Voice->AmpEnvelope.IsDone() ) {
					Voice->Active = false;
					NewNumActiveVoices--;
					VoiceEnded = true;
				}
			}
			else
			{
				Amp = Voice->StealEnvelope.Next();
				if ( Voice->StealEnvelope.IsDone() ) {
					Voice->Active = false;
					VoiceEnded = true;
				}
			}
			
			VoiceSample *= Amp;
			
			// Adjust amplitude
			*pFrame += VoiceSample;
			pFrame++;
			*pFrame += VoiceSample;
			pFrame++;
			
			if ( VoiceEnded ) {
				// If this voice is done, no need to continue rendering the rest of the frames
				break;
			}
		}
	}
	
	// remove non-active voices
	if ( NewNumActiveVoices < mNumActiveVoices )
	{
		unsigned int k=0;
		for (unsigned int j=0; j<mNumActiveVoices; j++)
		{
			if ( mVoices[j].Active )
			{
				mVoices[k] = mVoices[j];
				k++;
			}
		}
		mNumActiveVoices = k;
		// make sure all remaining voices are set to non-active
		for ( unsigned int j=k; j<NUM_VOICES; j++ )
		{
			mVoices[j].Active = false;
		}
	}
	
	// Apply filters/effects
	for ( int i = Setting_FirstFilter; i <= Setting_LastFilter; ++i )
	{
		SettingID id = static_cast<SettingID>( i );
		FilterType filter = static_cast<FilterType>( GetSetting( id ).toInt() );
		
		if ( filter != Filter_None )
		{
			ApplyFilter( filter, OutputFrames, NumFrames );
		}
	}
	
	if ( NumSimulRealVoices > mNumSimulRealVoices ) mNumSimulRealVoices = NumSimulRealVoices;
	if ( NumSimulStealVoices > mNumSimulStealVoices ) mNumSimulStealVoices = NumSimulStealVoices;
	if ( NumSimulActiveVoices > mNumSimulActiveVoices ) mNumSimulActiveVoices = NumSimulActiveVoices;
}

void Synth::SetSampleRate( int SampleRate )
{
	SYNCHRONIZED
	mSampleRate = SampleRate;
}

void Synth::SetSetting( SettingID id, SettingVal val )
{
	SYNCHRONIZED
	
	mSettings[id] = val;
	
	// Special case handling for settings is performed here.
	switch ( id )
	{
		case Osc1Type:
			// Need to stop all voices because osc source is changing (for wavetables specifically)
			DestroyAllVoices();
			break;
		case Osc2Type:
			// Need to stop all voices because osc source is changing (for wavetables specifically)
			DestroyAllVoices();
			break;
		case Osc1DetuneSemitones:
		case Osc1DetuneCents:
			mOsc1FreqMult = pow( 2.0f, ( ( GetSetting(Osc1DetuneSemitones).toInt() * 100 ) + GetSetting(Osc1DetuneCents).toFloat() ) / 1200.0f );
			break;
		case Osc2DetuneSemitones:
		case Osc2DetuneCents:
			mOsc2FreqMult = pow( 2.0f, ( ( GetSetting(Osc2DetuneSemitones).toInt() * 100 ) + GetSetting(Osc2DetuneCents).toFloat() ) / 1200.0f );
			break;
		case Osc1WavetablePath:
			{
				if ( mOsc1WavetableBuf ) delete mOsc1WavetableBuf;
				unsigned int WavetableNumChannels;
				ReadWavFile( val.toString().c_str(), &mOsc1WavetableBuf, &mOsc1WavetableNumFrames, &WavetableNumChannels );
				assert( WavetableNumChannels == 1 ); // wavetable oscillators only support mono
			}
			break;
		case Osc2WavetablePath:
			{
				DestroyAllVoices(); // Need to destroy any voices that are currently using the wavetable.  Safest bet is to destroy all.
				if ( mOsc2WavetableBuf ) delete mOsc2WavetableBuf;
				unsigned int WavetableNumChannels;
				ReadWavFile( val.toString().c_str(), &mOsc2WavetableBuf, &mOsc2WavetableNumFrames, &WavetableNumChannels );
				assert( WavetableNumChannels == 1 ); // wavetable oscillators only support mono
			}
			break;
		case DelayEnabled:
			if ( val ) ResetDelayEffect( &mDelayData );
			break;
		case ModDelayEnabled:
			if ( val ) ResetModDelayEffect( &mModDelayData );
			break;
		case DelaySecondsOffset1:
			mDelaySeconds1 = NoteStepToSeconds( (NoteStep)GetSetting(DelayStep1).toInt(), GetSetting(TempoBPM).toFloat() ) + val.toFloat();
			mDelaySeconds1 = clamp( 0.0, mDelaySeconds1, MAX_DELAY_SIZE_SECONDS );
			break;
		case DelaySecondsOffset2:
			mDelaySeconds2 = NoteStepToSeconds( (NoteStep)GetSetting(DelayStep2).toInt(), GetSetting(TempoBPM).toFloat() ) + val.toFloat();
			mDelaySeconds2 = clamp( 0.0, mDelaySeconds2, MAX_DELAY_SIZE_SECONDS );
			break;
		case DelayStep1:
			mDelaySeconds1 = NoteStepToSeconds( (NoteStep)val.toInt(), GetSetting(TempoBPM).toFloat() ) + GetSetting(DelaySecondsOffset1).toFloat();
			mDelaySeconds1 = clamp( 0.0, mDelaySeconds1, MAX_DELAY_SIZE_SECONDS );
			break;
		case DelayStep2:
			mDelaySeconds2 = NoteStepToSeconds( (NoteStep)val.toInt(), GetSetting(TempoBPM).toFloat() ) + GetSetting(DelaySecondsOffset2).toFloat();
			mDelaySeconds2 = clamp( 0.0, mDelaySeconds2, MAX_DELAY_SIZE_SECONDS );
			break;
		case TempoBPM:
			mDelaySeconds1 = NoteStepToSeconds( (NoteStep)GetSetting(DelayStep1).toInt(), GetSetting(TempoBPM).toFloat() ) + GetSetting(DelaySecondsOffset1).toFloat();
			mDelaySeconds2 = NoteStepToSeconds( (NoteStep)GetSetting(DelayStep2).toInt(), GetSetting(TempoBPM).toFloat() ) + GetSetting(DelaySecondsOffset2).toFloat();
			mDelaySeconds1 = clamp( 0.0, mDelaySeconds1, MAX_DELAY_SIZE_SECONDS );
			mDelaySeconds2 = clamp( 0.0, mDelaySeconds2, MAX_DELAY_SIZE_SECONDS );
			break;
		case OctaveEnabled:
			if ( val ) InitOctaveEffect( &mOctaveData );
			break;
		case Resonance:
			static const float Min = sqrt(2.0);
			static const float Max = 0.1;
			float res = (Min - Max) - (Min - Max ) * val.toFloat() + Max;
			res = clamp( Max, res, Min );
			mResonance = res;
			printf("Res = %f\n", res);
			break;
	}
}

const Synth::SettingVal& Synth::GetSetting( Synth::SettingID id )
{
	return mSettings[id];
}

void Synth::AddActiveNote( uint Pitch, float Velocity )
{
	// Check for duplicate notes
	for ( uint i=0; i<mNumActiveNotes; i++ )
	{
		if ( mActiveNotes[i].Pitch == Pitch ) {
			// duplicate note. don't re-add.
			return;
		}
	}
	
	assert( mNumActiveNotes < MAX_ACTIVE_NOTES );
	if ( mNumActiveNotes < MAX_ACTIVE_NOTES ) {
		mActiveNotes[ mNumActiveNotes ].Pitch = Pitch;
		mActiveNotes[ mNumActiveNotes ].Velocity = Velocity;
		mNumActiveNotes++;
	}
}

void Synth::RemoveActiveNote( uint Pitch )
{
	// Remove notes from the list and shift it down
	bool Found = false;
	uint i = 0;
	while ( i < mNumActiveNotes )
	{
		if ( mActiveNotes[i].Pitch == Pitch ) {
			Found = true;
			for ( uint j=i; j<mNumActiveNotes-1; j++ ) {
				mActiveNotes[j] = mActiveNotes[j+1];
			}
			mNumActiveNotes--;
		}
		else {
			i++;
		}
	}
}

const Synth::Note* Synth::GetLatestActiveNote()
{
	if ( mNumActiveNotes > 0 ) {
		return &mActiveNotes[ mNumActiveNotes - 1 ];
	}
	return NULL;
}

void Synth::NoteOn( int Pitch, float Velocity )
{
	//PROFILER_START(NoteOnMutexTime)
	SYNCHRONIZED
	//PROFILER_END(NoteOnMutexTime)

	assert( Pitch > 0 && Pitch < 127 );

	AddActiveNote( Pitch, Velocity );

	if ( GetSetting(MonoEnabled).toBool() )
	{
		if ( mNumActiveVoices > 0 ) {
			StealVoice( 0 );
		}
	}

	// check if note is already being played, if so, steal that voice
	for (unsigned int i=0; i<mNumActiveVoices; i++)
	{
		if( mVoices[i].Active && mVoices[i].Pitch == Pitch )
		{
			StealVoice( i );
			break;
		}
	}

	// check if we are out of voices.  if so, steal the oldest one.
	if ( mNumActiveVoices == NUM_VOICES )
	{
		StealVoice( 0 );
		assert( mNumActiveVoices == NUM_VOICES - 1 );
	}

	float Osc1Frequency = MIDI_TO_FREQ[Pitch] * mOsc1FreqMult;
	float Osc2Frequency = MIDI_TO_FREQ[Pitch] * mOsc2FreqMult;
	
	mVoices[mNumActiveVoices].Pitch = Pitch;
	mVoices[mNumActiveVoices].Osc1Frequency = Osc1Frequency;
	mVoices[mNumActiveVoices].Osc2Frequency = Osc2Frequency;
	mVoices[mNumActiveVoices].Volume = 1.0;
	mVoices[mNumActiveVoices].Active = true;

	// setup pitch envelope for note
	if ( GetSetting(GlideEnabled) ) {
		float StartValue = (mLastPitch != INVALID_PITCH ) ? MIDI_TO_FREQ[mLastPitch] : MIDI_TO_FREQ[Pitch];
		mVoices[mNumActiveVoices].Osc1PitchEnvelope.Init( mSampleRate, GetSetting( GlideTime), StartValue * mOsc1FreqMult, Osc1Frequency );
		mVoices[mNumActiveVoices].Osc1PitchEnvelope.Start();
		mVoices[mNumActiveVoices].Osc2PitchEnvelope.Init( mSampleRate, GetSetting( GlideTime), StartValue * mOsc2FreqMult, Osc2Frequency );
		mVoices[mNumActiveVoices].Osc2PitchEnvelope.Start();
	}
	
	// TODO: Clean this up
	OscillatorType osc1Type = (OscillatorType)GetSetting( Osc1Type ).toInt();
	if ( osc1Type == Wavetable || osc1Type == OneShot )
	{
		assert( mOsc1WavetableBuf != NULL );
		if ( mOsc1WavetableBuf != NULL )
		{
			InitWavetableOsc( &mVoices[mNumActiveVoices].Osc1WaveData, GetSetting(Osc1WavetableFreq).toFloat(), mSampleRate, mOsc1WavetableBuf, mOsc1WavetableNumFrames );
		}
	}
	else if ( osc1Type == BlepSaw )
	{
		InitBlepSawOsc(&mVoices[mNumActiveVoices].Osc1BlepData, mSampleRate);
	}
	else if ( osc1Type == BlepSquare )
	{
		InitBlepSquareOsc(&mVoices[mNumActiveVoices].Osc1BlepData, mSampleRate);
	}
	else
	{
		InitOsc( &mVoices[mNumActiveVoices].Osc1Data, mSampleRate );
	}
	
	OscillatorType osc2Type = (OscillatorType)GetSetting( Osc2Type ).toInt();
	if ( osc2Type == Wavetable || osc2Type == OneShot )
	{
		if ( mOsc2WavetableBuf != NULL )
		{
			InitWavetableOsc( &mVoices[mNumActiveVoices].Osc2WaveData, GetSetting(Osc2WavetableFreq).toFloat(), mSampleRate, mOsc2WavetableBuf, mOsc2WavetableNumFrames );
		}
	}
	else if ( osc2Type == BlepSaw )
	{
		InitBlepSawOsc(&mVoices[mNumActiveVoices].Osc2BlepData, mSampleRate);
	}
	else if ( osc2Type == BlepSquare )
	{
		InitBlepSquareOsc(&mVoices[mNumActiveVoices].Osc2BlepData, mSampleRate);
	}
	else
	{
		InitOsc( &mVoices[mNumActiveVoices].Osc2Data, mSampleRate );
	}
	
	Voice* Voice = &mVoices[mNumActiveVoices];
	float AmpEnvelopePeak = VOICE_VOL * Voice->Volume;
	float AmpSustainValue = AmpEnvelopePeak * GetSetting(Sustain).toFloat();
	Voice->AmpEnvelope.Init(EnvelopeADSR::LINEAR, mSampleRate, GetSetting(Attack).toFloat(), AmpEnvelopePeak, GetSetting(Decay).toFloat(), AmpSustainValue, GetSetting(Release).toFloat());
	Voice->AmpEnvelope.Start();
	float CutoffEnvelopePeak = GetSetting(FilterCutoffEnvelopeAmount).toFloat() /** 5000.0f*/;
	float CutoffSustainValue = CutoffEnvelopePeak * GetSetting(FilterCutoffSustain).toFloat();
	Voice->FilterCutoffEnvelope.Init(EnvelopeADSR::LINEAR, mSampleRate, GetSetting(FilterCutoffAttack).toFloat(), CutoffEnvelopePeak, GetSetting(FilterCutoffDecay).toFloat(), CutoffSustainValue, GetSetting(FilterCutoffRelease).toFloat());
	Voice->FilterCutoffEnvelope.Start();
	//InitMoogVCFFilter( &Voice->Filter, mSampleRate );
	TweakedButterworth_Init(&Voice->Filter, mSampleRate);
	mNumActiveVoices++;
	mLastPitch = Pitch;
	
	EnvBuffCount = 0;
}

void Synth::NoteOff( int Pitch )
{
	assert( Pitch > 0 && Pitch < 127 );

	RemoveActiveNote( Pitch );

	if ( GetSetting(MonoEnabled).toBool() )
	{
		// for mono, if the most recent note is turned off, then play the
		// next most recent note
		const Note* Note = GetLatestActiveNote();
		pthread_mutex_lock(&mMutex);
		bool NoteIsPlaying = false;
		for ( unsigned int i=0; i<mNumActiveVoices && Note != NULL; i++ )
		{
			if ( mVoices[i].Pitch == Note->Pitch ) {
				NoteIsPlaying = true;
				break;
			}
		}
		pthread_mutex_unlock(&mMutex);
		if ( Note != NULL && !NoteIsPlaying ) {
			NoteOn( Note->Pitch, Note->Velocity );
		}
	}

	pthread_mutex_lock(&mMutex);
	for ( unsigned int i=0; i<NUM_VOICES; i++ )
	{
		if ( mVoices[i].Pitch == Pitch )
		{
			mVoices[i].AmpEnvelope.Release();
			mVoices[i].FilterCutoffEnvelope.Release();
		}
	}
	pthread_mutex_unlock(&mMutex);
}

bool Synth::SaveSettings( const char *pPath )
{
	ofstream file( pPath );
	if ( !file ) return false;

	file.precision( 8 );
	
	for ( int i = 0; i < SettingID_Count; ++i )
	{
		SettingID id = (SettingID)i;
		SettingType type = GetSettingType( id );

		file << SettingIDToString( id ) << "=";
		
		if ( IntSetting == type )
		{
			file << GetSetting( id ).toInt();
		}
		else if ( StringSetting == type )
		{
			file << GetSetting( id ).toString();
		}
		else
		{
			file << GetSetting( id ).toFloat();
		}
		
		file << endl;
	}
	
	file.close();

	return true;
}

bool Synth::LoadSettings( const char *pPath )
{
	ifstream file( pPath );
	if ( !file ) return false;

	// parse settings and store values as strings
	map<SettingID, string> settings;
	ParseSettingsFile( file, settings );

	file.close();

	if ( 0 == settings.size() ) return false;

	for ( map<SettingID, string>::iterator it = settings.begin(); it != settings.end(); ++it )
	{
		SettingID id = it->first;
		SettingType type = GetSettingType( id );
		stringstream str( it->second );
		
		if ( IntSetting == type )
		{
			int val;
			str >> val;
			SetSetting( id, val );
		}
		else if ( StringSetting == type )
		{
			SetSetting( id, str.str() );
		}
		else
		{
			float val;
			str >> val;
			SetSetting( id, val );
		}
	}

	return true;
}

void Synth::StealVoice( unsigned int VoiceIndex )
{
	assert( VoiceIndex >= 0 && VoiceIndex < mNumActiveVoices );

	// add to destroyed voices list
	unsigned int i = 0;
	for (i=0; i<NUM_STEAL_VOICES; i++ )
	{
		if ( !mStealVoices[i].Active )
		{
			// Copy the voice
			mStealVoices[i] = mVoices[VoiceIndex];
			// make sure it is set to active
			mStealVoices[i].Active = true;
			// set up fade envelope to start at the voices last envelope value
			mStealVoices[i].StealEnvelope.Init( mSampleRate, STOLEN_VOICE_FADE_TIME, mVoices[VoiceIndex].AmpEnvelope.GetLatestValue(), 0.0 );
			mStealVoices[i].StealEnvelope.Start();
			break;
		}
	}
	// if we hit this, it means that the destroy voice list was full
	// we may want to increase it's size...or not, in which case the voice
	// just gets destroyed immediately (volume goes to zero immediately)
	assert( i != NUM_STEAL_VOICES );

	// remove from active voices list
	for (i=VoiceIndex; i<mNumActiveVoices-1; i++)
	{
		mVoices[i] = mVoices[i+1];
	}
	mVoices[mNumActiveVoices-1].Active = false;
	mNumActiveVoices--;
}

void Synth::DestroyAllVoices()
{
	// NOTE: THIS FUNCTION MUST BE SYNCRONIZED, BUT WE CANNOT SYNCHRONIZE HERE SINCE THIS FUNCTION
	// IS BEING CALLED FROM ANOTHER SYNCHRONIZED FUNCTION

	// destroy active voices voices
	for ( unsigned int i=0; i<NUM_VOICES; i++ )
	{
		mVoices[i].Active = false;
	}
	mNumActiveVoices = 0;

	// destroy stolen voices
	for ( unsigned int i=0; i<NUM_STEAL_VOICES; i++ )
	{
		mStealVoices[i].Active = false;
	}

}

void Synth::ApplyFilter( FilterType filter, SynSample* pOutputFrames, unsigned long numFrames )
{
	switch ( filter )
	{
	case Delay:
		if ( GetSetting(DelayEnabled).toBool() )
		{			
			DelayEffect( GetSetting(DelayBlend), mDelaySeconds1, GetSetting(DelayFeedForward1), GetSetting(DelayFeedBack1),
						mDelaySeconds2, GetSetting(DelayFeedForward2), GetSetting(DelayFeedBack2), pOutputFrames, numFrames, &mDelayData );
		}
		break;
	case ModDelay:
		if ( GetSetting(ModDelayEnabled).toBool() )
		{
			ModDelayEffect(
				GetSetting(ModDelayRate).toFloat(),
				GetSetting(ModDelayMin).toFloat(),
				GetSetting(ModDelayDepth).toFloat(),
				GetSetting(ModDelayBlend).toFloat(),
				GetSetting(ModDelayFF).toFloat(),
				GetSetting(ModDelayFB).toFloat(),
				pOutputFrames,
				numFrames,
				&mModDelayData
			);
		}
		break;
	case Distortion:
		if ( GetSetting(DistortionEnabled).toBool() )
		{
			DistortionEffect( GetSetting(DistortionValue).toFloat(), pOutputFrames, numFrames, &mDistortionData );
		}
		break;
	case Octave:
		if ( GetSetting(OctaveEnabled).toBool() )
		{
			OctaveEffect(
				GetSetting(OctaveHarmonic).toFloat(),
				GetSetting(OctaveSubharmonic).toFloat(),
				GetSetting(OctaveDry).toFloat(),
				pOutputFrames,
				numFrames,
				&mOctaveData
			);
		}
		break;
	}
}

Synth::SettingType Synth::GetSettingType( SettingID id )
{
	if ( id >= Setting_FirstFilter && id <= Setting_LastFilter )
	{
		return IntSetting;
	}
	
	switch ( id )
	{
	case Osc1Type:
	case Osc1DetuneSemitones:
	case Osc2Type:
	case Osc2DetuneSemitones:
	case DelayEnabled:
	case ModDelayEnabled:
	case DistortionEnabled:
	case OctaveEnabled:
	case Cutoff:
	case DelayStep1:
	case DelayStep2:
		return IntSetting;
	case Osc1WavetablePath:
	case Osc2WavetablePath:
		return StringSetting;
	}
	
	return FloatSetting;
}

const char* Synth::SettingIDToString( SettingID id )
{
	uint index = static_cast<uint>( id );
	assert( index < NUM_SETTING_ID_STRINGS );

	return SETTING_ID_STRINGS[index];
}

Synth::SettingID Synth::SettingIDFromString( const char* str )
{
	for ( uint i = 0; i < NUM_SETTING_ID_STRINGS; ++i )
	{
		if ( 0 == strcmp( str, SETTING_ID_STRINGS[i] ) )
		{
			return static_cast<SettingID>( i );
		}
	}

	return Setting_None;
}

void Synth::ParseSettingsFile( std::ifstream& file, std::map< Synth::SettingID, std::string>& settings )
{
	while ( !file.eof() )
	{
		// read next line
		string line;
		getline( file, line );

		// find the key/value separator
		size_t sepPos = line.find_last_of( '=' );
		if ( sepPos == string::npos ) continue;

		// translate key to setting ID
		string key = line.substr( 0, sepPos );
		SettingID id = SettingIDFromString( key.c_str() );
		if ( Setting_None == id ) continue;

		// read the setting value and store as string
		string value = line.substr( sepPos + 1, line.length() - sepPos - 1 );

		if ( value.length() )
		{
			settings.insert( make_pair( id, value ) );
		}
	}
}

void Synth_InitDataTables()
{
	// init midi note to frequency table
	int a = 440; // a is 440 hz...
	for (int x = 0; x < 127; ++x)
	{
	   MIDI_TO_FREQ[x] = (a / 32) * pow( (float)2, ((x - 9) / 12.0f) );
	}
}
