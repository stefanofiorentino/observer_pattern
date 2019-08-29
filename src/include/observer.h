#ifndef OBSERVER_PATTERN_OBSERVER_H
#define OBSERVER_PATTERN_OBSERVER_H

#include "observer_interface.h"

struct observer_concrete : public observer
{
    EVENT_TYPE state{EVENT_TYPE::REJECT};
public:
    void on_event(EVENT_TYPE to) noexcept override
    {
        switch (to)
        {
            case EVENT_TYPE::RESOLVE:
            case EVENT_TYPE::REJECT:
            default:
                state = to;
                break;
        }
    }
};

#endif //OBSERVER_PATTERN_OBSERVER_H
