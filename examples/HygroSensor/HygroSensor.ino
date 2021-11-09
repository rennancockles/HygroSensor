/*
  Program: LM393 Soil Hygrometer with ESP8266 NodeMCU
  Author: Rennan Cockles
*/

#include <HygroSensor.h>

int DELAY = 1000;

HygroSensor s0(D5);

void setup()
{
  Serial.begin(115200);
  Serial.println();
}

void loop()
{
  s0.update();

  if (s0.changedDry()) {
    Serial.println("Dry soil at sensor 0");
  }

  Serial.print("Sensor 0: ");
  Serial.println(s0.getText());

  delay(DELAY);
}
