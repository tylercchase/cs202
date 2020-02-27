g++ -c StopWatch.cpp -o StopWatch.o -I.
ar -crs libStopWatch.a StopWatch.o
g++ main.cpp -L. -lStopWatch -I. && ./a.out