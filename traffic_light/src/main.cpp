#include <Arduino.h>

const auto PIN_GREEN = 3;
const auto PIN_YELLOW = 5;
const auto PIN_RED = 7;
const int ON_DELAY = 3000;
const int ON_DELAY_2 = 1000;

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
  delay(ON_DELAY);
  digitalWrite(PIN_GREEN, LOW);

  // Yellow
  digitalWrite(PIN_YELLOW, HIGH);
  delay(ON_DELAY_2);
  digitalWrite(PIN_YELLOW, LOW);

  // Red
  digitalWrite(PIN_RED, HIGH);
  delay(ON_DELAY);
  digitalWrite(PIN_RED, LOW);
}
