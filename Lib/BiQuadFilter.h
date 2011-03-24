
#include "synglobal.h"

/* this holds the data required to update samples thru a filter */
typedef struct {
    SynSample a0, a1, a2, a3, a4;
    SynSample x1, x2, y1, y2;
} BiQuad;

/* filter types */
enum {
    LPF, /* low pass filter */
    HPF, /* High pass filter */
    BPF, /* band pass filter */
    NOTCH, /* Notch Filter */
    PEQ, /* Peaking band EQ filter */
    LSH, /* Low shelf filter */
    HSH /* High shelf filter */
};

void      BiQuad_Init(int type, SynSample dbGain, SynSample freq, SynSample srate, SynSample bandwidth, BiQuad* b);
SynSample BiQuad_Process(SynSample sample, BiQuad * b);
