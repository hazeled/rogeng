#pragma once

#include <stack>
#include <vector>
#include <cstdint>
#include <memory>
#include <bitset>
// A temporary fix. Eventually, we want to figure out (At compile time) how many components are being added, and create a bitfield from that
#define MAX_COMPONENT_TYPES 24

// An entity id
typedef uint16_t entity_id;

struct entity_desc {
    std::bitset<MAX_COMPONENT_TYPES> components_flags;
};

class rogeng;

// Singleton ECS class
class ecs_m {
public:
    ecs_m(rogeng* re);
    ~ecs_m();
    
    // Create a new entity and return its ID
    entity_id create();

    // Delete an entity specified by id
    void destroy(entity_id entity);

private:
    rogeng* re;

    // Table of entityp pointers, can be accessed with entity_id
    std::vector<entity_desc*> entities;
    
    
    /* NOTE: The classic way of doing entity IDs is to fill up a
     * queue with all possible ids and pull from the front. Then,
     * when an entity is deleted, you can put the ID at the back 
     * of the stack.
     * This fills up useless space in memory. Instead, deleted
     * entity ids are placed in deleted_entity_ids, and given
     * to new entities (assuming it isn't empty). If 
     * deleted_entity_ids is empty, the id will just be assigned by
     * the entity_id_counter.
     */ 
    std::stack<entity_id> deleted_entity_ids;

    uint16_t component_id_counter = 0;
    uint16_t entity_id_counter    = 0;

    // Template functions
    // Return a type-specific id
    template <typename T>
    uint16_t get_type_id() {
        static uint16_t component_id = component_id_counter++;
        return component_id;
    }
};
