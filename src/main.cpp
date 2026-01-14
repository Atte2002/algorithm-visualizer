#include <SFML/Graphics.hpp>
#include <quicksort.h>
#include <vector>
#include <iostream>

int main() 
{
    std::vector<int> arr {8,2,5,3,9,4,7,6,1};
    Quicksort quick;
    
    std::cout << "Original:\n";
    for(const auto& i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';

    quick.sort(arr);
    
    std::cout << "Sorted:\n";
    for(const auto& i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';

    return 0;
}
