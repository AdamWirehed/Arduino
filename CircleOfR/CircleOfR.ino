/*
 * Robotics with the BOE Shield - TestManeuverFunction
 * Move forward, left, right, then backward with maneuver function.
*/

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

float r = 0;          // Radius of circle[cm]
float x = 5.65;       // Distance between wheels divided by 2
int rightSpeed = 75;  // Speed of right wheel 

void setup() 
{
  servoLeft.attach(13);
  servoRight.attach(12);

  float leftRadius = 2*(r - x)*(PI);
  float rightRadius = 2*(r + x)*(PI);

  servoLeft.writeMicroseconds((1500 + leftRadius/rightRadius*rightSpeed));    // Set Left servo speed
  servoRight.writeMicroseconds(1500 - rightSpeed);   // Set Right servo speed
  // delay(6150);

  // servoLeft.writeMicroseconds(1500);
  // servoRight.writeMicroseconds(1500);
}

void loop() 
{ 
}
