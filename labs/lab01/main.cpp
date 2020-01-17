#include <iostream>


void doStuff() {
    std::cout << "Hey I did a thing!" << std::endl;
}

int main() {
    auto boolTest = true;
    auto listTest = {1, 4, 5, 6, 7};
    auto intTest = 5;
    auto counterOne = 0;
    auto counterTwo = 0;

    std::cout << std::endl << "------If statement--------" << std::endl;
    if (boolTest) {
        std::cout << "The boolean is true!" << std::endl;
    } else {
        std::cout << "The boolean is false" << std::endl;
    }

    std::cout << "------Switch Statement--------" << std::endl;
    switch (intTest) {
        case 1:
            std::cout << "It was one!" << std::endl;
            break;
        case 5:
            std::cout << "It was five!" << std::endl;
            break;
        default:
            std::cout << "Number wasn't in here" << std::endl;
            break;
    }

    std::cout << "------Function call--------" << std::endl;
    doStuff();

    std::cout << "------While Loop--------" << std::endl;
    while (counterOne < 3) {
        std::cout << counterOne << std::endl;
        counterOne++;
    }

    std::cout << "------Do while Loop--------" << std::endl;
    do {
        std::cout << counterTwo << std::endl;
        counterTwo++;
    } while (counterTwo < 3);

    std::cout << "------For Loop--------" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << i << std::endl;
    }

    std::cout << "------Range based for loop--------" << std::endl;
    for (int i: listTest) {
        std::cout << "Hello World #" << i << std::endl;
    }

    return 0;
}
