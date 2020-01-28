#include <iostream>
#include <random>
#include <algorithm>
#include "StopWatch.hpp"

std::vector<int> gen_group(int amount){
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

    std::random_device rd;
    std::mt19937 gen(rd());
    StopWatch timer;
    std::vector<int> amounts{10,100,1000,10000,1000000,10000000,1000000000};
    std::cout << "----------Running c++ std::search-----------" << std::endl;
    for(int i = 0; i < amounts.size(); i++){
        std::uniform_int_distribution<> dis(1,amounts[i]);
        auto stuff = gen_group(amounts[i]);
        std::cout << "Running search 5 times on dataset of size: " << amounts[i] << std::endl;
        for(int x = 0; x < 5; x++){
            std::vector<int> find{stuff[dis(gen)]};
            timer.start();
            std::search(stuff.begin(),stuff.end(),find.begin(), find.end());
            timer.end();
            std::cout  << timer.get_time_milsec() << std::endl;
        }
    }
    std::cout << "----------Running c++ std::binary_search-----------" << std::endl;
    for(int i = 0; i < amounts.size(); i++){
        std::uniform_int_distribution<> dis(1,amounts[i]);
        auto stuff = gen_group(amounts[i]);
        std::cout << "Running search 5 times on dataset of size: " << amounts[i] << std::endl;
        for(int x = 0; x < 5; x++){
            timer.start();
            std::binary_search(stuff.begin(),stuff.end(),dis(gen));
            timer.end();
            std::cout  << timer.get_time_milsec() << std::endl;
        }
    }
    std::cout << "----------Running c++ find-----------" << std::endl;
    for(int i = 0; i < amounts.size(); i++){
        std::uniform_int_distribution<> dis(1,amounts[i]);
        auto stuff = gen_group(amounts[i]);
        std::cout << "Running search 5 times on dataset of size: " << amounts[i] << std::endl;
        for(int x = 0; x < 5; x++){
            timer.start();
            find(stuff.begin(),stuff.end(),dis(gen));
            timer.end();
            std::cout  << timer.get_time_milsec() << std::endl;
        }
    }
    return 0;
}