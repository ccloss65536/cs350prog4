#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <utility>
#include "workloads.hpp"
#include "policies.hpp"

using std::ofstream;
using std::vector;
using std::get;
using std::pair;

#define NUM_ACCESSES 10000
#define MIN_MEM_SIZE 5
#define MAX_MEM_SIZE 100
#define NUM_PAGES 5
#define STEP 5

static const int INVALID_PAGE = -1;

int main(int argc, char** argv){
	vector<pair<std::string,Workload>> workloads({pair<std::string,Workload>("nonlocal",workload_nonlocal), pair<std::string, Workload>("80-20", workload_80_20), pair<std::string, Workload>("looping", workload_looping)}); 
	vector<PageReplacementPolicy> policies({PRP_OPT, PRP_LRU, PRP_FIFO, PRP_RAND, PRP_CLOCK});
	vector<int> access_sequence(NUM_ACCESSES, INVALID_PAGE);
	for(auto w : workloads){
		ofstream file(w.first + ".csv");
		for(int memsize = MIN_MEM_SIZE; memsize <= MAX_MEM_SIZE; memsize += STEP){
			file << memsize << ',';  
			for(auto p : policies){
				w.second(access_sequence, NUM_PAGES);
				double correct = (double)p(access_sequence, memsize);
				file << correct/NUM_ACCESSES * 100 << ',';
			}
			file.seekp(-1, std::ios_base::cur); //Overwrite the hanging comma with the newline coming up
			file << std::endl;
		}
		file.close();
		std::ostringstream cmd;
		cmd << "gnuplot -e \" title=\'" << w.first << "\'\" input_filename=\'" << w.first << ".csv\'\" plot_hit_rates.plt\" > " << w.first << "_plot.png";
		system(cmd.str().data()); 
	} 
}

