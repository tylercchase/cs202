#include <iostream>
#include <fstream>

struct room {
    int roomType;
    //roomType contains either
    // 0 - Empty room
    // 1 - Room with a wumpus
    // 2 - Room with a pit
    // 3 - Room with a bat
    int connectedRooms[3];
};
void initializeCaveSystem(){
    std::ofstream saveFile;
    saveFile.open("save.txt");

}
int main(){
    std::ifstream saveFile;

    return 0;
}