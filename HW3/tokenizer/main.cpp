#include <iostream>
#include <fstream>
#include <vector>

#include "tokenizer.hpp"
int main(int argc, char* argv[]){
    std::ifstream ifile("input.txt");
    std::string input;
    int line{0};
    std::vector<std::string> tokens;
    std::vector<std::pair<int,int>> linecols;
    tokenizer::ReadLine(ifile,tokens,linecols);

    tokenizer::PrintTokens(std::cout,tokens,linecols);
    return 0;
}