#include <vector>
#include <unordered_set>
#include <random>
#include <ctime>
#include <algorithm>

using std::vector;
using std::uniform_int_disribution;
using std::default_random_engine

static const int INVALID_PAGE = -1;

/*!
 *  \brief Calculate number of page hits when using FIFO page replacement policy.
 *
 *  Calculates the number of page cache hits generated for a given sequence of
 *  page accesses when using the FIFO page replacement policy.
 *
 *  \param workload Vector of page accesses to evaluate

 *  \param memsize Memory size, in pages
 *  \return Number of cache hits generated by using FIFO policy
 */
int PRP_FIFO(const vector<int>& workload, int memsize) {
    int hits = 0;
    vector<int> cachedPages(memsize, INVALID_PAGE);
    vector<int>::size_type cachedPagesHead = 0;

    // Loop for each page access in workload
    for (int access : workload) {
        // Check if page being accessed is in the page cache
        if (std::count(cachedPages.begin(), cachedPages.end(), access) > 0) {
            // Page cache hit
            hits++;
        } else {
            // Page cache miss
            // Replace page at head of queue with the one being accessed
            cachedPages.at(cachedPagesHead) = access;
            // Move head of queue forward by one
            cachedPagesHead = (cachedPagesHead + 1) % cachedPages.size();
        }
    }

    return hits;
}

/*!
 *  \brief Calculate number of page hits when using optimal page replacement policy.
 *
 *  Calculates the number of page cache hits generated for a given sequence of
 *  page accesses when using the optimal page replacement policy.
 *
 *  \param workload Vector of page accesses to evaluate
 *	\param memsize Size of physical memory to work with (in pages)
 *
 *  \return Number of cache hits generated by using random policy
 */
int PRP_OPT(const vector<int>& workload, int memsize){
	std::unordered_set<int> pages_in_mem;
	int hits = 0;
	for(unsigned int i = 0; i < workload.size(); i++){
		if(pages_in_mem.count(workload[i]) > 0){
			hits++;
		} 
		else if(pages_in_mem.size() < memsize){
			pages_in_mem.insert(workload[i]);
		}
		else {
			std::unordered_set<int> replacement_canidiates = pages_in_mem;
			unsigned int j = i;
			for(;j < workload.size() && replacement_canidiates.size() > 1; j++){
				if(replacement_canidates.count(workload[j] > 0){
					replacement_canidiates.erase(workload[j]);
				}
			}
			pages_in_mem.erase( *(replacement_canidiates.begin()) );
			pages_in_mem.insert(workload[i]);
		}
	}
	return hits;
}

/*!
 *  \brief Calculate number of page hits when using random page replacement policy.
 *
 *  Calculates the number of page cache hits generated for a given sequence of
 *  page accesses when using the random page replacement policy.
 *
 *  \param workload Vector of page accesses to evaluate
 *	\param memsize Size of physical memory to work with (in pages)
 *
 *  \return Number of cache hits generated by using random policy
 */
int PRP_RAND(const vector<int>& workload, int memsize){
	vector<int> pages_in_mem;
	default_random_engine random_engine;
	random_engine.seed(std::time(NULL));
	uniform_int_distribution<int> gen(0 , pages_in_mem.size() - 1);
	int hits = 0;
	for(unsigned int i = 0; i < workload.size(); i++){
		bool found = false;
		for(unsigned int j = 0; j < pages_in_mem.size(); j++){
			if(pages_in_mem[j] == workload[i])){
				hits++;
				found = true;
				break;
			}
		}
		if(!found){
			if(pages_in_mem.size() < memsize){
				pages_in_mem.push_back(workload[i]);
			}
			else {
				unsigned int index = random_engine(gen);
				pages_in_mem[index] = workload[i];
			}
		}

	}
	return hits;
}

/*!
 *  \brief Calculate number of page hits when using LRU page replacement policy.
 *
 *  Calculates the number of page cache hits generated for a given sequence of
 *  page accesses when using the Least Recently Used page replacement policy.
 *
 *  \param workload Vector of page accesses to evaluate
 *  \param memsize Memory size, in pages
 *  \return Number of cache hits generated by using LRU policy
 */
int PRP_LRU(const vector<int>& workload, int memsize) {
    // TODO
    return 0;
}

int PRP_Clock(const vector<int>& workload, int memsize) {
    // TODO
    return 0;
}

