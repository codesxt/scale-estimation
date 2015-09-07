#include "../include/visual_sensor.hpp"

VisualSensor::VisualSensor(float _mean, float _stddev){
  mean = _mean;
  stddev = _stddev;
  normal_distribution<double> gaussian(mean,stddev);
}

void VisualSensor::setMean(float _mean){
  mean = _mean;
}

double VisualSensor::getMeasurement(){
  normal_distribution<double> gaussian(mean,stddev);
  return gaussian(generator);
}
