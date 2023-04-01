#include "../inc/symboles.h"
#include "../inc/board.h"


Board::Board()
{
	type_board = 1;
	set_type_in_rectboard(type_board);
}

Board::Board(int t_board) 
{
	type_board = t_board;
	set_type_in_rectboard(type_board);
}

Board::Board(Board const& copy)
{
	type_board = copy.type_board;
	set_type_in_rectboard(type_board);
}

Board::~Board() 
{

}


void Board::set_type_in_rectboard(int type_b) 
{
	switch(type_b) {
		case 2 : gameboard = &src_b2;
			break;
		case 3 : gameboard = &src_b3;
			break;
		default: gameboard = &src_b1;
			break;
	}
}


void Board::set_startGhost(int i)
{
	int x,y;
	switch(i) {
		case 0: x = ghost_rstart.x;
				y = ghost_rstart.y;
			break;
		case 1: x = ghost_pstart.x;
				y = ghost_pstart.y;
			break;
		case 2: x = ghost_cstart.x;
				y = ghost_cstart.y;
			break;
		case 3:	x = ghost_ystart.x;
				y = ghost_ystart.y;
			break;
		default:
			break;
	}
	set_pos_perso(i,x,y);
}

int Board::getGum_with_x_y(int x, int y) const
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
	if(!goon) 
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
		Graine gum{gums.at(i)};
		int h_gum = gum.get_h();
		int x_gum = gum.get_x();
		int y_gum = gum.get_y();
		int w_gum = gum.get_w();
		if(h_gum > 0) {
			switch(sens) { // La pour le moment sa le fera dès le premier mur 
				case 'h': if((((old_y > y_gum) && (new_y <= (y_gum)))) && ((new_x > (x_gum-(w_gum*4))) && (new_x < (x_gum + (w_gum)))))
							goon = 0;
						break;
				case 'b': y_gum -= dim_perso;
						if((((old_y < y_gum) && (new_y >= (y_gum)))) && ((new_x > (x_gum-(w_gum*4))) && (new_x < (x_gum + (w_gum)))))
							goon = 0;
						break;
				case 'g':  if((((old_x > x_gum) && (new_x <= (x_gum)))) && ((new_y > (y_gum-(h_gum*4))) && (new_y < (y_gum + (h_gum))))) 
							goon = 0;
						break;
				case 'd': x_gum -= dim_perso; 
						if((((old_x < x_gum) && (new_x >= (x_gum)))) && ((new_y > (y_gum-(h_gum*4))) && (new_y < (y_gum + (h_gum))))) 
							goon = 0;
						break;
				default:
					break;
			}
		}
		if(!goon) {
			cout << "gum carac : x: " << x_gum  <<", y: " << y_gum << ", h: " << h_gum << ",w: " << w_gum << endl;
			cout << " old x : " << old_x << ", new x:" << new_x <<  " old y : " << old_y << ", new y:" << new_y << endl;
		}
		i++;
	}
	if(!goon) {
		gums[i-1].set_h(0);
		return (i-1);
	}
	else {
		return -1;
	}
}

void Board::set_perso_with_index(int idx,char carac, int n_c)
{
	switch(carac) {
		case 'x' : perso[idx].set_x(n_c);
		case 'y' : perso[idx].set_y(n_c);
		case 'w' : perso[idx].set_w(n_c);
		case 'h' : perso[idx].set_h(n_c);
	}
}