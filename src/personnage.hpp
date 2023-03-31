#include "../inc/personnage.h"

Personnage::Personnage(): Utile_elem()
{
	nom_perso = ';';
}
Personnage::Personnage(SDL_Rect* rect, int idx, char name): Utile_elem(rect)
{
	id = idx;
	nom_perso = name;
	statut = -1;
}



SDL_Rect* Personnage::get_Skin() 
{//0 = bas , 1 = haut, 2 = gauche, 3 = droit , s = sens_appuyer (que pour pacman)
	if((statut == 1) && (id != 4))
		return &(ghost_b1);
	if((statut == 2) && (id != 4))
		return &(ghost_w1);
	switch(id) {
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

void Personnage::set_start()
{
	int x,y;
	out = -1;
	statut = -1;
	switch(id) {
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
				x = pacman_start.x;
				y = pacman_start.y;
			break;
	}
	cout << "retour au départ" << endl;
	time_house = 0;
	change_pos(x,y);
	change_size(32,32);
}

void Personnage::change_pos(int x, int y)
{
	set_x(x);
	set_y(y);
}

void Personnage::change_size(int w, int h)
{
	set_w(w);
	set_h(h);
}

void Personnage::exit_ghost(int idx) { // r,p,c,y
	SDL_Rect* ghost_choice = nullptr;
	if(idx == get_id()) {
		out = 1;
		switch (idx) {
			case 0: ghost_choice = &(ghost_rr1);
				break;
			case 1: ghost_choice = &(ghost_pr1);
				break;
			case 2: ghost_choice = &(ghost_cr1);
				break;
			case 3: ghost_choice = &(ghost_yr1);
				break;
		}
		change_pos(ghost_free.x,ghost_free.y);
	}
}

Personnage::~Personnage()
{
}