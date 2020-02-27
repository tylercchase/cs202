g++ -c StopWatch.cpp -I.
ar -crs libcoolLibrary.a *.o
g++ main.cpp -LlibcoolLibrary.a -I. && ./a.out