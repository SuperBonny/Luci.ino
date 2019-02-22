#ifndef THRESHOLD_H
#define THRESHOLD_H

#include <Arduino.h>

class Threshold
{
  int low, high;
  bool toggle = false;

  unsigned int wait;
  unsigned long prev_time;
  bool waiting = false;

public:
  Threshold(int low, int high, int wait) : low(low), high(high), wait(wait) {}
  void loop(int lux);
  bool toggled();
};
#endif