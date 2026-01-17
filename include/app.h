#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include "event.h"
#include "visualizer.h"

class App
{
public:
    App();
    void run();
    void load(std::vector<int>& arr);
private:
    void handleEvents();
    void update();
    void draw();
    sf::RenderWindow m_window;
    Visualizer m_visualizer;
    std::vector<Event> m_events;
};

#endif
