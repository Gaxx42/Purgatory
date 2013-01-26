#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include "SDL.h"
#include <string>
#include "log.h"
#include <stdlib.h>

#define CURSOR_SIZE     26


#define PLAYER_WIDTH    56
#define PLAYER_HEIGTH   112

#define BORDER_X        220
#define BORDER_Y        120

#define DEF_BOX_SIZE    5

#define NO      0
#define YES     1

//The attributes of the screen
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP    = 32;






typedef enum
{
    PLAYER,
    SPIRIT,
    ANT,
    LEVIATHAN
}creature_type_t;

    //loads an image from a file and stores it in SDL_Surface*
    SDL_Surface *ih_load_image( std::string filename );

    //Blits image to screen. x,y - coordinates, creature indicates
    //creature type to be blitted, clip is used to show which part of image
    //will be blitted
    void        ih_apply_surface(   int x,
                                    int y,
                                    creature_type_t creature,
                                    SDL_Rect *clip);

    //Draws a rectangle. Not much to say here.
    void        ih_draw_box(SDL_Rect *box, uint8_t shining);

    //Initialization
    void        ih_init();

    //Flip buffers
    void        ih_update();

    //Clean all buffers, free memory, etc
    void        ih_cleanup();

    //Fill screen black
    void        ih_clear_screen();

    void        apply_cursor();
    void        set_cursor(int32_t x, int32_t y);
    int32_t     get_cursor_x();
    int32_t     get_cursor_y();

    void        center_camera(int32_t x, int32_t y);
    void        move_camera(int32_t x, int32_t y);
    int32_t     camera_x();
    int32_t     camera_y();

    void show_message();

#endif // IMAGEHANDLER_H
