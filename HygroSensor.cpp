/*
  HygroSensor.h - Library for using LM393 Soil Hygrometer.
  Created by Rennan Cockles, November 1, 2021.
*/

#include "HygroSensor.h"

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  extern "C" {
    #include "WConstants.h"
  }
#endif

HygroSensor::HygroSensor(uint8_t digitalPin)
{
  pinMode(digitalPin, INPUT);

  _digitalPin = digitalPin;
  _value = DRY;
  _lastValue = DRY;
}

bool HygroSensor::valueChanged()
{
  return _value != _lastValue;
}

void HygroSensor::update()
{
  _lastValue = _value;
  _value = digitalRead(_digitalPin);
}

int HygroSensor::getValue()
{
  return _value;
}

String HygroSensor::getText()
{
  return isDry() ? "DRY" : "WET";
}

bool HygroSensor::isDry()
{
  return getValue() == DRY;
}

bool HygroSensor::isWet()
{
  return getValue() == WET;
}

bool HygroSensor::changedDry()
{
  return valueChanged() && isDry();
}

bool HygroSensor::changedWet()
{
  return valueChanged() && isWet();
}