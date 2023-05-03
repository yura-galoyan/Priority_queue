#include <iterator>
#include <type_traits>

#ifndef HEAP_HPP
#define HEAP_HPP
namespace heap{

template <typename RandIt>
RandIt getChild(RandIt first, RandIt last, RandIt it,
                          typename std::iterator_traits<RandIt>::difference_type childId);

template <typename RandIt>
RandIt getParent(RandIt first, RandIt it);

template <typename RandIt> 
RandIt getLeft(RandIt first, RandIt last, RandIt i);

template <typename RandIt> 
RandIt getRight(RandIt first, RandIt last, RandIt i);

template <typename RandIt, typename Comp = std::less<typename RandIt::value_type>>
void heapify(RandIt first, RandIt last, RandIt i, Comp comp = Comp{} );

template <typename RandIt, typename Comp = std::less<typename RandIt::value_type> > 
void build_heap(RandIt first, RandIt last, Comp comp = Comp{}  );

template<typename T, typename RandIt, typename Comp = std::less<T> >
void increaseKey(RandIt first, RandIt it,const T key, Comp comp = Comp{} );

#include "heap.impl.hpp"

}
#endif //HEAP_HPP