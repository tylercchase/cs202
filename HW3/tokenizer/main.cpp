#include <iostream>
#include <fstream>
#include <vector>

#include "tokenizer.hpp"
#include "StopWatch.hpp"
int main(int argc, char* argv[]){
    std::string input;
    int line{0};
    if(argc >= 2){
        std::ifstream ifile(argv[1]);
        if(ifile){

            std::ifstream fileSize(argv[1], std::ios::binary | std::ios::ate);
            int bytes = fileSize.tellg();
            fileSize.close();

            if(argc == 4){
                StopWatch timer;
                std::vector<std::string> tokens;
                std::string line;
                while(getline(ifile,line)){
                    tokenizer::LineToTokens(line,tokens);
                }
                timer.end();
                std::cout << "Time to just read lines: " << timer.get_time_milsec() << std::endl;
                std::cout << "Size of file(bytes): " << bytes << std::endl;
                std::cout << "MB/ms for file: " << (bytes / 1000)/timer.get_time_milsec() << " MB/ms" << std::endl;



            }else{
                StopWatch timer;
                std::vector<std::string> tokens;
                std::vector<std::pair<int,int>> linecols;
                tokenizer::ReadLine(ifile,tokens,linecols);
                tokenizer::PrintTokens(std::cout,tokens,linecols);
                timer.end();
                std::cout << "Time to read and print: " << timer.get_time_milsec() << std::endl;
                std::cout << "Size of file(bytes): " << bytes << std::endl;
                std::cout << "MB/ms for file: " << (bytes / 1000)/timer.get_time_milsec() << " MB/ms" << std::endl;

            }
        }else{
            std::cout << "Couldn't open file" << std::endl;
        }
    }else{
        std::cout << "Please provide a file name to parse" << std::endl;
    }
    return 0;
}