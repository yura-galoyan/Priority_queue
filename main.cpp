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
    
        std::vector<int> a{1,2,3,4,5};

    priority_queue<int> b;

    priority_queue<int> pq( a.begin(), a.end());


    print(pq);

    return 0;
}