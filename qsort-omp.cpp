#include "qsort-omp.h"

void 
q_sort(int *data, long long end, size_t n_threads) 
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

    #pragma omp parallel sections num_threads(n_threads)
    {
        #pragma omp section // shared(data) firstprivate(forw, backw)
        {
            if (backw > 0) {
                q_sort(data, backw);
            }
        }
        #pragma omp section // shared(data) firstprivate(forw, backw)
        {
            if (forw < end) {
                q_sort(data + forw, end - forw);
            }
        }
    }
}