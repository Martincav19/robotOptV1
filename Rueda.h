#pragma once
#include <Arduino.h>
#include <string.h>
using namespace std;

class Rueda
{
protected:
  double pwm; 
  double initialPwm;
private:
  uint16_t adress; //0x88 o 0x8A
  uint8_t feedbackPin;
  float angle;

public:
  Rueda();
  Rueda(uint16_t, double, uint8_t);

  void mover(double);

  double get_pwm();
  void set_pwm(double);
  float get_angle();
};