#include "mergesort.h"
#include "event.h"

Mergesort::Mergesort(std::vector<Event>& events)
    : m_events{events} 
{
}

void Mergesort::sort(std::vector<int>& arr)
{
    // Put original vector positions to front of the events array
    for(int i = 0; i < static_cast<int>(arr.size()); i++)
    {
        m_events.push_back(Event{EventType::INIT, i, arr.at(i)});
    }

    mergesort(arr, 0, arr.size() - 1);
}

void Mergesort::mergesort(std::vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int middle = left + (right - left) / 2;

        mergesort(arr, left, middle);
        mergesort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void Mergesort::merge(std::vector<int>& arr, int left, int middle, int right)
{
    int leftLength = middle - left + 1;
    int rightLength = right - middle;

    std::vector<int> tempL {};
    std::vector<int> tempR {};

    for(int i = 0; i < leftLength; i++)
    {   
        tempL.push_back(arr.at(left + i));
    }

    for(int i = 0; i < rightLength; i++)
    {
        tempR.push_back(arr.at(middle + 1 + i));
    }
    
    int i = 0; // for tempL
    int j = 0; // for tempR
    int k = left; // for arr

    while(i < leftLength && j < rightLength)
    {
        if(tempL.at(i) <= tempR.at(j))
        {
            arr.at(k) = tempL.at(i);
            m_events.push_back({EventType::WRITE, k, tempL.at(i)});
            i++;
        }
        else 
        {
            arr.at(k) = tempR.at(j);
            m_events.push_back({EventType::WRITE, k, tempR.at(j)});
            j++;
        }
        k++;
    }

    while(i < leftLength)
    {
        arr.at(k) = tempL.at(i);
        m_events.push_back({EventType::WRITE, k, tempL.at(i)});
        i++;
        k++;
    }

    while(j < rightLength)
    {
        arr.at(k) = tempR.at(j);
        m_events.push_back({EventType::WRITE, k, tempR.at(j)});
        j++;
        k++;
    }
}
