#ifndef BOARD_H
#define BOARD_H
#include "utile_elem.h"
#include "map.h"
#include "graine.h"
#include "ghost.h"
#include "pacman.h"
#include "recompense.h"
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
	private:
		int type_board;
		SDL_Rect* gameboard;
		Map map;
		int gum_catch = 0;
		vector<Personnage> perso; //PAcman + les fantomes
		vector<Graine> gums;//a changer car il y a 2 types de gums et donc il faut crée un objet(graine)
		vector<Recompense> awards;//a changer car il y a plusieurs types de awards et donc il faut crée un objet(recompense)
		
	public:
		//Constructors
		Board();
		Board(int type_board);
		Board(Board const& copy);
		~Board();

		//Inline setters
		inline void set_gum_catch(int nb_gc) {gum_catch = nb_gc;}
		inline void set_typeboard(int type_b) {type_board = type_b;}
		inline void set_gameboard(SDL_Rect gameb) {gameboard = &gameb;}
		inline void set_perso_with_statut_idx(int idx,int statut) {perso[idx].set_statut(statut);}
		inline void set_perso_with_sens_idx(int idx,int sens) {perso[idx].set_sens(sens);}
		inline void set_perso_with_timehouse_idx(int idx,int time_h) {perso[idx].set_time_house(time_h);}
		inline void set_pos_perso(int index, int new_x, int new_y) {perso.at(index).change_pos(new_x,new_y);}
		inline void add_perso(Personnage pers) {perso.push_back(pers);}
		inline void add_gum(Graine gum) {gums.push_back(gum);}
		inline void add_awards(Recompense recp) {awards.push_back(recp);}
		
		//Setters
		void set_type_in_rectboard(int type_b);
		void set_perso_with_index(int idx,char carac, int n_c);
		void set_awards_with_index(int idx,char carac, int n_c);
		void set_startGhost(int i);

		//Inline getters
		inline int get_gum_catch() const {return gum_catch;}
		inline int get_typeboard() const {return type_board;}
		inline SDL_Rect* get_gameboard() const {return gameboard;}
		inline vector<Personnage> get_tab_perso() const {return perso;}
		inline Personnage get_perso_with_index(int index) const {return perso[index];}
		inline Recompense get_recompense_with_index(int index) const {return awards[index];}
		inline Map getMap() const {return map;}
		inline vector<Graine> get_gums() const {return gums;}
		inline vector<Recompense> get_awards() const {return awards;}
		inline Graine getGum_with_index(int i) const {return (gums[i]);}
		//Getters
		/** @brief	Renvoie la Gum qui se trouve aux coordonnées x,y
		 * @param{x,y} : {/,/}
		 * @return -1 si plus visible sur le terrain, son index sinon 
		*/
		int getGum_with_x_y(int x, int y) const ;

		//Others inline setters
		inline void exit_ghosts(int i) {perso[i].exit_ghost(i);}
		inline void home_ghosts(int i) {perso[i].home_ghost(i);}
		//Others
		/** @brief	Trie des gums en fonction de leur place sur le plateau
		 * @param{none}  
		 * @return{none}
		*/
		void sort_gums_by_xy() {std::sort(gums.begin(),gums.end(),compareGums);}
		/** @brief	Permet de collecter une gum (h_gum à 0) qu'elle soit spéciale 
		 * 			ou non
		 * @param{old_y,old_x,new_x,new_y} : {/,/,/,/}  
		 * @return son index ou -1 si elle a déjà était catch
		*/
		int catch_gum(int old_y, int old_x , int new_x, int new_y);
		/**
		 * 
		*/
		int catch_award(int old_y, int old_x, int new_x, int new_y);
};

#include "../src/board.hpp"

#endif // BOARD_H //