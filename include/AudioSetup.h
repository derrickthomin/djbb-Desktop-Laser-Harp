#pragma once

#include <Arduino.h>
#include <vector>
#include <Audio.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>


// limit maximum timing for parameters set by pots
#define attackMax          2000
#define decayMax           2000
#define releaseMax         2000
#define releaseMin         200                      // avoid clicks

// Tracking Globals            
extern int8_t scale_idx;   
extern int8_t sound_idx;
extern uint8_t   env_idx; 
extern int8_t octave_current;
extern int8_t rev_lvl_idx;                          // Track reverb setting (Off, Lo, Med, Hi)
extern int8_t theremin_idx;
extern int8_t playmode_idx;
extern int reverb_time;
extern bool      theremin_calibrated;
extern std::vector<float> current_notes;

// Default ADSR param settings.
extern int   attackParam;          
extern int   decayParam;           
extern float sustainParam;        
extern int   releaseParam;        
extern uint8_t   envidxadd;

// Pointer Arrays - Do this instead of global extern vars. 
// Audio tool stuff is all in the cpp file.. everything else can use these pointers.
extern const char               *scale_names[];
extern AudioSynthKarplusStrong  *string[8];
extern AudioSynthSimpleDrum     *drum[8];
extern AudioSynthWaveform       *waveform[8];
extern AudioEffectEnvelope      *envelope[24];

// Theremin stuff
extern   int16_t therValMax;
extern   int16_t therValMin;
extern   float ther_a;
extern   float ther_b;

//<><><><><><><><><><><><><><><><<><><>
//                                   //
//                                   //
//        F U N C T I O N S          //
//                                   //
//                                   //
//<><><><><><><><><><><><><><><><><>><>

/**
 * Initialize teensy audio lib stuff. 
 */
void initAudio(void);

/**
 * Set up initial waveforms. 
 */
void init_waveforms(void);

/**
 * Change value of global var scale_idx;
 */
void chg_scale(void);

/**
 * Change value of global var sound_idx;
 */
void chg_sound(bool changeSound=true);

/**
 * Change value of global reverb_time val;
 */
void chg_rev_time(bool upOrDown);

/**
 * Change theremin behavior;
 */
void chg_theremin_mode(bool upOrDown, bool skipCalibration = false);

/**
 * initialize constant env values based on sound index.
 */
void init_envelope(void);

/**
 * Upate envelope based on cur sound and sound idx
 * Parameters:
 *      idx = which envelope idx to update
 */
bool update_envelope(uint8_t idx, uint8_t env_idx);


// Funtion to update volume
void update_volume(void);

// Function to calibrate theremin. Find min and max raw sensor values.
void run_theremin_calibration(bool skipCalibration = false);

// Update fx / pitch / vol based on theremin value
void update_theremin_fx(void);

void chg_playmode(bool upOrDown=true);

void update_playmode_hits(int idx, bool init = false);