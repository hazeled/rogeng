#pragma once

#include <iostream>
#include <chrono>

namespace log 
{
    void init();

    std::chrono::milliseconds get_time();

    template<typename ...Args>
    void log(Args && ...args)
    {
        std::cout << "[" << get_time().count() << "] ";
        (std::cout << ... << args);
    }
}
