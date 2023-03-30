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
        Graine(SDL_Rect rect) : Utile_elem(rect) {}
        Graine(int x,int y,int w,int h, int type) : Utile_elem(x,y,w,h) {nb_pts = (type == 0) ? 10 : 40;}
        Graine(SDL_Rect rect, int type) : Utile_elem(rect) {nb_pts = (type == 0) ? 10 : 40;}
        ~Graine();

		void hideSeed() {this->set_h(0);}
        int get_val() {return nb_pts;}
        void set_val(int n_val) {nb_pts = n_val;}
};

#include "../src/graine.hpp"

#endif // GRAINE_H //