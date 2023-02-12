#include "Rad.h"

Rad::Rad(uint16_t adress, double initialPwm, uint8_t feedbackPin):Rueda(adress, initialPwm, feedbackPin){
  anglePast = get_angle();
  k = .01;
  wheelDistance = 0;
}

double Rad::move(int speedSP, bool cw){
  int s;
  if(cw) s = 1;
  else s = -1;
  unsigned long initialTime = millis();
  mover(pwm);
  delay(1);

  float angleNow = get_angle();
  float deltaAngle = operations.turnOrNot(angleNow, anglePast, cw);
  double deltaTime = millis() - initialTime;

  currentSpeed = s * 1000 * deltaAngle / deltaTime;
  currentSpeed = operations.convolutionFilter(currentSpeed);
  currentSpeed = operations.spikeFilter(currentSpeed, speedSP);

  pwm = (pwm - (speedSP - currentSpeed) * k * s);
  pwm = operations.stayInTheLimits(pwm, cw);

  double deltaPosition = currentSpeed * (deltaTime / 1000) * 3.1416 * 6.5 / 360;
  anglePast = angleNow;
  wheelDistance += deltaPosition;
  return deltaPosition;
}
void Rad::stop(){
  mover(initialPwm);
  anglePast = get_angle();
  set_pwm(initialPwm);
  wheelDistance = 0;
}

double Rad::get_currentSpeed(){
  return currentSpeed;
}
double Rad::get_wheelDistance(){
  return wheelDistance;
}
