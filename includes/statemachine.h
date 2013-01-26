#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "SDL.h"
#include "log.h"

typedef enum
{
    HEAVEN,
    PURGATORY,
    HELL
}wold_type;

typedef struct
{
    wold_type   current_type;
    uint32_t    current_stability;
    uint32_t    current_mmory;
}world_state_t;


#endif // STATEMACHINE_H
