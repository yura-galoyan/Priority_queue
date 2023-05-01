#include "heap.hpp"

template <typename RandIt>
RandIt heap::getChild(RandIt first, RandIt last, RandIt it,
                      typename std::iterator_traits<RandIt>::difference_type childId) {
    const auto index = std::distance(first, it);
    const auto childIndex = 2*index + childId;
    return childIndex >= std::distance(first, last) ? last : std::next(first, childIndex);
}

template <typename RandIt>
RandIt heap::getParent(RandIt first, RandIt it) {
    const auto index = std::distance(first, it);
    const auto parentIndex = (index - 1)/2 ;
    return std::next(first, parentIndex);
}

template <typename RandIt> 
RandIt heap::getLeft(RandIt first, RandIt last, RandIt i) {
    return getChild(first, last, i, 1);
}

template <typename RandIt> 
RandIt heap::getRight(RandIt first, RandIt last, RandIt i) {
    return getChild(first, last, i, 2);
}

template <typename RandIt>
void heap::heapify(RandIt first, RandIt last, RandIt i) {
    auto largest = i;
    if(const auto l = getLeft(first, last, i); l != last &&  *l > *largest) {
        largest = l;
    }
    if (const auto r = getRight(first, last, i); r != last && *r > *largest) {
        largest = r;
    }
    if (largest != i) {
        std::swap(*largest, *i);
        heapify(first, last, largest);
    }
}

template <typename RandIt>
void heap::build_heap(RandIt first, RandIt last) {
    const auto size = std::distance(first, last);
    const auto firstNonLeaf = size/2 - 1;
    for (auto i = firstNonLeaf + 1; i >= 1; --i) {
        heapify(first, last, std::next(first, i - 1));
    }
}

template<typename T, typename RandIt>
void heap::increaseKey(RandIt first, RandIt it,const T key ){
    *it = key;
    while( it != first && *getParent(first,it) < *it){
        auto tempP = getParent(first,it);
        std::swap( *it,*getParent(first,it)  );
        it = getParent(first,it);
    }
}
