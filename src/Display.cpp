#include <Arduino.h>
#include <string>
#include <string>
#include <vector>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "bitmaps.h"
#include "notes_and_chords.h"
#include "Display.h"
#include "AudioSetup.h"
#include "inputs.h"
#include "util.h"

bool                 update_display  = true;                // Flag to tell us we need to update the display
const int            framerate       = 20;                  // FPS for splash screen, maybe other things later
const int            frame_ms        = 1000 / framerate;    // ms per frame
const bool           skip_startup    = false;               // Skip intro splash screen for testing
int8_t               cur_screen_idx  = 0;                   // Track screen index
uint_fast8_t         num_screens     = 3;                   // Number of screens max
uint8_t       cur_screen2_idx = 0;                   // Track screen 2 idx (sound sel)
uint8_t       cur_screen3_idx = 0;                   // Track screen 3 idx (FX sel)
uint8_t       cur_screen4_idx = 0;                   // Track screen 4 (therein mode)
uint8_t       cur_screen5_idx = 0;                   // Track screen 5 (Playmodes)

const uint8_t note_circ_xpos[8]       = {10, 25, 40, 56, 72, 87, 102, 118}; 

// Screen tracking
const std::vector<std::string> screen_play         = {"PLAY"};
const std::vector<std::string> screen_sound_select = {"Harp", "Drums", "Synth"};
const std::vector<std::string> screen_verb_lvl     = {"off", "Low", "Med", "High"};
const std::vector<std::string> screen_theremin     = {"off", "Volume", "Filter", "Reverb"};  
const std::vector<std::string> screen_playmode     = {"Standard", "Tremelo", "Arpish"};

const std::vector<std::vector<std::string>> screens = {screen_play, screen_sound_select, screen_verb_lvl, screen_theremin, screen_playmode};     // Houses all of the screens
    

// Screen setup
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const unsigned char * splash_frames [13]= {
  animation1, animation2, animation3, animation4,
  animation5, animation6, animation7, animation8,
  animation9, animation10, animation11, animation12,
  animation13
};

// Update screen if needed depending on what screen we on. Called from main loop.
void update_screen(void){

  // do nothing 
  if (!update_display)return;                

  // Do something different based on screen
  switch (cur_screen_idx)
  {
  case  0:  // 1. Play Screen
    update_play_screen();
    break;
  
  case 1:   // 2. Sound Select Screen
    update_sound_sel_screen();
    break;

  case 2:   // 3. Reverb Screen
    update_rev_screen();
    break;
  
  case 3:   // 3. Reverb Screen
    update_theremin_screen();
    break;
  
  case 4:   // 4. Playmode Screen 
    update_playmode_screen();
    break;

  }
  // Don't update until we tell you to again   
  update_display = false;    
}

// Init the screen, call the startup function
void initDisplay(void){
    
    // IDK some safety thing
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
  
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.clearDisplay();
    startup_screen(skip_startup);
    display.display();
    delay(50);

}

// Advance and disp the next screen 
void next_screen(bool upOrDown = true)
{

  util_chg_index(upOrDown, cur_screen_idx, (screens.size()-1));

   // Display the new screen based on idx;
   display.clearDisplay();
   switch (cur_screen_idx)
   {
    
      // 1. Play Screen init
      case 0:
        display.drawRoundRect(0,0,SCREEN_WIDTH,16,10,WHITE);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(42, 5);
        display.println("P L A Y");
        break;

      // 2. Sound Select Screen init 
      case 1:
        display.drawRoundRect(0,0,SCREEN_WIDTH,16,10,WHITE);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(24, 5);
        display.println("Select Sound");
        break;

      // 3. FX Screen init 
      case 2:
        display.drawRoundRect(0,0,SCREEN_WIDTH,16,10,WHITE);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(25, 5);
        display.println("Reverb Level");
        break;
      
      // 4. Theremin mode screen init 
      case 3:
        display.drawRoundRect(0,0,SCREEN_WIDTH,16,10,WHITE);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(25, 5);
        display.println("Theremin Mode");
        break;
      
      // 5. Play mode screen init
      case 4:
        display.drawRoundRect(0,0,SCREEN_WIDTH,16,10,WHITE);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(25, 5);
        display.println("Play Modes");
        break;
      
   }
   display.display();
};

// Displays the startup splash bitmap screens
void startup_screen(bool skip_startup=false)
{
  if (skip_startup) return;

  for (int i=0; i < 13; i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, splash_frames[i], display.width(), display.height(), 1);
    display.display();
    delay(frame_ms);
    
  }
  
  for (int i = 0; i < 10; i++) {
    display.clearDisplay();
    display.drawBitmap(0, 0, animation1, display.width(), display.height(), 1);
    display.display();
    delay(frame_ms/(i+1));

    display.clearDisplay();
    display.drawBitmap(0, 0, animation2, display.width(), display.height(), 1);
    display.display();
    delay(frame_ms/(i+1));
  }
}

// Update screen circles
void update_play_screen(void){

    display.clearDisplay();
    for (int i = 0; i < 8; i++)
    {
        uint8_t note_circ_size;
        if (sens_ontime[i] > 0)
        {
          note_circ_size = sens_ontime[i]/30;
          display.drawCircle(note_circ_xpos[i], 32, note_circ_size, WHITE);
        }
    }

    display.display();

}

// Update the sound sel screen. String vs drum, etc.
void update_sound_sel_screen(void)
{

  cur_screen2_idx = sound_idx;     // Keep in sync with the audio idx. Prob should merge. 

  // Where do we want to set cursor to draw text?
  // djt - prob put these all in some header to use elsewhere... maybe even an array..
  uint8_t opt_x         = 30;      // X position for all.. keep em lined up
  uint8_t opt_y_spacing = 10;      // Spacing of options in pixels
  uint8_t opt_rect_ht   = 10;      // rectangle height for selected option
  uint8_t opt_rect_y    = 30 + cur_screen2_idx * opt_y_spacing; // Set starting y pos of rect.

  display.setTextSize(1);
  display.fillRect(0, 30, SCREEN_WIDTH , SCREEN_HEIGHT, BLACK);   // Clear just bottom section of screen
  
  // Create highlighted selection rect for selected opt.
  display.fillRect(0, opt_rect_y, SCREEN_WIDTH, opt_rect_ht, WHITE);

  // Display all of the option text. Set selected one to black.
  for (uint8_t i=0; i < screen_sound_select.size(); i++)
  {
    if (i == cur_screen2_idx) display.setTextColor(BLACK);      // Black text, white backfground for selected opt
    else display.setTextColor(WHITE);

    uint8_t opt_y = 31 + (opt_y_spacing * i);
    display.setCursor(opt_x, opt_y);
    display.println(screen_sound_select[i].c_str());             // display.println needs a char ary apparently
  }
    display.display();
}

// Update reverb screen index
void update_rev_screen(void)
{
  cur_screen3_idx = rev_lvl_idx;
  
  // Where do we want to set cursor to draw text?
  // djt - prob put these all in some header to use elsewhere... maybe even an array..
  uint8_t opt_x         = 30;      // X position for all.. keep em lined up
  uint8_t opt_y_spacing = 10;      // Spacing of options in pixels
  uint8_t opt_rect_ht   = 10;      // rectangle height for selected option
  uint8_t opt_rect_y    = 20 + cur_screen3_idx * opt_y_spacing; // Set starting y pos of rect.

  display.setTextSize(1);
  display.fillRect(0, 20, SCREEN_WIDTH , SCREEN_HEIGHT, BLACK);   // Clear just bottom section of screen
  
  // Create highlighted selection rect for selected opt.
  display.fillRect(0, opt_rect_y, SCREEN_WIDTH, opt_rect_ht, WHITE);

  // Display all of the option text. Set selected one to black.
  for (uint8_t i=0; i < screen_verb_lvl.size(); i++)
  {
    if (i == cur_screen3_idx) display.setTextColor(BLACK);      // Black text, white backfground for selected opt
    else display.setTextColor(WHITE);

    uint8_t opt_y = 20 + (opt_y_spacing * i);
    display.setCursor(opt_x, opt_y);
    display.println(screen_verb_lvl[i].c_str());             // display.println needs a char ary apparently
  }
    display.display();

}

// Update scale disp. Don't clear anything. Something else can clear this out later. Just a quick indicator of new scale.
void update_scale_screen(void)
{ 
  display.fillRect(68, 40, 60, 20, BLACK);
  display.setCursor(70, 45);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println(scale_names[scale_idx]);
  display.display();
}

// Update theremin screen options.
void update_theremin_screen(void)
{
  cur_screen4_idx = theremin_idx;     // Keep in sync with the thermein idx.. should merge . 

  uint8_t opt_x         = 30;      // X position for all.. keep em lined up
  uint8_t opt_y_spacing = 10;      // Spacing of options in pixels
  uint8_t opt_rect_ht   = 10;      // rectangle height for selected option
  uint8_t opt_rect_y    = 20 + cur_screen4_idx * opt_y_spacing; // Set starting y pos of rect.

  display.setTextSize(1);
  display.fillRect(0, 20, SCREEN_WIDTH , SCREEN_HEIGHT, BLACK);   // Clear just bottom section of screen
  
  // Create highlighted selection rect for selected opt.
  display.fillRect(0, opt_rect_y, SCREEN_WIDTH, opt_rect_ht, WHITE);

  // Display all of the option text. Set selected one to black.
  for (uint8_t i=0; i < screen_theremin.size(); i++)
  {
    if (i == cur_screen4_idx) display.setTextColor(BLACK);      // Black text, white backfground for selected opt
    else display.setTextColor(WHITE);

    uint8_t opt_y = 20 + (opt_y_spacing * i);
    display.setCursor(opt_x, opt_y);
    display.println(screen_theremin[i].c_str());             // display.println needs a char ary apparently
  }
    display.display();
}

// Update playmode screen
void update_playmode_screen(void)
{  

  cur_screen5_idx = playmode_idx;
  uint8_t opt_x         = 30;      // X position for all.. keep em lined up
  uint8_t opt_y_spacing = 10;      // Spacing of options in pixels
  uint8_t opt_rect_ht   = 10;      // rectangle height for selected option
  uint8_t opt_rect_y    = 20 + cur_screen5_idx * opt_y_spacing; // Set starting y pos of rect.

  display.setTextSize(1);
  display.fillRect(0, 20, SCREEN_WIDTH , SCREEN_HEIGHT, BLACK);   // Clear just bottom section of screen
  
  // Create highlighted selection rect for selected opt.
  display.fillRect(0, opt_rect_y, SCREEN_WIDTH, opt_rect_ht, WHITE);

  // Display all of the option text. Set selected one to black.
  for (uint8_t i=0; i < screen_playmode.size(); i++)
  {
    if (i == cur_screen5_idx) display.setTextColor(BLACK);      // Black text, white backfground for selected opt
    else display.setTextColor(WHITE);

    uint8_t opt_y = 20 + (opt_y_spacing * i);
    display.setCursor(opt_x, opt_y);
    display.println(screen_playmode[i].c_str());             // display.println needs a char ary apparently
  }
    display.display();
}
//                                                                                        //
// -------------        E   X   P   E   R   I   M   E   N   T   A   L      ---------------//
//                                                                                        //


void z_test_wavy_line(void)
{

  display.clearDisplay();
  int init_x = SCREEN_WIDTH/2;
  int cur_x = init_x;
  int prev_x = cur_x;
  int slop_max = 5;
  int line_width = 2;      // width in pixels

  // Draw one line
  for (int y = 0; y < SCREEN_HEIGHT; y++)
  {
    bool skip = false;
    if ((rand() % 2 + 1) == 1)
    {
      if (cur_x > (init_x - slop_max))
      {
        cur_x -= 1;
        skip = true;
      }
    } else if (cur_x < (init_x + slop_max))
    {
      cur_x += 1;
    }

    display.drawPixel(cur_x, y, WHITE);

    if (!skip){
      for (int width = 1; width < (line_width +1); width++)
      {
        display.drawPixel(cur_x + width, y, WHITE);
      }
    }
  }
  display.display();
  delay(100);
};