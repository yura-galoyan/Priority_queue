#include "Priority_queue.hpp"
#include <iterator>
#include <iostream>
#include <algorithm>

template<typename Priority_queue_t>
void print( Priority_queue_t pq  ){
    while(!pq.empty()){
        std::cout<<pq.top()<<std::endl;
        pq.pop();
    }
    if(pq.empty()) std::cout<<"pq is empty" <<std::endl;
}

int main(){
    
    std::vector<int> data{1,2,3,4};



    priority_queue cp( data.begin(), data.end());



    std::cout<<std::endl;

    cp.top();


    cp.emplace(7);
    return 0;

}