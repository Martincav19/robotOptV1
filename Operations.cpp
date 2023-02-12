#include "Operations.h"

Operations::Operations(){}

float Operations::convolutionFilter(float currentSpeed){
  float speedSum = 0;
  for(int i = 0; i < 15; i++){
    speedArr[i] = speedArr[i + 1];
    speedSum += speedArr[i];
  }
  speedArr[15] = currentSpeed;
  speedSum += speedArr[15];
  currentSpeed = speedSum / 16;

  return currentSpeed;
}

float Operations::turnOrNot(float angleNow, float anglePast, bool cw){
  float deltaAngle;
  if(cw){
    if(0 < angleNow && angleNow < 180 && 180 < anglePast && anglePast < 360)
      deltaAngle = angleNow - anglePast + 360;
    else
      deltaAngle = angleNow - anglePast;
  }
  else{
    if(360 > angleNow && angleNow > 180 && 0 < anglePast && anglePast< 180)
      deltaAngle = angleNow - anglePast - 360;
    else
      deltaAngle = angleNow - anglePast;
  }
  return deltaAngle;
}
float Operations::spikeFilter(float currentSpeed, int speedSP){
  if(currentSpeed > speedSP + 200 || currentSpeed < -100)
    currentSpeed = speedSP / 2;
  return currentSpeed;
}
double Operations::stayInTheLimits(double pwm, bool cw){
  if(cw){
    if (pwm < 20480){
      pwm = 20480;
      }
    if(pwm > 23680){
      pwm = 23680;
      }
  }
  else{
    if (pwm < 24320){
      pwm = 24320;
    }
    if(pwm > 27520){
      pwm = 27520;
    }
  }
  return pwm;
}
