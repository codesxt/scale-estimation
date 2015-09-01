#include "../include/random_walker.hpp"

RandomWalker::RandomWalker(float _mean, float _var){
  p_mean = 0.0;
  mean = _mean;
  var = _var;
  normal_distribution<double> rwalk(mean,var);
}

double RandomWalker::getSample(){
  normal_distribution<double> rwalk(p_mean,var);
  double value = rwalk(generator);
  p_mean = value;
  return value;
}
