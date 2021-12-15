#pragma once

#include <iostream>
#include <chrono>

class rogeng;

class log_m
{
public:
    log_m(rogeng* re);

    template<typename ...Args>
    void log(Args && ...args)
    {
        std::cout << "[" << get_time().count() << "] ";
        (std::cout << ... << args);
    }
    
    template<typename ...Args>
    void print(Args && ...args)
    {
        std::cout << "[x] ";
        (std::cout << ... << args);
    }
private:
    rogeng* re;
    std::chrono::milliseconds get_time();

};
