#include <Arduino.h>

void setup()
{
  // Set which
  pinMode(7, OUTPUT);
}

void loop()
{
  uint8_t pinNumber = 7;
  // put your main code here, to run repeatedly:
  digitalWrite(pinNumber, HIGH); // on

  delay(1000);

  digitalWrite(pinNumber, LOW); // off

  delay(500);

  digitalWrite(pinNumber, HIGH); // on

  delay(500);

  digitalWrite(pinNumber, LOW); // off

  delay(500);

  digitalWrite(pinNumber, HIGH); // on

  delay(500);

  digitalWrite(pinNumber, LOW); // off

  delay(500);

  digitalWrite(pinNumber, HIGH); // on

  delay(500);

  digitalWrite(pinNumber, LOW); // off

  delay(500);
}
