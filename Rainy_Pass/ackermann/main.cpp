#include <iostream>
#include "StopWatch.hpp"

int ackermann(int m, int n){
    if(m==0){
        return n + 1;
    }
    if(m >0 && n == 0){
        return ackermann(m-1,1);
    }
    if(m>0 && n >0){
        return ackermann(m-1,ackermann(m,n-1));
    }
    return 0;
}

int main(){
    std::cout << "Enter the first number of the ackermann function" << std::endl;
    int userNumber1;
    std::cin >> userNumber1;
    std::cout << "Enter the second number of the ackermann function" << std::endl;
    int userNumber2;
    std::cin >> userNumber2;
    StopWatch timer;
    timer.start();
    std::cout << ackermann(userNumber1,userNumber2) << std::endl;
    timer.end();
    std::cout << "Time to complete: " << timer.get_time_milsec() << "ms" << std::endl;
}