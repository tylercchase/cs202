#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include "cityNode.hpp"
class CityList {
    public:

        void loadCitiesFromFile(std::string filename);
        double distance(int first, int second);
    private:
        std::vector<CityNode> CityNodes;
    
};