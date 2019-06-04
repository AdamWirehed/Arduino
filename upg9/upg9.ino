// Robotics with the BOE Shield - RoamingWithWhiskers
// Go forward.  Back up and turn if whiskers indicate BOE Shield bot bumped
// into something.

#include <Servo.h>                           // Include servo library

 
Servo servoLeft;                             // Declare left and right servos
Servo servoRight;
 
void setup()                                 // Built-in initialization block
{
  pinMode(7, INPUT);                         // Set right whisker pin to input
  pinMode(5, INPUT);                         // Set left whisker pin to input  

  //tone(4, 3000, 1000);                       // Play tone for 1 second
  //delay(1000);                               // Delay to finish tone

  servoLeft.attach(13);                      // Attach left signal to pin 13
  servoRight.attach(12);                     // Attach right signal to pin 12
  

int x = 400;
int y = 1000;

int t = 3000;

forward(t);

turnRight(y+x);

forward(t/2.5);

turnLeft(2*x);

forward(t/2.5);

turnRight(y+x-100);

forward(t);

servoLeft.writeMicroseconds(1500);
servoRight.writeMicroseconds(1500); 


}


void loop()                                  // Main loop auto-repeats
{

}

void forward(int time)                       // Forward function
{
  servoLeft.writeMicroseconds(1550);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1450);        // Right wheel clockwise
  delay(time);                               // Maneuver for time ms
}

void turnLeft(int time)                      // Left turn function
{
  servoLeft.writeMicroseconds(1450);         // Left wheel clockwise
  servoRight.writeMicroseconds(1450);        // Right wheel clockwise
  delay(time);                               // Maneuver for time ms
}

void turnRight(int time)                     // Right turn function
{
  servoLeft.writeMicroseconds(1550);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1550);        // Right wheel counterclockwise
  delay(time);                               // Maneuver for time ms
}

void backward(int time)                      // Backward function
{
  servoLeft.writeMicroseconds(1450);         // Left wheel clockwise
  servoRight.writeMicroseconds(1550);        // Right wheel counterclockwise
  delay(time);                               // Maneuver for time ms
}
