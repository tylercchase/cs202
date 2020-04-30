#include "cityList.hpp"
#include "cityPath.hpp"
class TspSolver {
    private:
        CityList cities;
        CityPath paths;
        unsigned int bestDistance;
    public:
        void solveRandomly();

};