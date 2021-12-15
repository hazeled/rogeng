#include "log.h"
#include <chrono>

namespace 
{
    std::chrono::system_clock::time_point start_time;
}

log_m::log_m(rogeng* re) : 
    re(re) 
{
#ifdef LOG_TIME
    start_time = std::chrono::high_resolution_clock::now();
#endif // LOG_TIME
}

#ifdef LOG_TIME
std::chrono::milliseconds log_m::get_time() 
{
    auto current_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time);
}
#endif // LOG_TIME
