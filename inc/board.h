#ifndef BOARD_H
#define BOARD_H
#include "utile_elem.h"
#include "map.h"
#include "graine.h"
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
		Board();
		Board(int type_board);
		Board(Board const& copy);
		~Board();

		int get_typeboard();
		SDL_Rect* get_gameboard();
		void get_sizeofgameboard();

		void set_typeboard(int type_b);
		void set_gameboard(SDL_Rect gameb);
		void change_type_in_rectboard(int type_b);


		void add_elem(Utile_elem elem);
		void add_ghost(SDL_Rect ghost) {ghosts.push_back(&ghost);}
		void add_gum(Graine gum) {gums.push_back(gum);}
		void set_Pacman(SDL_Rect pac) {pacman = &(pac);}
		void del_elem(int index);

		void set_startGhost(int i);

		vector<Utile_elem> get_tab_elem() {return elems;}
		Utile_elem get_elem_with_index(int index) {return elems[index];}
		Map getMap() {return map;}
		vector<Graine> get_gums() {return gums;}
		vector<SDL_Rect*> get_Ghosts() {return ghosts;}

		void change_pos(int index, int new_x, int new_y);
		void change_size(int index, int new_w, int new_h);

		SDL_Rect* getGhost_with_index(int i) {return (ghosts[i]);}
		Graine getGum_with_index(int i) {return (gums[i]);}
		int getGum_with_x_y(int x, int y);
		SDL_Rect* getPacman() {return pacman;}
		SDL_Rect* getSkin(int idx, char sens, int statut);//dans l'ordre r/p/c/y/pacman

		int catch_gum(int old_y, int old_x , int new_x, int new_y);

		void sort_gums_by_xy();

	private:
		int type_board;
		SDL_Rect* gameboard;
		Map map;
		vector<Utile_elem> elems; //Voir pour suppr
		vector<Graine> gums;//a changer car il y a 2 types de gums et donc il faut crée un objet(graine)
		vector<SDL_Rect*> awards;//a changer car il y a plusieurs types de awards et donc il faut crée un objet(recompense) 
		vector<SDL_Rect*> ghosts;
		SDL_Rect* pacman;
};

#include "../src/board.hpp"

#endif // BOARD_H //