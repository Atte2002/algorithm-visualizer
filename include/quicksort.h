#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include "event.h"

class Quicksort 
{
public:
    Quicksort(std::vector<Event>& events);
    void sort(std::vector<int>& arr);
private: 
    void quicksort(std::vector<int>& arr, int left, int right);
    int partition(std::vector<int>& arr, int left, int right);
    std::vector<Event>& m_events;
};

#endif
