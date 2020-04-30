#ifndef cityPath
#define cityPath
#include <vector>

class CityPath {
    private:
        std::vector<int> connections;
    public:
        CityPath();
        std::vector<int>& getConnections();
        void setConnections(std::vector<int> &connections);
};
#endif