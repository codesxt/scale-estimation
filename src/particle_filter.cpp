#include "../include/particle_filter.hpp"

#include <iostream>

using namespace std;

ParticleFilter::ParticleFilter(int _n_particles){
  // Create initial set of _n_particles
  double weight = 1.0 / _n_particles;
  particle_stddev = 1.0;
  default_random_engine generator;
  normal_distribution<double> gaussian;
  for(int i=0; i<_n_particles; i++){
    weights.push_back(weight);
    double mean = gaussian(generator);
    Particle p(mean);
  }
}
