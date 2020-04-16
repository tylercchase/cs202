#include <iostream>
#include <fstream>
#include "cityList.hpp"
int main(){
    CityList list{};
    list.loadCitiesFromFile("test.tsp");
    std::cout << list.distance(1,2) << std::endl;
}