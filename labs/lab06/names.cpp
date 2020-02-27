#include "names.hpp"
#include <iostream>

namespace {
    int cool_number = 4;
}

void tyler::foo(){
    std::cout << "I was called in the Tyler namespace.\n"
    << "My cool number is: " << cool_number << std::endl;
}