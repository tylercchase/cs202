#include "cityList.hpp"
#include "cityPath.hpp"
class TspSolver {
    private:
        CityList cityList;
        CityPath cityPath;
        unsigned int bestDistance;
    public:
        void solveRandomly();

};