/*
 *  wavfile.c
 *  synth
 *
 *  WAV format reference:
 *  https://ccrma.stanford.edu/courses/422/projects/WaveFormat
 *  http://www-mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/WAVE.html
 *
 *  Created by Judah Menter on 1/6/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "wavfile.h"

#define WAVE_FORMAT_PCM			(0x01)
#define WAVE_FORMAT_FLOAT		(0x03)

static const char riffChunk[] = {
	0x52, 0x49, 0x46, 0x46,		/* ChunkID ("RIFF") */
	0, 0, 0, 0,					/* ChunkSize */
	0x57, 0x41, 0x56, 0x45,		/* Format ("WAVE") */
	0x66, 0x6d, 0x74, 0x20,		/* SubChunk1ID ("fmt ") */
	0x10, 0, 0, 0				/* SubChunk1Size */
};

static const char dataSubChunk[] = {
	0x64, 0x61, 0x74, 0x61,		/* SubChunk1ID ("data") */
	0, 0, 0, 0					/* SubChunk2Size */
};

static const long riffChunkSizeOffset = 4;
static const long dataSubChunkSizeOffset = 40;

int ReadWavFile(const char *path, SynSample **buffer, unsigned int *numFrames, unsigned int *numChannels )
{
	char tag[4];
	unsigned int sz, bufSize, bytesRead;
	FILE *file;
	unsigned short sampleFormat, numChan, blockAlign, bitsPerSample;
	unsigned int sampleRate, byteRate;
	SynSample *p;
	short shortSample;
	
	*buffer = NULL;
	*numFrames = 0;
	file = fopen(path, "rb");
	if (!file) return -1;
	
	/* RIFF chunk */
	fread(tag, 4, 1, file);
	if ( memcmp(tag, "RIFF", 4) ) return -1;
	assert( 0 == fseek(file, 4, SEEK_CUR) );

	fread(tag, 4, 1, file);
	if (memcmp(tag, "WAVE", 4)) return -1;
	
	fread(tag, 4, 1, file);
	while (memcmp(tag, "fmt ", 4)) {
		if (1 != fread(&sz, 4, 1, file)) return -1;
		fseek(file, sz, SEEK_CUR);
		if (1 != fread(tag, 4, 1, file)) return -1;
	}
	
	/* format subchunk */
	fread(&sz, 4, 1, file);
	fread(&sampleFormat, 2, 1, file);
	fread(&numChan, 2, 1, file);
	fread(&sampleRate, 4, 1, file);
	fread(&byteRate, 4, 1, file);
	fread(&blockAlign, 2, 1, file);
	fread(&bitsPerSample, 2, 1, file);
	
	if (sz > 16) {
		fseek(file, sz - 20, SEEK_CUR);
	}
	
	fread(tag, 4, 1, file);
	if (memcmp(tag, "data", 4)) return -1;
	
	/* data subchunk */
	fread(&sz, 4, 1, file);
	if (!sz) return -1;
	bufSize = sz * sizeof(SynSample) / (bitsPerSample >> 3);
	*buffer = (SynSample*)malloc(bufSize);
	
	p = *buffer;
	bytesRead = 0;
	if (WAVE_FORMAT_PCM == sampleFormat) {
		if (16 == bitsPerSample) {
			while (bytesRead < sz) {
				if ( 1 != fread(&shortSample, 2, 1, file) ) return -1;
				*p++ = SHORT_TO_SYNSAMPLE(shortSample);
				bytesRead += 2;
			}
			*numFrames = (sz >> 1) / numChan;
			*numChannels = numChan;
		}
		else {
			/* unsupported sample size */
			assert( 0 );
		}
	}
	else {
		/* unsupported sample format */
		assert( 0 );
	}
	
	return 0;
}

int WriteWavHeader(FILE *file, int sampleRate)
{
	short sampleFormat = WAVE_FORMAT_FLOAT;
	short numChannels = 2;
	int byteRate = 2 * sampleRate * sizeof(SynSample);
	short blockAlign = 2 * sizeof(SynSample);
	short bitsPerSample = sizeof(SynSample) << 3;
	
	fwrite(riffChunk, sizeof(riffChunk), 1, file);
	fwrite(&sampleFormat, 2, 1, file);
	fwrite(&numChannels, 2, 1, file);
	fwrite(&sampleRate, 4, 1, file);
	fwrite(&byteRate, 4, 1, file);
	fwrite(&blockAlign, 2, 1, file);
	fwrite(&bitsPerSample, 2, 1, file);
	fwrite(dataSubChunk, sizeof(dataSubChunk), 1, file);
	
	return 0;
}

int WriteWavDataSize(FILE *file, unsigned int numBytes)
{
	int chunkSize = numBytes + 36;
	
	fseek(file, riffChunkSizeOffset, SEEK_SET);
	fwrite(&chunkSize, 4, 1, file);
	
	fseek(file, dataSubChunkSizeOffset, SEEK_SET);
	fwrite(&numBytes, 4, 1, file);
	
	return 0;
}
