#include "cityList.hpp"
#include <fstream>
void CityList::loadCitiesFromFile(std::string filename){
    std::string line;
    std::ifstream file(filename);
    bool onCoords{false};
    if(file.is_open()){
        while(getline(file,line)){
            if(onCoords){
                std::cout << line << std::endl;
            }
            else if(line == "NODE_COORD_SECTION"){
                onCoords = true;
            }
            else {

            }
        }
        file.close();
    }
    else{
        std::cout << "Unable to open file" << std::endl;
    }
    CityNodes.push_back(CityNode{1,14.2,12.2});
}