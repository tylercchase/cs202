#include <iostream>

int factorial(int n){
    return 0;
}
int factorial_loop(int n){

}


int main(){
    std::cout << "Enter a number to select method of finding the factorial of \n 1.) Recursive \n 2.) Non-recursive" << std::endl;
    int userChoice;
    std::cin >> userChoice;
    std::cout << "Enter number to find the factorial of" << std::endl;
    int userNumber;
    std::cin >> userNumber;
    switch (userChoice)
    {
    case 1:
        std::cout << "Result: " << factorial(userNumber) << std::endl;
        break;
    case 2:
        std::cout << "Result" << factorial_loop(userNumber) << std::endl;
    default:
        std::cout << "Invalid menu selection" << std::endl;
    }
}