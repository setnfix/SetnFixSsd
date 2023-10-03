/*
  SetnFixSsd Library Implementation
  Created by BMIAKBASNAYAKA

  Description:
  This file contains the implementation of the SetnFixSsd library, which facilitates 
  the easy interfacing of a 6-digit 7-segment display. It is designed for common cathode 
  displays. If using common anode displays, invert the logic accordingly.

  Library features:
  - Simplified interface for displaying numbers on a 6-digit 7-segment display.

  Credits:
  - Library coded by BMIAKBASNAYAKA for SetnFix
 - Date: [03/10/2023]
  - Time: [13:12]
  - Version: [1.0]

  For updates and support, visit: [www.setnfix.com]
*/



#include "SetnFixSsd.h"

SetnFixSsd::SetnFixSsd(int segmentPins[], int digitPins[], int numDigits) {
  this->segmentPins = segmentPins;
  this->digitPins = digitPins;
  this->numDigits = numDigits;
}

void SetnFixSsd::begin() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  for (int i = 0; i < numDigits; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
}

void SetnFixSsd::displayNumber(int number) {
  int digit[numDigits];
  for (int i = 0; i < numDigits; i++) {
    digit[i] = number % 10;
    number /= 10;
  }

  for (int i = 0; i < numDigits; i++) {
    digitalWrite(digitPins[i], HIGH);

    for (int j = 0; j < 7; j++) {
      digitalWrite(segmentPins[j], bitRead(digitSegments[digit[i]], j));
    }

    delay(5);

    for (int j = 0; j < 7; j++) {
      digitalWrite(segmentPins[j], LOW);
    }

    digitalWrite(digitPins[i], LOW);
  }
}
