#pragma once
#include <Arduino.h>
#include <string.h>
#include "Rueda.h"
#include "Rad.h"
#include "Operations.h"
using namespace std;

class Auto{
private:
  double traveledDistance;
  Rad radRechts;
  Rad radLinks;
  int k;
  int prueba;
public:
  Auto();
  void moveForward(int, int);
  void moveBackwards(int);
  void turnRight(int);
  void turnLeft(int);
  Rad get_radRechts();
  Rad get_radLinks();
};
