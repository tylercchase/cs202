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
                CityNodes.push_back(CityNode{nodeNumber,latitude,longitude});
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
}

double CityList::distance(int first,int second) {
    if(first >= 0 && first < CityNodes.size() && second >= 0 || second < CityNodes.size()){
        if(first ==  second){
            return 0;
        }
        return sqrt(pow((CityNodes[second].getLatitude() - CityNodes[first].getLatitude() ),2) + pow(CityNodes[second].getLongitude() - CityNodes[first].getLongitude() ,2));
    }
    return 0;
}