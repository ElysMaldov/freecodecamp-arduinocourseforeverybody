#include <Arduino.h>

int READER_PIN = A5;

void setup()
{
  pinMode(READER_PIN, INPUT);

  Serial.begin(9600);
}

void loop()
{
  int input = analogRead(READER_PIN);

  Serial.print("Raw Read: ");
  Serial.println(input);

  // We divide by 1023.0 because that's the max value for 10-bit resolution
  // Multiplying by 5.0 converts that ratio into a voltage scale
  float voltage = (input / 1023.0) * 5.0;

  Serial.print("Voltage: ");
  Serial.println(voltage);

  delay(1000);
}
