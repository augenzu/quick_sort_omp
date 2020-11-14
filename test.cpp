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
    fout << "nums_threads: ";
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

//------------------------------------------------------------------


std::vector<std::function<void()>> tests{
    []()
    {
        int data[] = {2, 5, 4, 3, 6, 7, 3};
        q_sort(data, 6);
        print(data, 7);
    },
    []()
    {
        int data[] = {2, 5};
        q_sort(data, 1);
        print(data, 2);
    },
    []()
    {
        int data[] = {2, 1};
        q_sort(data, 1);
        print(data, 2);
    },
    []()
    {
        int data[] = {1};
        q_sort(data, 0);
        print(data, 1);
    },
    []()
    {
        int data[] = {4, 7, 3, 6, 8, 2, 4, 6, 5, 1, 9, 4, 6, 2, 4, 2, 1, 6, 6, 5, 4, 7, 6, 8, 9, 9};
        q_sort(data, 25);
        print(data, 26);
    },
    []()
    {
        int data[] = {4, 7, 3, 6, 8, 2, 4, 6, 5, 1, 9, 4, 2, 4, 2, 1, 6, 6, 5, 4, 7, 6, 8, 9, 9};
        q_sort(data, 24);
        print(data, 25);
    },
    []()
    {
        int data[] = {4, 7, 3, 6};
        q_sort(data, 3);
        print(data, 4);
    },
    []()
    {
        int data[] = {4, 7, 3, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
        q_sort(data, 14);
        print(data, 15);
    },
    []()
    {
        int data[] = {4, 7, 3, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
        q_sort(data, 15);
        print(data, 16);
    },
    []()
    {
        int data[] = {4, 4, 4, 7, 3, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
        q_sort(data, 17);
        print(data, 18);
    }
};

void
print(int *data, size_t data_len)
{
    for (size_t i = 0; i < data_len; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void
testing()
{
    for (auto &test: tests) {
        test();
    }
}
