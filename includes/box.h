#ifndef BOX_H
#define BOX_H

#include "SDL.h"
#include "imagehandler.h"
#include "log.h"

class Box
{
private:
    SDL_Rect    *box;       //type holding box coordinates
    uint8_t     shining;    //YES/NO

public:
                Box(uint32_t x, uint32_t y, uint32_t h, uint32_t w);
                Box(uint32_t x, uint32_t y, uint32_t h, uint32_t w, uint8_t shining);
                ~Box();

    void        draw();
    SDL_Rect    *get_box();
};

#endif // BOX_H
