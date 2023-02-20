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

        void update_pos_of_elem(int idx_elem_to_update, int x, int y, int add);
        void update_size_of_elem(int idx_elem_to_update, int w, int h, int add);

        int updateRedGhost(int x_pac, int y_pac, char &sens);
        void updatePinkGhost(int x_pac, int y_pac);
        void updateCyanGhost(int x_pac, int y_pac);
        void updateYellowGhost(int x_pac, int y_pac);
        void update_ghosts(int x_pac, int y_pac);
        void updatePacman(int x_pac, int y_pac, char s);

        char sens_of_walk(int x_old,int y_old, int x, int y,char base_sens, int g_or_p);

        int catchPacman();

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

void Game::update_pos_of_elem(int idx_elem_to_update, int x, int y, int add) // 1 pour += , 0 pour = 
{
    //On peut ici checker le cas si c'est fantome ou pacman ou un autre élement
    //Normalement seul les fantômes voit leur position changer 
    //car les autres éléments apparaisse ou disparaisse donc position fixe ou nul sur 
    //le terrain 
    SDL_SetColorKey(sprites_planches, false, 0);//On efface tout 
	SDL_BlitScaled(sprites_planches, boar->get_gameboard(), win_surface, &bg);


    for (int i = 0 ; i < 5; i++) {
        SDL_Rect save_elem = boar->get_elem_with_index(i).get_val_elem();//boar->getGhost_with_index(i);//boar->get_elem_with_index(i).get_val_elem();
        SDL_Rect *skin_choice = boar->getSkin(i,'d');//boar->getGhost_with_index(i);//ghosts.at(i);//(boar->get_elem_with_index(i).get_val_elem());
        SDL_BlitScaled(sprites_planches, skin_choice, win_surface, &save_elem);
    }

    int nb_gums = boar->get_gums().size();
    for(int i = 0 ; i < nb_gums ; i++) {
        SDL_Rect gum = (boar->getGum_with_index(i));
        if(gum.h > 0)
            SDL_BlitScaled(sprites_planches, &(lgum), win_surface, &gum);
    }

    //Il faut aussi sauver l'emplacement des billes// 

    /*for(int i = 0 ; i < 28;i++) {
        SDL_Rect *wall = (boar->getMap().getMurs().at(i));
        //gum étallé = mur //ils vont de toutes façon disparaitre, c'est juste pour le style pour le moment
        SDL_BlitScaled(sprites_planches,&(lgum),win_surface, wall);
    }*/

	int new_x = x;
	int new_y = y;
    SDL_Rect add_rect = boar->get_elem_with_index(idx_elem_to_update).get_val_elem();
	if(add) {
		new_x += add_rect.x;
		new_y += add_rect.y;
	}

    char result_hitwal = 'x';
    if((result_hitwal = boar->getMap().hitWall(add_rect.x,add_rect.y,new_x,new_y,24)) != 'f') {//((new_x > 610) || (new_y > 800) || (new_y < 28) || (new_x < 28)) {//murs provisoires
        if(add) {
            new_x = add_rect.x;
            new_y = add_rect.y;
        }
    }
    else {
        int gum_catch = 0;
        if((gum_catch = boar->catch_gum(add_rect.x,add_rect.y,new_x,new_y)) != -1)
            cout << "catch gum number : " << gum_catch << endl;
        boar->change_pos(idx_elem_to_update,new_x,new_y);
        //Test du catch ball 
    }
    SDL_Rect elem_newpos{new_x,new_y,32,32};//(g.get_board()->get_elem_with_index(2).get_val_elem());
    boar->get_elem_with_index(idx_elem_to_update).set_rect(&elem_newpos);
    SDL_Rect* ghost_choice = nullptr;
    if(idx_elem_to_update < 5)
        ghost_choice = boar->getGhost_with_index(idx_elem_to_update);
    /*else 
        ghost_choice = boar->getPacman();*/
    SDL_BlitScaled(sprites_planches, ghost_choice, win_surface, &elem_newpos);
    //SDL_SetColorKey(sprites_planches, true, 0);
    cout << boar->get_elem_with_index(idx_elem_to_update).get_x() << endl;
}


//****Voir pour utiliser update en ajoutant un param avec add = 2 pour mettre voir x et y comme w et h !!!!!****
void Game::update_size_of_elem(int idx_elem_to_update, int w, int h, int add) // 1 pour += , 0 pour = 
{
    //On peut ici checker le cas si c'est fantome ou pacman ou un autre élement
    //Normalement seul les fantômes voit leur position changer 
    //car les autres éléments apparaisse ou disparaisse donc position fixe ou nul sur 
    //le terrain 
    SDL_SetColorKey(sprites_planches, false, 0);
	SDL_BlitScaled(sprites_planches, boar->get_gameboard(), win_surface, &bg);
	int new_w = w;
	int new_h = h;
	if(add) {
		SDL_Rect add_rect = boar->get_elem_with_index(idx_elem_to_update).get_val_elem();
		new_w += add_rect.w;
		new_h += add_rect.h;
	}
	
	//boar->change_pos(idx_elem_to_update,new_x,new_y);
    boar->change_size(idx_elem_to_update,new_w,new_h);
	SDL_Rect elem_newpos{boar->get_elem_with_index(idx_elem_to_update).get_x(),boar->get_elem_with_index(idx_elem_to_update).get_x(),new_w,new_h};//(g.get_board()->get_elem_with_index(2).get_val_elem());
	boar->get_elem_with_index(idx_elem_to_update).set_rect(&elem_newpos);
    SDL_Rect* ghost_choice = nullptr;
    ghost_choice = &(lgum);
    
    SDL_BlitScaled(sprites_planches, ghost_choice, win_surface, &elem_newpos);
    SDL_SetColorKey(sprites_planches, true, 0);
    cout << boar->get_elem_with_index(idx_elem_to_update).get_h() << endl;

}

// attaque directement Pac Man. Il suit Pac-Man comme son ombre.
/*
- 
*/
int Game::updateRedGhost(int x_pac, int y_pac, char &sens)
{
    int red_x = boar->get_elem_with_index(0).get_x();
    int red_y = boar->get_elem_with_index(0).get_y();
    int distance = 6;//distance de déplacement des fantomes

    int new_x = red_x;//à changer en fonction de la position de pacman
    int new_y = red_y;// "" "" 
    int add_x = 0;
    int add_y = 0;
    char sens_potentiel_x = (x_pac < red_x) ? 'g' : 'd'; 
    char sens_potentiel_y = (y_pac < red_y) ? 'h' : 'b';
    char final_sens = 'x';

    int delta_x = (x_pac - red_x)*(x_pac - red_x);
    int delta_y = (y_pac - red_y)*(y_pac - red_y);
    cout << "d_x : " << delta_x << " d_y : " << delta_y << endl; //on cherche à se rapprocher le plus possible donc le plus grand delta
    /*char avancee = (delta_x < delta_y) ? sens_potentiel_y : sens_potentiel_x;
    char option_xy = ((avancee == 'g') || (avancee == 'h')) ? '-' : '+';
    new_x = (avancee == sens_potentiel_x) ? ((option_xy == '-') ? red_x-distance : red_x+distance) : red_x;
    new_y = (avancee == sens_potentiel_y) ? ((option_xy == '-') ? red_y-distance : red_y+distance) : red_y;*/

    char result_hitwal = 'f';
    int i = 0;
    int rtn = 0;
    if(sens == 'b') {
        new_x = red_x;
        new_y = red_y + distance;
    }
    if(sens == 'd') {
        new_x = red_x + distance;
        new_y = red_y;
    }

    if(sens == 'g') {
        new_x = red_x - distance;
        new_y = red_y;
    }
    if(sens == 'h') {
        new_x = red_x;
        new_y = red_y - distance;
    }
    result_hitwal = boar->getMap().hitWall(red_x,red_y,new_x,new_y,24);
    
    if(result_hitwal == 'f') { //debut
        switch(sens) {
            case 'g': new_x = red_x - distance;
                if((new_x == x_pac) && ((new_y >= y_pac-5)&&(new_y <= y_pac+5)))
                    rtn = -1;
                break;
            case 'd': new_x = red_x + distance;
                if((new_x == x_pac) && ((new_y >= y_pac-5)&&(new_y <= y_pac+5)))
                    rtn = -1;
                break;
            case 'h': new_y = red_y - distance;
                if((new_y == y_pac) && ((new_x >= x_pac-5)&&(new_x <= x_pac+5)))
                    rtn = -1;
                break;
            case 'b': new_y = red_y + distance;
                if(((new_y == y_pac)) && ((new_x >= x_pac-5)&&(new_x <= x_pac+5)))
                    rtn = -1;
                break;
            default:
                break;
        }
        final_sens = sens;
        if(rtn != -1)
            rtn =  0;
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
        new_x = red_x;
        new_y = red_y;
    
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
    cout << "new_x :" << new_x << endl;
    cout << "new_y :" << new_y << endl;
    cout << "x_pac : " << x_pac << endl;
    cout << "y_pac : " << y_pac << endl;
    cout << "res wall : " << result_hitwal << endl;

    boar->change_pos(0,new_x,new_y);
    SDL_Rect elem_newpos{new_x,new_y,32,32};//(g.get_board()->get_elem_with_index(2).get_val_elem());
    boar->get_elem_with_index(0).set_rect(&elem_newpos);
    char sens_walk = sens_of_walk(red_x,red_y,new_x,new_y,'g',0); 
    SDL_BlitScaled(sprites_planches, boar->getSkin(0,sens), win_surface, &elem_newpos);
    return rtn;
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
void Game::updatePinkGhost(int x_pac, int y_pac)
{
    int pink_x = boar->getGhost_with_index(1)->x;
    int pink_y = boar->getGhost_with_index(1)->y;
    int abs_x = x_pac - pink_x;
    int abs_y = y_pac - pink_y;
    //bas/haut/gauche/droit
    char sens_y = (pink_y < y_pac) ? 'b' : 'h';
    char sens_x = (pink_x < x_pac) ? 'd' : 'g';


    /*pink_x += (sens_x == 'g') ? -6 : 6;
    pink_y += (sens_y == 'h') ? -6 : 6; */

    //boar->change_pos(0,pink_x,pink_y);
}

// De temps en temps, il part dans la direction opposée à Pac-Man.
/*
-
*/
void Game::updateCyanGhost(int x_pac, int y_pac)
{
    int cyan_x = boar->getGhost_with_index(2)->x;
    int cyan_y = boar->getGhost_with_index(2)->y;
    int abs_x = x_pac - cyan_x;
    int abs_y = y_pac - cyan_y;
    //bas/haut/gauche/droit
    char sens_y = (cyan_y < y_pac) ? 'b' : 'h';
    char sens_x = (cyan_x < x_pac) ? 'd' : 'g';

    //Je doit lancer un random de tel sorte que 1/3 ou 1/4 il aille dans la direction
    //opposer de pacman

    /*cyan_x += (sens_x == 'g') ? -6 : 6;
    cyan_y += (sens_y == 'h') ? -6 : 6;*/
    //boar->change_pos(0,cyan_x,cyan_y);
}

//De temps en temps, il choisit une direction au hasard (qui peut être celle de Pac-Man).
/*
-
*/
void Game::updateYellowGhost(int x_pac, int y_pac)
{
    int yel_x = boar->getGhost_with_index(3)->x;
    int yel_y = boar->getGhost_with_index(3)->y;
    int abs_x = x_pac - yel_x;
    int abs_y = y_pac - yel_y;
    //bas/haut/gauche/droit
    char sens_y = (yel_y < y_pac) ? 'b' : 'h';
    char sens_x = (yel_x < x_pac) ? 'd' : 'g';
    /*yel_x += (sens_x == 'g') ? -6 : 6;
    yel_y += (sens_y == 'h') ? -6 : 6; */

    //On combine cyan avec ici sauf que cette fois ci il va dans n'importe
    //quelle direction 1/3 ou 1/4 fois.

    //boar->change_pos(0,yel_x,yel_y);
}

void Game::updatePacman(int x_pac, int y_pac, char s) 
{
    SDL_SetColorKey(sprites_planches, false, 0);//On efface tout 
	SDL_BlitScaled(sprites_planches, boar->get_gameboard(), win_surface, &bg);

    //updateRedGhost(boar->get_elem_with_index(4).get_val_elem().x,boar->get_elem_with_index(4).get_val_elem().y);
    for (int i = 1 ; i < 4; i++) {
        SDL_Rect save_elem = boar->get_elem_with_index(i).get_val_elem();//boar->getGhost_with_index(i);//boar->get_elem_with_index(i).get_val_elem();
        SDL_Rect *skin_choice = boar->getSkin(i,'d');//boar->getGhost_with_index(i);//ghosts.at(i);//(boar->get_elem_with_index(i).get_val_elem());
        SDL_BlitScaled(sprites_planches, skin_choice, win_surface, &save_elem);
    }

    int nb_gums = boar->get_gums().size();
    for(int i = 0 ; i < nb_gums ; i++) {
        SDL_Rect gum = (boar->getGum_with_index(i));
        if(gum.h > 0)
            SDL_BlitScaled(sprites_planches, &(lgum), win_surface, &gum);
    }

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
        int gum_catch = 0;
        if((gum_catch = boar->catch_gum(add_rect.x,add_rect.y,new_x,new_y)) != -1)
            cout << "catch gum number : " << gum_catch << endl;
        boar->change_pos(4,new_x,new_y);
        //Test du catch ball 
    }
    SDL_Rect elem_newpos{new_x,new_y,32,32};//(g.get_board()->get_elem_with_index(2).get_val_elem());
    boar->get_elem_with_index(4).set_rect(&elem_newpos);
    SDL_Rect* ghost_choice = nullptr;
    ghost_choice = boar->getSkin(4,sens_of_walk(add_rect.x,add_rect.y,new_x,new_y,s,1));
    SDL_BlitScaled(sprites_planches, ghost_choice, win_surface, &elem_newpos);
    //SDL_SetColorKey(sprites_planches, true, 0);
    //cout << boar->get_elem_with_index(idx_elem_to_update).get_x() << endl;
}


// fonction qui met à jour la surface de la fenetre "win_surf"
void Game::update_ghosts(int x_pac, int y_pac)
{
	/*SDL_SetColorKey(plancheSprites, false, 0);
	SDL_BlitScaled(plancheSprites, &src_b3, win_surf, &bg);*/

	//Faire tourner les fantomes 
	//Update algo rouge
    //Chercher la position de Pacman -> lui fourni un +6 le plus proche de pacman


	//Update algo rose
    //updateRedGhost(x_pac,y_pac);
	//Update algo cyan
    updatePinkGhost(x_pac,y_pac);

	//Update algo jaune
    updateCyanGhost(x_pac,y_pac);
	//puis on appel update_pos_of_elem(pacman) 
    updateYellowGhost(x_pac,y_pac);

	
	//print the skins on the window
	/*SDL_SetColorKey(plancheSprites, true, 0);
	SDL_BlitScaled(plancheSprites, &ghost_in2, win_surface, &ghost);*/
}


char Game::sens_of_walk(int x_old,int y_old, int x, int y,char base_sens, int g_or_p)//g_or_p = ghost_or_pacman ; 0 pour g, 1 pour pacman
{
    int x_m_nx = x - x_old;
	int y_m_ny = y - y_old;
	char sens = ((x_m_nx != 0) ? ((x_m_nx < 0) ? 'g': 'd') : ((y_m_ny < 0) ? 'h': 'b'));
    cout << "sens direct : " << sens << endl;



    if((x_m_nx == 0) && (y_m_ny == 0))
        sens = base_sens;//no sens
    return sens;
}

int Game::catchPacman() //Mis en pause car implemter dans updateGhost
{//test après chaque update de ghost et pacman si il y'a contact entre un fantomes et pacman
    int hit_box_xpacman = 0; 
    int hit_box_ypacman = 0;
    return 0;
}


Game::~Game()
{

}

#endif // GAME_H //