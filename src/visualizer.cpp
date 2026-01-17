#include "visualizer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <algorithm>
#include "constants.h"

void Visualizer::load(const std::vector<Event>& events)
{
    m_events = &events;
    m_eventIndex = 0;

    for(const auto& event : *m_events)
    {
        // Save initial positions
        if(event.type == EventType::INIT)
        {
            m_currentPositions.push_back(Element{event.y});
        }
    } 
}

void Visualizer::playBack()
{
    if(m_events == nullptr)
    {
        return;
    }
    
    if(m_eventIndex >= m_events->size())
    {
        return;
    }
    
    auto event = m_events->at(m_eventIndex);

    if(event.type == EventType::SWAP)
    {   
        std::swap(m_currentPositions.at(event.x), m_currentPositions.at(event.y));
    }

    m_eventIndex++;
    sf::sleep(sf::milliseconds(50));
}

void Visualizer::draw(sf::RenderTarget& target) const
{   
   for(int i = 0; i < static_cast<int>(m_currentPositions.size()); i++)
   {
       drawBar(m_currentPositions.at(i), i, target);
   }
}

void Visualizer::drawBar(const Element& element, int index, sf::RenderTarget& target) const
{
    using namespace constants;

    float x_pos = index * barWidth;
    float height = element.value * barHeightMultiplier;

    sf::RectangleShape rect({barWidth - barOutline, height});
    rect.setOutlineThickness(barOutline);
    rect.setOutlineColor(sf::Color::Black);
    rect.setPosition(x_pos, constants::windowHeight - height);
    rect.setFillColor(sf::Color::Green);
    target.draw(rect);
}








