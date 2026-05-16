#include <Arduino.h>

int readPin = A0;
float scaleF = 0.01;

void setup()
{
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int readValue = analogRead(readPin);
  float calcValue = readValue / 1023 * 5; // 0 - 5v
  float temp = calcValue / scaleF;

  Serial.println(temp);

  delay(1000);
}
