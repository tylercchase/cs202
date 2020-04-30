#include "tspSolver.hpp"

#include <random>

void TspSolver::solveRandomly(){
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<int> randomNumber(0, cityPath.getConnections().size());
    randomNumber(engine);
    std::vector<CityNode> chosenCityPath;
    std::vector<CityNode> unchosenCities;
}