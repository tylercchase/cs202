#include "cityPath.hpp"
#include <math.h>
void CityPath::addCity(CityNode &city){
    connections.push_back(city);
}
int CityPath::totalDistance(){
    int total = 0;
    for(int i = 0; i < connections.size() - 1; i++){
        total += sqrt(pow((connections[i+1].getLatitude() - connections[i].getLatitude() ),2) + pow(connections[i+1].getLongitude() - connections[i].getLongitude() ,2));
    }
    return total;
}