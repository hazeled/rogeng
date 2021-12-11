#include "log.h"
#include <chrono>

namespace 
{
    std::chrono::system_clock::time_point start_time;
}

void log::init() {
    start_time = std::chrono::high_resolution_clock::now();
}

std::chrono::milliseconds log::get_time() {
    auto current_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time);
}
