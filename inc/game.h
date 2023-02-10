#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game 
{
    private:
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
    SDL_SetColorKey(sprites_planches, false, 0);
	SDL_BlitScaled(sprites_planches, boar->get_gameboard(), win_surface, &bg);
	int new_x = x;
	int new_y = y;
	if(add) {
		SDL_Rect add_rect = boar->get_elem_with_index(idx_elem_to_update).get_val_elem();
		new_x += add_rect.x;
		new_y += add_rect.y;
	}
	
	boar->change_pos(idx_elem_to_update,new_x,new_y);
	SDL_Rect elem_newpos{new_x,new_y,32,32};//(g.get_board()->get_elem_with_index(2).get_val_elem());
	boar->get_elem_with_index(idx_elem_to_update).set_rect(&elem_newpos);
    SDL_Rect* ghost_choice = nullptr;
    ghost_choice = &(ghost_rr1);
    
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