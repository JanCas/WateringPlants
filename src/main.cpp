#include <Arduino.h>
#include "LedMatrix.hpp"


LedMatrix lm = LedMatrix(12,11,10);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lm.clear();
  lm.wake_up();
  lm.set_brightness(10);
  Serial.println("got here");
  lm.display_integer(100);
}



void loop() {
  // put your main code here, to run repeatedly:
}