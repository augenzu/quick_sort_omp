#include "test.h"
#include <iomanip>

void
time_testing(const std::vector<size_t> &elm_cnts,
        const std::string &fname)
{    
    // #pragma omp parallel num_threads(1)
    // then set it to 2; 4; 8; 16; ...
    
    // this is what we will return from this function
    // and exactly what we wanna get from this all stuff
    std::vector<double> timings{};
    
    for (const auto &elm_cnt : elm_cnts) {
        int *data = test_data(elm_cnt);

        // measure start cpu time
        clock_t start = clock();

        q_sort(data, elm_cnt);

        // we assume here that q_sort function has already been tested
        // and hence result data doesn't need to to be checked for non-decreasing 

        // measure end time
        clock_t end = clock();

        // calculate the difference & store it
        double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        timings.push_back(elapsed);

        delete[] data;
    }

        // measure end time
        double end = omp_get_wtime();

    // save timings
    fout << "num_threads: " << omp_get_num_threads() << std::endl;
    fout << "elm_cnts: ";
    for (auto elm_cnt: elm_cnts) {
        fout << elm_cnt << " ";
    }
    fout << std::endl << "timings:" << std::endl;
    for (auto timing: timings) {
        fout << timing << " ";
    }
    fout << std::endl;
}