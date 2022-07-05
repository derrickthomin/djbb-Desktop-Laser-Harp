#pragma once

#include <Arduino.h>
#include <list>
#include <vector>
#include <Bounce2.h>

// Volume Pot
extern int   pot_vol; 
extern uint16_t theremin_val;
extern int   pot_vol_pre;
extern float velocity;

extern const uint8_t pot_thresh;
extern const uint8_t debounce_ms;

#define SENS_1 2
#define SENS_2 3
#define SENS_3 4
#define SENS_4 5
// #define SENS_5 6
// #define SENS_6 7     BROKEN - need to replace. Also need to solder to new pin.., need 7 for shield
// #define SENS_7 8     BROKN - replace 
#define SENS_8 9

// Pots / Theremin
#define VOL 14
#define THEREMIN 15

// Control Buttons
#define BTN_WC 12
#define BTN_OCTDOWN 11
#define BTN_OCTUP 10

// Screen Nav Buttons
#define NAV_L 23
#define NAV_R 21
#define NAV_ENTER 22

// Bounce objects for btns
extern Bounce bounce_btn_wc;
extern Bounce bounce_btn_octdown;
extern Bounce bounce_btn_octup;
extern Bounce bounce_btn_nav_l;
extern Bounce bounce_btn_nav_r;
extern Bounce bounce_btn_nav_enter;

// Put them in lists
extern std::list<int> nav_btn_list;
extern std::list<int> oct_btn_list;               

// Sensor Tracking
extern std::vector<int> sensor_list;     
extern std::vector<bool> prev_sens_vals;
extern std::vector<bool> cur_sens_vals;
extern std::vector<bool> new_notes;
extern std::vector<bool> off_notes;
extern std::vector<double> sens_ontime;
extern std::vector<double> sens_st_time;

bool get_new_notes(void);
bool pot_changed(void);
void process_buttons (void);              // Check for new button vals, returns true if screen needs an update
void check_buttons(void);
void initInputs(void);