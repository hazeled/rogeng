#pragma once

#include <modules/ecs/ecs.h>
#include <modules/log/log.h>

// The main engine class, contains pointers to all engine modules
class rogeng
{
public:
    rogeng();
    ~rogeng();

    ecs_m* get_ecs() const { return ecs; };

    log_m* _get_log() const { return log; };

private:
    void initialize_modules();

    ecs_m* ecs;
    log_m* log;
};
