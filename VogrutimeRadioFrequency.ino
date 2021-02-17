#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
Adafruit_7segment matrix = Adafruit_7segment();
float input;
const int enter = A0;
double fx;
float stable;
float fz;
float initial;
void setup() {
  // put your setup code here, to run once:
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);
pinMode(enter, INPUT);
initial = 0.11*input+86.34;
}

void loop() {
  // put your main code here, to run repeatedly:
input = analogRead(enter);
fx = 0.11*input+86.34;
if(abs(fx - initial) > 1)
{
  initial = fx;

}
Serial.println(initial, 1);
matrix.print(initial, 1);
matrix.writeDisplay();

}
