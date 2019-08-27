#include <iostream>
#include <vector>
#include <future>

// https://cpppatterns.com/patterns/observer.html

using namespace std::chrono_literals;

enum class EVENT_TYPE
{
    RESOLVE = 0, REJECT
};

class observer
{
public:
    virtual void on_event(EVENT_TYPE to) noexcept = 0;
};

class observer_concrete : public observer
{
public:
    void on_event(EVENT_TYPE to) noexcept final
    {
        std::puts(__PRETTY_FUNCTION__);
        switch (to)
        {
            case EVENT_TYPE::RESOLVE:
                std::puts("RESOLVE");
                break;
            case EVENT_TYPE::REJECT:
                std::puts("REJECT");
                break;
            default:
                break;
        }
    }
};

class subject
{
public:
    void register_observer(observer &o) noexcept
    {
        observers.emplace_back(o);
    }

    void emit(EVENT_TYPE to = EVENT_TYPE::RESOLVE) noexcept
    {
        for (observer &o : observers)
        {
            o.on_event(to);
        }
    }

private:
    std::vector<std::reference_wrapper<observer>> observers;
};

int main()
{
    subject s{};
    observer_concrete oc;
    s.register_observer(oc);

    std::this_thread::sleep_for(5s);
    s.emit();

    return 0;
}
