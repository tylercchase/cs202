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
    std::cout << "Solve random" << std::endl;
    solver.solveRandomly(1);
    std::cout << "Solve greedy" << std::endl;
    solver.solveGreedy();
}