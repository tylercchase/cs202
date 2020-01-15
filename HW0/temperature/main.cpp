#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

//Cpp method for farenheit to celsius
double cpp_ftoc(const char* str){
    return std::stod(str) - 32 * 5 / 9;
}

//C method for string to double with celsius to farenheits
double c_ctof(const char* str){
    char* end;
    return std::strtod(str, &end) * 9 / 5 + 32;
    
}

int main(int argc, char* argv[]){
    //check if arguments supplied match required length
    if(argc == 3){
        if( strcmp(argv[1],"--ftoc") == 0){
            cout << cpp_ftoc(argv[2]) << endl;
        }
        else if(strcmp(argv[1],"--ctof") == 0){
            cout << c_ctof(argv[2]) << endl;
        }
        else{
            cout << "Invalid argument" << argv[1] << endl;
        }
    }
    else{
        cout << "Invalid number of arguments" << endl;
    }
    return 0;
}
