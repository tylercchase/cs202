#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <iomanip>
#include <algorithm>
int main(){
    std::ifstream readFile("text.txt");
    std::string line;
    //Print out the file
    int charTracker{0};
    int wordTracker{0};
    int lineTracker{0};
    int paraTracker{1};

    while(getline(readFile,line)){
        std::cout << line << std::endl;
        int numWords{0};
        if(line == ""){
            paraTracker++;
        }else{
            wordTracker += (1 + std::count( line.begin(), line.end(), ' ' ));
        }
        

        charTracker += line.length();
        lineTracker++;
    }
    readFile.close();
    std::cout << "-----------------" << std::endl;
    std::cout << std::setw(15) << "Line total |" << std::setw(15)<< "Char total |"<< std::setw(15) << "Paragraph total |" << std::setw(15) << "Word total |" << std::endl;
    std::cout  << std::setw(15) << lineTracker << std::setw(15) << charTracker << std::setw(15) << paraTracker << std::setw(15) << wordTracker << std::endl; 
    //Get user input
    std::string userString;
    int userInt;
    std::cout << "Input string: " << std::endl;
    std::getline(std::cin,userString);
    std::cout << "How many times" << std::endl;
    std::cin >> userInt;
    
    std::ofstream inputFile("text.txt",std::ios::app);
    for(int i = 0; i < userInt; i++){
        inputFile << userString << '\n';
    }
    
    return 0;
}