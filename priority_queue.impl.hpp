#include "Priority_queue.hpp"
#include "heap.hpp"

template<typename T, typename Container,  typename Compare>
priority_queue<T, Container, Compare>::priority_queue(const std::initializer_list<T>& list){
    container.insert(container.end(), list);
    heap::build_heap(std::begin(container),std::end(container));
};

template<typename T, typename Container, typename Compare>
priority_queue<T,Container,Compare>::priority_queue( const Compare& cmp, const Container& cont )
    :comp(cmp),container(cont)
{
    heap::build_heap(std::begin(container), std::end(container));
};

template<typename T, typename Container,  typename Compare>
priority_queue<T, Container, Compare>::priority_queue(const Container& other): container(other){
    container.insert(  std::end(container), other );
    heap::build_heap(std::begin(container), std::end(container));
};

template<typename T, typename Container,  typename Compare>
template<typename InputIt>
priority_queue<T, Container, Compare>::priority_queue( InputIt first, InputIt last,const Compare& cmp , const Container& container  ){   
    container.insert(  std::end(container), first, last );
    heap::build_heap(std::begin(container), std::end(container));
};



template<typename T, typename Container,  typename Compare>
void priority_queue<T, Container, Compare>::pop(){
    *std::begin(container) = *std::prev( std::end(container) );
    container.pop_back();
    heap::heapify(std::begin(container),  std::end(container), std::begin(container));
};

template<typename T, typename Container,  typename Compare>
void priority_queue<T, Container, Compare>::push(const value_type& elem){
    container.push_back(elem);
    heap::increaseKey( std::begin(container), std::prev( std::end(container) ),elem  );
};
template<typename T, typename Container, typename Compare>
template< class... Args >
void priority_queue<T, Container, Compare>::emplace( Args&&... args ){
    container.emplace_back(args...);
    heap::increaseKey( std::begin(container), std::prev( std::end(container)),*std::prev( std::end(container)) );
};



template<typename T, typename Container,  typename Compare>
void priority_queue<T, Container, Compare>::swap(priority_queue& other){
    std::swap(container, other.container);
    std::swap(comp, other.comp);
};
