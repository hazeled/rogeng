#include "helperr.h"
#include "command_line_arguments.h"
#include <iostream>
#include <utility>

void helperr::display_params() 
{
    // Printing an option parser to stdout will display a help message
    popl::OptionParser* op = command_line_arguments::get_op();
    std::cout << *op << std::endl;
}

void helperr::display_usage()
{
    std::cout << "Usage: rogeng <source_filename>" << std::endl;
}
