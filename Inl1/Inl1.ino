void setup() {
  pinMode(13, OUTPUT);
  for(int i = 1; i <= 50; i++)
  {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    Serial.println(i);
    }
    digitalWrite(13, HIGH);
}

void loop() {
}
