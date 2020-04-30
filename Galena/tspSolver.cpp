#include "tspSolver.hpp"

#include <random>
#include <vector>

void TspSolver::solveRandomly(int repeat){
    for(int x = 0; x < repeat; x++){
        std::random_device device;
        std::default_random_engine engine(device());
        std::uniform_int_distribution<int> randomNumber(0, _cities.getCities().size() - 1);

        double bestfound = 1e12;
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
        }
        std::cout << "Total distance: " << totalDistance << std::endl;
    }
}
