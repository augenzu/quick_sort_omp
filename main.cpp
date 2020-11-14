#include "test.h"
#include <string>

int
main(int argc, char **argv)
{
    long long limit = std::stoll(argv[1]);
    std::vector<size_t> elm_cnts{ 4000, 6000, 8000, 16000, 32000, 64000, 128000, 
		256000, 512000, 1024000, 2048000, 4096000, 8192000 };

    time_testing(limit, elm_cnts);
    
    return 0;
}
