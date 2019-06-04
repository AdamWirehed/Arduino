#include <Servo.h>

// Start measuring time
unsigned long startTime = millis();

// Define pin for ping-sensor
int pingPin =11;

Servo servoLeft;
Servo servoRight;



//---------------------------------------------------//
void setup() {
  Serial.begin(9600);
  
  // Define pin for left and right servo and attach
  servoLeft.attach(13);
  servoRight.attach(12);
  

  float spinTimeReturned = spin();
  Serial.println("\n");
  Serial.println(spinTimeReturned);
  
}
//--------------------------------------------------.//
void loop(){

  
}

//-------------------FUNCTIONS----------------------//

float spin() {
  long duration, cm;

  
  int pulser = 1550;
  int pulsel = 1550;

  servoLeft.writeMicroseconds(pulsel);
  servoRight.writeMicroseconds(pulser);  
  
  float startTime = millis();
  float currentTime = millis();
  int i = 0;
  float distance[200] = {};
  float times[200] = {};
  float elapsedTime;
   
  while (currentTime-startTime < 3000){
    
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

//    distance[i][0] = i;
//    distance[i][1] = elapsedTime;
//    distance[i][2] = cm;
    distance[i] = cm;
    times[i] = elapsedTime;
    
    Serial.print(i);
    Serial.print("\t");
    Serial.print(distance[i]);
    Serial.print("\t");
    Serial.print(times[i]);
    Serial.print("\n");
    
    i = i +1;
  }

  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  
  float maxValue = 0;
  float spinTime = 0;
  float valueCheck;
  
  for (int j=0; j < i; j++)
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
