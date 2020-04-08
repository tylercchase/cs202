#include "StopWatch.hpp"
#include <chrono>

StopWatch::StopWatch(){
    _start = std::chrono::system_clock::now();
}
void StopWatch::start(){
    _start = std::chrono::system_clock::now();
}
void StopWatch::end(){
    _end = std::chrono::system_clock::now();
}
const double StopWatch::get_time_milsec(){
    return std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();

}
const double StopWatch::get_time_sec(){
    return std::chrono::duration_cast<std::chrono::seconds>(_end - _start).count();

}
