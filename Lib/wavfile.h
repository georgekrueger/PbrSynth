/*
 *  wavfile.h
 *  synth
 *
 *  Created by Judah Menter on 1/6/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef WAVFILE_H
#define WAVFILE_H

#include <stdio.h>
#include "synglobal.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Allocates a stereo sample buffer and reads a wav file into it.
 * @param path The wav file path.
 * @param buffer Buffer pointer to point at the read sample data.
 * @param numFrames Value to hold the number of stereo frames read.
 */
int ReadWavFile(const char *path, SynSample **buffer, unsigned int *numFrames, unsigned int *numChannels);

/**
 * Writes a wav file header to a file.
 * @param file The file to write to.
 * @param sampleRate The sample rate of the audio data.
 */
int WriteWavHeader(FILE *file, int sampleRate);

/**
 * Completes a wav file by writing the data size to the header.
 * @param file The file to write to.
 * @param numBytes The size of the audio data in bytes.
 */
int WriteWavDataSize(FILE *file, unsigned int numBytes);

#ifdef __cplusplus
}
#endif

#endif  /* WAVFILE_H */
