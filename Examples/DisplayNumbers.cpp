
/*
  DisplayNumbers Example Sketch
  Created by BMIAKBASNAYAKA

  Description:
  This Arduino sketch demonstrates the usage of the SetnFixSsd library to easily display
  a 6-digit number on a 7-segment display. The library is designed for common cathode 
  displays. If using common anode displays, invert the logic accordingly.

  Credits:
  - Library coded by BMIAKBASNAYAKA for SetnFix
  - Date: [03/10/2023]
  - Time: [13:12]
  - Version: [1.0]

  Library GitHub Repository: [Insert Link]

  Instructions:
  1. Include the SetnFixSsd library in your Arduino IDE.
  2. Connect your 7-segment display to the Arduino as per the library documentation.
  3. Upload this sketch to your Arduino board.

  For updates and support, visit: [www.setnfix.com]
*/



#include <SetnFixSsd.h>

// Pin configuration for 7-segment displays
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};
const int digitPins[] = {9, 10, 11, 12, 13, A0}; // Assuming 6 digits

SetnFixSsd display(segmentPins, digitPins, 6);

void setup() {
  display.begin();
}

void loop() {
  int numberToDisplay = 123456; // Replace with your 6-digit number

  display.displayNumber(numberToDisplay);
  delay(2000); // Display for 2 seconds (adjust as needed)
}
