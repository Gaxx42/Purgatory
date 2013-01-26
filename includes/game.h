#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "player.h"
#include "imagehandler.h"
#include "timer.h"
#include "world.h"
#include "log.h"
#include "music_player.h"

class Game
{
public:
                Game();
                ~Game();
    uint32_t    run();
    void        handle_events(Player *player);
};

#endif // GAME_H
