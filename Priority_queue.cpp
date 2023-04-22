#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>
#include <functional>

template<typename T, typename Container = std::vector<T>,  typename Compare = std::less<T> >
class Priority_queue
{
public:
    using const_reference = typename Container::const_reference;
    using reference = typename Container::reference;
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;
    using container_type = Container;
    using value_compare = Compare;

public:
    Priority_queue() = default;

    //copy constructor
    Priority_queue( const Priority_queue& other ){
        container = other.container;
        comp = other.comp;
    };

    //container initialization
    Priority_queue(const Container& container): container(container){};

    //initializer list initialization
    Priority_queue(const std::initializer_list<T>& list){
        container.insert(container.end(), list);
        build_heap(std::begin(container),std::end(container));
    };

    //range initialization
    template<typename InputIt>
    Priority_queue( InputIt first, InputIt last, Compare cmp = Compare{}, const Container& c = Container{} )
    : container(c), comp(cmp)
    {        
        container.insert(  std::end(container), first, last );
        build_heap(std::begin(container), std::end(container));
    };



    void pop(){
        *std::begin(container) = *std::prev( std::end(container) );
        container.pop_back();
        heapify(std::begin(container),  std::end(container), std::begin(container));
    };

    void push(const value_type& elem){
        container.push_back(elem);
        increaseKey( std::begin(container), std::prev( std::end(container) ),elem  );
    };

    void emplace();

    bool empty(){
        return container.empty();
    };
    
    const_reference top()const{
        return container.front();
    };
    std::size_t size() const{
        return container.size();
    };

    void swap(Priority_queue& other){
        std::swap(container, other.container);
        std::swap(comp, other.comp);
    };
    
private: 
    template <typename RandIt>
    RandIt getChild(RandIt first, RandIt last, RandIt it,
                          typename std::iterator_traits<RandIt>::difference_type childId) {
        const auto index = std::distance(first, it);
        const auto childIndex = 2*index + childId;
        return childIndex >= std::distance(first, last) ? last : std::next(first, childIndex);
    }

    template <typename RandIt>
    RandIt getParent(RandIt first, RandIt it) {
        const auto index = std::distance(first, it);
        const auto parentIndex = (index - 1)/2 ;
        return std::next(first, parentIndex);
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
    void heapify(RandIt first, RandIt last, RandIt i) {
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
    void build_heap(RandIt first, RandIt last) {
        const auto size = std::distance(first, last);
        const auto firstNonLeaf = size/2 - 1;
        for (auto i = firstNonLeaf + 1; i >= 1; --i) {
            heapify(first, last, std::next(first, i - 1));
        }
    }

    template<typename RandIt>
    void increaseKey(RandIt first, RandIt it,const value_type key ){
        *it = key;
        while( it != first && *getParent(first,it) < *it){
            auto tempP = getParent(first,it);
            std::swap( *it,*getParent(first,it)  );
            it = getParent(first,it);
        }
    }


private:
    std::vector<int> container;
    // Container container;
    Compare comp;
};

#endif