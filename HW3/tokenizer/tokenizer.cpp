#include <fstream>
#include <ostream>
#include <vector>
#include "tokenizer.hpp"

    bool tokenizer::LineToTokens(const std::string& line,
    std::vector<std::string>& tokens){
        return false;
    }
    bool tokenizer::ReadLine(std::istream& is,
    std::vector<std::string>& tokens,
    std::vector<std::pair<int, int>>& linecols){
        return false;
    }

    void tokenizer::PrintTokens(std::ostream& os,
    const std::vector<std::string>& tokens,
    const std::vector<std::pair<int, int>>& linecols){
        
    }



