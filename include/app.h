#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "visualizer.h"

class App
{
public:
    App();
    void run();

private:
    sf::RenderWindow m_window;
    Visualizer m_visualizer;
};

#endif
