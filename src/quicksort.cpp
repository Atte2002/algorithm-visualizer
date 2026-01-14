#include "quicksort.h" 

void Quicksort::sort(std::vector<int>& arr)
{   
    if(arr.size() < 2)
    {
        return;
    }
    else 
    {
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

void Quicksort::swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
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
            swap(arr.at(i), arr.at(j));
        }
    }
    i++;
    swap(arr.at(i), arr.at(right));

    return i; 
}
