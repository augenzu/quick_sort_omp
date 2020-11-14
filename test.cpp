#include "test.h"
#include <iomanip>

void
time_testing(long long limit, 
        const std::vector<size_t> &elm_cnts)
{    
    // this is what we will return from this function
    // and exactly what we wanna get from this all stuff
    std::vector<double> timings{};

    for (auto elm_cnt : elm_cnts) {
        int *data = test_data(elm_cnt);

        // measure start time
        double start = omp_get_wtime();

        #pragma omp parallel shared(data)
        {
            #pragma omp single nowait
            q_sort(data, elm_cnt - 1, limit);
        }

        // measure end time
        double end = omp_get_wtime();

        // calculate the difference & store it
        double elapsed = end - start;
        timings.push_back(elapsed);

        delete[] data;
    }

    // save timings
    for (auto timing: timings) {
        std::cout << std::setw(12) << std::setprecision(8) << std::fixed << timing;
    }
}