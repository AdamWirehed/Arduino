/*
Robotics with the BOE Shield – ServoRunTimes
Generate a servo full speed counterclockwise signal with pin 13 and full speed clockwise signal with pin 12.
*/

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void setup() 
{
  servoLeft.attach(13);
  servoRight.attach(12);
  
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(12000);

  servoLeft.detach();
  servoRight.detach();

  //servoLeft.writeMicroseconds(1520);
  //servoRight.writeMicroseconds(1510);
  
}

void loop() 
{
 

}
