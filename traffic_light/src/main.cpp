#include <Arduino.h>

const auto PIN_GREEN = 3;
const auto PIN_YELLOW = 5;
const auto PIN_RED = 7;

void setup()
{
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
}

void loop()
{
  // Green
  digitalWrite(PIN_GREEN, HIGH);
  delay(5000);
  digitalWrite(PIN_GREEN, LOW);

  // Yellow
  digitalWrite(PIN_YELLOW, HIGH);
  delay(1000);
  digitalWrite(PIN_YELLOW, LOW);

  // Red
  digitalWrite(PIN_RED, HIGH);
  delay(5000);
  digitalWrite(PIN_RED, LOW);
}
