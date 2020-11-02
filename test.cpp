#include "test.h"

std::vector<std::function<void()>> tests{
    []()
    {
        int data[] = {2, 5, 4, 3, 6, 7, 3};
        q_sort(data, 6);
        print(data, 7);
    },
    []()
    {
        int data[] = {2, 5};
        q_sort(data, 1);
        print(data, 2);
    },
    []()
    {
        int data[] = {2, 1};
        q_sort(data, 1);
        print(data, 2);
    },
    []()
    {
        int data[] = {1};
        q_sort(data, 0);
        print(data, 1);
    },
    []()
    {
        int data[] = {4, 7, 3, 6, 8, 2, 4, 6, 5, 1, 9, 4, 6, 2, 4, 2, 1, 6, 6, 5, 4, 7, 6, 8, 9, 9};
        q_sort(data, 25);
        print(data, 26);
    },
    []()
    {
        int data[] = {4, 7, 3, 6, 8, 2, 4, 6, 5, 1, 9, 4, 2, 4, 2, 1, 6, 6, 5, 4, 7, 6, 8, 9, 9};
        q_sort(data, 24);
        print(data, 25);
    },
    []()
    {
        int data[] = {4, 7, 3, 6};
        q_sort(data, 3);
        print(data, 4);
    },
    []()
    {
        int data[] = {4, 7, 3, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
        q_sort(data, 14);
        print(data, 15);
    },
    []()
    {
        int data[] = {4, 7, 3, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
        q_sort(data, 15);
        print(data, 16);
    },
    []()
    {
        int data[] = {4, 4, 4, 7, 3, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
        q_sort(data, 17);
        print(data, 18);
    }
};

void
print(int *data, size_t data_len)
{
    for (size_t i = 0; i < data_len; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void
testing()
{
    for (auto &test: tests) {
        test();
    }
}