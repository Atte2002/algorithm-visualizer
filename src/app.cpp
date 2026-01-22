#include "app.h"
#include "quicksort.h"
#include "mergesort.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "constants.h"

App::App()
    : m_window(sf::VideoMode(constants::windowWidth, constants::windowHeight), "Algorithm-visualizer")
{
}

void App::run()
{   
    while(m_window.isOpen())
    {
        handleEvents();
        update();     
        draw();
        m_window.display();
    }
}

void App::handleEvents()
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }
}

void App::load(std::vector<int>& arr)
{ 
    m_events.clear();    
    //Quicksort qs(m_events);
    //qs.sort(arr);
     
    Mergesort ms(m_events);
    ms.sort(arr);

    m_visualizer.load(m_events);
}

void App::update()
{
    m_visualizer.playBack();
}

void App::draw()
{
    m_window.clear(sf::Color::Black);
    m_visualizer.draw(m_window);
}

