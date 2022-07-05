// Use this for display testing functions
// Inlcude everything cause why not its a test thing
#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <list>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <iostream>
#include <Bounce2.h>

#include "notes_and_chords.h"     // All of the note definitions and such
#include "bitmaps.h"              // Bitmaps for screen
#include "AudioSetup.h"
#include "Display.h"
#include "Inputs.h"

void zdraw_circle(void);                  // Draw a quick rect, for testing
void zdraw_title_rect(void);              // Draw a quick rect, for testing
void zdraw_play_screen(void);             // Draw a quick rect, for testing
void zdraw_8_circles(void);