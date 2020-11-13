#include "test.h"

int
main(int argc, char **argv)
{
    int *data = test_data(1000000);

    clock_t start = clock();
    q_sort(data, 1000000);
    clock_t end = clock();
    double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  
    std::string fname = std::string("timings/") + argv[1] + ".txt";
    std::ofstream fout{ fname };
    fout << elapsed << std::endl;
    
    return 0;
}
