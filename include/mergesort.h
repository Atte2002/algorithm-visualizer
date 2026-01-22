#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include "event.h"

class Mergesort 
{
public:
    Mergesort(std::vector<Event>& events);
    void sort(std::vector<int>& arr);
private:
    std::vector<Event>& m_events;
    void mergesort(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>& arr, int left, int middle, int right); 
};

#endif
