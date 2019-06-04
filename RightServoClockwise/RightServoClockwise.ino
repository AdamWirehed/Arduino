/*
Robotics with the BOE Shield – RightServoClockwise
Generate a servo full speed clockwise signal on digital pin 13. */

#include <Servo.h>

Servo servoRight;

void setup() 
{
  servoRight.attach(12);
  servoRight.writeMicroseconds(1300);

}

void loop() 
{
 

}
