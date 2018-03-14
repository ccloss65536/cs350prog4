#include <stdlib.h>
#include <vector>
#include <random>
#include "workloads.hpp"

void workload_nonlocal(vector<int>& workload, int num_pages){
	default_random_engine random_engine;
	random_engine.seed(std::time(NULL));
	std::uniform_int_distribution<int> gen(0 , num_pages - 1);
	for(int i& : workload){ //We get to use convient syntax and still modify the array
		i = random_engine(gen);
	}
}
void workload_80_20(vector<int>& workload, int num_pages){
	default_random_engine random_engine;
	random_engine.seed(std::time(NULL));
	std::uniform_int_distribution<int> eighty(1 , 5); //if 1 or 2, use cold page. Otherwise, use a hot page
	std::uniform_int_distribution<int> hot_pages(0,  (2 * num_pages) / 5 - 1);
	std::uniform_int_distribution<int> cold_pages(2 * num_pages / 5, num_pages );
	for(int i& : workload){ //We get to use convient syntax and still modify the array
		if(random_engine(eighty) <= 2) i = random_engine(cold_pages);
		else i = random_engine(hot_pages);
	}
}

void workload_looping(vector<int>& workload int num_pages){
	int page = 0;
	for(int i& : workload){
		i = page;
		page %= num_pages / 2;
	}
}


