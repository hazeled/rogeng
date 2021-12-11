#include "core.h"
#include "command_line_arguments.h"
#include <log/log.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) 
{
    log::init();
    command_line_arguments::init(argc, argv);
    
    int init_res = core::init();
    if (init_res != 0) { 
        printf("Rogeng initialization failed with code %d", init_res);
        exit(init_res);
    }

    int shutdown_res = core::shutdown();
    if (shutdown_res != 0) {
        printf("Rogeng shutdown failed with code %d", shutdown_res);
        exit(shutdown_res);
    }
    return 0;
}
