#include <iostream>
#include <StopWatch.hpp>
int main(){
    StopWatch timer;
    timer.end();
    auto end = timer.get_time_milsec();
    std::cout << end << std::endl;
}