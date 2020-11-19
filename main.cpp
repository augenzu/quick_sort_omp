#include "test.h"
#include <string>

constexpr long long LIMIT{1024};

int
main(int argc, char **argv)
{
    std::vector<size_t> elm_cnts{ 16000, 32000, 64000, 128000, 256000, 512000, 
            1024000, 2048000, 4096000, 8192000 };
    std::string fname{std::string("timings/") + argv[1] + ".txt"};
    long long limit{LIMIT};
    if (argc > 2) {
        limit = std::stoll(argv[1]);  
    }

    time_testing(elm_cnts, fname, limit);
    
    return 0;
}
