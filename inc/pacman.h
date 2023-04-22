#ifndef PACMAN_H
#define PACMAN_H

#include <string>
#include <iostream>
using namespace std;

class Pacman: public Personnage
{
	private:
		int life = 3;
	
	public:
		Pacman();
		Pacman(Pacman const& perso);
		Pacman(SDL_Rect* rect, int idx,char name) : Personnage(rect,idx,name) {}
		Pacman(Personnage const& perso) : Personnage(perso) {}
		~Pacman();

		inline void setLife(int l) {life = l;}
		inline void loseLife() {life = (life>0) ? life-- : 0;}
		inline void winLife() {life = (life > 3) ? 3 : life++;}
		inline int getLife() const {return life;}
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