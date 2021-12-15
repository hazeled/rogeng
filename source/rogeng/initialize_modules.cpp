#include "rogeng.h"

void rogeng::initialize_modules() 
{
    log = new log_m(this);
    log->log("Initializing modules\n");
    ecs = new ecs_m(this);
}
