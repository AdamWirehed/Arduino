/*
Robotics with the BOE Shield – AroundAndAround
Generate a servo full speed counterclockwise signal with pin 13 and full speed clockwise signal with pin 12.
Then turn 180° and do it again.
*/

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void setup() 
{
  servoLeft.attach(13);
  servoRight.attach(12);
  
}

void loop() 
{
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1633);
  delay(12000);


  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1520);
  delay(2070);


  //servoLeft.detach();
  //servoRight.detach(); 

}
