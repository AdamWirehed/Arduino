/*
 * Robotics with the BOE Shield - StartResetIndicator
 * Test the piezospeaker circuit
 */

void setup() 
{
 Serial.begin(9600);
 Serial.println("Beep!");

 tone(4, 3000, 500);
 delay(1000);
}

void loop() {
  Serial.println("Waiting for reset...");
  delay(1000);

}
