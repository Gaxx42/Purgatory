#ifndef WRAITH_H
#define WRAITH_H

#include "creature.h"

#define WRAITH_IMAGE "concept_2.bmp"
#define WRAITH_VEL 5


class Wraith : public Creature
{
private:

public:
                    Wraith();
                    ~Wraith();

    void            draw();
    void            act();
};

#endif // WRAITH_H
