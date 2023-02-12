#include "Rueda.h"

Rueda::Rueda(){
  adress = 0;
  pwm = 0;
  angle = 0;
}
Rueda::Rueda(uint16_t adress, double initialPwm, uint8_t feedbackPin){
  this->adress = adress;
  pwm = initialPwm;
  this->feedbackPin = feedbackPin;
  this->initialPwm = initialPwm;
  _SFR_MEM16(adress) = initialPwm;
}

void Rueda::mover(double pwm){
  _SFR_MEM16(adress) = pwm;
}
float Rueda::get_angle(){
  float tHigh;
  float tLow;
  float tCycle;
  float dCycle;
  while (1){
    tHigh = pulseIn(feedbackPin, HIGH); // Measure high pulse
    tLow = pulseIn(feedbackPin, LOW); // Measure low pulse
    tCycle = tHigh + tLow; // Calculate cycle 
    if((tCycle > 1000) && (tCycle < 1200)) break; // Cycle time valid? Break!
  }
  dCycle = 100 * tHigh / tCycle;
  angle = (dCycle - 2.9) * 360 / (97.1 - 2.9 + 1);
  return angle;
}

double Rueda::get_pwm(){
  return pwm;
}
void Rueda::set_pwm(double pwm){
  this->pwm = pwm;
}