#include "test.h"

int
main(int argc, char **argv)
{
    std::vector<size_t> nums_threads{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096 };
    std::vector<size_t> elm_cnts{ 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000};
    std::string fname = std::string("timings/") + argv[1] + ".txt";

    time_testing(nums_threads, elm_cnts, fname);
    
    return 0;
}