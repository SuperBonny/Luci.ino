#include "sensor.h"

Sensor::Sensor(unsigned int read_interval)
{
  interval = read_interval;
}

int Sensor::setup()
{
  if (sensor.begin())
  {
    sensor.setGain(TSL2561_GAIN_0X);
    sensor.setTiming(TSL2561_INTEGRATIONTIME_13MS);
    return 0;
  }

  return -1;
}

bool Sensor::loop()
{
  if (millis() - wait_start >= interval)
  {
    wait_start = millis();
    lux = sensor.getLuminosity(TSL2561_VISIBLE);
    return true;
  }
  return false;
}

unsigned int Sensor::get_lux()
{
  return lux;
}