#include "test.h"

int
main(int argc, char **argv)
{
    std::vector<size_t> nums_threads{ 1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32,
		34, 36, 38, 40, 42, 44, 46, 68, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76,
		78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 102, 104, 106, 108, 120, 122, 124, 126,
		128 };
    std::vector<size_t> elm_cnts{ 1000, 2000, 4000, 6000, 8000, 16000, 32000, 64000, 128000, 256000 };
    std::string fname = std::string("timings/") + argv[1] + ".txt";

    time_testing(nums_threads, elm_cnts, fname);
    
    return 0;
}
