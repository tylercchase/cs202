#ifndef coolLibrary_HPP
#define coolLibrary_HPP
#include <iostream>
namespace mgl {
    void printStuff(){
        std::cout << "asd" << std::endl;
    };
    class Texture2D {
        Texture2D();
        ~Texture2D();
        void use();
        void init(int w, int h, const std::string & pixels);


    };
}

#endif
