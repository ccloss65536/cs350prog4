#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "workloads.hpp"
#include "policies.hpp"

using std::ofstream;
using std::vector;
#define NUM_WORKLOADS 3
#define NUM_POLICIES 5
#define NUM_ACCESSES 10000

int main(int argc, char** argv){
	ofstream out("data.csv");
	vector<Workload> workloads({workload_nonlocal, workload_80_20, workload_looping});
	vector<PageReplacementPolicy> policies({PRP_FIFO, PRP_OPT, PRP_RAND});
}

