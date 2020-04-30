
#include "cityList.hpp"
#include "cityPath.hpp"

class TspSolver {
    private:
        CityList _cities;
        CityPath _paths;
        unsigned int bestDistance;
    public:
        void setCities(CityList &cities){
            _cities = cities;
        }
        void solveRandomly(int repeat);
        void solveGreedy();
        void SolveMyWay();
};