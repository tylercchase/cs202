#include <chrono>
#include <ctime>
#include <vector>
class StopWatch {
    public:    
        std::chrono::time_point<std::chrono::system_clock> _start;
        std::chrono::time_point<std::chrono::system_clock> _end;

        StopWatch();
        void start();
        void end();
        const double get_time_sec();
        const double get_time_milsec();

};