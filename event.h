#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED
#include "MouseEvent.h"

struct Event
{
    bool Close=0;
    MouseEvent mouseEvent;
};

#endif // KEYEVENT_H_INCLUDED
