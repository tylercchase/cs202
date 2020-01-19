#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

bool download(int number, int type){
    std::string command;
    auto newType = type + 1;
    if(type == 0){
        command = "wget -qO output.txt http://www.gutenberg.org/files/" + std::to_string(number) + "/" + std::to_string(number) + ".txt 2>/dev/null";
    }
    else if(type == 1){
        command = "wget -qO output.txt http://www.gutenberg.org/files/" + std::to_string(number) + "/" + std::to_string(number) + "-0.txt 2>/dev/null";
    }
    else if(type == 2){
        command = "wget -qO output.txt http://www.gutenberg.org/files/" + std::to_string(number) + "/pg" + std::to_string(number) + "-0.txt 2>/dev/null";
    }
    system(command.c_str());
    std::string line;
    std::ifstream myfile ("output.txt");

    //Check if file is null and if it is try a different URL
    if (myfile.is_open())
    {
        std::string line;
        getline (myfile,line);
        std::cout << line << std::endl;
        myfile.close();

        if(line != ""){
            return true;
        }
        else if(type == 2){
            return false;

        }else{
            download(number,newType);
        }
    }else{
        download(number,newType);
    }
    return false;
}

int getNumLines(){
    int numLines = 0;
    std::string line;
    std::ifstream myfile("output.txt");

    while (std::getline(myfile, line))
        ++numLines;
    return numLines;
}


int main(){
    if(download(250,0)){
        std::cout << "Succesful download" << std::endl;
    } 
    else {
        std::cout << "Unsuccesful download" << std::endl;
    }
    int numLines = getNumLines();
    std::cout << numLines << std::endl;

    // std::string command = "wget -O stdout";
}