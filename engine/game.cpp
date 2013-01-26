#include "game.h"



//The event structure
SDL_Event event;

uint32_t  mouseleft_flag    = NO;
uint32_t  mouseright_flag   = NO;

Game::Game()
{
}

void Game::handle_events(Player *player)
{
    SDL_Rect    *tmp;
    Box         *tmpbox;

    //The mouse offsets
    int32_t x = 0;
    int32_t y = 0;

    //Handle events for player
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP:
                player->jump();
                break;
            case SDLK_LEFT:
                player->set_x_vel(player->get_x_vel() - PLAYER_VEL);
                break;
            case SDLK_RIGHT:
                player->set_x_vel(player->get_x_vel() + PLAYER_VEL);
                break;
            default:
                break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP:
                //Nothing to do here really. Set some flags maybe.
                break;
            case SDLK_LEFT:
                player->set_x_vel(player->get_x_vel() + PLAYER_VEL);
                break;
            case SDLK_RIGHT:
                player->set_x_vel(player->get_x_vel() - PLAYER_VEL);
                break;
            default:
                break;
        }
    }
    //If a mouse button was pressed
    else if( event.type == SDL_MOUSEBUTTONDOWN )
    {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            mouseleft_flag = YES;
        }
        //If the right mouse button was pressed
        if( event.button.button == SDL_BUTTON_RIGHT )
        {
            mouseright_flag = YES;
        }
    }
    else if( event.type == SDL_MOUSEBUTTONUP )
    {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            mouseleft_flag = NO;
        }
        //If the right mouse button was pressed
        if( event.button.button == SDL_BUTTON_RIGHT )
        {
            mouseright_flag = NO;
        }
    }
    //If mouse moved
    else if( event.type == SDL_MOUSEMOTION )
    {
        set_cursor(event.button.x, event.button.y);
    }
    if(mouseleft_flag == YES)
    {
        //Get the mouse offsets
        x = get_cursor_x() + camera_x();
        y = get_cursor_y() + camera_y();

        add(new Box(x,y,DEF_BOX_SIZE,DEF_BOX_SIZE, YES));
    }
    if(mouseright_flag == YES)
    {
        SDL_Rect eraser;
        //Get the mouse offsets
        eraser.x = get_cursor_x() + camera_x();
        eraser.y = get_cursor_y() + camera_y();
        eraser.h = DEF_BOX_SIZE;
        eraser.w = DEF_BOX_SIZE;
        //If the mouse is over the box
        start_over();
        while(get_curr())
        {
            tmpbox = get_curr();
            if(tmpbox != NULL)
            {
                tmp = tmpbox->get_box();
            }

            if(check_collision(tmp, &eraser))
            {
                remove();
            }
            traverse();
        }

    }


}

uint32_t Game::run()
{
//This is a main game

    //Quit flag
    bool quit = false;

    //The frame rate regulator
    Timer fps;

    ih_init();
    music_init();
    world_init();

    //SOME SORT OF MENU SHOULD BE HERE


    //Constructor calls etc
    Player *player = new Player();
    center_camera((player->get_x() + PLAYER_WIDTH/2), (player->get_y() + PLAYER_HEIGTH/2));

    show_message();
    //BOX FOR TEST
    world_generate();


    //main loop
    while(quit == false)
    {
        //Start the frame timer
        fps.start();

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            handle_events(player);
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        music_play();


        //MOVES
        player->move();
        player->center();

        //CLS
        ih_clear_screen();

        //DRAWING

        //hide cursor
        SDL_ShowCursor(0);
        apply_cursor();

        player->draw();

        start_over();

        while(get_curr())
        {
            get_curr()->draw();
            traverse();
        }

        ih_update();

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }

    }


    delete player;
    world_finit();
    music_finit();
    ih_cleanup();


    return 0;
}
