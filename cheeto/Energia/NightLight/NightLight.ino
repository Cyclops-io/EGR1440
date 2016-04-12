#include <Wire.h>			// Needed by Energia for Tiva C LaunchPad 
#include "OPT3001.h"
#define USE_USCI_B1 

//global vals
opt3001 opt3001; //light sensor
const int ledPin = 39; //pin for the LED/LCD
const int brightnessCutoff = 500; //if the lux reading is greater than this value the LED will turn off

void setup()
{
  Serial.begin(115200);
  delay(1000);
  opt3001.begin(); 
}

void loop()
{
  // Read OPT3001
  uint32_t readings = opt3001.readResult();  
  if (readings <= brightnessCutoff)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
