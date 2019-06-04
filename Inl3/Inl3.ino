#include <Servo.h>

Servo servoLeft; 
Servo servoRight;

void setup()
{
  tone(4, 3000, 1000); 
  delay(1000);
  
  Serial.begin(9600);
  servoRight.attach(13);
  servoLeft.attach(12);
}

void loop()
{
  for(int pulseWidth = 1500; pulseWidth <= 1700; pulseWidth += 10)
  {
    Serial.print("pulseWidth = ");            // Display pulseWidth value
    Serial.println(pulseWidth);
    Serial.println("Press a key and click");  // User prompt
    Serial.println("Send to start servo...");

    Serial.read();
    while(Serial.available() == 0);   // Wait for character  
    Serial.read();                    // Clear character
    Serial.println("Running..."); 
    //servoLeft.writeMicroseconds(pulseWidth); // Pin 12 servo speed = pulse 
    //delay(6000);                             // ..for 6 seconds
    //servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(pulseWidth); // Pin 13 servo speed = pulse
    delay(6000);
    servoRight.writeMicroseconds(1500);
    }
}
