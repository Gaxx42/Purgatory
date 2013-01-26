#include "creature.h"



Creature::Creature()
{
    direction   = RIGHT;
    jumping     = NO;
    x_velocity  = 0;
    y_velocity  = 0;
    crashbox.x  = 150;
    crashbox.y  = 150;
    flying = NO;
    LOG("Creature creation: SUCCESS\n");
}

Creature::Creature(uint32_t h, uint32_t w)
{
    direction   = RIGHT;
    jumping     = NO;
    x_velocity  = 0;
    y_velocity  = 0;
    crashbox.x  = 150;
    crashbox.y  = 150;
    crashbox.h  = h;
    crashbox.w  = w;
    flying = NO;
    LOG("Creature creation: SUCCESS\n");
}

Creature::~Creature()
{

}

void Creature::move()
{
    SDL_Rect    *tmp;
    Box         *tmpbox;

    //set direction and animation frame
    if(x_velocity > 0)
    {
        direction = RIGHT;
        frame++;
        if(frame >= 30)
        {
            frame = 0;
        }
    }
    if(x_velocity < 0)
    {
        direction = LEFT;
        frame++;
        if(frame >= 30)
        {
            frame = 0;
        }
    }
    if(x_velocity == 0)
    {
        frame = 0;
    }

    if(flying == NO)
    {
        y_velocity++;   //Gravity! Cruel bitch!
    }


    //Move left or right
    crashbox.x += x_velocity;

    //Check horizontal collisions
    start_over();
    while(get_curr())
    {
        tmpbox = get_curr();
        if(tmpbox != NULL)
        {
            tmp = tmpbox->get_box();
        }

        if(check_collision(tmp, &crashbox))
        {
            if(((crashbox.y + crashbox.h) - tmp->y) <= 5)
            {
                crashbox.y -= (crashbox.y + crashbox.h) - tmp->y +1;
                crashbox.x += x_velocity/5;
            }
            crashbox.x -= x_velocity;
        }
        traverse();
    }



    //Move up or down
    crashbox.y += y_velocity;

    //Check vertical collisions
    start_over();
    while(get_curr())
    {
        tmpbox = get_curr();
        if(tmpbox != NULL)
        {
            tmp = tmpbox->get_box();
        }

        if(check_collision(tmp, &crashbox))
        {
            crashbox.y -= y_velocity;
            y_velocity = 0;
            jumping = NO;
        }
        traverse();
    }
}



void        Creature::set_x(uint32_t x)
{
    crashbox.x = x;
}

void        Creature::set_y(uint32_t y)
{
    crashbox.y = y;
}

uint32_t    Creature::get_x()
{
    return crashbox.x;
}

uint32_t    Creature::get_y()
{
    return crashbox.y;
}

void        Creature::set_x_vel(uint32_t x_vel)
{
    x_velocity = x_vel;
}

void        Creature::set_y_vel(uint32_t y_vel)
{
    y_velocity = y_vel;
}

int32_t    Creature::get_x_vel()
{
    return x_velocity;
}

int32_t    Creature::get_y_vel()
{
    return y_velocity;
}

SDL_Rect   *Creature::get_crasbox()
{
    return &crashbox;
}

void        Creature::jump()
{
    if(jumping == NO)
    {
        //play_jump();  //Jump sound is shit
        y_velocity -= JUMP_STRENGTH;
        jumping = YES;
    }
}

uint32_t Creature::get_direction()
{
    return direction;
}

uint32_t    Creature::get_frame()
{
    return frame;
}
