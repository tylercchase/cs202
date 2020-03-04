#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
struct room {
    int roomNumber;
    int roomType;
    //roomType contains either
    //
    // 0 - Empty room
    // 1 - Room with a wumpus
    // 2 - Room with a pit
    // 3 - Room with a bat
    int connectedRooms[3];
};
std::map<int,room> initializeCaveSystem(){
    std::ifstream saveFile;
    saveFile.open("save.txt");
    std::map<int,room> rooms;

    std::string roomLine;
    while(getline(saveFile,roomLine,' ')){
        std::cout << roomLine << std::endl;
    }
}
void makeSave(){
    std::ofstream saveFile;
    saveFile.open("save.txt");
    int numBats{2};
    int numWumpus{1};
    int numPits{2};
    int numRooms{20};
    //Example: 10:0:12,3,4
    for (int x = 1; x <= numRooms; x++){

    }
}
int main(){
    std::ifstream saveFile;
    // initializeCaveSystem();
    return 0;   
}