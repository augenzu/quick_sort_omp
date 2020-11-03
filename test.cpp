#include "test.h"

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

std::vector<std::vector<double>>
time_testing(const std::vector<size_t> &nums_threads, 
        const std::vector<size_t> &elm_cnts)
{
    // this is what we will return from this function
    // and exactly what we wanna get from this all stuff

    // std::vector<std::vector<double>> timings{
    //     nums_threads, 
    //     std::vector<double>{elm_cnts}
    // };
    std::vector<std::vector<double>> timings{};
    
    for (const auto &num_threads : nums_threads) {
        timings.push_back(std::vector<double>{});
        for (const auto &elm_cnt : elm_cnts) {
            int *data = test_data(elm_cnt);

            // measure start cpu time
            clock_t start = clock();

            q_sort(data, elm_cnt, num_threads);

            // we assume here that q_sort function has already been tested
            // and hence result data doesn't need to to be checked for non-decreasing 

            // measure end time
            clock_t end = clock();

            // calculate the difference & store it
            double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            timings.back().push_back(elapsed);

            delete[] data;
        }
    }

    return timings;
}