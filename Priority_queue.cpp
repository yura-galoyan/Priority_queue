#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>
#include <functional>

template<typename T, typename Container = std::vector<T>,  typename Compare = std::less<T> >
class Priority_queue
{
public:
    using value_type = Container::value_type;
    using container_type = Container;
    using size_type = Container::size_type;
    using reference = Container::reference;
    using const_reference = Container::const_reference;

    Priority_queue() = default;
    
    Priority_queue( const Priority_queue& other ):container(other) ;
 
    template<typename Container>
    Priority_queue(const Container& container): container(container) ;

    template<typename InputIt>
    Priority_queue( InputIt first, InputIt last, Compare cmp = Compare{}, const Container& c = Container{} )
    : container(c), comp(cmp)
    {
        container.insert(  std::end(container), first, last );
    };


    void pop(){
        std::begin(container) = std::prev( std::end(container) );
        container.pop_back();
        heapify(std::begin(container),  std::end(container), std::begin(container));
    };

    void push(const value_type& elem){
        container.push_back(elem);

    
/*HEAP-INCREASE-KEY.A; i; key/
1 if key < A[i]
2 error “new key is smaller than current key”
3 A[i] = key
4 while i > 1 and A[PARENT(i)] < A[i]
5 exchange A[i] with A[PARENT(i)]
6 i = PARENT.i /*/


        
    };
    void emplace();
    bool empty();
    
    const_reference top()const{
        return container.front();
    };
    std::size_t size() const{
        return container.size();
    };
    void swap();

    ~Priority_queue();
    
private: 
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
    template<typename RandIt>
    void increaseKey(Container container,RandIt it,const value_type key ){
        *it = key;
        while( it != )
    }


    /*HEAP-INCREASE-KEY.A; i; key/
1 if key < A[i]
2 error “new key is smaller than current key”
3 A[i] = key
4 while i > 1 and A[PARENT(i)] < A[i]
5 exchange A[i] with A[PARENT(i)]
6 i = PARENT.i /*/



private:
    std::vector<int> container;
    // Container container;
    Compare comp;
};

#endif