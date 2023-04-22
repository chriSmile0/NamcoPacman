#ifndef PACMAN_H
#define PACMAN_H

#include <string>
#include <iostream>
using namespace std;

class Pacman: public Personnage
{
	public:
		Pacman();
		Pacman(Pacman const& perso);
		Pacman(SDL_Rect* rect, int idx,char name) : Personnage(rect,idx,name) {}
		Pacman(Personnage const& perso) : Personnage(perso) {}
		~Pacman();
};

Pacman::Pacman(): Personnage()
{
}

Pacman::Pacman(Pacman const& perso): Personnage(perso)
{
}

Pacman::~Pacman()
{
}

#endif // PACMAN_H //