#include "test.h"

int
main(int argc, char **argv)
{
    // int data[]{ 3, 5, 8, 6, 7, 2, 1, 4 };
    int sz = 20;
    int *data = test_data(sz);

    // clock_t start = clock();
    q_sort(data, sz - 1);

    std::string sdata{"sorted data:"};
    for (int i = 0; i < sz; ++i) {
        sdata += " " + std::to_string(data[i]);
    }
    sdata += "\n";
    std::cout << sdata;

    // clock_t end = clock();

    // delete[] data;
    // double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  
    // std::string fname = std::string("timings/") + argv[1] + ".txt";
    // std::ofstream fout{ fname };
    // fout << elapsed << std::endl;
    
    return 0;
}
