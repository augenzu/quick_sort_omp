#include "qsort-omp.h"
#include <iostream>
#include <string>

void
q_sort(int *data, long long end, size_t n_threads)
{
    std::cout << std::string(std::to_string(omp_get_thread_num()) + "\n");

    long long forw = 0;
    long long backw = end;

    int middle_val = data[end >> 1];

    while (forw <= backw) {
        while(data[forw] < middle_val) {
            ++forw;
        }
        while (data[backw] > middle_val) {
            --backw;
        }
        if (forw <= backw) {
            std::swap(data[forw], data[backw]);
            ++forw;
            --backw;
        }
    } 

    if (backw > 0) {
        #pragma omp task shared(data) firstprivate(forw, backw)
        q_sort(data, backw);
    }
    if (forw < end) {
        #pragma omp task shared(data) firstprivate(forw, backw)
        q_sort(data + forw, end - forw);
    }
    #pragma omp taskwait
}

