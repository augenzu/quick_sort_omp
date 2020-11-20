#include "test.h"
#include <string>

constexpr long long LIMIT{1024};

int
main(int argc, char **argv)
{
    std::vector<size_t> elm_cnts{ 256000, 512000, 
            1024000, 2048000, 4096000, 8192000 };
    std::string fname{std::string("timings/") + argv[1] + ".txt"};

    size_t num_procs{std::stoul(argv[2])};

    long long limit{LIMIT};
    if (argc > 3) {
        limit = std::stoll(argv[1]);  
    }

    time_testing(elm_cnts, fname, num_procs, limit);
    
    return 0;
}
