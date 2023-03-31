#ifndef GHOST_H
#define GHOST_H
#include "symboles.h"
#include "personnage.h"
#include <string>
#include <iostream>
using namespace std;

class Ghost: public Personnage {
    public:
        Ghost();
        Ghost(Ghost const& perso);
        Ghost(SDL_Rect* rect, int id, char nom);
        Ghost(Personnage per);
        Ghost(char nom);
        ~Ghost();

        

    private:
        int out;
};

Ghost::Ghost(): Personnage()
{

}

Ghost::Ghost(SDL_Rect* rect, int id, char nom): Personnage(rect,id,nom)
{

}

Ghost::Ghost(Ghost const& gho): Personnage(gho)
{

}

Ghost::Ghost(Personnage per): Personnage(per)
{  

}
/*
Ghost::Ghost(char nom): Personnage(nom)
{

}*/



Ghost::~Ghost()
{
}

#endif // GHOST_H //