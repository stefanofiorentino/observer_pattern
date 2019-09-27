#ifndef OBSERVER_PATTERN_SUBJECT_H
#define OBSERVER_PATTERN_SUBJECT_H

#include <memory>
#include <vector>

#include "observer.h"

class subject
{
public:
    void register_observer(std::shared_ptr<observer> const &o_ptr) noexcept
    {
        observers.emplace_back(o_ptr);
    }

    void emit(EVENT_TYPE to = EVENT_TYPE::RESOLVE) const noexcept
    {
        for (auto const &o : observers)
        {
            if (auto shared_o = o.lock())
            {
                shared_o->on_event(to);
            }
        }
    }

private:
    std::vector<std::weak_ptr<observer>> observers;
};

#endif //OBSERVER_PATTERN_SUBJECT_H
