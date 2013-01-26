#include "world.h"

node_t *curr;
node_t *prev;
node_t *head = NULL;

static uint8_t known_world[LEVEL_WIDTH][LEVEL_HEIGHT];

void    world_init()
{
    memset(known_world, VOID, sizeof(known_world));
}

void    world_finit()
{
    delete[] known_world;
}

void    world_generate()
{
    uint32_t i = 0;
    uint32_t j = 0;
    srand ( time(NULL) );
    //fill array
    for(i = 0; i < LEVEL_WIDTH; i+=2)
    {
        for(j = 0; j < LEVEL_HEIGHT; j+=3)
        {
            known_world[i][j] = rand()%2;   //This is shit. Think of something
        }
    }


    //make rects
    for(i = 0; i < LEVEL_WIDTH; i++)
    {
        for(j = 0; j < LEVEL_HEIGHT; j++)
        {
            if(known_world[i][j] == GROUND)
            {
                draw_rect((i*60),(j*60),60,60);
            }
        }
    }
}

bool check_collision( SDL_Rect *A, SDL_Rect *B )
{
    //The sides of the rectangles
    int32_t leftA, leftB;
    int32_t rightA, rightB;
    int32_t topA, topB;
    int32_t bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A->x;
    rightA = A->x + A->w;
    topA = A->y;
    bottomA = A->y + A->h;

    //Calculate the sides of rect B
    leftB = B->x;
    rightB = B->x + B->w;
    topB = B->y;
    bottomB = B->y + B->h;

    //If any of the sides from A are outside of B
    if( bottomA < topB )
    {
        return false;
    }

    if( topA > bottomB )
    {
        return false;
    }

    if( rightA < leftB )
    {
        return false;
    }

    if( leftA > rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

void    draw_rect(int32_t x, int32_t y, uint32_t h, uint32_t w)
{
    uint32_t i = 0;
    uint32_t j = 0;

    for(i = x; i < (x+w); i+=(DEF_BOX_SIZE+1))
    {
        for(j = y; j < (y+h); j+=(DEF_BOX_SIZE+1))
        {
            add(new Box(i, j, DEF_BOX_SIZE, DEF_BOX_SIZE, NO));
        }
    }
}

void start_over()
{
    curr = head;
}

void add(Box *box)
{
    // Create a new node
    node_t *newNode = new node_t;
    newNode->data = box;
    newNode->next = NULL;

    // Create a temp pointer
    node_t *tmp = head;

    if ( tmp != NULL )
    {
        // Nodes already present in the list
        // Parse to end of list
        while ( tmp->next != NULL ) {
            tmp = tmp->next;
        }

        // Point the last node to the new node
        tmp->next = newNode;
    }
    else
    {
        // First node in the list
        head = newNode;
    }
}

void remove()
{
    if(curr != head)
    {
        prev->next = curr->next;
        delete      (curr->data);
        delete[]    curr;
        curr = prev->next;
    }
    else
    {
        delete      (curr->data);
    }
}

void traverse()
{
    if(curr != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
}

Box  *get_curr()
{
    if(curr != NULL)
    {
        return curr->data;
    }
    else
    {
        return NULL;
    }
}


