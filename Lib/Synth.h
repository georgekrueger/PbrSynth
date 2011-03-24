
#include <string>
#include <fstream>
#include <map>
#include <pthread.h>

#include "EnvelopeADSR.h"
#include "EnvelopeSimple.h"
#include "Arpeggiator.h"
#include "oscillators.h"
#include "filters.h"
#include "effects.h"

class Synth : public ArpeggiatorListener
{
public:
	// When adding new settings, don't forget to update SETTING_ID_STRINGS and GetSettingType if the
	// setting value is not a float.
	enum SettingID {
		GlobalVolume = 0,

		TempoBPM,
		
		// ADSR
		Attack,
		Decay,
		Sustain,
		Release,
		
		// oscillator 1
		Osc1Type,
		Osc1Volume,
		Osc1DetuneSemitones,
		Osc1DetuneCents,
		Osc1PulseWidth,
		Osc1WavetablePath,
		Osc1WavetableFreq,
		
		// oscillator 2
		Osc2Type,
		Osc2Volume,
		Osc2DetuneSemitones,
		Osc2DetuneCents,
		Osc2FreqMult,
		Osc2PulseWidth,
		Osc2WavetablePath,
		Osc2WavetableFreq,
		
		// filter
		Cutoff,
		CutoffLFOFreq,
		CutoffLFORange,
		Resonance,

		// filter cutoff ADSR
		FilterCutoffEnvelopeAmount,
		FilterCutoffAttack,
		FilterCutoffDecay,
		FilterCutoffSustain,
		FilterCutoffRelease,
		
		// delay
		DelayEnabled,
		DelayBlend,
		DelayStep1,
		DelaySecondsOffset1,
		DelayFeedForward1,
		DelayFeedBack1,
		DelayStep2,
		DelaySecondsOffset2,
		DelayFeedForward2,
		DelayFeedBack2,
		
		// modulated delay
		ModDelayEnabled,
		ModDelayRate,
		ModDelayMin,
		ModDelayDepth,
		ModDelayBlend,
		ModDelayFF,
		ModDelayFB,
		
		// Distortion
		DistortionEnabled,
		DistortionValue,
		
		// Octave
		OctaveEnabled,
		OctaveHarmonic,
		OctaveSubharmonic,
		OctaveDry,
		
		// filters/effects
		Setting_FirstFilter,
		Filter1 = Setting_FirstFilter,
		Filter2,
		Filter3,
		Filter4,
		Filter5,
		Filter6,
		Filter7,
		Filter8,
		Filter9,
		Filter10,
		Setting_LastFilter = Filter10,

		// Oscillator Sync
		OscillatorSyncEnabled,

		MonoEnabled,

		GlideEnabled,
		GlideTime,

		SettingsEnd,
		Setting_None = 0xFFFFFFFF
	};
	static const int SettingID_Count = SettingsEnd;
	
	enum OscillatorType {
		Sine = 1,
		Pulse,
		Saw,
		Triangle,
		WhiteNoise,
		Wavetable,
		OneShot,
		BlepSaw,
		BlepSquare
	};
	
	enum FilterType {
		Filter_None,
		Filter_First,
		Delay = Filter_First,
		ModDelay,
		Distortion,
		Octave,
		Filter_Last = Octave
	};
	static const int FilterType_Count = Filter_Last - Filter_First + 1;
	
	class SettingVal
	{
	public:
		SettingVal() throw() : mI(0) {}
		SettingVal(int i) throw() : mI(i) {}
		SettingVal(bool b) throw() : mI(b) {}
		SettingVal(float f) throw() : mF(f) {}
		SettingVal(const std::string& s) : mS(s), mI(0) {}
		
		int toInt() const throw() { return mI; }
		bool toBool() const throw() { return mI != 0; }
		float toFloat() const throw() { return mF; }
		std::string toString() const throw() { return mS; }
		
		operator int() const throw() { return mI; }
		operator bool() const throw() { return mI != 0; }
		operator float() const throw() { return mF; }
		
		SettingVal& operator=(int i) throw() { mI = i; return *this; }
		SettingVal& operator=(bool b) throw() { mI = b; return *this; }
		SettingVal& operator=(float f) throw() { mF = f; return *this; }
		
	private:
		union {
			int mI;
			float mF;
		};
		std::string mS;
	};
	
	Synth();
	virtual ~Synth();

	void	Generate( float* OutputFrames, unsigned long NumFrames );

	void	SetSampleRate( int SampleRate );

	void	SetSetting( SettingID id, SettingVal val );
	const SettingVal& GetSetting( SettingID id );
	
	void	NoteOn( int Pitch, float Velocity );
	void	NoteOff( int Pitch );
	
	bool	SaveSettings( const char *pPath );
	bool	LoadSettings( const char *pPath );

private:
	enum SettingType
	{
		FloatSetting,
		IntSetting,
		StringSetting
	};

	typedef struct
	{
		bool Active;
		int Pitch;
		float Osc1Frequency;
		float Osc2Frequency;
		float Volume;

		//MoogVCFFilterData Filter;
		TweakedButterworthFilter Filter;
		
		union
		{
			OscData Osc1Data;
			WavetableOscData Osc1WaveData;
			BlepOscData Osc1BlepData;
		};

		union
		{
			OscData Osc2Data;
			WavetableOscData Osc2WaveData;
			BlepOscData Osc2BlepData;
		};

		EnvelopeADSR        AmpEnvelope;
		EnvelopeADSR        FilterCutoffEnvelope;
		EnvelopeSimple      Osc1PitchEnvelope;
		EnvelopeSimple      Osc2PitchEnvelope;
		EnvelopeSimple      StealEnvelope;

	} Voice;

	struct Note
	{
		int   Pitch;
		float Velocity;
	};

	static const unsigned int NUM_VOICES = 4;
	static const unsigned int NUM_STEAL_VOICES = 3;
	static const uint MAX_ACTIVE_NOTES = 10;
	static const int INVALID_PITCH = -1;
	static const float VOICE_VOL;
	static const char* SETTING_ID_STRINGS[];
	static const uint NUM_SETTING_ID_STRINGS;
	static const uint FILTER_CUTOFF_CONTROL_RATE = 1;
	
	void StealVoice( unsigned int VoiceIndex );
	void DestroyAllVoices();
	void ApplyFilter( FilterType filter, SynSample* pOutputFrames, unsigned long numFrames );
	void ApplyVoiceEffects( Voice* Voice, SynSample* Frame, bool IsStealVoice );
	SettingType GetSettingType( SettingID id );
	const char* SettingIDToString( SettingID id );
	SettingID SettingIDFromString( const char* str );
	void ParseSettingsFile( std::ifstream& file, std::map<SettingID, std::string>& settings );

	void AddActiveNote( uint Pitch, float Velocity );
	void RemoveActiveNote( uint Pitch );
	const Note* GetLatestActiveNote();

	unsigned int		mSampleRate;

	Voice               mVoices[ NUM_VOICES ];
	uint                mNumActiveVoices;

	Voice               mStealVoices[ NUM_STEAL_VOICES ];
	
	Note                mActiveNotes[ MAX_ACTIVE_NOTES ];
	uint                mNumActiveNotes;

	int                 mLastPitch;
	
	SettingVal          mSettings[ SettingID_Count ];
	
	float				mOsc1FreqMult;
	SynSample*			mOsc1WavetableBuf;
	unsigned int		mOsc1WavetableNumFrames;
	
	float				mOsc2FreqMult;
	SynSample*			mOsc2WavetableBuf;
	unsigned int		mOsc2WavetableNumFrames;
	
	OscData				mCutoffLFOData;
	DelayEffectData		mDelayData;
	ModDelayEffectData	mModDelayData;
	DistortionData      mDistortionData;
	OctaveEffectData	mOctaveData;

	float               mDelaySeconds1;
	float               mDelaySeconds2;
	
	int                 mNumSimulActiveVoices;
	int                 mNumSimulRealVoices;
	int                 mNumSimulStealVoices;
	
	float               mResonance; // sqrt(2) to 0.1
	
	uint                mFilterCutoffControlRate;
	
	pthread_mutex_t     mMutex;
};
