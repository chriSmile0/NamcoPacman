#ifndef MAP_H
#define MAP_H
#include "murs.h"
#include <vector>

//Il s'agit ici de crées les passages par lesquels les 
//objets peuvent se déplacer //Pacman + les fantomes
//Il faudra aussi implémenté les tunnels qui permettent d'aller de x = 700 à x = 0

//Soit sous forme d'objet ou de SDL_Rect à l'infini

//2 solutions -> On suit les verticales / horizontales en créant un cirtcuit 
//            -> On crée des MUR qui sont donc des parties grises que les
//                  les fantomes et que pacman ne peut traverser
//

class Map {
	private:
		std::vector<SDL_Rect*> Murs;

	public:
		//Constructors
		Map();
		~Map();
		//Inline Getters 
		std::vector<SDL_Rect*> getMurs() {return Murs;}
		SDL_Rect* getMur_with_index(int index) {return Murs[index];}

		//Hit-Wall
		/**
		* @brief	Il s'agit ici de déterminer si un personnage est libre de 
		* 			se déplacer dans un sens précis ou non.
		*			La fonction détermine le sens via les différents coordonnées
		*			en paramètres.
		*			Si on heurte un mur le sens devra changer mais ce changement 
		*			n'a pas lieu dans cette fonction 
		* @param{x,y,new_x,new_y,dim_perso} : x,y les coordonnées exacts new_x/y les nouvelles coordonnées
		* 									dim_perso , les dimensions de personnage concernée
		* @return , le sens pour savoir où est le mur par rapport au personnage 
		*			et f si le personnage peut aller aux nouveaux coordonnées ou non
		**/
		char hitWall(int x, int y , int new_x, int new_y, int dim_perso);//char pour savoir de quel côté on est bloqué
};

#include "../src/map.hpp"

#endif // MAP_H //