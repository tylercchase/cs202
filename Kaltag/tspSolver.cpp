#include "tspSolver.hpp"

#include <random>
#include <vector>

void TspSolver::solveRandomly(int repeat){
    int bestfound = 500000000;

    for(int x = 0; x < repeat; x++){
        std::random_device device;
        std::default_random_engine engine(device());
        std::uniform_int_distribution<int> randomNumber(0, _cities.getCities().size() - 1);

        auto unchosenCities = _cities.getCities();
        CityPath chosenCities{};
        int start = randomNumber(engine);
        CityNode startCity = unchosenCities[start];
        for(int i = 0; i < unchosenCities.size(); i++){
            std::uniform_int_distribution<int> randomNumber(0, unchosenCities.size() - 1);
            int selection = randomNumber(engine);
            chosenCities.addCity(unchosenCities[selection]);
            unchosenCities.erase(unchosenCities.begin() + selection);
        }
        int totalDistance = chosenCities.totalDistance();
        if(bestfound > totalDistance){
            bestfound = totalDistance;
            solvedPath = chosenCities;
        }
    }
    std::cout << "Total distance: " << bestfound << std::endl;

}
void TspSolver::solveGreedy(){
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<int> randomNumber(0, _cities.getCities().size() - 1);

    auto unchosenCities = _cities.getCities();
    CityPath chosenCities{};
    int start = randomNumber(engine);
    CityNode startCity = unchosenCities[start];
    CityNode lastCity = startCity;
    while(unchosenCities.size() > 1){
        double closestDistance = 1e12;
        for(int i = 0; i < unchosenCities.size(); i++){
            double found = sqrt(pow((unchosenCities[i].getLatitude() - lastCity.getLatitude() ),2) + pow(unchosenCities[i].getLongitude() - lastCity.getLongitude() ,2));
            if(closestDistance > found){
                closestDistance = found;
                chosenCities.addCity(unchosenCities[i]);
                unchosenCities.erase(unchosenCities.begin() + i);
            }
        }
    }
    solvedPath = chosenCities;
    std::cout << "Total distance: " << chosenCities.totalDistance() << std::endl;

    
}
void TspSolver::SolveMyWay(){
    //Find the longest way possible
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<int> randomNumber(0, _cities.getCities().size() - 1);

    auto unchosenCities = _cities.getCities();
    CityPath chosenCities{};
    int start = randomNumber(engine);
    CityNode startCity = unchosenCities[start];
    CityNode lastCity = startCity;
    while(unchosenCities.size() > 1){
        double closestDistance = 0;
        for(int i = 0; i < unchosenCities.size(); i++){
            double found = sqrt(pow((unchosenCities[i].getLatitude() - lastCity.getLatitude() ),2) + pow(unchosenCities[i].getLongitude() - lastCity.getLongitude() ,2));
            if(closestDistance < found){
                closestDistance = found;
                chosenCities.addCity(unchosenCities[i]);
                unchosenCities.erase(unchosenCities.begin() + i);
            }
        }
    }
    solvedPath = chosenCities;
    std::cout << "Total distance: " << chosenCities.totalDistance() << std::endl;

}
void outputSVG(std::string name){
    std::string templateStart;
    std::string templateEnd;
}