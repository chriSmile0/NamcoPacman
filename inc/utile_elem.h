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
		//Constructors 
		Utile_elem();
		Utile_elem(SDL_Rect rect);
		Utile_elem(SDL_Rect* rect);
		Utile_elem(int xe, int ye, int we , int he);
		Utile_elem(Utile_elem const& copy);
		~Utile_elem();

		//Inline setters 
		inline int set_x(int nx) {x = nx; elem->x = (nx);}
		inline int set_y(int ny) {y = ny; elem->y = (ny);}
		inline int set_w(int nw) {w = nw; elem->w = (nw);}
		inline int set_h(int nh) {h = nh; elem->h = (nh);}

		//Setter
		SDL_Rect* set_rect(SDL_Rect *rect);

		//Inline getters
		inline int get_x() const {return x;}
		inline int get_y() const {return y;}
		inline int get_w() const {return w;}
		inline int get_h() const {return h;}
		inline SDL_Rect* get_ptr_elem() const {return elem;}
		inline SDL_Rect get_val_elem() const {SDL_Rect retour{x,y,w,h};return retour;}
		inline int get_rect_x() const {SDL_Rect sdl{x,y,w,h}; return sdl.x;}
};

//Ajout possible de getters comme l'aire, le périmètre etc..
#include "../src/utile_elem.hpp"

#endif // UTILE_ELEM_H //