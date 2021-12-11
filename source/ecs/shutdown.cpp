#include "ecs.h"

void ecs::shutdown()
{
    delete(ecs::g_ecs);
}
