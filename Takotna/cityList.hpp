#include <vector>
#include <string>
#include <iostream>
#include "cityNode.hpp"
class CityList {
    public:

        void loadCitiesFromFile(std::string filename);
    private:
        std::vector<CityNode> CityNodes;
    
};