#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
int main(){
    
    std::ifstream ifile("data.dat",std::ios::binary);
    char* output;
    int counter{0};
    std::vector<int> outputs;

    int stuff;
    while(!ifile.read((char*)&stuff,sizeof(int)).eof()){
        std::cout << stuff << std::endl;
        outputs.push_back(stuff);
    }

    int sum{0};
    for(auto x : outputs){
        sum += x;
    }
    std::cout << "Number of integers: " << outputs.size() << std::endl;
    std::cout << "Sum of the integers: " << sum << std::endl;
    std::cout << "Average of the integers: " << (double)sum/outputs.size() << std::endl;
}