#include <string>
#include <iostream>
#include <random>
#include <boost/program_options.hpp>
#include <../include/random_walker.hpp>

using namespace std;
namespace po = boost::program_options;

int main( int argc, char** argv )   {
	float rwalk_var = 0.01;
	float rwalk_mean = 0.0;

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
	for(int i=0; i<1000; i++){
		double rw = rwalk.getSample();
		cout << "Step " << i << ": " << rw << endl;
	}
}
