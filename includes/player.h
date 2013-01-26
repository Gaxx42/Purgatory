#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

#define PLAYER_IMAGE "concept_1.bmp"
#define PLAYER_VEL 5

typedef enum
{
    DRONE,
    GHOST
}player_type;

typedef struct
{
    player_type     current_type;
    uint32_t        current_momento;
    uint32_t        current_frustration;
    uint32_t        max_momento;
    uint32_t        max_frustration;
}player_state_t;

class Player : public Creature
{
private:
    player_state_t  player;

public:
                    Player();
                    ~Player();

    void            draw();
    void            center();

};

#endif // PLAYER_H
