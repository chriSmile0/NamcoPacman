#include "../inc/symboles.h"
#include "../inc/board.h"


Board::Board()
{
	type_board = 1;
	set_type_in_rectboard(type_board);
	vid = &vide;
}

Board::Board(int t_board) 
{
	type_board = t_board;
	set_type_in_rectboard(type_board);
	vid = &vide;
}

Board::Board(Board const& copy)
{
	type_board = copy.type_board;
	set_type_in_rectboard(type_board);
	vid = &vide;
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
		if(!goon) 
			gum_catch++;
		i++;
	}
	if(!goon) {
		gums[i-1].set_h(0);
		active_gums--;
		if((gum_catch == 70) || (gum_catch == 170)) 
			set_awards_with_index(awards.size()-1,'w',awards[awards.size()-1].get_Skin().w);
		if(active_gums == 0) {
			for(int i = 0 ; i < 192;i++)
				gums[i].showSeed();
		}
		return (i-1);
	}
	else {
		return -1;
	}
}

int Board::catch_award(int old_x, int old_y ,int new_x, int new_y)
{
	int x_m_nx = new_x - old_x;
	int y_m_ny = new_y - old_y;
	char sens = ((x_m_nx != 0) ? ((x_m_nx < 0) ? 'g': 'd') : ((y_m_ny < 0) ? 'h': 'b'));
	Recompense p = get_recompense_with_index(get_awards().size()-1);
	if(p.get_w() > 0) {
			int goon = 1;
			int y_award = award_place.y;
			int x_award = award_place.x;
			int w_award = award_place.w;
			int h_award = award_place.h;
			switch(sens) { // La pour le moment sa le fera dès le premier mur 
				case 'g':  if((((old_x > x_award) && (new_x <= (x_award)))) && ((new_y > (y_award-(h_award))) && (new_y < (y_award + (h_award))))) 
							goon = 0;
						break;
				case 'd': if((new_y > (y_award-(h_award))) && (new_y < (y_award + (h_award))))
							goon = 0;
						break;
				default:
					break;
			}
			if(!goon) {
				int index = get_awards().size()-1;
				set_awards_with_index(index,'w',0);
				return index;
			}
	}
	return -1;
		
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

void Board::set_awards_with_index(int idx,char carac, int n_c)
{
	switch(carac) {
		case 'x' : awards[idx].set_x(n_c);
		case 'y' : awards[idx].set_y(n_c);
		case 'w' : awards[idx].set_w(n_c);
			if(n_c > 0)
				awards[idx].setViewTime();//60 = 1 secondes
		case 'h' : awards[idx].set_h(n_c);
	}
}

//Setup des niveaux
void Board::add_award_in_list(int niveau)
{
	switch(niveau) {
		case 1 : awards.push_back(Recompense{cherry_r,Cerise,6});
			break;
		case 2 : awards.push_back(Recompense{strawberry_r,Fraise,5});
			break;
		case 3 : awards.push_back(Recompense{orange_o,Orange,4});
			break;
		case 4 : awards.push_back(Recompense{orange_o,Orange,3});
			break;
		case 5 : awards.push_back(Recompense{apple_r,Pomme,2});
			break;
		case 6 : awards.push_back(Recompense{apple_r,Pomme,5});
			break;
		case 7 : awards.push_back(Recompense{melon_g,Melon,2});
			break;
		case 8 : awards.push_back(Recompense{melon_g,Melon,2});
			break;
		case 9 : awards.push_back(Recompense{galboss_r,Galboss,1});
			break;
		case 10 : awards.push_back(Recompense{galboss_r,Galboss,5});
			break;
		case 11 : awards.push_back(Recompense{bell_o,Cloche,2});
			break;
		case 12 : awards.push_back(Recompense{bell_o,Cloche,1});
			break;
		default: awards.push_back(Recompense{key_r,Cle,1});
			// 13 ou + 
			break;
	}
}