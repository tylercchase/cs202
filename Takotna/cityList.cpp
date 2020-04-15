#include "cityList.hpp"
void CityList::loadCitiesFromFile(std::string filename){
    std::string line;
    std::ifstream file(filename);
    bool onCoords{false};
    unsigned int nodeNumber;
    double latitude;
    double longitude;
    if(file.is_open()){
        while(getline(file,line)){
            if(onCoords){
                std::istringstream iss(line);
                
                iss >> nodeNumber;
                if(nodeNumber == 0){
                    break;
                }
                iss >> latitude;
                iss >> longitude;
                std::cout << longitude << std::endl;
                CityNodes.push_back(CityNode{nodeNumber,latitude,longitude});
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
        std::cout << CityNodes[0].getNumber() << " " << CityNodes[0].getLatitude() << " " << CityNodes[0].getLongitude() << std::endl;
}

double CityList::distance(int first,int second) const{
    return 0;
}