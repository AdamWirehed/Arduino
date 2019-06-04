#include <Servo.h>

// Start measuring time
unsigned long startTime = millis();

// Define pin for ping-sensor
int pingPin = 11;

Servo servoLeft;
Servo servoRight;

//---------------------Setup------------------------//
void setup() {
  Serial.begin(9600);
  
  // Define pin for left and right servo and attach
  servoLeft.attach(13);
  servoRight.attach(12);
  
  float spinTimeReturned = spin();
  Serial.println("\n");
  Serial.println(spinTimeReturned);

  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(2000);
  
  drive(spinTimeReturned);
  
}
//----------------------Loop-----------------------.//
void loop()
{
  
  
}

//-------------------Functions----------------------//

float spin() {
  long duration, cm;

  servoLeft.writeMicroseconds(1530);
  servoRight.writeMicroseconds(1530);
  
  float startTime = millis();
  float currentTime = millis();
  int i = 0;
  
  float distance[80] = {};
  float times[80] = {};
  float elapsedTime;
   
  while (currentTime-startTime < 6150)
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

    delay(100);
    
    currentTime = millis();
    elapsedTime = currentTime - startTime;

    distance[i] = cm;
    times[i] = elapsedTime;
    
    /*
    Serial.print(i);
    Serial.print("\t");
    Serial.print(distance[i]);
    Serial.print("\t");
    Serial.print(times[i]);
    Serial.print("\n");
    */
    
    i = i +1;
  }
  
  float maxValue = 0;
  float spinTime = 0;
  float valueCheck;
  
  for (int j=0; j < i; j++)         // time of spin at max distance
    {
      valueCheck = distance[j];
      
      if (valueCheck > maxValue)
      {
        maxValue = valueCheck;
        spinTime = times[j];
      }
   }
  return spinTime;
}


float drive(float spinTime)
{
  long duration, cm;

  servoLeft.writeMicroseconds(1530);
  servoRight.writeMicroseconds(1530);
  delay(spinTime);

  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(1000);
  
  servoLeft.writeMicroseconds(1575);    // Set Left servo speed
  servoRight.writeMicroseconds(1425);   // Set Right servo speed

  cm = 1000;
  
  while(cm > 30)
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
    delay(100);
  }
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);
    delay(1000);
}
