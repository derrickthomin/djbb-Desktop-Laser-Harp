// Use this to collect sensor data.
#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include "AudioSetup.h"
#include <list>
#include <vector>
#include <Bounce2.h>

#include "inputs.h"
#include "Display.h"
#include "AudioSetup.h"


// - - - - - - - - - - - - - - - - -  //
//          Hardware Setup            //
// - - - - - - - - - - - - - - - - -  //

// Laser Sensors
#define SENS_1      2
#define SENS_2      3
#define SENS_3      4
#define SENS_4      5
#define SENS_5      6
#define SENS_6      0     
#define SENS_7      1     
#define SENS_8      9

// Pot / Theremin (theremin - analog input on laser sensor #8)
#define VOL         14
#define THEREMIN    15

// Control Buttons (vertical ones)
#define BTN_WC      12
#define BTN_OCTDOWN 11
#define BTN_OCTUP   10

// Screen Nav Buttons (Under the screen)
#define NAV_L       17
#define NAV_R       16 
#define NAV_ENTER   22

// Volume related globals
int             pot_vol      = 0; 
uint16_t        theremin_val = 0;
int             pot_vol_prev = 0;
const uint8_t   pot_thresh   = 2;      // How much does the pot analog value need to change to count
float           velocity     = 1;

// Debounce Settings
const uint8_t   debounce_ms  = 10;

// Bounce objects for btns
Bounce bounce_btn_wc             = Bounce();
Bounce bounce_btn_octdown        = Bounce();
Bounce bounce_btn_octup          = Bounce();
Bounce bounce_btn_nav_l          = Bounce();
Bounce bounce_btn_nav_r          = Bounce();
Bounce bounce_btn_nav_enter      = Bounce();

// Put them in lists
std::list<int> nav_btn_list      = {NAV_L, NAV_R, NAV_ENTER};
std::list<int> oct_btn_list      = {BTN_WC, BTN_OCTDOWN, BTN_OCTUP};                

// Sensor Tracking
std::vector<int> sensor_list     = {SENS_1, SENS_2, SENS_3, SENS_4, SENS_5, SENS_6, SENS_7, SENS_8};      // DJT - update later
std::vector<bool> prev_sens_vals = {false, false, false, false, false, false, false, false};
std::vector<bool> cur_sens_vals  = {false, false, false, false, false, false, false, false};
std::vector<bool> new_notes      = {false, false, false, false, false, false, false, false};             // Tells the main loop whether or not to play a note
std::vector<bool> off_notes      = {false, false, false, false, false, false, false, false};             // Tells the main loop to turn off a note
std::vector<double> sens_ontime  = {0,0,0,0,0,0,0,0};
std::vector<double> sens_st_time = {0,0,0,0,0,0,0,0};


// Updates sensor vals, and returns true if anything changed. Also updates screen
bool get_new_notes(void)
{

  bool has_changed_any = false;                               // Track if ANYTHIING changed
  update_display = false;                                    // do we need to update the screen?
  uint8_t sens_ary_size = sensor_list.size();

  // Init things here
  for (int idx = 0; idx < sens_ary_size; idx++)
  {
    new_notes[idx] = false;
    off_notes[idx] = false;
  }

  if (theremin_idx > 0) sens_ary_size = sensor_list.size()-1;                // Theremin mode is on.. ignore snesor 8 from the getgo

  for (int idx = 0; idx < sens_ary_size; idx++)
  {
    pot_vol = analogRead(VOL);
    theremin_val = analogRead(THEREMIN);
    bool sensor_val = digitalRead(sensor_list[idx]);
    bool has_changed = (sensor_val != (prev_sens_vals[idx]));

    // Initialize a few things
    prev_sens_vals[idx] = sensor_val;                          // already checked for a change, do this now, might as well!

    if (has_changed)
    {
      has_changed_any    = true;
      update_display     = true;
      cur_sens_vals[idx] = sensor_val;                         // update tracking array djt might not need this at all... usiung newnotes ary
      if (sensor_val)                                          // new note on, initialize time tracking
      {
        if (sound_idx == 2)
        {
          new_notes[idx] = true;                               // Synth sound works differently... start playing when laser is broken.
        }
        else
        {        
          sens_st_time[idx] = millis();                        // Start counting how long the laser has been broken
          sens_ontime[idx] = 0;
        }

      }
      else
      {
        if (!(sound_idx == 2)) new_notes[idx] = true;       // Play a new note when the laser is broken.. bur not for synth sound
      }
    } 
    
    // If we are here, the sensor val is the same as before
    else 
    {
      if (sensor_val)
      {
          sens_ontime[idx] = (millis() - sens_st_time[idx]);         // On before, on now. Update the hold time.
          if (cur_screen_idx == 0) update_display = true;            // Only update this often if on play screen
          if (cur_screen5_idx > 0) update_playmode_hits(idx);        // Get new notes, etc. if we are on a fancy play mode

      } else {
          //off_notes[idx] = true;
          sens_ontime[idx] = 0;                                      // On before, off now. Reset time counter
          if (sound_idx == 2)
          {
            off_notes[idx] = true;                                   // Go to release phase if pad sound
          }

          if (cur_screen5_idx > 0) update_playmode_hits(idx, true);  // Reset playmode stuff
      }
    }
  
  }
  if (theremin_idx > 0)
  {
    new_notes[7] = false; 
  }
  if (update_display);       //DJT - maybe update scren here.
  return (has_changed_any);
}

// Function to check if the pot changed
bool pot_changed(void){

  pot_vol = analogRead(VOL);
  if (abs(pot_vol - pot_vol_prev) > pot_thresh){
    pot_vol_prev = pot_vol;
    return true;
  } else {
    return false;  
  }
}

// Check for new button presses
void check_buttons(void){
  
  bounce_btn_wc.update();
  bounce_btn_octdown.update();
  bounce_btn_octup.update();
  bounce_btn_nav_l.update();
  bounce_btn_nav_r.update();
  bounce_btn_nav_enter.update();
  return;
}

// Do stuff if a button was pressed. Return true if the screen needs an update.
void process_buttons(void){
  bool wc       = bounce_btn_wc.fell();             // Just doing this to keep below cleaner
  bool oct_down = bounce_btn_octdown.fell();
  bool oct_up   = bounce_btn_octup.fell();
  bool nav_l    = bounce_btn_nav_l.fell();
  bool nav_r    = bounce_btn_nav_r.fell();
  bool nav_sel  = bounce_btn_nav_enter.fell();

  // WC   - Bottom Right (under oct)
  if (wc)
  {
    chg_scale();
    update_scale_screen();
  }

  // OCT UP  BUTTON WAS PRESSED.. DO THIS
  if (oct_up)
  {
    octave_current += 1; 
  }
  
  // OCT DOWN BUTTON WAS PRESSED... DO THIS
  if (oct_down)
  {
    octave_current -= 1; 
  }

  if (nav_l)
  {
    next_screen(false);                
    update_display = true;
  }

  if (nav_r)
  {
    next_screen(true);  
    update_display = true;
  }

  // ENTER/SEL  - Under menu, rightmost
  if (nav_sel)
  {
    switch(cur_screen_idx)
      {
        case 1:     // Chg Sound Screen
          chg_sound(true);                 // true == increase (lowest idx is top option, so increase to go down)
          update_display = true;
          break;

        case 2:     // Reverb Screen
          chg_rev_time(true);         
          update_display = true;
          break;

        case 3:     // Theremin Screen
          chg_theremin_mode(true);         // djt - FOR TESTING - Skip theremin mode
          update_display = true;
          break;

        case 4:     // Playmode Screen
          chg_playmode(true);         // djt - FOR TESTING - Skip theremin mode
          update_display = true;
          break;
      }
  }
}

void initInputs(void)
{
  // Set up Pins and buttons
  pinMode(SENS_1, INPUT);
  pinMode(SENS_2, INPUT);
  pinMode(SENS_3, INPUT);
  pinMode(SENS_4, INPUT);
  // pinMode(SENS_5, INPUT);
  // pinMode(SENS_6, INPUT);  BROKEN - And needs assigned new pin. See above
  // pinMode(SENS_7, INPUT);  BROKEN - need to replace the sensor
  pinMode(SENS_8, INPUT);

  // Pots and stuff
  pinMode(VOL, INPUT);
  pinMode(THEREMIN, INPUT);

  // Assign input pins to debounce instances with a certain debounce time
  bounce_btn_wc.attach(BTN_WC, INPUT_PULLUP);
  bounce_btn_wc.interval(debounce_ms);

  bounce_btn_octdown.attach(BTN_OCTDOWN, INPUT_PULLUP);
  bounce_btn_octdown.interval(debounce_ms);

  bounce_btn_octup.attach(BTN_OCTUP, INPUT_PULLUP);
  bounce_btn_octup.interval(debounce_ms);

  bounce_btn_nav_l.attach(NAV_L, INPUT_PULLUP);
  bounce_btn_nav_l.interval(debounce_ms);

  bounce_btn_nav_r.attach(NAV_R, INPUT_PULLUP);
  bounce_btn_nav_r.interval(debounce_ms);

  bounce_btn_nav_enter.attach(NAV_ENTER, INPUT_PULLUP);
  bounce_btn_nav_enter.interval(debounce_ms);
}