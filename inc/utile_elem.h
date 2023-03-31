#ifndef UTILE_ELEM_H
#define UTILE_ELEM_H
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

//Possibilité de la passer en template si autre chose que des Rect
class Utile_elem 
{
	private:
		SDL_Rect* elem = nullptr;
		int x = 0;
		int y = 0;
		int w = 0;
		int h = 0;

	public:
		Utile_elem();
		Utile_elem(SDL_Rect rect);
		Utile_elem(SDL_Rect* rect);
		Utile_elem(int xe, int ye, int we , int he);
		Utile_elem(Utile_elem const& copy);
		~Utile_elem();
		int get_x() {return x;}
		int get_y() {return y;}
		int get_w() {return w;}
		int get_h() {return h;}
		SDL_Rect* get_ptr_elem() {return elem;}
		SDL_Rect get_val_elem() {SDL_Rect retour{x,y,w,h};return retour;}

		int get_rect_x() {SDL_Rect sdl{x,y,w,h}; return sdl.x;}
		int set_x(int nx) {x = nx; elem->x = (nx);}
		int set_y(int ny) {y = ny; elem->y = (ny);}
		int set_w(int nw) {w = nw; elem->w = (nw);}
		int set_h(int nh) {h = nh; elem->h = (nh);}

		SDL_Rect* set_rect(SDL_Rect *rect);
};

//Ajout possible de getters comme l'aire, le périmètre etc..
#include "../src/utile_elem.hpp"

#endif // UTILE_ELEM_H //