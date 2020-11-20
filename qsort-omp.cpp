#include "qsort-omp.h"
#include <iostream>
#include <string>

void
q_sort(int *data, long long end, long long limit)
{
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
        if (backw < limit) {
            q_sort(data, backw, limit);
        } else {
            #pragma omp task shared(data) firstprivate(forw, backw)
            q_sort(data, backw, limit);
        }
    }
    if (forw < end) {
        if (end - forw < limit) {
            q_sort(data + forw, end - forw, limit);
        } else {
            #pragma omp task shared(data) firstprivate(forw, backw)
            q_sort(data + forw, end - forw, limit);
        }
    }
    #pragma omp taskwait
}
