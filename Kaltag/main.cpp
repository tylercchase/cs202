#include <iostream>
#include "cityList.hpp"
#include "tspSolver.hpp"
int main(){
    CityList list{};
    list.loadCitiesFromFile("d18512.tsp");


    TspSolver solver;
    solver.setCities(list);
    std::cout << "Solve random" << std::endl;
    solver.solveRandomly(1);
    std::cout << "Solve greedy" << std::endl;
    solver.solveGreedy();
    std::cout << "Solve my way" << std::endl;
    solver.SolveMyWay();
}