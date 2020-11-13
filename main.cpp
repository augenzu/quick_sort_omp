#include "test.h"

int
main(int argc, char **argv)
{
    std::vector<size_t> elm_cnts{ 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000 };
    std::string fname = std::string("timings/") + argv[1] + ".txt";

    time_testing(elm_cnts, fname);
    
    return 0;
}
