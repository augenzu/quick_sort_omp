#ifndef TEST_H
#define TEST_H

#include "generate-data.h"
#include "qsort-omp.h"
#include <cstdio>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

void
time_testing(long long, const std::vector<size_t> &);

#endif