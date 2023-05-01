#include "Priority_queue.hpp"
#include <iterator>
#include <iostream>
#include <algorithm>

void print(  priority_queue<int> pq  ){
    while(!pq.empty()){
        std::cout<<pq.top()<<std::endl;
        pq.pop();
    }
    if(pq.empty()) std::cout<<"pq is empty" <<std::endl;
}

int main(){
    
    priority_queue<int> cp{10,4,5,1,2};

    std::cout<<std::endl;

    cp.emplace(7);
    return 0;
}