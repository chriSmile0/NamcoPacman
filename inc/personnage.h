#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "symboles.h"
#include <string>
#include <iostream>
using namespace std;

class Personnage: public Utile_elem {
	private:
		char nom_perso;
		int statut = -1;
		int id; //id pour id le perso plutôt que son nom //0=r/1=p/2=c/3=y/4=pac/
		char sens = 'd';
		int out = -1;
		int time_house = 0;
		SDL_Rect* Skin;
		
	public:
		Personnage();
		Personnage(SDL_Rect* rect, int idx, char name);
		Personnage(int x,int y, int w, int h) : Utile_elem(x,y,w,h) {}
		~Personnage();

		void set_nom(char name) {nom_perso = name;}
		void set_id(int idx) {id = idx;}
		void set_statut(int new_stat) {statut = new_stat;}
		void set_sens(char n_sens) {sens = n_sens;}
		void set_out(int o) {out = o;}
		void set_time_house(int time) {time_house = time;}

		char get_nom() {return nom_perso;}
		int get_id() {return id;}
		int get_statut() {return statut;}
		char get_sens() {return sens;}
		int get_out() {return out;}
		SDL_Rect* get_Skin();
		int get_time_house() {return time_house;}

		void set_start();
		void change_pos(int x, int y);
		void change_size(int w,int h);

		void exit_ghost(int idx);
		void home_ghost(int idx) {set_start();}
};


#include "../src/personnage.hpp"

#endif // PERSONNAGE_H //