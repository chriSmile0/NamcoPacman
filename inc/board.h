#ifndef BOARD_H
#define BOARD_H
#include "utile_elem.h"
#include "map.h"
#include "graine.h"
#include "ghost.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareGums(Graine sr1, Graine sr2)
{
	return ((sr1.get_x() <= sr2.get_x()) && (sr1.get_y() <= sr2.get_y()));
}

class Board 
{
	public:
		//Constructors
		Board();
		Board(int type_board);
		Board(Board const& copy);
		~Board();

		//Inline setters
		inline void set_typeboard(int type_b) {type_board = type_b;}
		inline void set_gameboard(SDL_Rect gameb) {gameboard = &gameb;}
		inline void set_perso_with_statut_idx(int idx,int statut) {perso[idx].set_statut(statut);}
		inline void set_perso_with_sens_idx(int idx,int sens) {perso[idx].set_sens(sens);}
		inline void set_perso_with_timehouse_idx(int idx,int time_h) {perso[idx].set_time_house(time_h);}
		inline void set_pos_perso(int index, int new_x, int new_y) {perso.at(index).change_pos(new_x,new_y);}
		//Setters
		void set_type_in_rectboard(int type_b);
		void set_perso_with_index(int idx,char carac, int n_c);
		void set_startGhost(int i);

		//Inline getters
		inline int get_typeboard() const {return type_board;}
		inline SDL_Rect* get_gameboard() const {return gameboard;}
		inline void add_perso(Personnage pers) const {perso.push_back(pers);}
		inline void add_gum(Graine gum) const {gums.push_back(gum);}
		inline vector<Personnage> get_tab_perso() const {return perso;}
		inline Personnage get_perso_with_index(int index) const {return perso[index];}
		inline Map getMap() const {return map;}
		inline vector<Graine> get_gums() const {return gums;}
		inline Graine getGum_with_index(int i) const {return (gums[i]);}
		//Getters
		int getGum_with_x_y(int x, int y) const ;
		SDL_Rect* getSkin(int idx, char sens, int statut);//dans l'ordre r/p/c/y/pacman

		//Others inline setters
		inline void exit_ghosts(int i) {perso[i].exit_ghost(i);}
		inline void home_ghosts(int i) {perso[i].home_ghost(i);}
		//Others
		void sort_gums_by_xy() {std::sort(gums.begin(),gums.end(),compareGums);}
		int catch_gum(int old_y, int old_x , int new_x, int new_y);
		
	private:
		int type_board;
		SDL_Rect* gameboard;
		Map map;
		vector<Personnage> perso; //PAcman + les fantomes
		vector<Graine> gums;//a changer car il y a 2 types de gums et donc il faut crée un objet(graine)
		vector<SDL_Rect*> awards;//a changer car il y a plusieurs types de awards et donc il faut crée un objet(recompense) 
};

#include "../src/board.hpp"

#endif // BOARD_H //