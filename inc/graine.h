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
		//Constructors
		Graine();
		Graine(SDL_Rect rect) : Utile_elem(rect) {}
		Graine(int x,int y,int w,int h, int type) : Utile_elem(x,y,w,h) {nb_pts = (type == 0) ? 10 : 40;}
		Graine(SDL_Rect rect, int type) : Utile_elem(rect) {nb_pts = (type == 0) ? 10 : 40;}
		~Graine();

		//Hide 
		inline void hideSeed() {this->set_h(0);}
		//Getter
		inline int get_val() const {return nb_pts;}
		//Setter
		inline void set_val(int n_val) {nb_pts = n_val;}

		inline void showSeed();
};

#include "../src/graine.hpp"

#endif // GRAINE_H //