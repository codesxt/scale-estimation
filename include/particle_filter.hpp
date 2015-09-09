#ifndef PARTICLE_FILTER_H
#define PARTICLE_FILTER_H

#include <vector>
#include <random>

using namespace std;

class Particle{
public:
  double value;
  Particle();
private:

};

class ParticleFilter{
public:
  ParticleFilter(int _n_particles);
  double getEAPEstimate();
  double getMAPEstimate();
  void update();
private:
  double particle_stddev;
  vector<Particle> particles;
  vector<double> weights;
};

#endif
