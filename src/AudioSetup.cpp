// Functions for setting up audio objects and such

#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include <string>
#include <SerialFlash.h>
#include "AudioSetup.h"
#include "notes_and_chords.h"
#include "Display.h"
#include "util.h"
#include "Inputs.h"

#pragma region audioTool
// GUItool: begin automatically generated code
AudioSynthKarplusStrong  string1;        //xy=213,91
AudioSynthKarplusStrong  string2;        //xy=213,130
AudioSynthKarplusStrong  string3;        //xy=213,168
AudioSynthKarplusStrong  string4;        //xy=215,205
AudioSynthKarplusStrong  string5;        //xy=216,268
AudioSynthWaveform       waveform6;      //xy=214,1195
AudioSynthSimpleDrum     drum6;          //xy=217,774
AudioSynthWaveform       waveform3;      //xy=216,1051
AudioSynthSimpleDrum     drum7;          //xy=217,822
AudioSynthWaveform       waveform5;      //xy=216,1151
AudioSynthSimpleDrum     drum2;          //xy=219,556
AudioSynthKarplusStrong  string6;        //xy=220,308
AudioSynthSimpleDrum     drum5;          //xy=219,725
AudioSynthWaveform       waveform7; //xy=217,1237
AudioSynthSimpleDrum     drum1;          //xy=220,510
AudioSynthWaveform       waveform1;      //xy=219,962
AudioSynthWaveform       waveform2;      //xy=219,1008
AudioSynthWaveform       waveform4;      //xy=219,1093
AudioSynthKarplusStrong  string7;        //xy=222,355
AudioSynthSimpleDrum     drum3;          //xy=221,608
AudioSynthWaveform       waveform8; //xy=219,1283
AudioSynthSimpleDrum     drum8;          //xy=221,875
AudioSynthKarplusStrong  string8;        //xy=223,405
AudioSynthSimpleDrum     drum4;          //xy=222,656
AudioEffectEnvelope      envelope12;     //xy=365,653
AudioEffectEnvelope      envelope11;     //xy=367,608
AudioEffectEnvelope      envelope23; //xy=366,1244
AudioEffectEnvelope      envelope9;      //xy=369,513
AudioEffectEnvelope      envelope14;     //xy=368,778
AudioEffectEnvelope      envelope10;     //xy=370,557
AudioEffectEnvelope      envelope22; //xy=368,1199
AudioEffectEnvelope      envelope15;     //xy=370,823
AudioEffectEnvelope      envelope24; //xy=369,1286
AudioEffectEnvelope      envelope21; //xy=370,1151
AudioEffectEnvelope      envelope13;     //xy=372,728
AudioEffectEnvelope      envelope16;     //xy=373,872
AudioEffectEnvelope      envelope2;      //xy=377,128
AudioEffectEnvelope      envelope18; //xy=374,1013
AudioEffectEnvelope      envelope1;      //xy=378,91
AudioEffectEnvelope      envelope20; //xy=374,1095
AudioEffectEnvelope      envelope19; //xy=376,1059
AudioEffectEnvelope      envelope3;      //xy=380,168
AudioEffectEnvelope      envelope17; //xy=377,962
AudioEffectEnvelope      envelope4;      //xy=382,205
AudioEffectEnvelope      envelope5;      //xy=385,271
AudioEffectEnvelope      envelope7;      //xy=385,358
AudioEffectEnvelope      envelope8;      //xy=387,406
AudioEffectEnvelope      envelope6;      //xy=389,316
AudioMixer4              mixer8; //xy=523,1206
AudioMixer4              mixer7; //xy=539,1025
AudioMixer4              mixer5; //xy=558,785
AudioMixer4              mixer4; //xy=567,588
AudioMixer4              mixer1;         //xy=574,145
AudioMixer4              mixer2;         //xy=574,341
AudioMixer4              mixer9; //xy=639,1121
AudioMixer4              mixer3;         //xy=710,254
AudioMixer4              mixer6; //xy=734,688
AudioSynthWaveform       LFO1;      //xy=807,1283
AudioMixer4              mixerMaster; //xy=828,1047
AudioMixer4              mixerFXVerb;  //xy=898,478
AudioFilterStateVariable filterMaster;        //xy=989,1053
AudioEffectReverb        reverb1;        //xy=1071,485
AudioOutputI2S           i2s1;           //xy=1162,1058
AudioConnection          patchCord1(string1, envelope1);
AudioConnection          patchCord2(string2, envelope2);
AudioConnection          patchCord3(string3, envelope3);
AudioConnection          patchCord4(string4, envelope4);
AudioConnection          patchCord5(string5, envelope5);
AudioConnection          patchCord6(waveform6, envelope22);
AudioConnection          patchCord7(drum6, envelope14);
AudioConnection          patchCord8(waveform3, envelope19);
AudioConnection          patchCord9(drum7, envelope15);
AudioConnection          patchCord10(waveform5, envelope21);
AudioConnection          patchCord11(drum2, envelope10);
AudioConnection          patchCord12(string6, envelope6);
AudioConnection          patchCord13(drum5, envelope13);
AudioConnection          patchCord14(waveform7, envelope23);
AudioConnection          patchCord15(drum1, envelope9);
AudioConnection          patchCord16(waveform1, envelope17);
AudioConnection          patchCord17(waveform2, envelope18);
AudioConnection          patchCord18(waveform4, envelope20);
AudioConnection          patchCord19(string7, envelope7);
AudioConnection          patchCord20(drum3, envelope11);
AudioConnection          patchCord21(waveform8, envelope24);
AudioConnection          patchCord22(drum8, envelope16);
AudioConnection          patchCord23(string8, envelope8);
AudioConnection          patchCord24(drum4, envelope12);
AudioConnection          patchCord25(envelope12, 0, mixer4, 3);
AudioConnection          patchCord26(envelope11, 0, mixer4, 2);
AudioConnection          patchCord27(envelope23, 0, mixer8, 2);
AudioConnection          patchCord28(envelope9, 0, mixer4, 0);
AudioConnection          patchCord29(envelope14, 0, mixer5, 1);
AudioConnection          patchCord30(envelope10, 0, mixer4, 1);
AudioConnection          patchCord31(envelope22, 0, mixer8, 1);
AudioConnection          patchCord32(envelope15, 0, mixer5, 2);
AudioConnection          patchCord33(envelope24, 0, mixer8, 3);
AudioConnection          patchCord34(envelope21, 0, mixer8, 0);
AudioConnection          patchCord35(envelope13, 0, mixer5, 0);
AudioConnection          patchCord36(envelope16, 0, mixer5, 3);
AudioConnection          patchCord37(envelope2, 0, mixer1, 1);
AudioConnection          patchCord38(envelope18, 0, mixer7, 1);
AudioConnection          patchCord39(envelope1, 0, mixer1, 0);
AudioConnection          patchCord40(envelope20, 0, mixer7, 3);
AudioConnection          patchCord41(envelope19, 0, mixer7, 2);
AudioConnection          patchCord42(envelope3, 0, mixer1, 2);
AudioConnection          patchCord43(envelope17, 0, mixer7, 0);
AudioConnection          patchCord44(envelope4, 0, mixer1, 3);
AudioConnection          patchCord45(envelope5, 0, mixer2, 0);
AudioConnection          patchCord46(envelope7, 0, mixer2, 2);
AudioConnection          patchCord47(envelope8, 0, mixer2, 3);
AudioConnection          patchCord48(envelope6, 0, mixer2, 1);
AudioConnection          patchCord49(mixer8, 0, mixer9, 1);
AudioConnection          patchCord50(mixer7, 0, mixer9, 0);
AudioConnection          patchCord51(mixer5, 0, mixer6, 1);
AudioConnection          patchCord52(mixer4, 0, mixer6, 0);
AudioConnection          patchCord53(mixer1, 0, mixer3, 0);
AudioConnection          patchCord54(mixer2, 0, mixer3, 1);
AudioConnection          patchCord55(mixer9, 0, mixer6, 2);
AudioConnection          patchCord56(mixer3, 0, mixerFXVerb, 0);
AudioConnection          patchCord57(mixer3, 0, mixerMaster, 0);
AudioConnection          patchCord58(mixer6, 0, mixerFXVerb, 1);
AudioConnection          patchCord59(mixer6, 0, mixerMaster, 1);
AudioConnection          patchCord60(LFO1, 0, filterMaster, 1);
AudioConnection          patchCord61(mixerMaster, 0, filterMaster, 0);
AudioConnection          patchCord62(mixerFXVerb, reverb1);
AudioConnection          patchCord63(filterMaster, 0, i2s1, 0);
AudioConnection          patchCord64(filterMaster, 0, i2s1, 1);
AudioConnection          patchCord65(reverb1, 0, mixerMaster, 2);
AudioControlSGTL5000     sgtl5000_1;     //xy=229,38
// GUItool: end automatically generated code

#pragma endregion audioTool

// Tracking Vars related to audio stuff
int8_t    sound_idx        = 0;
uint8_t   env_idx          = 0;
int8_t    scale_idx        = 0;
int8_t    octave_current   = 3; 
int8_t    rev_lvl_idx      = 0;
int8_t    playmode_idx     = 0;
int8_t    theremin_idx     = 0;    // Default to off           
int       reverb_time      = 0;     
bool      theremin_calibrated = false;
bool      playmode_chord_posorneg = true;    // 

// Default ADSR param settings.
int       attackParam      = 0;
int       decayParam       = 50;
float     sustainParam     = 1;
int       releaseParam     = 500;
uint8_t   envidxadd        = 0;

// Theremin initial values
int16_t therValMax = 1200;
int16_t therValMin = 200;
float ther_a = 1/((float)therValMax - (float)therValMin);
float ther_b = 1 - ther_a * therValMax;

// Pointer Arrays
AudioSynthKarplusStrong  *string[8]    = {&string1, &string2, &string3, &string4, &string5, &string6, &string7, &string8};
AudioEffectEnvelope      *envelope[24] = {&envelope1, &envelope2, &envelope3, &envelope4, &envelope5, &envelope6, &envelope7, &envelope8,
                                          &envelope9, &envelope10, &envelope11, &envelope12, &envelope13, &envelope14, &envelope15, &envelope16,
                                          &envelope17, &envelope18, &envelope19, &envelope20, &envelope21, &envelope22, &envelope23, &envelope24
                                         };
AudioSynthSimpleDrum      *drum[8]     = {&drum1, &drum2, &drum3, &drum4, &drum5, &drum6, &drum7, &drum8};
AudioSynthWaveform        *waveform[8] = {&waveform1, &waveform2, &waveform3, &waveform4, &waveform5, &waveform6, &waveform7, &waveform8};

// ------- NOTE STUFF ------------ //
std::vector<float> note_list           = {C1_NT, Cs1_NT, D1_NT, Ds1_NT, E1_NT, F1_NT, Fs1_NT, G1_NT, Gs1_NT, A1_NT, As1_NT, B1_NT};

// MAJOR SCALES
std::vector<float> scale_cmaj = {C1_NT, D1_NT, E1_NT,  F1_NT, G1_NT, A1_NT, B1_NT, C1_NT * 2};
std::vector<float> scale_dmaj = {D1_NT, E1_NT, Fs1_NT, G1_NT, A1_NT, B1_NT, Cs1_NT * 2, D1_NT *2};

// MINOR SCALES
std::vector<float> scale_dmin = {D1_NT, E1_NT, F1_NT, G1_NT, A1_NT, As1_NT,  C1_NT * 2, D1_NT * 2};

// Save them a vector of vectors
std::vector<std::vector<float>> scales = {scale_cmaj, scale_dmaj, scale_dmin};

// And also save the names of the scales.
const char * scale_names[] = {"Cmaj", "Dmaj", "Dmin"};

// Track stuff for diff playmodes
std::vector<uint32_t> playmode_ms_between      = {500, 500, 500, 500, 500, 500, 500, 500};
std::vector<uint32_t> playmode_last_hit        = {0,0,0,0,0,0,0,0};
std::vector<int>  playmode_chord_idx_next      = {0,1,2,3,4,5,6,7};

// Initialize audio stuff for teensy audio lib
void initAudio(void){

    // audio library init
    AudioMemoryUsageMaxReset();
    AudioMemory(24);  

    // Turn down reverb mixer gain to avoid noise.
    mixerFXVerb.gain(0,0.1);
    mixerFXVerb.gain(1,0.1);
    mixerFXVerb.gain(2,0.1);
    mixerFXVerb.gain(3,0.1);
    mixerMaster.gain(2, 1.0);

    // Init LFO + Filter
    LFO1.begin(0.001, 2, WAVEFORM_SINE); 
    filterMaster.frequency(15000);   
    filterMaster.resonance(1.1);
  

    // assign initial envelope parameters
    for (int i=0; i < 24; i++)
    {
      envelope[i] -> delay(0);
      envelope[i] -> attack(attackParam);    
      envelope[i] -> hold(0);                
      envelope[i] -> decay(decayParam);      
      envelope[i] -> sustain(sustainParam);  
      envelope[i] -> release(releaseParam);    
    }

    init_waveforms();   // set up the waveforms to default

    //
    sgtl5000_1.enable();
    sgtl5000_1.volume(0.3);
    AudioInterrupts();

}

// Set all waveforms to triangle to start
void init_waveforms(void)
{
  for (int i=0; i < 8; i++)
  {
    waveform[i] -> begin(1, note_list[i], WAVEFORM_TRIANGLE);
  }
}

// next scale in the list
void chg_scale(void){

  util_chg_index(true, scale_idx, scales.size()-1);
  current_notes = scales[scale_idx];                      // Set to new scale

  return;
}

// Go to next or prev sound in the list, and perform any necessary setup 
void chg_sound(bool upOrDown=true){

  util_chg_index(upOrDown, sound_idx, screen_sound_select.size()-1);
  init_envelope();                                 
}

// Update reverb time
void chg_rev_time(bool upOrDown){
  int rev_time_new = 0;
  util_chg_index(upOrDown, rev_lvl_idx, screen_verb_lvl.size()-1);

  switch(rev_lvl_idx)
  {
    case 0: // off
      rev_time_new = 0;
      mixerMaster.gain(2,0);    // Turn off reverb mixer master input
      break;

    case 1: // Low
      rev_time_new = 200;
      mixerMaster.gain(2,0.7);
      break;

    case 2: // Med 
      rev_time_new = 600;
      mixerMaster.gain(2, 1.2);  // MAKE IT A LIL LOUDER
      break;

    case 3: // High
      rev_time_new = 1500; 
      mixerMaster.gain(2, 1.6);  // MAKE IT LOUDER STILL
      break;

  }

  reverb1.reverbTime(rev_time_new);
  return;
}

// Change theremin mode stuff
void chg_theremin_mode(bool upOrDown=true, bool skipCalibration = false){

  util_chg_index(upOrDown, theremin_idx, screen_theremin.size()-1);

  if (!theremin_calibrated && !skipCalibration)
  {
    run_theremin_calibration();  
    theremin_calibrated = true;  
  }
  switch (theremin_idx)
  {
    case 0:  // off
      //
      break;
    
    case 1:  // Map to Volume
      //
      break;
  }          

}

// Toggle playmodes
void chg_playmode(bool upOrDown=true)
{
  util_chg_index(upOrDown, playmode_idx, screen_playmode.size()-1);                                 
}

// Update envelopes based on sound selected
bool update_envelope(uint8_t idx, uint8_t env_idx)
{

    switch(sound_idx) 
    {
      case 0: // String sound
        envelope[env_idx] -> release(releaseMin + (sens_ontime[idx] * 2));
        break;
      
      case 1: // Drum sound
        envelope[env_idx] -> release(releaseMin + (sens_ontime[idx] * 2));
        break;

      case 2: // Synth sound
        // envelope[env_idx] -> release(releaseMin + (sens_ontime[idx] * 2));
        break;
    }
}

// Update envelopes based on sound selected
void update_volume(void)
{
  float volume;

  // Base velocity based on velocity pot
  volume = (static_cast<float>(pot_vol) / 1024);
  mixerMaster.gain(0, volume);
  mixerMaster.gain(1, volume);
  mixerMaster.gain(2, volume);
}

// Set initial & constant env values based on the sound we are on.
void init_envelope(void)
{
  uint8_t env_idx_st = (sound_idx * 8);
  uint8_t env_idx_end = env_idx_st + 8;

  for (int env_idx = env_idx_st; env_idx < env_idx_end; env_idx++)
  {
    switch(sound_idx)
    {
      case 0: // String sound
        envelope[env_idx] -> attack(attackParam);
      break;

      case 1: // Drum sound
        envelope[env_idx] -> attack(attackParam);
      break;

      case 2: // Synth sound
        envelope[env_idx] -> attack(3000);
        envelope[env_idx] -> decay(3000);
        envelope[env_idx] -> release(3000);
      break;
    }
  }
}

// Get the high and low values of theremin sensor to calibrate.
void run_theremin_calibration(bool skipCalibration = false)
{

  if (skipCalibration) return;

  // Show user what's going on
  display.clearDisplay();
  display.setCursor(0, 2);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setTextWrap(true);
  display.println("Running Theremin Calibration...");
  display.display();

  delay(1500);
  display.clearDisplay();
  display.setCursor(0, 2);
  display.println("Cover & uncover");
  display.println("sensor 8");
  display.println("when you see GO..");
  display.display();

  delay(3000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(2,2);
  display.println("GO!");
  display.display();

  display.setTextSize(1);
  display.setCursor(20,20);
  display.println("MAX: ");
  display.setCursor(20,30);
  display.println("MIN: ");


  float calibration_timer = millis();
  float calibration_time = 5000;   
  therValMax = 0;
  therValMin = 5000;                    // Set to crazy values to ensure we update with sensor info.  

  // Find min and max
  while (millis() - calibration_timer < calibration_time)
  {
    int16_t cur_ther_val = analogRead(THEREMIN);
    if (cur_ther_val > therValMax) therValMax = cur_ther_val;     
    if (cur_ther_val < therValMin) therValMin = cur_ther_val;

    display.fillRect(70, 0, 100, 100, BLACK);
    display.setCursor(70, 20);
    display.println(therValMax);
    display.setCursor(70, 30);
    display.println(therValMin);
    display.display();
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,20);
  display.println("Calibration Complete");
  display.display();

  delay(2000);
  display.clearDisplay();
  display.drawRoundRect(0,0,SCREEN_WIDTH,16,10,WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(25, 5);
  display.println("Theremin Mode");

  ther_a = 1/((float)therValMax - (float)therValMin);
  ther_b = 1 - ther_a * therValMax;

  // DEBUG INFO
  // Serial.println("theremin calibration complete");
  // Serial.println("------------------------------");
  // Serial.println("Theremin Value Max:    ");
  // Serial.println(therValMax);
  // Serial.println("Theremin Value Min:    ");
  // Serial.println(therValMin);
}

// Update values based on theremin mode.
void update_theremin_fx(void)
{
  float theremin_mult = ther_a * theremin_val + ther_b;
  float volume;
  float rtime;
  float gain;

  switch (theremin_idx)
  {
    case 1:   // Update volume

      // Velocity pot - theremin multiplier thing
      volume = (static_cast<float>(pot_vol) / 1024) - theremin_mult;          

      // Print debug info once per second. 
      if (millis() - util_debug_print_timer > 1000)
      {
        Serial.println("Theremin debug:");
        Serial.println("Theremin Value Raw:    ");
        Serial.println(theremin_val);
        Serial.println("New Volume:    ");
        Serial.println(volume);
        Serial.println("**********************");
        util_debug_print_timer = millis();
      }
             
      mixerMaster.gain(0, volume);
      mixerMaster.gain(1, volume);
      mixerMaster.gain(2, volume);
      break;

    case 2:   // Update Filter

      LFO1.amplitude(theremin_mult/2);
      filterMaster.frequency(18000 - (theremin_mult * 18000));

                  // Print debug info once per second. 
      if (millis() - util_debug_print_timer > 1000)
      {
        Serial.println("Theremin debug:");
        Serial.println("Theremin Value Raw:    ");
        Serial.println(theremin_val);
        Serial.println("Theremin Mult:    ");
        Serial.println(theremin_mult);
        Serial.println("filter freq new:    ");
        Serial.println(18000 - (theremin_mult * 17000));
        Serial.println("LFO Amplitude    ");
        Serial.println(theremin_mult/2);
        Serial.println("**********************");
        util_debug_print_timer = millis();
      }
      break;

    case 3:   // Update reverb 
      rtime = 500 * (1 + (1 - theremin_mult));    // Less light = higher mult
      gain = (1 - theremin_mult) * 1.2;

      reverb1.reverbTime(rtime);
      mixerMaster.gain(2, gain);  // MAKE IT A LIL LOUDER

            // Print debug info once per second. 
      if (millis() - util_debug_print_timer > 1000)
      {
        Serial.println("Theremin debug:");
        Serial.println("Theremin Value Raw:    ");
        Serial.println(theremin_val);
        Serial.println("Theremin Mult:    ");
        Serial.println(theremin_mult);
        Serial.println("Reverb Gain:    ");
        Serial.println(gain);
        Serial.println("Reverb Time:    ");
        Serial.println(rtime);
        Serial.println("**********************");
        util_debug_print_timer = millis();
      }

      break;
  }

}

// Manage playmode stuff
void update_playmode_hits(int idx, bool init = false)
{
  //Serial.println(playmode_idx);
  if (init)
  {
    playmode_last_hit[idx] = 0;
    playmode_chord_idx_next[idx] = idx;
    playmode_ms_between[idx] = 500;
    return;
  }

  int new_idx = 0;

  switch (playmode_idx)
  {
    case 0:  // Playmode = Standard
      //
      break;

    case 1:  // Playmopde = tremelo
      Serial.println(millis() - playmode_last_hit[idx]);
      Serial.println(playmode_ms_between[idx]);
      if (playmode_ms_between[idx] < (millis() - playmode_last_hit[idx]))
      {
        playmode_last_hit[idx] = millis();
        playmode_ms_between[idx] = playmode_ms_between[idx] - (playmode_ms_between[idx]/4);

        if (playmode_ms_between[idx] < 100) playmode_ms_between[idx] = 100 - (rand() % 25);    // Dont play TOO fast

        new_notes[idx] = true;

      }

      break;
    
    case 2:  // playmode = chords

      if (playmode_ms_between[idx] < (millis() - playmode_last_hit[idx]))
      {
        playmode_last_hit[idx] = millis();
        playmode_ms_between[idx] = playmode_ms_between[idx] - (playmode_ms_between[idx]/7);

        if (playmode_ms_between[idx] < 100) playmode_ms_between[idx] = 100 - (rand() % 25);

        if (playmode_chord_posorneg) playmode_chord_idx_next[idx]++;
        if (!playmode_chord_posorneg) playmode_chord_idx_next[idx]--;
        if (playmode_chord_idx_next[idx] > 7)
        {
          playmode_chord_idx_next[idx] = 7;
          playmode_chord_posorneg = false;
        }

        if (playmode_chord_idx_next[idx] < 0)
        {
          playmode_chord_idx_next[idx] = 0;
          playmode_chord_posorneg = true;
        }

        new_notes[playmode_chord_idx_next[idx]] = true;
        // playmode_chord_idx_add[idx]++;

      }
      break;
    }
  //
}