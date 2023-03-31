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
		//Constructors
		Game();
		Game(string name, Board* b);
		Game(string name, Board* b, SDL_Window* w, SDL_Surface* s, SDL_Surface* pl);
		~Game();

		//Inline setters
		inline void set_pts(int nb_p) {nb_pts = nb_p;}
		inline void set_level(int l) {level = l;}
		inline void set_PacHuntime(int htime) {pac_huntime = htime;}
		inline void set_PacHuntimeLimit(int htimel) {pac_huntime_limit = htimel;}
		inline void set_ghosts_out(int g_out) {ghosts_out = g_out;}
		inline void set_name(string name) {player_name = name;}

		//Inline getters
		inline int get_pts() const {return nb_pts;}
		inline int get_level() const {return level;}
		inline int get_PacHuntime() const {return pac_huntime;}
		inline int get_PacHuntimeLimit() const {return pac_huntime_limit;}
		inline int get_ghosts_out() const {return ghosts_out;}
		inline Board* get_board() const {return boar;}
		inline SDL_Surface* get_planche() const {return sprites_planches;}
		inline SDL_Surface* get_win_surf() const {return win_surface;}
		inline SDL_Window* get_window() const {return win;}
		inline string get_name() const {return player_name;}

		//Draws
		void drawGums();
		void drawGhostsAPac();

		//Init
		void init_walls();
		void init_seeds();
		
		//Ghosts
		void exit_ghost(int id);
		void go_home_ghost(int id);

		//Update Personnage
		int moveGhost(int x_pac, int y_pac, char sens, int index, int statut);
		int updateRedGhost(int x_pac, int y_pac);
		int updatePinkGhost(int x_pac, int y_pac);
		int updateCyanGhost(int x_pac, int y_pac);
		int updateYellowGhost(int x_pac, int y_pac);
		int updateGhosts(int x_pac, int y_pac,int ghosts_out);
		void updatePacman(int x_pac, int y_pac, char s);

		//Others
		char sens_of_walk(int x_old,int y_old, int x, int y,char base_sens, int g_or_p);
		int catchPacman(int x_ghost, int y_ghost, int x_pac, int y_pac, char sens);
};

#include "../src/game.hpp"

#endif // GAME_H //