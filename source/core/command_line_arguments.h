#pragma once

#include <pch/pch.h>

namespace command_line_arguments 
{
    void init(int argc, char** argv);
    popl::OptionParser* get_op();
}
