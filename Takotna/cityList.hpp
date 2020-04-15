#include <vector>
#include <string>
#include <iostream>
#include "cityNode.hpp"
class CityList {
    public:
        std::vector<CityNode> CityNodes;

        void loadCitiesFromFile(std::string filename);
    private:
    
};