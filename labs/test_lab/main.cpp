#include <iostream>
#include <fstream>

class File {
    
};

int main(){
    std::ofstream outFile;
    std::ifstream inFile("save.txt");
    
    inFile.read(reinterpret_cast<char*>(2));
    return 0;
}