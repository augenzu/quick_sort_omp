#include "test.h"
#include <iomanip>

void
time_testing(const std::vector<size_t> &elm_cnts,
        const std::string &fname, size_t num_procs,
        long long limit)
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

    std::ofstream fout(fname, std::ios::app);

    // save timings to file
    fout << std::setw(2) << num_procs;
    fout << std::setw(4) << omp_get_max_threads();
    for (auto timing: timings) {
        fout << std::setw(12) << std::setprecision(8) << std::fixed << timing;
    }
    fout << std::endl;
}