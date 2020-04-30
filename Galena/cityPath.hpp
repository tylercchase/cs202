#ifndef cityPath
#define cityPath
#include <vector>
#include "cityNode.hpp"

class CityPath {
    private:
        std::vector<CityNode> connections{};
    public:
        std::vector<CityNode>& getConnections();
        void setConnections(std::vector<CityNode> &connections);
        void addCity(CityNode &city);
        int totalDistance();
};
#endif