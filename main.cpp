#include "test.h"

int
main()
{
    std::vector<size_t> nums_threads{ 1, 2, 4, 8 };
    std::vector<size_t> elm_cnts{ 100, 1000 };
    std::string fname = "timings/12-11-20.txt";

    time_testing(nums_threads, elm_cnts, fname);
    
    return 0;
}