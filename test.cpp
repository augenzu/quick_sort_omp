#include "test.h"
#include <iomanip>

void
time_testing(const std::vector<size_t> &nums_threads, 
        const std::vector<size_t> &elm_cnts,
        const std::string &fname)
{    
    // this is what we will return from this function
    // and exactly what we wanna get from this all stuff
    std::vector<std::vector<double>> timings{};
    
    for (const auto &num_threads : nums_threads) {
        timings.push_back(std::vector<double>{});

        for (const auto &elm_cnt : elm_cnts) {
            int *data = test_data(elm_cnt);

            // measure start time
            double start = omp_get_wtime();

            #pragma omp parallel num_threads(num_threads) shared(data)
            {
                #pragma omp single nowait
                q_sort(data, elm_cnt - 1);
            }

            // measure end time
            double end = omp_get_wtime();

            // calculate the difference & store it
            double elapsed = end - start;
            timings.back().push_back(elapsed);

            delete[] data;
        }
    }

    std::ofstream fout{ fname };

    // save timings
    fout << "nums_threads:" << std::endl;
    for (auto num_threads: nums_threads) {
        fout << num_threads << " ";
    }
    fout << std::endl;
    fout << "elm_cnts:" << std::endl;
    for (auto elm_cnt: elm_cnts) {
        fout << std::setw(12) << elm_cnt;
    }
    fout << std::endl << "timings:" << std::endl;
    for (const auto &t_row: timings) {
        for (const auto &timing: t_row) {
            fout << std::setw(12) << std::setprecision(8) << std::fixed << timing;
        }
        fout << std::endl;
    }
}