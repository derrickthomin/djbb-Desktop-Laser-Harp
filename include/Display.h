#pragma once

#include <Arduino.h>
#include <string>
#include <vector>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "notes_and_chords.h"

/////////////////////////////////////////////////////////////
#define SCREEN_WIDTH    128 // OLED display width, in pixels
#define SCREEN_HEIGHT   64 // OLED display height, in pixels
#define OLED_RESET      -1  
#define SCREEN_ADDRESS  0x3C 
extern Adafruit_SSD1306 display;

// Vars
extern bool          update_display;
extern const int     framerate;
extern const int     frame_ms;
extern const bool    skip_startup;
extern const uint8_t note_circ_xpos[8];

// Track screen indicies
extern int8_t        cur_screen_idx;            // Overall screen
extern uint_fast8_t  num_screens;               // djt need this now?...
extern uint8_t       cur_screen2_idx;          // What setting are we on on the sound sel screen??
extern uint8_t       cur_screen3_idx;          // What setting are we on on the sound sel screen??
extern uint8_t       cur_screen4_idx;          // What setting are we on on the sound sel screen??
extern uint8_t       cur_screen5_idx;          // What setting are we on on the sound sel screen??

// Screen setup
extern const std::vector<std::string> screen_play;
extern const std::vector<std::string> screen_sound_select;
extern const std::vector<std::string> screen_verb_lvl;  
extern const std::vector<std::string> screen_theremin;         // Theremin Mode Screens
extern const std::vector<std::string> screen_playmode;         // Play mode screens
extern const std::vector<std::vector<std::string>> screens;

// Screen Functions
void initDisplay(void);
void next_screen(bool upOrDown = true);        // Pass true to go to next screen. False to go back.
void startup_screen(bool skip_startup=false);  // Play fun animation
void z_test_wavy_line(void);
void update_screen(void);                      // Main screen update function. Called from main loop.
void update_play_screen(void);                 // Draw circles on the screen for notes and such
void update_sound_sel_screen(void);            // Update the screen if the user picks a new sound
void update_rev_screen(void);                  // Update reverb screen
void update_scale_screen(void);                // Add a quick scale indicator.
void update_theremin_screen(void);             // Update theremin screen
void update_playmode_screen(void);             // Update playmode