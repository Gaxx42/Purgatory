#include "imagehandler.h"



static SDL_Surface *screen;
static SDL_Surface *background;
static SDL_Surface *player;
static SDL_Surface *cursor;
static SDL_Surface *message;

static int32_t cursor_x = 0;
static int32_t cursor_y = 0;

//The camera
static SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };


void center_camera(int32_t x, int32_t y)
{
    camera.x = x - SCREEN_WIDTH/2;
    camera.y = y - SCREEN_HEIGHT/2;
}

void move_camera(int32_t x, int32_t y)
{
    camera.x += x;
    camera.y += y;
}

int32_t     camera_x()
{
    return camera.x;
}

int32_t     camera_y()
{
    return camera.y;
}

void ih_cleanup()
{
    //Free the surfaces
    SDL_FreeSurface( player );
    SDL_FreeSurface( background );
    SDL_FreeSurface( screen );
    //Quit SDL
    SDL_Quit();
}

void ih_clear_screen()
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    offset.x = 0;
    offset.y = 0;
    //Fill the screen black
    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x00, 0x00 ) );
    //Set background
    SDL_BlitSurface( background, NULL, screen, &offset );
}

void ih_init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        //ERROR HANDLING
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        //ERROR HANDLING
    }

    //Set the window caption
    SDL_WM_SetCaption( "Purgatory", NULL );

    //Load the images
    player = ih_load_image( "img/concept_1.bmp" );
    background = ih_load_image( "img/background.bmp" );
    cursor = ih_load_image( "img/cursor.bmp" );
    message = ih_load_image( "img/pregen.bmp" );
}

SDL_Surface *ih_load_image( std::string filename )
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );

    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
     //If the image was optimized just fine
    if( optimizedImage != NULL )
    {
        //Map the color key
        Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0xC3, 0xC3, 0xC3 );
        //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
        SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
    }
    //Return the optimized image
    return optimizedImage;
}

void ih_apply_surface( int x,
                    int y,
                    creature_type_t creature,
                    SDL_Rect *clip)
{
    //Make a temporary surface to hold the creature surface
    SDL_Surface *creature_surface;

    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

    switch(creature)
    {
    case PLAYER:
        creature_surface = player;
        break;
    case SPIRIT:
        break;
    case ANT:
        break;
    case LEVIATHAN:
        break;
    }

    //Blit the surface
    SDL_BlitSurface( creature_surface, clip, screen, &offset );
}

void ih_update()
{
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        //ERROR HANDLING
    }
}

void ih_draw_box(SDL_Rect *box, uint8_t shining)
{
    SDL_Rect tbox;
    tbox.x = box->x - camera_x();
    tbox.y = box->y - camera_y();
    tbox.w = box->w;
    tbox.h = box->h;
    if(shining == YES)
    {
        SDL_FillRect(   screen,
                        &tbox,
                        SDL_MapRGB( screen->format, (rand()%0x1F), (rand()%0x1F), (rand()%0xFF) ) );
    }
    if(shining == NO)
    {
        SDL_FillRect(   screen,
                        &tbox,
                        SDL_MapRGB( screen->format, 0x6F, 0x4F, 0x1F) );
    }
}

void        apply_cursor()
{
    SDL_Rect offset;
    offset.x = cursor_x - CURSOR_SIZE/2;
    offset.y = cursor_y - CURSOR_SIZE/2;

    SDL_BlitSurface( cursor, NULL, screen, &offset );
}

void        set_cursor(int32_t x, int32_t y)
{
    cursor_x = x;
    cursor_y = y;
}

int32_t     get_cursor_x()
{
    return cursor_x;
}

int32_t     get_cursor_y()
{
    return cursor_y;
}

void show_message()
{
    SDL_Rect offset;
    offset.x = SCREEN_WIDTH/2 - 145;
    offset.y = SCREEN_HEIGHT/2 - 25;
    SDL_BlitSurface( message, NULL, screen, &offset );
    SDL_Flip( screen );
}
