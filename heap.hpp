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

template <typename RandIt>
void heapify(RandIt first, RandIt last, RandIt i);

template <typename RandIt>
void build_heap(RandIt first, RandIt last);

template<typename T, typename RandIt>
void increaseKey(RandIt first, RandIt it,const T key );

#include "heap.impl.hpp"

}
#endif //HEAP_HPP