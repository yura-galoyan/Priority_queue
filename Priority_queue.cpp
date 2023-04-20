#include "Priority_queue.hpp"


Priority_queue::Priority_queue( const Priority_queue& other ){

};

void Priority_queue:: pop(){

};

void Priority_queue::push(const int& a){

};

void Priority_queue::emplace(){

};

bool Priority_queue::empty(){

};

int Priority_queue::top(){

};

std::size_t Priority_queue::size(){

};

void Priority_queue::swap(){

};

template <typename RandIt>
RandIt getChild(RandIt first, RandIt last, RandIt it,
                      typename std::iterator_traits<RandIt>::difference_type childId) {
    const auto index = std::distance(first, it);
    const auto childIndex = 2*index + childId;
    return childIndex >= std::distance(first, last) ? last : std::next(first, childIndex);
}

template <typename RandIt> 
RandIt getLeft(RandIt first, RandIt last, RandIt i) {
    return getChild(first, last, i, 1);
}

template <typename RandIt> 
RandIt getRight(RandIt first, RandIt last, RandIt i) {
    return getChild(first, last, i, 2);
}

template <typename RandIt>
void Heapify(RandIt first, RandIt last, RandIt i) {
    auto largest = i;
    if(const auto l = getLeft(first, last, i); l != last &&  *l > *largest) {
        largest = l;
    }
    if (const auto r = getRight(first, last, i); r != last && *r > *largest) {
        largest = r;
    }
    if (largest != i) {
        std::swap(*largest, *i);
        maxHeapify(first, last, largest);
    }
}

template <typename RandIt>
void build_heap(RandIt first, RandIt last) {
    const auto size = std::distance(first, last);
    const auto firstNonLeaf = size/2 - 1;
    for (auto i = firstNonLeaf + 1; i >= 1; --i) {
        maxHeapify(first, last, std::next(first, i));
    }
}


Priority_queue::~Priority_queue(){

};

