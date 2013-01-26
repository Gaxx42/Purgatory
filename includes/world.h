#ifndef WORLD_H
#define WORLD_H

#include "box.h"
#include "log.h"

//The dimensions of the level
#define LEVEL_WIDTH     320
#define LEVEL_HEIGHT    32

#define VOID            0x00
#define GROUND          0x01
#define WRAITH          0x02

//Node of a linked list
struct node
{
    Box         *data;
    struct node *next;
};
typedef struct node node_t;

void    world_init();

void    world_finit();

void    world_generate();

//Checks collisions between two rectangles
bool    check_collision( SDL_Rect *A, SDL_Rect *B );

//draw a rect from boxes
void    draw_rect(int32_t x, int32_t y, uint32_t h, uint32_t w);

//Starts linked list from beginning
void    start_over();

//Adds a box to linked list
void    add(Box *box);

//removes a box
void    remove();

//Next element
void    traverse();

//Get current node
Box     *get_curr();

#endif // WORLD_H
