#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
int count_char(char* input){
    int counter = 0;

    while(input[counter] != '\0'){
        counter++;
    }
    return counter;
}

void to_lower( char *s){
    int counter = count_char(s);
    for (int i = 0; i < (counter-1); i++){
        if(s[i] >= 65 && s[i] <= 90){
            s[i] += 32;
        }
    }
}

TEST_CASE("Lowercase test","[lowercase]"){
    char test[] = "Hello World!";
    to_lower(test);
    char final[] = "hello world!";

    REQUIRE(std::strcmp(test,final) == 0);
}
