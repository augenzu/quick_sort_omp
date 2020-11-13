#include "qsort-omp.h"

void 
q_sort_iter(int *data, long long end) 
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

    #pragma omp task shared(data) firstprivate(forw, backw)
    {
        if (backw > 0) {
            q_sort_iter(data, backw);
        }
    }

    #pragma omp task shared(data) firstprivate(forw, backw)
    {
        if (forw < end) {
            q_sort_iter(data + forw, end - forw);
        }
    }

    #pragma omp taskwait
}

void 
q_sort(int *data, long long end) 
{
    #pragma omp parallel num_threads(1) shared(data)
    // then set it to 2; 4; 8; 16; ...
    {
        #pragma omp single nowait
        {
            q_sort_iter(data, end);
        }
    }
}
