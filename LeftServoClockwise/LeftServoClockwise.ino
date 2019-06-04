/*
Robotics with the BOE Shield – LeftServoClockwise
Generate a servo full speed clockwise signal on digital pin 13. */

#include <Servo.h>

Servo servoLeft;

void setup() 
{
  servoLeft.attach(13);
  servoLeft.writeMicroseconds(1700);

}

void loop() 
{
 

}
