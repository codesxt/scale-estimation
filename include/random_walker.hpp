#ifndef RandomWalker_H
#define RandomWalker_H

#include <random>
#include <iostream>

using namespace std;

class RandomWalker{
public:
  RandomWalker(float mean, float var);

  default_random_engine generator;
  normal_distribution<double> rwalk;

  double getSample();
private:
  float mean;
  float var;
  float p_mean;
};

#endif //RandomWalker
