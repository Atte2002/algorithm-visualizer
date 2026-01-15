#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <vector>
#include "event.h"

struct Item
{
    int index;
    int value;
};

class Visualizer 
{
public:
    void load(const std::vector<Event>& events);
    void playBack() const;
private:
    const std::vector<Event>* m_events = nullptr;
    std::vector<Item> m_items;
    void init(); 
    void draw(Item& item) const;
    
};
        
#endif
