#include "command_line_arguments.h"
#include "helperr.h"
#include <vector>
#include <assert.h>
#include <string>

#include <iostream>

namespace {
    char* gFile;
    popl::OptionParser* op = 0x00;
}

void command_line_arguments::init(int argc, char** argv) 
{
    op = new popl::OptionParser("Allowed options");

    auto opt_help = op->add<popl::Switch>("h", "help", "Display a help message");

    op->parse(argc, argv);

    if (opt_help->is_set()) {
        // Help is set, display a help message
        helperr::display_usage();
        helperr::display_params();

        return;
    }

    else if (op->non_option_args().empty()) {
        std::cout << "Error! At least one source filename is required" << std::endl;
        helperr::display_usage();
        helperr::display_params();

        return;
    }

    gFile = (char*)op->non_option_args()[0].c_str();
}

popl::OptionParser* command_line_arguments::get_op() 
{
    assert(op);
    return op;
}
