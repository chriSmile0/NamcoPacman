#include "../inc/utile_elem.h"

Utile_elem::Utile_elem() 
{
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

Utile_elem::Utile_elem(SDL_Rect* rect) 
{
    elem = rect;
    x = rect->x;
    y = rect->y;
    w = rect->w;
    h = rect->h;
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
