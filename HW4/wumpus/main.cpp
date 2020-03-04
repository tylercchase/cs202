#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <random>
#include <functional>
#include <chrono>
#include <algorithm>
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
// std::map<int,room> initializeCaveSystem(){
//     std::ifstream saveFile;
//     saveFile.open("save.txt");
//     std::map<int,room> rooms;

//     std::string roomLine;
//     while(getline(saveFile,roomLine,' ')){
//         std::cout << roomLine << std::endl;
//     }
//     return r
// }
void makeSave(){
    std::ofstream saveFile;
    saveFile.open("save.txt");
    int numBats{2};
    int numWumpus{1};
    int numPits{2};
    int numRooms{20};
    //Example: 10:0:12,3,4
    std::default_random_engine generator;
    generator.seed(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> distribution(0,3);
    auto randomThing = std::bind ( distribution, generator );
    std::uniform_int_distribution<int> roomDistribution(1,20);
    auto randomRoom = std::bind ( roomDistribution, generator );
    

    for (int x = 1; x <= numRooms; x++){
        // 0 - Empty room
        // 1 - Room with a wumpus
        // 2 - Room with a pit
        // 3 - Room with a bat
        bool typeChecking = true;
        int type;
        while(typeChecking){
            type = randomThing();
            switch (type)
            {
                case 0:
                    typeChecking = false;
            case 1:
                if(numWumpus != 0){
                    numWumpus--;
                    typeChecking = false;
                }
                break;
            case 2:
                if(numPits != 0){
                    numPits--;
                    typeChecking = false;
                } 
            case 3:
                if(numBats != 0){
                    numBats--;
                    typeChecking = false;
                }
            default:
                break;
            }
        }
        //Generate connecting rooms
        std::vector<int> rooms;
        for(int i=0;i<3;i++){
            int room = randomRoom();
            while(std::find(rooms.begin(),rooms.end(), room) != rooms.end()){
                room = randomRoom();
            }
            rooms.push_back(room);
        }
        saveFile << x << ":" <<  type << ":";
        for(int i=1; i<=rooms.size();i++){
            saveFile << rooms[i-1];
            if(i != rooms.size()){
                saveFile << ',';
            }
        }
        saveFile << '\n';
    }
}
int main(){
    std::ifstream saveFile;
    // initializeCaveSystem();
    makeSave();
    return 0;   
}