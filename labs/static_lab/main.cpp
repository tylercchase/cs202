#include <iostream>
#include <StopWatch.hpp>
#include <random>
#include <algorithm>
std::vector<int> gen_group(int amount) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> output;
    std::uniform_int_distribution<> dis(1,1000000000);

    for(int x=0; x < amount; x++){
        output.push_back(dis(gen));
    }
    std::cout << "Done creating; first num:" << output[0] << std::endl;
    std::sort(output.begin(),output.end());
    std::cout << "Done sorting; first num:" << output[0] << std::endl;

    return output;
}

int main(){
    StopWatch timer;
    gen_group(10000000);
    timer.end();
    auto end = timer.get_time_milsec();
    std::cout << "Milliseconds to gen and sort vector" << end << std::endl;
}