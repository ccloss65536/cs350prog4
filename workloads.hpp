#pragma once 

#include <stdlib.h>
#include <random>
#include <ctime>

using std::vector
typedef void (*Workload)(vector<int>&, int );

/*\brief Simulates a page workload that does not exhibit locality,
 * which here is accomplished with generating random page numbers
 *
 * param vector<int>& workload the vector to fill with the workload, which 
 * should already be of the proper size
 * param num_pages the number of addressable pages
 */
void workload_nonlocal(vector<int>& workload);

/*\brief Simulates a page workload following the 80-20 rule
 * which here will simply be pages 0 - 20 getting 80% of the accesses
 * 
 * param vector<int>& workload the vector to fill with the workload, which 
 * should already be of the proper size
 * param num_pages the number of addressable pages
 */
void workload_80_20(vector<int>& workload);

/*\brief Simulates a page workload that repeats 0,1,2,...,50 twice
 * 
 * param vector<int>& workload the vector to fill with the workload, which 
 * should already be of the proper size
 * param num_pages the number of addressable pages
 */
void workload_looping(vector<int>& workload);
