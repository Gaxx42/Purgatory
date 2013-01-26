#include "music_player.h"

static const char *playlist[5] = {  "music/01.DepressionAtMario.mp3",
                                    "music/02.Outro.mp3",
                                    "music/03.Happy.....mp3",
                                    "music/04.Sidtone.mp3",
                                    "music/05.Tz-tz-tz.mp3"
};
static const uint32_t playlist_length = 4;

//The music that will be played
Mix_Music   *music = NULL;
uint32_t    current_track_num = 0;

//The sound effects that will be used
Mix_Chunk   *jump = NULL;


void    music_init()
{
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    Mix_Init(MIX_INIT_MP3);

    jump = Mix_LoadWAV( "sounds/jump.wav" );
}

void    music_play()
{
    //If there is no music playing
    if( Mix_PlayingMusic() == 0 )
    {
        music_choose_track(playlist[current_track_num]);

        LOG("Track %d is playing: %s\n", current_track_num, playlist[current_track_num]);

        if(current_track_num++ == playlist_length)
        {
            current_track_num = 0;
        }

        Mix_PlayMusic( music, 1 );
    }
}

void    music_pause()
{
    Mix_PauseMusic();
}

void    music_stop()
{
    Mix_HaltMusic();
}

void    music_resume()
{
    if( Mix_PausedMusic() == 1 )
    {
        //Resume the music
        Mix_ResumeMusic();
    }
}

void    music_choose_track(const char *track)
{
    music = Mix_LoadMUS(track);
}

void    music_finit()
{
    Mix_FreeChunk( jump );

    Mix_FreeMusic( music );
    Mix_Quit();
    Mix_CloseAudio();
}

void    play_jump()
{
    Mix_PlayChannel( -1, jump, 0 );
}
