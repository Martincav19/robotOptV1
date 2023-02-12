#pragma once
#include <Arduino.h>
#include <string.h>
#include "Rueda.h"
#include "Operations.h"
using namespace std;

class Rad : public Rueda {
private:
  double currentSpeed;
  float anglePast;
  double wheelDistance;
  Operations operations;
  float k;

public:
  Rad(uint16_t, double, uint8_t);

  double move(int, bool);
  void stop();

  double get_currentSpeed();
  double get_wheelDistance();
};
