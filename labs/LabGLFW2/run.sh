g++ -c coolLibrary.hpp -I.
ar -crs libcoolLibrary.a *.hpp.gch
g++ LabGLFW_Refactor.cpp -LlibcoolLibrary.a -I. -lGL -lglfw && ./a.out