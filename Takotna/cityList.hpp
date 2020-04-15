#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "cityNode.hpp"
class CityList {
    public:

        void loadCitiesFromFile(std::string filename);
        double distance(int first, int second) const;
    private:
        std::vector<CityNode> CityNodes;
    
};