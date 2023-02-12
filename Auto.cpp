#include "Auto.h"

Auto::Auto() : radRechts(0x88, 23800, A0), radLinks(0x8A, 24380, A1) {
  traveledDistance = 0;
  k = 20;
}

void Auto::moveForward(int desiredDistance, int speedSP){
  traveledDistance = 0;
  float deltaPositionRight = 0;
  float deltaPositionLeft = 0;

  while(traveledDistance < desiredDistance){
    int linksSpeedSP;

    linksSpeedSP = speedSP + (deltaPositionRight - deltaPositionLeft) * k;
      
    deltaPositionRight = radRechts.move(speedSP, true);
    deltaPositionLeft = radLinks.move(linksSpeedSP, false);
    traveledDistance += (deltaPositionRight + deltaPositionLeft)/2;
 
    Serial.print(radRechts.get_wheelDistance());
    Serial.print(",");
    Serial.println(radLinks.get_wheelDistance());
  }
  radRechts.stop();
  radLinks.stop();
}
void Auto::moveBackwards(int desiredDistance){}
void Auto::turnRight(int desiredDistance){}
void Auto::turnLeft(int desiredDistance){}

Rad Auto::get_radRechts(){
  return radRechts;
}
Rad Auto::get_radLinks(){
  return radLinks;
}
