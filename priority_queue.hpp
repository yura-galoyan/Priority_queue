#include <vector>
#include <functional>

#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

template<typename T, typename Container = std::vector<T>,  typename Compare = std::less<T> >
class priority_queue
{
public:
    using const_reference = typename Container::const_reference;
    using reference = typename Container::reference;
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;
    using container_type = Container;
    using value_compare = Compare;

public:
    priority_queue() = default;

    priority_queue( const Compare& compare )
        : priority_queue(compare, Container()) { }

    priority_queue( const Compare& compare, const Container& cont );

    priority_queue(const Container& container);

    priority_queue(const std::initializer_list<T>& list);

    template<typename InputIt >
    priority_queue( InputIt first, InputIt last, const Compare& cmp = Compare{}, const Container& c = Container{} );

    void pop();

    void push(const value_type& elem);

    template< class... Args >
    void emplace( Args&&... args );

    inline bool empty(){ return container.empty(); };
    
    inline const_reference top() const { return container.front(); };
    
    inline std::size_t size() const{ return container.size(); };

    void swap(priority_queue& other);
 
private:
    Container container;
    Compare comp;
};


#include "Priority_queue.impl.hpp"

#endif