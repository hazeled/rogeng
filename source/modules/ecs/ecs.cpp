#include "ecs.h"

#include <rogeng/rogeng.h>
#include <modules/log/log.h>

ecs_m::ecs_m(rogeng* re) :
    re(re)
{
    log_m* log = re->_get_log();
    log->log("ECS initialized\n");
}


ecs_m::~ecs_m() 
{

}
