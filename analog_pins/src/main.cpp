#include <Arduino.h>

int ANALOG_INPUT_4 = A4; // analog constants prefixed with A
int PWM_PIN_9 = 9;       // PWM pin

void setup()
{
  pinMode(PWM_PIN_9, OUTPUT);
  pinMode(ANALOG_INPUT_4, INPUT);

  Serial.begin(9600);
}

void loop()
{
  // PWM pins
  // analogWrite(PWM_PIN_9, 255);

  // delay(1000);

  // analogWrite(PWM_PIN_9, 128);

  // delay(1000);

  // analogWrite(PWM_PIN_9, 10);

  // delay(1000);

  int input = analogRead(ANALOG_INPUT_4);
  Serial.println(input);

  delay(1000);
}
