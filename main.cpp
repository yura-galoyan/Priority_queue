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
    
    priority_queue<int> pq1{1,2,3,4,5};


    print(pq1);


    return 0;
}