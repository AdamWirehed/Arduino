/*
 * Morse Code, Inlämning 2
 * Code will loop through the text string, identify each character and translate the character..
 * into morse code and then display the signal on the LED light.
 */

int unit = 300; // Out length of one unit
char w[] = "SOS"; // Word that will translate into morse code

// Creating function for dot
void dot()
{
  digitalWrite(13, HIGH);
  delay(unit);
  digitalWrite(13, LOW);
  delay(unit);
}

// Creating function for dash
void dash()
{
  digitalWrite(13, HIGH);
  delay(unit*3);
  digitalWrite(13, LOW);
  delay(unit);
}

void setup() 
{
  pinMode(13, OUTPUT);
  for(int i = 0; i <= sizeof(w)-1;  i++)  // Looping through the text string
  {
    char tmpLetter = w[i]; // Getting the character from the string
    checkChar(tmpLetter); // Identifying the characters morse code
    digitalWrite(13, LOW);  // Turns off the light between letters
    delay(unit*3); // Space between letters
    }
}

void loop()
{
  }

void checkChar(char tmpLetter)  // Function that identifies the character in the string...
{                               // and puts out the morse code of that character
  switch (tmpLetter)
  {
    case 'O': // Morse code for letter "O"
      dash();
      dash();
      dash();
      break;

    case 'S': // Morse code for letter "S"
      dot();
      dot();
      dot();
      break;
      
    /*default:  // Invalid input from user
      Serial.println("No matching character");
      digitalWrite(13, HIGH);
      delay(1e9);
      break;
    */
  }
}
