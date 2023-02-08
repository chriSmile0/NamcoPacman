#ifndef BOARD_H
#define BOARD_H
#include "graine.h"
#include "recompense.h"
#include "symboles.h"
#include <iostream>
#include <vector>
using namespace std;

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
		void del_elem(int index);

		vector<Utile_elem> get_tab_elem() {return tab_elem;}
		Utile_elem get_elem_with_index(int index) {cout << "tab_elem::x " << (tab_elem.at(index)).get_x() << endl;return tab_elem[index];}

		void change_pos(int index, int new_x, int new_y);


	private:
		int type_board;
		SDL_Rect* gameboard;
		vector<Utile_elem> tab_elem;
		vector<Graine> tab_seed;
		vector<Recompense> tab_award;
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
	tab_elem.push_back(elem);

}

void Board::del_elem(int index)
{
	tab_elem.erase(tab_elem.begin() + index);
}

void Board::change_pos(int index_elem, int new_x, int new_y)
{
	Utile_elem recup_elem = tab_elem.at(index_elem);
	tab_elem[index_elem] = {new_x,new_y,recup_elem.get_w(),recup_elem.get_h()};
}


#endif // BOARD_H //