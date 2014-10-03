#include <cassert>

namespace onhands
{

// Your implementation of simple single-linked list here.
template<class T>
class slist
{
public:
    explicit slist(T const& val, slist* next) :
        m_value(val),
        m_next(next)
    {}
    
    slist const* next() const
    {
        return m_next;
    }
    
private:
    T m_value;
    slist* m_next;
};

template<class T>
bool cycle(slist<T> const& list)
{
    // Implementation should go here. This function should return `true` if cycle is found.
    return false;
}

} // namespace onhands

int main(int, char**)
{
    onhands::slist<int> l1(1, nullptr);
    // Fill l1 according to slist interface. l1 should have a cycle.

    onhands::slist<int> l2(2, nullptr);
    // l2 should have no cycle.

    assert(onhands::cycle(l1));
    assert(!onhands::cycle(l2));
}

