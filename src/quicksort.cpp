#include "quicksort.h" 
#include "event.h"
#include <algorithm>

Quicksort::Quicksort(std::vector<Event>& events)
    : m_events{events}
{ 
}

void Quicksort::sort(std::vector<int>& arr)
{   
    if(arr.size() < 2)
    {
        return;
    }
    else 
    {   
        // Put original vector positions to front of the events array
        for(int i = 0; i < static_cast<int>(arr.size()); i++)
        {
            m_events.push_back(Event{EventType::INIT, i, arr.at(i)});
        }

        quicksort(arr, 0, arr.size() - 1);
    }
}

void Quicksort::quicksort(std::vector<int>& arr, int left, int right)
{
    if(left >= right)
    {
        return;
    }   
    else 
    {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

int Quicksort::partition(std::vector<int>& arr, int left, int right)
{
    int pivot = arr.at(right);
    int i = left - 1;
    
    for(int j = left; j <= right - 1; j++)
    {
        if(arr.at(j) < pivot)
        {
            i++;
            std::swap(arr.at(i), arr.at(j));
            m_events.push_back(Event{EventType::SWAP, i, j});
        }
    }
    i++;
    std::swap(arr.at(i), arr.at(right));
    m_events.push_back(Event{EventType::SWAP, i, right});

    return i; 
}
