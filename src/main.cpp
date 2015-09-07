#include <string>
#include <iostream>
#include <random>
#include <boost/program_options.hpp>
#include <../include/random_walker.hpp>
#include <../include/visual_sensor.hpp>
#include <../include/metric_sensor.hpp>
#include <../include/particle_filter.hpp>
#include <math.h>
#include <fstream>

using namespace std;
namespace po = boost::program_options;

int main( int argc, char** argv )   {
	ofstream synthetic_data;
	ofstream sample_pairs;
	synthetic_data.open("../data/data.csv");
	sample_pairs.open("../data/sample_pairs.csv");
	float rwalk_mean = 0.0;
	float rwalk_stddev = 0.001;
	float m_sensor_mean = 0.0;
	float m_sensor_stddev = 0.05;
	float v_sensor_mean = 0.0;
	float v_sensor_stddev = 0.05;

	ParticleFilter pfilter(100);

  po::options_description desc("Scale Estimation Options");

  desc.add_options()
    ("help", "Prints this message.");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if(vm.count("help"))
    cout << desc << endl;

	RandomWalker drift(rwalk_mean, rwalk_stddev);
	VisualSensor vsensor(v_sensor_mean, v_sensor_stddev);
	MetricSensor msensor(m_sensor_mean, m_sensor_stddev);

	//Generate Artificial Data
	std::default_random_engine generator;
	std::uniform_real_distribution<float> uniform(0.2,1);
	float alpha = uniform(generator);

	int nsecs = 20;
	int millis = (1000*nsecs);

	float scale = 2.0;
	//float scaleEstimate = 1.0;
	vector<double> height_values;
	vector<double> metric_measurements;
	vector<double> visual_measurements;
	for(int i=0; i<millis; i++){
		double dr = drift.getSample();
		float t = i/1000.0;
		double true_height = sin(alpha*t);

		//Metric sensor generation
		msensor.setMean(true_height + dr);
		double metric_measurement = msensor.getMeasurement();

		//Visual measurement generation
		vsensor.setMean(true_height*scale);
		double visual_measurement = vsensor.getMeasurement();

		height_values.push_back(true_height);
		metric_measurements.push_back(metric_measurement);
		visual_measurements.push_back(visual_measurement);

		int k_window = 30;
		if(i > 80){
			if(i % 40 == 0){
				// Get visual measurement
				double x_i = visual_measurements.at(i) - visual_measurements.at(i-40);
				double i_sample = 0;
				double i_k_sample = 0;
				for(int j=0; j<k_window; j+=1){
					i_sample += metric_measurements.at(i-j);
					i_k_sample += metric_measurements.at((i-40)-j);
				}
				double a_i = i_sample / 30.0;
				double a_i_k = i_k_sample / 30.0;
				double y_i = a_i - a_i_k;
				sample_pairs << t << "," << x_i << "," << y_i << endl;
			}
		}
		synthetic_data << t << "," <<true_height << "," << metric_measurement << "," << visual_measurement << endl;
	}
	synthetic_data.close();
	sample_pairs.close();
}
