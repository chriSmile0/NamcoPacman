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
		char *sens[5];
		int *status[5];
		
    public:
        Game();
        Game(string name, Board* b);
		Game(string name, Board* b, SDL_Window* w, SDL_Surface* s, SDL_Surface* pl);
        ~Game();


        void set_pts(int nb_p) {nb_pts = nb_p;}
        void set_level(int l) {level = l;}
		void set_tabsens(char *s[5]) {for(int i = 0 ; i < 5; i++) sens[i] = (s[i]);}
		void set_sens(int i, char s) {*(sens[i]) = s;}
		void set_tabstatus(int *st[5]) {for(int i = 0 ; i < 5; i++) status[i] = (st[i]);}
		void set_status(int i, int st) {*(status[i]) = st;}
		void set_PacHuntime(int htime) {pac_huntime = htime;}
		void set_PacHuntimeLimit(int htimel) {pac_huntime_limit = htimel;}

        int get_pts() {return nb_pts;}
        int get_level() {return level;}
		char* get_tabsens() {return *sens;}
		char get_sens(int i) {return *(sens[i]);}
		int* get_tabstatus() {return *status;}
		int get_status(int i) {return *(status[i]);}
		int get_PacHuntime() {return pac_huntime;}
		int ge_tPacHuntimeLimit() {return pac_huntime_limit;}


        void init_walls();
        void init_seeds();

        Board* get_board() {return boar;}
        SDL_Surface* get_planche() {return sprites_planches;}
        SDL_Surface* get_win_surf() {return win_surface;}
        SDL_Window* get_window() {return win;}

        void set_name(string name) {player_name = name;}
        string get_name() {return player_name;}

		void drawGums();
		void drawGhostsAPac(char sens[5], int status[5]);

		void exit_ghost(int id);

        int moveGhost(int x_pac, int y_pac, char &sens, int index, int statut);
        int updateRedGhost(int x_pac, int y_pac, char &sens, int statut);
        int updatePinkGhost(int x_pac, int y_pac, char &sens, int statut);
        int updateCyanGhost(int x_pac, int y_pac, char &sens, int statut);
        int updateYellowGhost(int x_pac, int y_pac, char &sens, int statut);
        int updateGhosts(int x_pac, int y_pac, char sens[5], int out_ghost, int status[5]);
        void updatePacman(int x_pac, int y_pac, char &sens, char s);

        char sens_of_walk(int x_old,int y_old, int x, int y,char base_sens, int g_or_p);

        int catchPacman(int x_ghost, int y_ghost, int x_pac, int y_pac, char &sens);
};

#include "../src/game.hpp"

#endif // GAME_H //