#pragma once
#ifndef POLICIES_HPP_
#define POLICIES_HPP_

#include <vector>

// PRP function pointer type
typedef int (*PageReplacementPolicy)(const std::vector<int>&, unsigned int); 
//Added memsize param to the function type, because this varies between runs as well.

int PRP_FIFO(const std::vector<int>& workload, unsigned int memsize);
int PRP_OPT(const std::vector<int>& workload, unsigned int memsize);
int PRP_RAND(const std::vector<int>& workload, unsigned int memsize);
int PRP_LRU(const std::vector<int>& workload, unsigned int memsize);
int PRP_Clock(const std::vector<int>& workload, unsigned int memsize);

#endif /* end of include guard: POLICIES_HPP_ */
