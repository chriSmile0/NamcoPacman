#ifndef BOARD_H
#define BOARD_H
#include "graine.h"
#include "recompense.h"
#include "symboles.h"
#include "map.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareRect(SDL_Rect sr1, SDL_Rect sr2)
{
    return ((sr1.x <= sr2.x) && (sr1.y <= sr2.y));
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
		void add_gum(SDL_Rect gum) {gums.push_back(gum);}
		void set_Pacman(SDL_Rect pac) {pacman = &(pac);}
		void del_elem(int index);

		vector<Utile_elem> get_tab_elem() {return elems;}
		Utile_elem get_elem_with_index(int index) {return elems[index];}
		Map getMap() {return map;}
		vector<SDL_Rect> get_gums() {return gums;}
		vector<SDL_Rect*> get_Ghosts() {return ghosts;}

		void change_pos(int index, int new_x, int new_y);
		void change_size(int index, int new_w, int new_h);

		SDL_Rect* getGhost_with_index(int i) {return (ghosts[i]);}
		SDL_Rect getGum_with_index(int i) {return (gums[i]);}
		int getGum_with_x_y(int x, int y);
		SDL_Rect* getPacman() {return pacman;}
		SDL_Rect* getSkin(int idx, char sens);//dans l'ordre r/p/c/y/pacman

		int catch_gum(int old_y, int old_x , int new_x, int new_y);

		void sort_gums_by_xy();

	private:
		int type_board;
		SDL_Rect* gameboard;
		Map map;
		vector<Utile_elem> elems; //Voir pour suppr
		vector<SDL_Rect> gums;//a changer car il y a 2 types de gums et donc il faut crée un objet(graine)
		vector<SDL_Rect*> awards;//a changer car il y a plusieurs types de awards et donc il faut crée un objet(recompense) 
		vector<SDL_Rect*> ghosts;
		SDL_Rect* pacman;
};

Board::Board()
{
	type_board = 1;
	change_type_in_rectboard(type_board);
}

Board::Board(int t_board) 
{
	type_board = t_board;
	change_type_in_rectboard(type_board);
}

Board::Board(Board const& copy)
{
	type_board = copy.type_board;
	change_type_in_rectboard(type_board);
}

Board::~Board() 
{

}

int Board::get_typeboard() 
{
	return type_board;
}

void Board::set_typeboard(int t_board)
{
	type_board = t_board;
}

SDL_Rect* Board::get_gameboard() 
{
	return gameboard;
}

void Board::set_gameboard(SDL_Rect gameb)
{
	gameboard = &gameb;
}

void Board::change_type_in_rectboard(int type_b) 
{
	switch(type_b) {
		case 2 : 
			gameboard = &src_b2;
			break;
		case 3 :
			gameboard = &src_b3;
			break;
		default:
			gameboard = &src_b1;
			break;
	}
}

void Board::get_sizeofgameboard() 
{
	Utile_elem ue(*gameboard);
	cout << "Board dimension :";
	cout << " x:" << ue.get_x() << " y:" << ue.get_y();
	cout << " w:" << ue.get_w() << " h:" << ue.get_h() << endl;
}

void Board::add_elem(Utile_elem elem)
{
	cout << "pos elem : " << elem.get_x() << endl;
	elems.push_back(elem);
}

SDL_Rect* Board::getSkin(int idx, char sens)//0 = bas , 1 = haut, 2 = gauche, 3 = droit , s = sens_appuyer (que pour pacman)
{
	switch(idx) {
		case 0: 
			switch(sens) {
				case 'b': return &(ghost_rd1); 
				case 'h': return &(ghost_ru1);
				case 'g': return &(ghost_rl1);
				case 'd': return &(ghost_rr1);
			}
		case 1: 
			switch(sens) {
				case 'b': return &(ghost_pd1); 
				case 'h': return &(ghost_pu1);
				case 'g': return &(ghost_pl1);
				case 'd': return &(ghost_pr1);
			}
		case 2:
			switch(sens) {
				case 'b': return &(ghost_cd1); 
				case 'h': return &(ghost_cu1);
				case 'g': return &(ghost_cl1);
				case 'd': return &(ghost_cr1);
			}
		case 3: 
			switch(sens) {
				case 'b': return &(ghost_yd1); 
				case 'h': return &(ghost_yu1);
				case 'g': return &(ghost_yl1);
				case 'd': return &(ghost_yr1);
			}
		default:
			switch(sens) {
				case 'b': return &(lpacman_cod); 
				case 'h': return &(lpacman_cou);
				case 'g': return &(lpacman_col);
				case 'd': return &(lpacman_cor);
			}
	}
}

void Board::sort_gums_by_xy()
{
	cout << "x : " << gums.at(0).x << " y : " << gums.at(0).y << endl;
	cout << "x : " << gums.at(192).x << " y : " << gums.at(192).y << endl;
	std::sort(gums.begin(),gums.end(),compareRect);
	cout << "x : " << gums.at(0).x << " y : " << gums.at(0).y << endl;
	cout << "x : " << gums.at(192).x << " y : " << gums.at(192).y << endl;
	gums[0].h = 0;
	gums[192].h = 0;
}

void Board::del_elem(int index)
{
	elems.erase(elems.begin() + index);
}

int Board::getGum_with_x_y(int x, int y)
{
	int nb_gums = gums.size();
	int goon = 1;
	int i = 0;
	SDL_Rect gum;
	while((goon) && (i < nb_gums)) {
		gum = gums.at(i);
		if((gum.x == x) && (gum.y == y))
			goon = 0;
		i++;
	}
	if(goon == 0) 
		i-1;
	return -1;
}

int Board::catch_gum(int old_x, int old_y ,int new_x, int new_y)
{	//On pourrais rejoindre hit wall et catch_gum en une seule et même fonction
	//pour optimiser

	int x_m_nx = new_x - old_x;
	int y_m_ny = new_y - old_y;
	char sens = ((x_m_nx != 0) ? ((x_m_nx < 0) ? 'g': 'd') : ((y_m_ny < 0) ? 'h': 'b'));
	//Ici on fait pour le moment la recherche dans toutes les gums mais on peut
	//créer des recherches en fonction des différentes sections que l'on aura décidé
	int nb_gums = gums.size();
	int dim_perso = 32;
	int goon = 1;
	int i = 0;
	while((goon) && (i < nb_gums)) {
		SDL_Rect gum = gums.at(i);
		int hauteur_gum = gum.h;
		int largeur_gum = gum.w;
		if(hauteur_gum > 0) {
			switch(sens) { // La pour le moment sa le fera dès le premier mur 
				case 'h': //y -= dim_perso; 
						if((((old_y > gum.y) && (new_y <= (gum.y)))) && ((new_x > (gum.x-(largeur_gum*3))) && (new_x < (gum.x + (largeur_gum*2)))))
							goon = 0;
						break;
				case 'b': //gum.y -= dim_perso;
						if((((old_y < gum.y) && (new_y >= (gum.y)))) && (((new_x > (gum.x-(largeur_gum*3)) && (new_x < (gum.x + (largeur_gum)))))))
							goon = 0;
						break;
				case 'g': //x += dim_perso; 
						if(((old_x > gum.x) && (new_x <= (gum.x))) && (((new_y > (gum.y-(hauteur_gum*3))) && (new_y < (gum.y + (hauteur_gum*2)))))) 
							goon = 0;
						break;
				case 'd': //gum.x -= dim_perso; 
						if(((old_x < gum.x) && (new_x >= (gum.x))) && (((new_y > (gum.y-(hauteur_gum*3))) && (new_y < (gum.y + (hauteur_gum*2)))))) 
							goon = 0;
						break;
				default:
					break;
			}
		}
		if(goon == 0) {
			cout << "gum carac : x: " << gum.x  <<", y: " << gum.y << ", h: " << hauteur_gum << ",w: " << largeur_gum << endl;
			cout << " old x : " << old_x << ", new x:" << new_x <<  " old y : " << old_y << ", new y:" << new_y << endl;
		}
		i++;
	}
	if(goon == 0) {
		gums[i-1].h = 0;
		return (i-1);
	}
	else {
		return -1;
	}
}


void Board::change_pos(int index_elem, int new_x, int new_y)
{
	Utile_elem recup_elem = elems.at(index_elem);
	elems[index_elem] = {new_x,new_y,recup_elem.get_w(),recup_elem.get_h()};
}

void Board::change_size(int index_elem, int new_w , int new_h)
{
	Utile_elem recup_elem = elems.at(index_elem);
	elems[index_elem] = {recup_elem.get_x(),recup_elem.get_y(),new_w,new_h};
}

#endif // BOARD_H //