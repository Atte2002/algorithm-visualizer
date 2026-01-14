#ifndef EVENT_H
#define EVENT_H

enum class EventType 
{
    SWAP,
    COMPARE
};

struct Event 
{
    EventType type;
    int x;
    int y;
};

#endif
