# Arduino-Automatic-Plant-Watering-System
Arduino Plant watering System for four Plants (added some optimisations and LCD display)


### ToDo###

Code:
  - remove position after decimal point for % in LCD
  - Add Sensor calibration function (https://github.com/Trickery710/Automatic-Plant-Watering-System-Tutorial/blob/c8e3205a77603acb73d5489f55570fc86c736b9b/examples/01_calibration/main.cpp)
  - Optimize code as used by https://github.com/TheRealBeowulf/Automatic-Plant-Watering-System-Tutorial/blob/c63c6c0f5720cf6e074827d02cda44a5c78929a0/4%20Channel%20Relay%20Plant%20Watering%20System%20and%20code/arduino_Watering4/arduino_Watering4.ino)
  - 
 
HW:
- create drawing for cabling
- add 3d printer designs
- Add pictures

I have changed the process how plants are watered if humidity is to low.
Instead of switching the pump on until configured humidity is reached I'm switching it on for 2 seconds, wait for a few seconds and switch it on again, to give the water a chance to drain into soil.
