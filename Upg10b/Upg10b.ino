#include <Servo.h>

// Define pin for ping-sensor
int pingPin = 11;

Servo servoLeft;
Servo servoRight;

int distanceCheck = 0;

//---------------------------------------------------//
void setup() 
{
  Serial.begin(9600);
  
  // Define pin for left and right servo and attach
  servoLeft.attach(13);
  servoRight.attach(12);
}

void loop() 
{
  long duration, cm;

  servoLeft.writeMicroseconds(1575);    // Set Left servo speed
  servoRight.writeMicroseconds(1425);   // Set Right servo speed
  cm = 1000;

  while(distanceCheck < 2)
  {
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);
    
    pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);
    
    cm = duration / 29 /2;

    if(cm < 23)
    {
      distanceCheck = distanceCheck + 1;
    }
      else
      {
        distanceCheck = 0;
      }
    
    delay(100);
  }
    
    check();
    distanceCheck = 0;
}
  
void check(){
  long duration1, duration2;
    
  servoLeft.writeMicroseconds(1530);
  servoRight.writeMicroseconds(1530);
  delay(800);
  
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);
    pinMode(pingPin, INPUT);
    duration1 = pulseIn(pingPin, HIGH);

  servoLeft.writeMicroseconds(1470); 
  servoRight.writeMicroseconds(1470);                         
  delay(1600);
  
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);
    pinMode(pingPin, INPUT);
    duration2 = pulseIn(pingPin, HIGH);

  if(duration2 < duration1)
  {
    servoLeft.writeMicroseconds(1530);
    servoRight.writeMicroseconds(1530);
    delay(1600);
   }
}
