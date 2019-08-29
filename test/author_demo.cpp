#include  <gtest/gtest.h>
#include "include/odr.h"

// https://cpppatterns.com/patterns/observer.html

struct test_observer_concrete : public observer_concrete
{
    bool on_event_called{false};
    using parent = observer_concrete;
    void on_event(EVENT_TYPE to) noexcept final
    {
        parent::on_event(to);
        on_event_called = true;
    }
};

TEST(ObserverPatter, AuthorDemo)
{
    auto s_ptr = std::make_unique<subject>();
    auto oc_ptr = std::make_shared<test_observer_concrete>();
    s_ptr->register_observer(oc_ptr);

    s_ptr->emit();

    ASSERT_EQ(oc_ptr->state, EVENT_TYPE::RESOLVE);
    ASSERT_TRUE(oc_ptr->on_event_called);
}