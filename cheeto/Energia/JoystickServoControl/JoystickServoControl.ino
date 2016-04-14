#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
int potpin = 2;  // analog pin used to connect the potentiometer on the joystick
 
void setup() 
{ 
  myservo.attach(19);  // attaches the servo on pin 19 to the servo object 
} 
 
void loop() 
{ 
  int reading = analogRead(potpin);    // reads the value of the potentiometer (value between 0 and 1023) 
  int val = map(reading, 0, 1024, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo speed/position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
} 
