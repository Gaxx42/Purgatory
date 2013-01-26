#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "SDL_mixer.h"
#include "log.h"

void    music_init();
void    music_play();
void    music_pause();
void    music_stop();
void    music_resume();
void    music_choose_track(const char *track);
void    music_finit();

void    play_jump();

#endif // MUSIC_PLAYER_H
