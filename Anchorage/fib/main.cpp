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
    return 0;
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
        std::cout << "Result" << fib_loop(userNumber) << std::endl;
    default:
        std::cout << "Invalid menu selection" << std::endl;
    }
    
}