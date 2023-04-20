#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "symboles.h"
#include <string>
#include <iostream>
using namespace std;

class Personnage: public Utile_elem {
	private:
		char nom_perso;
		int statut = -1;
		int id; //id pour id le perso plutôt que son nom //0=r/1=p/2=c/3=y/4=pac/
		char sens = 'd';
		int out = -1;
		int time_house = 0;
		SDL_Rect* Skin;
		
	public:
		//Constructors
		Personnage();
		Personnage(SDL_Rect* rect, int idx, char name);
		Personnage(int x,int y, int w, int h) : Utile_elem(x,y,w,h) {}
		~Personnage();

		//Inline setters
		inline void set_nom(char name) {nom_perso = name;}
		inline void set_id(int idx) {id = idx;}
		inline void set_statut(int new_stat) {statut = new_stat;}
		inline void set_sens(char n_sens) {sens = n_sens;}
		inline void set_out(int o) {out = o;}
		inline void set_time_house(int time) {time_house = time;}

		//Setters
		/**
		* @brief	Change les coordonnées du personnage en fonction 
					du personnage concerné.
					Ainsi que reset du temps dans la maison des fantomes 
		* @param{none} 
		* @return 
		**/
		void set_start();
		/**
		* @brief	set_x/y des nouvelles coordonnées du personnage
		* @param{none}
		* @return 
		**/
		void change_pos(int x, int y);
		/**
		* @brief	set_w/h de la nouvelle taille du personnage
		* @param{none}
		* @return 
		**/
		void change_size(int w,int h);

		//Inline getters
		inline char get_nom() const {return nom_perso;}
		inline int get_id() const {return id;}
		inline int get_statut() const {return statut;}
		inline char get_sens() const {return sens;}
		inline int get_out() const {return out;}
		inline int get_time_house() const {return time_house;}

		//Get Skin
		/**
		* @brief	Chaque personnage possède un statut qui lui donne 
					un certain pouvoir sur le plateau de jeu.
					Cela concerne surtout les fantomes qui voit leur statut
					changer au cours du jeu et si ce statut est > 0 ce skin ne
					sera pas unique et sera donc bleu ou blanc pour chaque 
					fantome concerner.
					Dans l'autre cas chaque fantome possède un skin en fonction 
					de son sens sur le plateau de jeu.
		* @param{none}
		* @return On retourne l'adresse du skin sur la bitmap
		**/
		SDL_Rect* get_Skin();

		//Ghost 
		/**
		* @brief	Change la position d'un fantome sur la case de départ d'un 
					fantome qui est juste au dessus de la maison des fantomes
					Maj de l'entier out qui permet de définir un fantome 
					comme à l'intérieur ou à l'extérieur de la maison des ghosts
		* @param{none}
		* @return 
		**/
		void exit_ghost(int idx);
		inline void home_ghost(int idx) {set_start();}
};


#include "../src/personnage.hpp"

#endif // PERSONNAGE_H //