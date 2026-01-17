#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>
#include <SFML/Graphics.hpp>
#include "event.h"

struct Element 
{ 
    int value;
};

class Visualizer 
{
public:
    void load(const std::vector<Event>& events);
    void playBack();
    void init(sf::RenderTarget& target);
    void draw(sf::RenderTarget& target) const;
private:
    const std::vector<Event>* m_events = nullptr;
    std::vector<Element> m_currentPositions; 
    size_t m_eventIndex = 0;
    void drawBar(const Element& element, int index, sf::RenderTarget& target) const;
};
            
#endif
