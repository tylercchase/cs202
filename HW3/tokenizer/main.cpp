#include <iostream>
#include <fstream>
#include "tokenizer.hpp"
int main(int argc, char* argv[]){
    std::ifstream ifile("input.txt");
    std::string input;
    int line{0};
    while(getline(ifile,input)){
        // line++;
        // if(input.size() == 0){
        //         std::cout << "Line " << line << ", Column 1"<< ": blank line" << std::endl;
        // }
        // else{
        //     for(int i = 0; i < input.size(); i++){
        //         if(input[i]){
        //             std::string output{""};
        //             int stepper;
        //             do{
        //                 output += input[i];
        //                 i++;
        //             }while(!std::isspace(input[i]) && input[i]);
        //             std::cout << "Line " << line << ", Column " << i << ": " << output << std::endl;
        //         }
        //     }
        // }
    }
    return 0;
}