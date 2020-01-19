#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#include <vector>
using std::cout;
using std::endl;
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
    myfile.close();
    return numLines;
}


void findExcerpt(int numLines){
    std::string line;
    std::ifstream myfile ("output.txt");

    
    srand (time(NULL));
    int start = numLines - (rand() % (numLines-100));
    //Make sure start won't cross the EOF
    if(start > numLines - 50){
        start -= 50;
    }

    for(int x = 0; x < start; x++){
        getline(myfile,line);
    }
    int counter = 0;
    do{

        if(isspace(line[1])){
            counter++;
        }
        else{
            counter = 0;
        }
    }while(getline(myfile,line) && counter != 2);
    if(getline(myfile,line)){

    }else{
        std::cout << "uh oh reached EOF" << std::endl;
    }
    std::vector<std::string> output;
    for(int i = 0; i < 10; i++){
        getline(myfile,line);
        output.push_back(line);
    }

    for( auto x : output){
        cout << x << endl;
    }
    myfile.close();
}

int main(int argc, char* argv[]){
    char* p;
    double converted = strtod(argv[2], &p);
    if(argc == 3 && !*p && converted > 0){
        //check if the third arg is a number using c library
        if (!*p) {

            if( strcmp(argv[1],"-b") == 0){
                download(std::stoi(argv[2]),0);
            }

        }
        else {
            cout << "Not a number input: " << argv[2] << endl;
            return false;
        }

    }
    else{
        srand (time(NULL));
        int random = rand() % 60000 + 1;
        download(random,0);
    }

    int numLines = getNumLines();
    findExcerpt(numLines);
    return 0;
}