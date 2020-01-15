#include <iostream>
#include <string.h>
using std::cout;
using std::endl;


double cpp_ftoc(const char* str){
    return 0;
}
double c_ctof(const char* str){
    return 0;
}

int main(int argc, char* argv[]){
    //check if arguments supplied match required length
    for(int x=0; x < argc; x++){
        cout << x << ": " << argv[x] << endl;
    }
    if(argc == 3){
        if( strcmp(argv[1],"--ftoc") == 0){
            cout << cpp_ftoc(argv[3]) << endl;
        }
        else if(strcmp(argv[1],"--ctof")){
            cout << c_ctof(argv[3]) << endl;
        }else{
            cout << "Invalid argument" << argv[1] << endl;
        }
    }else{
        cout << "Invalid number of arguments" << endl;
    }
    return 0;
}
