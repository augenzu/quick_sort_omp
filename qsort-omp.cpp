#include "qsort-omp.h"

#include <string>

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
            std::string ldata{"thread_num: "};
            ldata += std::to_string(omp_get_thread_num());
            ldata += "; ltask; ldata:";
            for (int i = 0; i < backw; ++i) {
                ldata += " " + std::to_string(data[i]);
            }
            ldata += "\n";
            std::cout << ldata;

            q_sort_iter(data, backw);
        }
    }

    #pragma omp task shared(data) firstprivate(forw, backw)
    {
        if (forw < end) {
            std::string rdata{"thread_num: "};
            rdata += std::to_string(omp_get_thread_num());
            rdata += "; rtask; rdata:";
            for (int i = forw; i < end; ++i) {
                rdata += " " + std::to_string(data[i]);
            }
            rdata += "\n";
            std::cout << rdata;

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
            std::cout << "begin\n";
            q_sort_iter(data, end);
        }
    }
}
