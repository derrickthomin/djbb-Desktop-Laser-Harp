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


void zdraw_8_circles(void)
{   
    uint8_t note_circ_size[8];
    uint8_t note_circ_xpos[8] = {10, 25, 40, 56, 72, 87, 102, 118}; 

    for (int i = 0; i < 8; i++)   // Random circle sizes
    {
        note_circ_size[i] = rand() % 12 + 1;
    }

    // Now display
    display.clearDisplay();
    for (int i = 0; i < 8; i++)
    {
        display.drawCircle(note_circ_xpos[i], 32, note_circ_size[i], WHITE);
    }

    display.display();
    delay(50);

    // OLD STUFF... replaced by loop above. For ref.
    // display.drawCircle(10, 32, size, WHITE);
    // display.drawCircle(25, 32, size, WHITE);
    // display.drawCircle(40, 32, size, WHITE);
    // display.drawCircle(56, 32, size, WHITE);
    // display.drawCircle(72, 32, size, WHITE);
    // display.drawCircle(87, 32, size, WHITE);
    // display.drawCircle(102, 32, size, WHITE);
    // display.drawCircle(118, 32, size, WHITE);
}

// Draw the title box rect
void zdraw_title_rect(void)
{
    display.drawRoundRect(0,0,SCREEN_WIDTH,16,10,WHITE);
}


void zdraw_circle(void)
{   
    display.clearDisplay();
    display.drawCircle(20, 20, 20, WHITE);
    display.display();
    delay(300);
}

void zdraw_play_screen(void)
{   
    display.clearDisplay();
    zdraw_title_rect();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(42, 5);
    display.println("P L A Y");
    display.display();
}
