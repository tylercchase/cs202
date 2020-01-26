#include <iostream>
#include <random>
#include <algorithm>
#include "StopWatch.hpp"

std::vector<int> gen_group(int amount){
    std::vector<int> output;
    for(int x=0; x < amount; x++){
        output.push_back(x);
    }
    return output;
}
void run_test(){

}

int main(){

    std::random_device rd;
    std::mt19937 gen(rd());
    StopWatch timer;
    std::vector<int> amounts{1,2,3,4,5};
    for(int i = 0; i < amounts.size(); i++){

    std::uniform_int_distribution<> dis(1,amounts[i]);
    auto stuff = gen_group(amounts[i]);
    std::cout << "Running search 5 times on dataset of size: " << amounts[i] << std::endl;
    for(int x = 0; x < 5; x++){
        auto find = dis(gen);
        timer.start();
        std::search(stuff.begin(),stuff.end(),find);
        timer.end();
        std::cout << timer.get_time_milsec() << std::endl;
    }
    }
    
    timer.end();
    std::cout << timer.get_time_milsec();


}