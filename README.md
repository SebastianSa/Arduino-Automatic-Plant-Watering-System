# Arduino-Automatic-Plant-Watering-System
Arduino Plant watering System for four Plants 
  added some optimisations
  added LCD display
  Display based on % not absolute values from sensor
  3d printed Box and assessories

## LCD display Design (4*20)

  Plant1:    xx % 50 %   
  Plant2:    xx % 50 %   
  Plant3:    xx % 80 %   
  channel disabled   


# ToDo

## Code:
  - Add Sensor calibration function (https://github.com/Trickery710/Automatic-Plant-Watering-System-Tutorial/blob/c8e3205a77603acb73d5489f55570fc86c736b9b/examples/01_calibration/main.cpp)
  - Optimize code as used by https://github.com/TheRealBeowulf/Automatic-Plant-Watering-System-Tutorial/blob/c63c6c0f5720cf6e074827d02cda44a5c78929a0/4%20Channel%20Relay%20Plant%20Watering%20System%20and%20code/arduino_Watering4/arduino_Watering4.ino)
 
## HW:
- create drawing for cabling
- add 3d printer designs

I have changed the process how plants are watered if humidity is to low.
Instead of switching the pump on until configured humidity is reached I'm switching it on for 2 seconds, wait for a few seconds and switch it on again, to give the water a chance to drain into soil.

# Pictures
## Prototype with 3dPrinted parts

Prototype with Watertank
![Protype with Watertank](https://github.com/SebastianSa/Arduino-Automatic-Plant-Watering-System/blob/f1e2738a31b8f112fcfcc49f49099789c70dabdf/pictures/PXL_20230504_083422437.jpg)

Inside view of the 3d printed box to cover Arduino Uno and Relay Module
![Protype with Watertank](https://github.com/SebastianSa/Arduino-Automatic-Plant-Watering-System/blob/f1e2738a31b8f112fcfcc49f49099789c70dabdf/pictures/PXL_20230504_083448540.jpg)

Sensor and watering pipe holder with sprinkler
![Protype with Watertank](https://github.com/SebastianSa/Arduino-Automatic-Plant-Watering-System/blob/f1e2738a31b8f112fcfcc49f49099789c70dabdf/pictures/PXL_20230504_083549173.jpg)
