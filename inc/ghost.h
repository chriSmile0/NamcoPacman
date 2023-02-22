#ifndef GHOST_H
#define GHOST_H
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
using namespace std;

class Ghost: public Personnage
{
    public:
        Ghost();
        Ghost(Ghost const& perso);
        Ghost(SDL_Rect rect);
        Ghost(Personnage per);
        Ghost(string nom);
        ~Ghost();

    private:
};

Ghost::Ghost(): Personnage()
{
}

Ghost::Ghost(SDL_Rect rect): Personnage(rect)
{
}

Ghost::Ghost(Ghost const& gho): Personnage(gho)
{
}

Ghost::Ghost(Personnage per): Personnage(per)
{  
}

Ghost::Ghost(string nom): Personnage(nom)
{
}


Ghost::~Ghost()
{
}

#endif // GHOST_H //