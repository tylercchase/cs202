#include <iostream>
#include "cityList.hpp"
#include "tspSolver.hpp"
int main(){
    CityList list{};
    list.loadCitiesFromFile("d18512.tsp");
    std::cout << list.distance(1,2) << std::endl;


    TspSolver solver;
    std::cout << list.getCities().size() << std::endl;
    solver.setCities(list);
    solver.solveRandomly(1);
}