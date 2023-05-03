#include <queue>
#include <vector>
#include <iostream>


int main(){

    std::vector<int> data{1,2,3,4};
    std::priority_queue cp(data.begin(), data.end(),std::greater<int>{});

    std::cout<<std::endl;

    cp.emplace(7);
    return 0;

}