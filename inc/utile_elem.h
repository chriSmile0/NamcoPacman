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


Utile_elem::Utile_elem() 
{
	cout << "utile_elem" << endl;
    x = 1;
    y = 1;
    w = 1;
    h = 1;
    SDL_Rect rec{x,y,w,h};
    elem = &(rec);
}

Utile_elem::Utile_elem(SDL_Rect rect) 
{
    elem = &rect;
    x = rect.x;
    y = rect.y;
    w = rect.w;
    h = rect.h;
}

Utile_elem::Utile_elem(int xe, int ye, int we , int he)
{
    x = xe;
	y = ye;
	w = we;
	h = he;
	SDL_Rect rec{x,y,w,h};
    elem = &(rec);
}

Utile_elem::Utile_elem(Utile_elem const& copy)
{
	elem = copy.elem;
	x = copy.x;
	y = copy.y;
	w = copy.w;
	h = copy.h;
}

SDL_Rect* Utile_elem::set_rect(SDL_Rect *rect)
{
    rect->x = (x);
    rect->y = (y);
    rect->w = (w);
    rect->h = (h);
    return rect;
}

Utile_elem::~Utile_elem()
{
}

//Ajout possible de getters comme l'aire, le périmètre etc..

#endif // UTILE_ELEM_H //