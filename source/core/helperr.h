#pragma once

#include <iostream>
#include <utility>

namespace helperr
{
    void display_params(); // Display a help message with all parameters
    void display_usage(); // Display a help message with program usage

    template<typename ...Args>
    void error(Args && ...args)
    {
        std::cout << "Error! ";
        (std::cout << ... << args);
        display_usage();
        display_params();
        exit(0);
    }
}
