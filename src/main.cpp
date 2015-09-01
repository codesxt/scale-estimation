#include <string>
#include <iostream>
#include <random>
#include <boost/program_options.hpp>
#include <../include/random_walker.hpp>
#include <math.h>

using namespace std;
namespace po = boost::program_options;

int main( int argc, char** argv )   {
	float rwalk_mean = 0.0;
	float rwalk_var = 0.001;
	float m_sensor_mean = 0.0;
	float m_sensor_var = 0.6;
	float v_sensor_mean = 0.0;
	float v_sensor_var = 0.3;

  po::options_description desc("Scale Estimation Options");

  desc.add_options()
    ("help", "Prints this message.");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if(vm.count("help"))
    cout << desc << endl;

	RandomWalker rwalk(rwalk_mean, rwalk_var);

	//Generate Artificial Data
	std::default_random_engine generator;
	std::uniform_real_distribution<float> uniform(0.2,1);
	normal_distribution<double> metric_sensor(m_sensor_mean, m_sensor_var);
	normal_distribution<double> visual_sensor(v_sensor_mean, v_sensor_var);
	int nsecs = 20;
	int millis = (1000*nsecs);
	float scale = 2.0;
	float alpha = uniform(generator);
	for(int i=0; i<millis; i++){
		double rw = rwalk.getSample();
		float t = i/1000.0;
		float true_height = sin(alpha*t);

		//Metric sensor generation
		normal_distribution<double> metric_sensor(true_height + rw, m_sensor_var);
		float metric_measurement = metric_sensor(generator);

		//Visual measurement generation
		normal_distribution<double> visual_sensor(true_height*scale, v_sensor_var);
		float visual_measurement = visual_sensor(generator);

		cout << t << "," <<true_height << "," << metric_measurement << "," << visual_measurement << endl;
	}
}
