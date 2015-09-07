#include "../include/metric_sensor.hpp"

MetricSensor::MetricSensor(float _mean, float _stddev){
  mean = _mean;
  stddev = _stddev;
  normal_distribution<double> gaussian(mean,stddev);
}

void MetricSensor::setMean(float _mean){
  mean = _mean;
}

double MetricSensor::getMeasurement(){
  normal_distribution<double> gaussian(mean,stddev);
  return gaussian(generator);
}
