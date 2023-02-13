#ifndef GAME_H
#define GAME_H

#include "board.h"

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
        SDL_Rect *skin_choice = boar->getSkin(i);//boar->getGhost_with_index(i);//ghosts.at(i);//(boar->get_elem_with_index(i).get_val_elem());
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

    int result_hitwal = 0;
    if((result_hitwal = boar->getMap().hitWall(add_rect.x,add_rect.y,new_x,new_y,24)) != -1) {//((new_x > 610) || (new_y > 800) || (new_y < 28) || (new_x < 28)) {//murs provisoires
        cout << "passage ici r_hit : " << result_hitwal << endl;
        if(add) {
            new_x = add_rect.x;
            new_y = add_rect.y;
        }
    }
    else {
        cout << "change pos of pacman" << endl;
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
    SDL_SetColorKey(sprites_planches, true, 0);
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

Game::~Game()
{

}

#endif // GAME_H //