#ifndef GAME_H
#define GAME_H

#include "../inc/board.h"
#include <random>
#include <cmath>

SDL_Window* pWindow = nullptr;
SDL_Surface* win_surf = nullptr;
SDL_Surface* plancheSprites = nullptr;

class Game 
{
	private:
		int nb_pts = 0;
		int level;
		int pac_huntime = 0;
		int pac_huntime_limit;//Pour le moment en tour de boucle 
		string player_name;
		Board *boar;
		SDL_Window* win;
		SDL_Surface* win_surface;
		SDL_Surface* sprites_planches;
		vector<SDL_Rect> letters_hs;
		vector<SDL_Rect> digits_hs;
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
		/** @brief	Permet d'afficher une gum d'une certaine taille en fonction 
		 * 			de sa hauteur (>6 = gum spéciale)
		 * @param{none}
		 * @return{none} 
		*/
		void drawGums();
		/** @brief	Permet d'afficher pacman et les fantomes en fonction de leur
		 * 			statut et en fonction du scénario (GmangeP,PmangeG,FinDePmangeG)	
		 *			On a donc plusieurs statut : 
		 				- -1 ou 0 pour ghost = chasseur
						- 1 pour ghost chasser en bleu
						- 2 pour ghost chasser en bleu/blanc
					On a donc un skin pour chacun
		 * @param{none}
		 * @return{none} 
		*/
		void drawGhostsAPac();
		/** @brief	Dessiner la récompense courant sur la map 
		 * 			(Voir pour la généraliser pour la barre des récompenses totales)
		 * @param{none}
		 * @return{none} 
		*/
		void drawAward();

		void drawScore();

		void drawLifes();

		void drawListAwards();

		//Init
		/** @brief	Affichage des murs (pas beau!!!)
		 * 			On applatit une gum pour la texture 
		 * 			Sinon les murs sont déjà implémentés dans le constructeur
		 * 			de la map et donc déjà présent lorsque l'on joue sans cette 
		 * 			fonction
		 * @param{none}
		 * @return{none} 
		*/
		void init_walls();
		/** @brief	Créer les gums avec les coordonnées relatives 
		 * 			(ce qui permet) de gagner du temps et potentiellement
		 * 			de la dynamicité pour de l'amélioration ex:
		 * 			agrandissement de la fenêtre etc..
		 * 			C'est ici que l'on crée les gum normales et spéciale
		 * 			de manière bien précise avec chaque gum spéciale à un 
		 * 			endroit précis
		 * @param{none}
		 * @return{none}
		*/
		void init_seeds();
		
		//Ghosts
		/** @brief	Increment du nombre de ghosts en chasse
		 * 			Plus héritage sur l'exit_ghosts du board
		 * @param{idx} : l'id du ghost dans le tableau de personnages
		 * @return{none} 
		*/
		void exit_ghost(int id);
		/** @brief	Décrémente le nombre de ghosts en chasse
		 * 			Plus héritage sur l'home_ghosts du board
		 * @param{idx} : l'id du ghost dans le tableau
		 * @return{none} 
		*/
		void go_home_ghost(int id);

		//Update Personnage
		/** @brief	Permet de mettre en mouvement un fantome en utilisant
		 * 			la position de pacman.
		 * 			On peut voir cette fonction comme l'IA des fantomes
		 * 			mais pour le moment elle est très basique 
		 * 			et assez faible par rapport à Pacman
		 * 
		 * 			FONCTIONNEMENT DE L'IA À EXPLIQUER 
		 * 
		 * 			Chacun des comportements de fantome doivent être différent 
		 * 			par rapport au autres
		 * 
		 * @param{x_pac,y_pac,sens,index,statut}
		 * @return 0 pour rien à signaler, 1 pour GmangeP, 2 pour PmangeG 
		*/
		int moveGhost(int x_pac, int y_pac, char sens, int index, int statut);
		int updateRedGhost(int x_pac, int y_pac);
		int updatePinkGhost(int x_pac, int y_pac);
		int updateCyanGhost(int x_pac, int y_pac);
		int updateYellowGhost(int x_pac, int y_pac);
		/** @brief	Déplace le fantome à condition qu'il soit dehors 
		 * 			dès la première fois.
		 * 
		 * 			On pourrais le remobiliser si on change légèrement la fonction
		 * 			en regardant précisement le 'out' de chaque fantome
		 * @param{x_pac,y_pac,ghosts_out} : pos de pacman, le nombre de fantomes
		 * 						dehors
		 * @return 0 si aucun fantome actif sinon le nombre de ces derniers.
		*/
		int updateGhosts(int x_pac, int y_pac,int ghosts_out);
		/** @brief	On met ici à jour le sens de pacman ainsi que sa position
		 * 			si il heurte un mur on ne change pas sa position
		 * 			Il y a aussi l'utilisation de catchgum pour faire
		 * 			engranger les points lorsque pacman se déplace
		 * 			Comme c'est le seul à en bénéfier on peut utilsier la fonction 
		 * 			ici	
		 * @param{x_pac,y_pac,s} , s = la flèche appuyer(peut être sauvegarder en cas 
		 * 						d'hitwall et donc d'éviter de rester bloquer)
		 * @return{none} 
		*/
		void updatePacman(int x_pac, int y_pac, char s);

		//Others
		/** @brief	On va ici déterminer vers quelle direction se dirige un 
		 * 			personnage(surtout pacman)
		 * 			J'utilise aussi cela pour les passages de la droite 
		 * 			vers la gauche(et vice versa) via le tunnel
		 * 			Cela est encore une fois utiliser pour diriger pacman
		 * 			et lui fournir le bon skin par la suite et un parcours
		 * 			cohérent
		 * @param{x_old,y_old,x,y,base_sens,g_or_p}
		 * @return h|b|g|d pour haut,bas,gauche,droit
		*/
		char sens_of_walk(int x_old,int y_old, int x, int y,char base_sens, int g_or_p);
		/** @brief	Permet de savoir si l'un des 2 se touchent et donc si
		 * 			c'est le cas il y'a capture , dans cette fonction
		 * 			on n'occupe pas de savoir qui capture qui , on regarde
		 * 			juste si il y a capture
		 * 			Il y a donc aussi une certaine hitbox à gerer
		 * 			(Hitbox à améliorer!!)
		 * @param{x_ghost,y_ghost,x_pac,y_pac,sens}
		 * @return 1 pour capture , 0 pour pas de capture
		*/
		int catchPacman(int x_ghost, int y_ghost, int x_pac, int y_pac, char sens);

		/**
		 * @brief	init des lettres du champ texte high score
		 * @param{none}
		 * @return 
		**/
		void init_high_score_letters();

		/**
		 * @brief	init des chiffres du champ texte des points
		 * @param{none}
		 * @return 
		**/
		void init_high_score_digits();


};

#include "../src/game.hpp"

#endif // GAME_H //