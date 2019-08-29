#ifndef OBSERVER_PATTERN_OBSERVER_INTERFACE_H
#define OBSERVER_PATTERN_OBSERVER_INTERFACE_H

#include "enums.h"

class observer
{
public:
    virtual void on_event(EVENT_TYPE to) noexcept = 0;
};

#endif //OBSERVER_PATTERN_OBSERVER_INTERFACE_H
