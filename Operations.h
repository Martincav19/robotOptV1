#pragma once
#include <Arduino.h>
#include <string.h>
using namespace std;

class Operations{
private:
  float speedArr[16];
public:
  Operations();
  float convolutionFilter(float);
  float turnOrNot(float, float, bool);
  float spikeFilter(float, int);
  double stayInTheLimits(double, bool);
};