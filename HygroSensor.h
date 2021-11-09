/*
  HygroSensor.h - Library for using LM393 Soil Hygrometer.
  Created by Rennan Cockles, November 1, 2021.
*/

#ifndef HygroSensor_h
#define HygroSensor_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define DRY	1
#define WET	0

class HygroSensor
{
  private:
    uint8_t _digitalPin;
    int _value;
    int _lastValue;
  public:
    HygroSensor(uint8_t digitalPin);
    bool valueChanged();
    void update();
    bool isDry();
    bool isWet();
    bool changedDry();
    bool changedWet();
    int getValue();
    String getText();
};

#endif