#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <random>

class Game 
{
    private:
        int nb_pts;
        int level;
        string player_name;
        Board *boar;
		SDL_Window* win;
		SDL_Surface* win_surface;
		SDL_Surface* sprites_planches;
		
    public:
        Game();
        Game(string name, Board* b);
		Game(string name, Board* b, SDL_Window* w, SDL_Surface* s, SDL_Surface* pl);
        ~Game();


        void set_pts(int nb_p) {nb_pts = nb_p;}
        void set_level(int l) {level = l;}
        int get_pts() {return nb_pts;}
        int get_level() {return level;}


        Board* get_board() {return boar;}
        SDL_Surface* get_planche() {return sprites_planches;}
        SDL_Surface* get_win_surf() {return win_surface;}
        SDL_Window* get_window() {return win;}

        void set_name(string name) {player_name = name;}
        string get_name() {return player_name;}

		void drawGums();
		void drawGhostsAPac(char sens[5]);

		void exit_ghost(char ghost_name);

        int moveGhost(int x_pac, int y_pac, char &sens, int index);
        int updateRedGhost(int x_pac, int y_pac, char &sens);
        int updatePinkGhost(int x_pac, int y_pac, char &sens);
        int updateCyanGhost(int x_pac, int y_pac, char &sens);
        int updateYellowGhost(int x_pac, int y_pac, char &sens);
        int updateGhosts(int x_pac, int y_pac, char sens[5], int out_ghost);
        void updatePacman(int x_pac, int y_pac, char &sens, char s);

        char sens_of_walk(int x_old,int y_old, int x, int y,char base_sens, int g_or_p);

        int catchPacman(int x_ghost, int y_ghost, int x_pac, int y_pac, char &sens);

};

Game::Game()
{
    player_name = "no_name";
}

Game::Game(string name , Board* b)
{
    player_name = name;
    boar = b;

}

Game::Game(string name, Board* b, SDL_Window* w, SDL_Surface* s, SDL_Surface* pl) 
{
	player_name = name;
	boar = b;
	win = w;
	win_surface = s;
	sprites_planches = pl;
}


int Game::moveGhost(int x_pac, int y_pac, char &sens, int index)
{
    int g_x = boar->get_elem_with_index(index).get_x();
    int g_y = boar->get_elem_with_index(index).get_y();
    int distance = 6;//distance de déplacement des fantomes

    int new_x = g_x;//à changer en fonction de la position de pacman
    int new_y = g_y;// "" "" 
    char sens_potentiel_x = (x_pac < g_x) ? 'g' : 'd'; 
    char sens_potentiel_y = (y_pac < g_y) ? 'h' : 'b';

    char result_hitwal = 'f';
    int i = 0;
    int rtn = 0;
    if(sens == 'b') {
        new_x = g_x;
        new_y = g_y + distance;
    }
    if(sens == 'd') {
        new_x = g_x + distance;
        new_y = g_y;
    }

    if(sens == 'g') {
        new_x = g_x - distance;
        new_y = g_y;
    }
    if(sens == 'h') {
        new_x = g_x;
        new_y = g_y - distance;
    }
    result_hitwal = boar->getMap().hitWall(g_x,g_y,new_x,new_y,24);
    
    if(result_hitwal == 'f') { //debut
		rtn = catchPacman(new_x,new_y,x_pac,y_pac,sens);
    }
    else {
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(0, 3);
        int valeur_random =  distrib(gen);
        char new_sens = 'f';
        switch(valeur_random) {
            case 0: new_sens = 'd';
                break;
            case 1: new_sens = 'g';
                break;
            case 2: new_sens = 'b';
                break;
            case 3: new_sens = 'h';
                break;
            default : 
                break;
        }
        new_x = g_x;
        new_y = g_y;
    
        if(sens == 'g') {
            if(new_sens == 'd')
                new_sens = sens_potentiel_y;//On influence en fonction de la position de pacman
        }
        else if(sens == 'd') {
            if(new_sens == 'g')
                new_sens = sens_potentiel_y;
        }
        else if(sens == 'h') {
            if(new_sens == 'b')
                new_sens = sens_potentiel_x;
        }
        else if(sens == 'b') {
            if(new_sens == 'h')
                new_sens = sens_potentiel_x;
        }
        sens = new_sens;
    }

    boar->change_pos(index,new_x,new_y);
    SDL_Rect elem_newpos{new_x,new_y,32,32};//(g.get_board()->get_elem_with_index(2).get_val_elem());
    boar->get_elem_with_index(index).set_rect(&elem_newpos);
    return rtn;
}
// attaque directement Pac Man. Il suit Pac-Man comme son ombre.
/*
- 
*/
int Game::updateRedGhost(int x_pac, int y_pac, char &sens)
{
    return moveGhost(x_pac,y_pac,sens,0);
    /*Fonctionne mais ne prend pas les intervalles, c'est à dire ne fonctionne que dans les coins
        pour le moment, il faut trouver un moyen de faire aller dans un sens encore plus aléatoire
        en fonction de certain espace
    - En tout cas fonctiionne bien pour les coins de la map car on va dans une direction , on ne peut pas
    aller dans celle d'où l'on viens ni l'inverse donc on va forcément dans le dernier sens possible 
    */
}

// a tendance à se mettre en embuscade. Elle vise l'endroit où va se trouver Pac-Man.
/*
-
*/
int Game::updatePinkGhost(int x_pac, int y_pac,char &sens)
{
    return moveGhost(x_pac,y_pac,sens,1);
}

// De temps en temps, il part dans la direction opposée à Pac-Man.
/*
-
*/
int Game::updateCyanGhost(int x_pac, int y_pac, char &sens)
{
    return moveGhost(x_pac,y_pac,sens,2);
}

//De temps en temps, il choisit une direction au hasard (qui peut être celle de Pac-Man).
/*
-
*/
int Game::updateYellowGhost(int x_pac, int y_pac, char &sens)
{
    return moveGhost(x_pac,y_pac,sens,3);
}

void Game::updatePacman(int x_pac, int y_pac, char& sens,char s) 
{
    int new_x = x_pac;
	int new_y = y_pac;
    SDL_Rect add_rect = boar->get_elem_with_index(4).get_val_elem();
	new_x += add_rect.x;
	new_y += add_rect.y;
	
    char result_hitwal = 'x';
    if((result_hitwal = boar->getMap().hitWall(add_rect.x,add_rect.y,new_x,new_y,24)) != 'f') {//((new_x > 610) || (new_y > 800) || (new_y < 28) || (new_x < 28)) {//murs provisoires
        new_x = add_rect.x;
        new_y = add_rect.y;
    }
    else {
		cout << "iciiii  , new_x , y : " << new_x << " , " << new_y << endl;
        int gum_catch = gum_catch = boar->catch_gum(add_rect.x,add_rect.y,new_x,new_y);
        //Test du catch ball 
		
		sens = sens_of_walk(add_rect.x,add_rect.y,new_x,new_y,s,1);
		if((new_x < 0) && (new_y < 420+20)&&(new_y > 420-20)) {
			new_x = 700;
			sens = 'g';
		}
		else if((new_x > 700) &&(new_y < 420+20)&&(new_y > 420-20)) {
			new_x = 0;
			sens = 'd';
		}
	 	boar->change_pos(4,new_x,new_y);
    }
}


// fonction qui met à jour la surface de la fenetre "win_surf"
int Game::updateGhosts(int x_pac, int y_pac, char sens[4], int out_ghost)
{
	//Faire tourner les fantomes 
    if(updateRedGhost(x_pac,y_pac, sens[0])==1)
        return 1;
    if(out_ghost > 0)
        if(updatePinkGhost(x_pac,y_pac, sens[1])==1)
            return 1;
    if(out_ghost > 1)
        if(updateCyanGhost(x_pac,y_pac,sens[2])==1)
            return 1;
    if(out_ghost > 2)
        if(updateYellowGhost(x_pac,y_pac,sens[3])==1)
            return 1;
    return 0;
}


char Game::sens_of_walk(int x_old,int y_old, int x, int y,char base_sens, int g_or_p)//g_or_p = ghost_or_pacman ; 0 pour g, 1 pour pacman
{
    int x_m_nx = x - x_old;
	int y_m_ny = y - y_old;
	char sens = ((x_m_nx != 0) ? ((x_m_nx < 0) ? 'g': 'd') : ((y_m_ny < 0) ? 'h': 'b'));
    if((x_m_nx == 0) && (y_m_ny == 0))
        sens = base_sens;//no sens
    return sens;
}

int Game::catchPacman(int x_ghost, int y_ghost, int x_pac, int y_pac, char &sens) //Mis en pause car implemter dans updateGhost
{//test après chaque update de ghost et pacman si il y'a contact entre un fantomes et pacman
    int l_box = x_pac;
    int u_box = y_pac;
    int r_box = x_pac+24;//24 = dim_perso
    int d_box = y_pac+24;// "" ""
	switch(sens) {
		case 'g': 
			return (((x_ghost <= r_box) && (x_ghost >= l_box)) && ((y_ghost >= u_box-10) && (y_ghost <= d_box+10)));
		case 'd':
			return (((x_ghost <= r_box) && (x_ghost >= l_box)) && ((y_ghost >= u_box-10) && (y_ghost <= d_box+10)));
		case 'h':
			return (((x_ghost <= r_box+10) && (x_ghost >= l_box-10)) && ((y_ghost >= u_box) && (y_ghost <= d_box)));
		case 'b':
			return (((x_ghost <= r_box+10) && (x_ghost >= l_box-10)) && ((y_ghost >= u_box) && (y_ghost <= d_box)));
		default:
			return 0;
	}
}


void Game::exit_ghost(char ghost_name) { // r,p,c,o
	SDL_Rect* ghost_choice = nullptr;
	int index_choice = -1;
	switch (ghost_name) {
		case 'r':
			index_choice = 0;
			ghost_choice = &(ghost_rr1);
			break;
		case 'p':
			index_choice = 1;
			ghost_choice = &(ghost_pr1);
			break;
		case 'c':
			index_choice = 2;
			ghost_choice = &(ghost_cr1);
			break;
		case 'y':
			index_choice = 3;
			ghost_choice = &(ghost_yr1);
			break;
	}
	boar->change_pos(index_choice,ghost_free.x,ghost_free.y);
}

void Game::drawGums()
{
	SDL_SetColorKey(sprites_planches, false, 0);//On efface tout 
	SDL_BlitScaled(sprites_planches, boar->get_gameboard(), win_surface, &bg);

    int nb_gums = boar->get_gums().size();
    for(int i = 0 ; i < nb_gums ; i++) {
        SDL_Rect gum = (boar->getGum_with_index(i));
        if((gum.h > 0) && (gum.h < 7)) //lgum limite a 6 de taille
            SDL_BlitScaled(sprites_planches, &(lgum), win_surface, &gum);
		else if(gum.h > 6) //bgum de taille sup à 6 (> lgum)
			SDL_BlitScaled(sprites_planches,&(bgum),win_surface, &gum); 
    }
}

void Game::drawGhostsAPac(char sens[5])
{
	for (int i = 0 ; i < 5; i++) {
        SDL_Rect save_elem = boar->get_elem_with_index(i).get_val_elem();//boar->getGhost_with_index(i);//boar->get_elem_with_index(i).get_val_elem();
        SDL_Rect *skin_choice = boar->getSkin(i,sens[i]);//boar->getGhost_with_index(i);//ghosts.at(i);//(boar->get_elem_with_index(i).get_val_elem());
        SDL_BlitScaled(sprites_planches, skin_choice, win_surface, &save_elem);
    }
}

Game::~Game()
{

}

#endif // GAME_H //