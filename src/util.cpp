// Just some utility functions that don't belong anywhere else.
#include "util.h"
#include <Arduino.h>


float util_debug_print_timer = millis();

/*
Change the index but don't allow it to go below 0, or above the max. Loop around to beg or end.
Params:
    upOrDown - True = try to increment. False = Try to decrement.
    &idx     - The value to change
    max      - Max value the IDX can be. Usually size of vector -1. If it is surpassed
            then return 0.
*/
void util_chg_index(bool upOrDown, int8_t &idx, uint8_t max)
{
    (upOrDown) ? idx++ : idx--;

    // Attemting to go above the max. Loop back to 0.
    if (idx > max && idx > 0)
    {
        idx= 0;
    }
    
    // Attempting to go below 0 index... go to the last option (loop around)
    if (idx < 0)
    {
        idx = max;
    }
}