#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

namespace tokenizer{
    bool LineToTokens(const std::string& line,
    std::vector<std::string>& tokens);

    bool ReadLine(std::istream& is,
    std::vector<std::string>& tokens,
    std::vector<std::pair<int, int>>& linecols);

    void PrintTokens(std::ostream& os,
    const std::vector<std::string>& tokens,
    const std::vector<std::pair<int, int>>& linecols);

}

#endif