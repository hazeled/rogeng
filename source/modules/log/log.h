#pragma once

#include <config.h>

#include <iostream>

#ifdef LOG_TIME
#include <chrono>
#endif // LOG_TIME

class rogeng;

class log_m
{
public:
    log_m(rogeng* re);

    template<typename ...Args>
    void log(Args && ...args)
    {
#ifdef LOG_TIME
        std::cout << "[" << get_time().count() << "] ";
#endif // LOG_TIME
        (std::cout << ... << args);
    }
    
    template<typename ...Args>
    void print(Args && ...args)
    {
#ifdef LOG_TIME
        std::cout << "[x] ";
#endif // LOG_TIME
        (std::cout << ... << args);
    }
private:
    rogeng* re;
#ifdef LOG_TIME
    std::chrono::milliseconds get_time();
#endif // LOG_TIME

};
