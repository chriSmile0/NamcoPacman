#include "../inc/symboles.h"
#include "../inc/board.h"

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
	cout << "x : " << gums.at(0).get_x() << " y : " << gums.at(0).get_y() << endl;
	cout << "x : " << gums.at(192).get_x() << " y : " << gums.at(192).get_y() << endl;
	std::sort(gums.begin(),gums.end(),compareGums);
	cout << "x : " << gums.at(0).get_x() << " y : " << gums.at(0).get_y() << endl;
	cout << "x : " << gums.at(192).get_x() << " y : " << gums.at(192).get_y() << endl;
	gums[0].set_h(0);
	gums[192].set_h(0);
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
	Graine gum;
	while((goon) && (i < nb_gums)) {
		gum = gums.at(i);
		if((gum.get_x() == x) && (gum.get_y() == y))
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
		Graine gum = gums.at(i);
		int h_gum = gum.get_h();
		int x_gum = gum.get_x();
		int y_gum = gum.get_y();
		int w_gum = gum.get_w();
		if(h_gum > 0) {
			switch(sens) { // La pour le moment sa le fera dès le premier mur 
				case 'h': //y -= dim_perso; 
						if((((old_y > y_gum) && (new_y <= (y_gum)))) && ((new_x > (x_gum-(w_gum*3))) && (new_x < (x_gum + (w_gum*2)))))
							goon = 0;
						break;
				case 'b': //gum.y -= dim_perso;
						if((((old_y < y_gum) && (new_y >= (y_gum)))) && (((new_x > (x_gum-(w_gum*3)) && (new_x < (x_gum + (w_gum)))))))
							goon = 0;
						break;
				case 'g': //x += dim_perso; 
						if(((old_x > x_gum) && (new_x <= (x_gum))) && (((new_y > (y_gum-(h_gum*3))) && (new_y < (y_gum + (h_gum*2)))))) 
							goon = 0;
						break;
				case 'd': //gum.x -= dim_perso; 
						if(((old_x < x_gum) && (new_x >= (x_gum))) && (((new_y > (y_gum-(h_gum*3))) && (new_y < (y_gum + (h_gum*2)))))) 
							goon = 0;
						break;
				default:
					break;
			}
		}
		if(goon == 0) {
			cout << "gum carac : x: " << x_gum  <<", y: " << y_gum << ", h: " << h_gum << ",w: " << w_gum << endl;
			cout << " old x : " << old_x << ", new x:" << new_x <<  " old y : " << old_y << ", new y:" << new_y << endl;
		}
		i++;
	}
	if(goon == 0) {
		gums[i-1].set_h(0);
		return (i-1);
	}
	else {
		return -1;
	}
}


void Board::change_pos(int index, int new_x, int new_y)
{
	Utile_elem recup_elem = elems.at(index);
	elems[index] = {new_x,new_y,recup_elem.get_w(),recup_elem.get_h()};
}

void Board::change_size(int index_elem, int new_w , int new_h)
{
	Utile_elem recup_elem = elems.at(index_elem);
	elems[index_elem] = {recup_elem.get_x(),recup_elem.get_y(),new_w,new_h};
}
