#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>

class Priority_queue
{
public:
    Priority_queue() = default;
    Priority_queue( const Priority_queue& other );

    void pop();
    void push(const int& a);
    void emplace();
    bool empty();
    int top();
    std::size_t size();
    void swap();

    ~Priority_queue();
    
private:
    template <typename RandIt>
    void build_heap(RandIt first, RandIt last);

private:
    std::vector<int> container;
    //Comp comp
};




#endif