#include "player.h"

Player::Player()
{
    get_crasbox()->h = PLAYER_HEIGTH;
    get_crasbox()->w = PLAYER_WIDTH;
    get_crasbox()->x = 2000;
    get_crasbox()->y = 1000;
    player.current_type = DRONE;
    player.current_frustration = 0;
    player.current_momento = 0;
    LOG("Player creation: SUCCESS\n");
}

Player::~Player()
{

}

void Player::draw()
{
    SDL_Rect clip;

    clip.x = (PLAYER_WIDTH*3)*get_direction() + (PLAYER_WIDTH*(get_frame()/10));
    clip.y = 0;
    clip.h = PLAYER_HEIGTH;
    clip.w = PLAYER_WIDTH;

    //Apply the message to the screen
    ih_apply_surface( (get_x() - camera_x()), (get_y() - camera_y()), PLAYER, &clip);
}

void Player::center()
{

    if((get_x() - BORDER_X) < camera_x())
    {
        move_camera((get_x() - BORDER_X) - camera_x(), 0);
    }
    if((get_y() - BORDER_Y) < camera_y())
    {
        move_camera(0, (get_y() - BORDER_Y) - camera_y());
    }
    if((get_x() + PLAYER_WIDTH  + BORDER_X) > (camera_x() + SCREEN_WIDTH))
    {
        move_camera((get_x() + PLAYER_WIDTH  + BORDER_X) - (camera_x() + SCREEN_WIDTH), 0);
    }
    if((get_y() + PLAYER_HEIGTH + BORDER_Y) > (camera_y() + SCREEN_HEIGHT))
    {
        move_camera(0, (get_y() + PLAYER_HEIGTH + BORDER_Y) - (camera_y() + SCREEN_HEIGHT));
    }


}
