#ifndef GRAINE_H
#define GRAINE_H

#include <string>
#include "utile_elem.h"
using namespace std;

class Graine: public Utile_elem
{
    private:
        int nb_pts = 10; //type = nombre de pts
                    //petite = 10 pts, grande(spéciale) = 50 pts

    public:
        Graine();
        Graine(int nb_points);
        Graine(Graine const& copy);
        Graine(SDL_Rect rect);
        ~Graine();

		void hideSeed();
};

Graine::Graine(): Utile_elem()
{

}

Graine::Graine(int nb_points): Utile_elem()
{
	nb_pts = nb_points;
}

Graine::Graine(Graine const& copy): Utile_elem()
{
	nb_pts = copy.nb_pts;
}

Graine::Graine(SDL_Rect rect): Utile_elem(rect)
{

}

void Graine::hideSeed()
{
    this->set_h(0);
    this->set_w(0);
}

Graine::~Graine()
{
}


#endif // GRAINE_H //