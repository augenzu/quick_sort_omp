#ifndef TEST_H
#define TEST_H

#include "generate-data.h"
#include "qsort-omp.h"
#include <cstdio>
#include <ctime>
#include <functional>
#include <iostream>
#include <vector>

void
print(int *, size_t);
void
testing();
// I'm not sure that's exactly I want to have here
// maybe we should use smth like std::pair or std::tuple instead of vecotrs...
// maybe vectors of necessary (what exactly?) size can't exist at all and hence we have to read data from files...
// I dunno...
std::vector<std::vector<double>>
time_testing(const std::vector<size_t> &, const std::vector<size_t> &);

#endif