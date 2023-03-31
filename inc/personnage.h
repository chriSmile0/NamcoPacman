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
		//Constructors
		Personnage();
		Personnage(SDL_Rect* rect, int idx, char name);
		Personnage(int x,int y, int w, int h) : Utile_elem(x,y,w,h) {}
		~Personnage();

		//Inline setters
		inline void set_nom(char name) {nom_perso = name;}
		inline void set_id(int idx) {id = idx;}
		inline void set_statut(int new_stat) {statut = new_stat;}
		inline void set_sens(char n_sens) {sens = n_sens;}
		inline void set_out(int o) {out = o;}
		inline void set_time_house(int time) {time_house = time;}

		//Setters
		void set_start();
		void change_pos(int x, int y);
		void change_size(int w,int h);

		//Inline getters
		inline char get_nom() const {return nom_perso;}
		inline int get_id() const {return id;}
		inline int get_statut() const {return statut;}
		inline char get_sens() const {return sens;}
		inline int get_out() const {return out;}
		inline int get_time_house() const {return time_house;}

		//Get Skin
		SDL_Rect* get_Skin();

		//Ghost 
		void exit_ghost(int idx);
		inline void home_ghost(int idx) {set_start();}
};


#include "../src/personnage.hpp"

#endif // PERSONNAGE_H //