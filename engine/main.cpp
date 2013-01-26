#include "game.h"

int main( int argc, char* args[] )
{
    LOG("Starting game\n");
    Game *game = new Game();
    game->run();

    return 0;
}
