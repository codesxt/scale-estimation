#ifndef VISUAL_SENSOR_H
#define VISUAL_SENSOR_H

#include <random>
#include <iostream>

using namespace std;

class VisualSensor{
public:
  VisualSensor(float _mean, float _stddev);

  default_random_engine generator;

  void setMean(float _mean);
  double getMeasurement();
  normal_distribution<double> gaussian;
private:
  float mean;
  float stddev;
};

#endif //VISUAL_SENSOR_H
