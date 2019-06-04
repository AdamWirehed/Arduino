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
}  
 
void loop()                                  // Main loop auto-repeats
{
  byte wLeft = digitalRead(5);               // Copy left result to wLeft  
  byte wRight = digitalRead(7);              // Copy right result to wRight

  if((wLeft == 0) && (wRight == 0))          // If both whiskers contact
  {
    backward(500);                           // Back up 1 second
    int i = random(1,2);
    if(i == 1)
      {
        turnLeft(600);                      // Turn left about 90 degrees
        }                          
        else
        {
        turnRight(600);                   // Turn right about 90 degrees
        }
      }
      
  else if(wLeft == 0)                        // If only left whisker contact
  {
    backward(500);                          // Back up 1 second
    turnRight(500);                          // Turn right about 30 degrees
  }
  else if(wRight == 0)                       // If only right whisker contact
  {
    backward(500);                          // Back up 1 second
    turnLeft(500);                           // Turn left about 30 degrees
  }
  else                                       // Otherwise, no whisker contact
  {
    forward(20);                             // Forward 1/50 of a second
  }
}

void forward(int time)                       // Forward function
{
  servoLeft.writeMicroseconds(1600);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1400);        // Right wheel clockwise
  delay(time);                               // Maneuver for time ms
}

void turnLeft(int time)                      // Left turn function
{
  servoLeft.writeMicroseconds(1400);         // Left wheel clockwise
  servoRight.writeMicroseconds(1400);        // Right wheel clockwise
  delay(time);                               // Maneuver for time ms
}

void turnRight(int time)                     // Right turn function
{
  servoLeft.writeMicroseconds(1600);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1600);        // Right wheel counterclockwise
  delay(time);                               // Maneuver for time ms
}

void backward(int time)                      // Backward function
{
  servoLeft.writeMicroseconds(1400);         // Left wheel clockwise
  servoRight.writeMicroseconds(1600);        // Right wheel counterclockwise
  delay(time);                               // Maneuver for time ms
}
