#include <iostream>
#include "cityList.hpp"
#include "tspSolver.hpp"
int main(){
    CityList list{};
    list.loadCitiesFromFile("d18512.tsp");
    std::cout << list.distance(1,2) << std::endl;


}