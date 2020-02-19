#include <fstream>
#include <ostream>
#include <vector>
#include "tokenizer.hpp"
#include "StopWatch.hpp"

bool tokenizer::LineToTokens(const std::string& line,
std::vector<std::string>& tokens){
    if(line.size() == 0){
            tokens.push_back("blank line");
            return false;
    }
    else{
        for(int i = 0; i < line.size(); i++){
            if(line[i]){
                std::string output{""};
                int stepper;
                do{
                    output += line[i];
                        i++;
                }while(!std::isspace(line[i]) && line[i]);
                tokens.push_back(output);
                }
            }
        return true;
    }
}

bool tokenizer::ReadLine(std::istream& is,
std::vector<std::string>& tokens,
std::vector<std::pair<int, int>>& linecols) {
    std::string line;
    int linenumber{0};
    while(getline(is,line)){
        linenumber++;
        if(line.size() == 0){
            tokens.push_back("blank line");
            linecols.push_back(std::pair<int,int>{linenumber,0});
        }
        else{
            for(int i = 0; i < line.size(); i++){
                if(line[i]){
                    std::string output{""};
                    int stepper;
                    do{
                        output += line[i];
                        i++;
                    }while(!std::isspace(line[i]) && line[i]);
                    tokens.push_back(output);
                    linecols.push_back(std::pair<int,int>{linenumber,i});
                }
            }
        }
    }
    return true;
}

void tokenizer::PrintTokens(std::ostream& os,
const std::vector<std::string>& tokens,
const std::vector<std::pair<int, int>>& linecols){
    for(int x=0; x < tokens.size(); x++){
            os<< "Line " << linecols[x].first << ", Column " <<
            linecols[x].second << ": " << tokens[x] << std::endl;  
    }
}



