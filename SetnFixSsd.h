/*
  SetnFixSsd Library
  Created by BMIAKBASNAYAKA

  Description:
  This Arduino library facilitates the easy interfacing of a 6-digit 7-segment display. 
  It is designed for common cathode displays. If using common anode displays, invert the 
  logic accordingly.

  Library features:
  - Simplified interface for displaying numbers on a 6-digit 7-segment display.

  Usage:
  1. Include this library in your Arduino sketch: #include <SetnFixSsd.h>
  2. Configure the pin connections for your specific setup.
  3. Initialize the SetnFixSsd object with the appropriate pins.
  4. Use the displayNumber() function to display a 6-digit number.

  Credits:
  - Library coded by BMIAKBASNAYAKA for SetnFix
  - Date: [03/10/2023]
  - Time: [13:12]
  - Version: [1.0]

  Connections:
  - Connect the segment pins (A to G) of the 7-segment display to the corresponding
    pins on your Arduino.
  - Connect the digit pins (D1 to D6) of the 7-segment display to the corresponding
    pins on your Arduino.
  
  Note: Adjust the pin configurations based on your specific hardware setup.

  For updates and support, visit: [www.setnfix.com]
*/



#ifndef SetnFixSsd_h
#define SetnFixSsd_h

#include <Arduino.h>

class SetnFixSsd {
public:
  SetnFixSsd(int segmentPins[], int digitPins[], int numDigits);
  void begin();
  void displayNumber(int number);
private:
  int* segmentPins;
  int* digitPins;
  int numDigits;
  const byte digitSegments[10] = {
    B11111100, // 0
    B01100000, // 1
    B11011010, // 2
    B11110010, // 3
    B01100110, // 4
    B10110110, // 5
    B10111110, // 6
    B11100000, // 7
    B11111110, // 8
    B11110110  // 9
  };
};

#endif
