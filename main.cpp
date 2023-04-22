#include "Priority_queue.cpp"
#include <iterator>
#include <iostream>

void print(  Priority_queue<int> pq  ){
    while(!pq.empty()){
        std::cout<<pq.top()<<std::endl;
        pq.pop();
    }
    if(pq.empty()) std::cout<<"pq is empty" <<std::endl;
}

int main(){
    std::vector<int> a{5,10,6,17,9};
    Priority_queue<int> pq (a.begin(), a.end());

    Priority_queue<int> pq1 (a.begin(), a.end());
    Priority_queue<int> pq2 (a);
    Priority_queue<int> pq3 ({5,10,6,17,9});
    Priority_queue<int> pq4 {5,10,6,17,9};
    Priority_queue<int> pq5;



    std::cout<< "size = " <<pq.size()<<std::endl;
    std::cout<< "17 = " <<pq.top()<<std::endl;
    pq.pop();
    std::cout<< "10 = " <<pq.top()<<std::endl;
    pq.push(50);
    std::cout<< "50 = " <<pq.top()<<std::endl;
    if(!pq.empty()){
        std::cout<<"pq is not empty"<<std::endl;
    }

    print(pq);
    


    return 0;
}