#include "core.h"
#include "ecs/ecs.h"

int core::shutdown()
{
    ecs::shutdown();
    return 0;
}
