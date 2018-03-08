#pragma once
#ifndef POLICIES_HPP_
#define POLICIES_HPP_

#include <vector>

// PRP function pointer type
typedef int (*PageReplacementPolicy)(const std::vector<int>&, int); 
//Added memsize param to the function type, because this varies between runs as well.

int PRP_FIFO(const std::vector<int>& workload, int memsize);
int PRP_OPT(const std::vector<int>& workload, int memsize);
int PRP_RAND(const std::vector<int>& workload, int memsize);


#endif /* end of include guard: POLICIES_HPP_ */
