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

entity_id ecs_m::create()
{
    if (deleted_entity_ids.empty()) {
        return entity_id_counter++;
    } else {
        entity_id id = deleted_entity_ids.top();
        deleted_entity_ids.pop();
        return id;
    }
}
