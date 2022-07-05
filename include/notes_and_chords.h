#pragma once
// Deifine all of the music-y constant stuff here

// Only need the first set of notes... octaves just multiply by 2^#oct
// Don't need anything lower... hearing bottoms out at ~20 hz. Can divide if really needed.
#include <vector>

#define C1_NT   32.70
#define Cs1_NT  34.65
#define D1_NT   36.71
#define Ds1_NT  38.89
#define E1_NT   41.20
#define F1_NT   43.65
#define Fs1_NT  46.25
#define G1_NT   49.00
#define Gs1_NT  51.91
#define A1_NT   55.00
#define As1_NT  58.27
#define B1_NT   61.74

extern std::vector<float> note_list;

// Set up scals. Mult some by 2 to go up an octave, if called for.
// MAJOR SCALES
extern std::vector<float> scale_cmaj; 
extern std::vector<float> scale_dmaj;



// MINOR SCALES
extern std::vector<float> scale_dmin;

// Save them a vector of vectors
extern std::vector<std::vector<float>> scales;

// And also save the names of the scales.
extern const char * scale_names[3];
