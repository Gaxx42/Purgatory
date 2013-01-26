#ifndef CREATURE_H
#define CREATURE_H

#include "SDL.h"
#include "imagehandler.h"
#include "log.h"
#include "world.h"
#include "music_player.h"

#define LEFT    0
#define RIGHT   1

#define NO      0
#define YES     1

#define JUMP_STRENGTH 20


class Creature
{
private:
    uint32_t    direction;      //right/left
    uint32_t    jumping;        //yes/no
    uint32_t    flying;         //yes/no
    int32_t     x_velocity;
    int32_t     y_velocity;
    int32_t     spirit;
    uint32_t    frame;          //frame indicates current animation frame
    SDL_Rect    crashbox;

public:
                Creature();
                Creature(uint32_t h, uint32_t w);
                ~Creature();

    void        set_x(uint32_t x);
    void        set_y(uint32_t y);

    uint32_t    get_x();
    uint32_t    get_y();

    void        set_x_vel(uint32_t x_vel);
    void        set_y_vel(uint32_t y_vel);

    int32_t     get_x_vel();
    int32_t     get_y_vel();

    SDL_Rect    *get_crasbox();

    uint32_t    get_direction();
    uint32_t    get_frame();

    uint32_t    add_spirit(int32_t change);    //change>0 if add change<0 if remove

    void        move();
    uint32_t    update();

    void        jump();         //set jump flag and change velocity
};

#endif // CREATURE_H
