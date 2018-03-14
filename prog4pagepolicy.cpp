#include <stdio.h>
#include <iostream>
#include <fstream>
#include "workloads.h"
#include "policies.h"

#define NUM_WORKLOADS 3
#define NUM_POLICIES 5
#define NUM_ACCESSES 10000

int main(int argc, char** argv){
	ofstream("data.csv");
	Workload workloads[NUM_WORKLOADS] = {workload_nonlocal, workload_80_20, workload_looping};
	PageReplacementPolicy policies[NUM_POLICIES] = {PRP_FIFO, PRP_OPT, PRP_RAND}
}

