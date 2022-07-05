# Desktop Laser Harp
Desktop laser harp based on the Teensy 4.0 with Audio Shield, and a 3d printed enclosure.

## Demo
https://www.youtube.com/watch?v=X28VLMFqv5Y

## About
Inspired by an installation at the Santa Fe Meow Wolf. It's basically just 8 lasers that are constantly powered, pointing into 8 photoresistor modules (some random ones from aliexpress). 

NOTE - The code is not the cleanest, but might as well stick it here for reference in case it helps anyone. 

## Features
- 3 Voice modes
  <br>String

## Ideas for next time / lessons / Thoughts

- Right now, only sensor 8 has analog out (for theremin mode), but it would be neat to have analog readings for all of them, and wouldn't be tough to do. 
- Using analog multiplexors (like 74HC405), you could probably make a full size harp with all analog signals from the photoresistors, which would be cool.
- It would be easy to add a midi mode, and then use midi over USB to control synths / VSTs, etc.
- It's wise to leave more room than you think for the laser diodes... I thought if the holes were the perfect size, then alignment would be easy / automatic. This is not the case. More wiggle room would make it easier to manually align, and then fix it place with hot glue or something.
- This kind of defeats the purpose.. but you probably don't even need lasers if you use analog outs from the photoresistor modules. Just would need to tune them well, or have a calibration mode.

## Parts
Just for reference.. some of the specific parts that I used, though they are all pretty generic.

Laser diodes - https://www.aliexpress.com/item/3256802366869690.html?spm=a2g0o.order_list.0.0.18751802Ue2rlI&gatewayAdapt=4itemAdapt
Sensor Modules - https://www.aliexpress.com/item/3256803109578618.html?spm=a2g0o.order_list.0.0.18751802Ue2rlI&gatewayAdapt=4itemAdapt
Screen - https://www.aliexpress.com/item/2251832770994631.html?spm=a2g0o.order_list.0.0.18751802Ue2rlI&gatewayAdapt=4itemAdapt
