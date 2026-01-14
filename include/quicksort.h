#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

class Quicksort 
{
public:
    void sort(std::vector<int>& arr);
private: 
    void quicksort(std::vector<int>& arr, int left, int right);
    void swap(int& x, int& y);
    int partition(std::vector<int>& arr, int left, int right);
};

#endif
