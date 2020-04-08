#include <iostream>

int fib(int n){
    if( n==0 ){
        return 0;
    }
    if( n == 1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
int fib_loop(int n){
        if(n==0){
        return 1;
        }
        if(n == 1){
            return 1;
        }
        int holder1{1};
        int holder2{1};
        int sum{2};
        for(int x =2; x < (n-1); x++){
            holder1 = sum;
            sum = holder2 + sum;
            holder2 = holder1;
        }
        return sum;
}

int main(){
    std::cout << "Enter a number to select method of finding the fibonacci  number \n 1.) Recursive \n 2.) Non-recursive" << std::endl;
    int userChoice;
    std::cin >> userChoice;
    std::cout << "Enter number to find in the fibonacci sequence" << std::endl;
    int userNumber;
    std::cin >> userNumber;
    switch (userChoice)
    {
    case 1:
        std::cout << "Result: " << fib(userNumber) << std::endl;
        break;
    case 2:
        std::cout << "Result: " << fib_loop(userNumber) << std::endl;
        break;
    default:
        std::cout << "Invalid menu selection" << std::endl;
    }
    
}