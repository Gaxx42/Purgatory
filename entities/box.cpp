#include "box.h"


Box::Box(uint32_t x, uint32_t y, uint32_t h, uint32_t w)
{
    LOG("New box created [x:%d, y:%d, w:%d, h:%d]\n", x, y, w, h);
    box = new SDL_Rect();
    box->x = x;
    box->y = y;
    box->w = w;
    box->h = h;
    shining = NO;
}

Box::Box(uint32_t x, uint32_t y, uint32_t h, uint32_t w, uint8_t shining)
{
    LOG("New box created [x:%d, y:%d, w:%d, h:%d]\n", x, y, w, h);
    box = new SDL_Rect();
    box->x = x;
    box->y = y;
    box->w = w;
    box->h = h;
    this->shining = shining;
}

Box::~Box()
{
    delete[] box;
}

SDL_Rect *Box::get_box()
{
    return box;
}

void Box::draw()
{
    ih_draw_box(box, shining);
}
