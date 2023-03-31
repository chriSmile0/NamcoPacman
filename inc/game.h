#ifndef GAME_H
#define GAME_H

#include "../inc/board.h"
#include <random>

SDL_Window* pWindow = nullptr;
SDL_Surface* win_surf = nullptr;
SDL_Surface* plancheSprites = nullptr;

class Game 
{
	private:
		int nb_pts;
		int level;
		int pac_huntime = 0;
		int pac_huntime_limit;//Pour le moment en tour de boucle 
		string player_name;
		Board *boar;
		SDL_Window* win;
		SDL_Surface* win_surface;
		SDL_Surface* sprites_planches;
		int ghosts_out = -1;
		
	public:
		Game();
		Game(string name, Board* b);
		Game(string name, Board* b, SDL_Window* w, SDL_Surface* s, SDL_Surface* pl);
		~Game();

		void set_pts(int nb_p) {nb_pts = nb_p;}
		void set_level(int l) {level = l;}
		void set_PacHuntime(int htime) {pac_huntime = htime;}
		void set_PacHuntimeLimit(int htimel) {pac_huntime_limit = htimel;}
		void set_ghosts_out(int g_out) {ghosts_out = g_out;}

		int get_pts() {return nb_pts;}
		int get_level() {return level;}
		int get_PacHuntime() {return pac_huntime;}
		int get_PacHuntimeLimit() {return pac_huntime_limit;}
		int get_ghosts_out() {return ghosts_out;}

		void init_walls();
		void init_seeds();

		Board* get_board() {return boar;}
		SDL_Surface* get_planche() {return sprites_planches;}
		SDL_Surface* get_win_surf() {return win_surface;}
		SDL_Window* get_window() {return win;}

		void set_name(string name) {player_name = name;}
		string get_name() {return player_name;}

		void drawGums();
		void drawGhostsAPac();

		void exit_ghost(int id);
		void go_home_ghost(int id);

		int moveGhost(int x_pac, int y_pac, char sens, int index, int statut);
		int updateRedGhost(int x_pac, int y_pac);
		int updatePinkGhost(int x_pac, int y_pac);
		int updateCyanGhost(int x_pac, int y_pac);
		int updateYellowGhost(int x_pac, int y_pac);
		int updateGhosts(int x_pac, int y_pac,int ghosts_out);
		void updatePacman(int x_pac, int y_pac, char s);

		char sens_of_walk(int x_old,int y_old, int x, int y,char base_sens, int g_or_p);

		int catchPacman(int x_ghost, int y_ghost, int x_pac, int y_pac, char sens);
};

#include "../src/game.hpp"

#endif // GAME_H //