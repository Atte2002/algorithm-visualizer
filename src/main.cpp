#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Window.hpp>
#include "app.h"
#include <vector>

int main() 
{
    std::vector<int> arr {9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,2,3};
    
    App app;
    app.load(arr);
    app.run();
    

    return 0;
}
