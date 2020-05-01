
#include "cityList.hpp"
#include "cityPath.hpp"
#include <string>
class TspSolver {
    private:
        CityList _cities;
        CityPath _paths;
        CityPath solvedPath;
        unsigned int bestDistance;
    public:
        void setCities(CityList &cities){
            _cities = cities;
        }
        void solveRandomly(int repeat);
        void solveGreedy();
        void SolveMyWay();
        void outputSVG(std::string name);
};