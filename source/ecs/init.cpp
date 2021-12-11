#include "ecs.h"

void ecs::init() 
{
    // Create a new ecs, and set the global ecs singleton
    ecs::ecs_c* ecs = new ecs::ecs_c();
    ecs::g_ecs = ecs; // Set gobal ecs singleton
}
