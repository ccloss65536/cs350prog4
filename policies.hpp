#pragma once
#ifndef POLICIES_HPP_
#define POLICIES_HPP_

#include <vector>

// PRP function pointer type
typedef int (*PageReplacementPolicy)(const std::vector<int>&);

int PRP_FIFO(const std::vector<int>& workload);

#endif /* end of include guard: POLICIES_H_ */
