#include "test.h"

int
main()
{
    std::vector<size_t> nums_threads{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096 };
    std::vector<size_t> elm_cnts{ 1000, 10000, 100000, 1000000, 10000000, 100000000,
                                  1000, 10000, 100000, 1000000, 10000000, 100000000,
                                  1000, 10000, 100000, 1000000, 10000000, 100000000,
                                  1000, 10000, 100000, 1000000, 10000000, 100000000
                                };
    std::string fname = "timings/12-11-20.txt";

    time_testing(nums_threads, elm_cnts, fname);
    
    return 0;
}