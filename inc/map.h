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
    public:
        Map();
        ~Map();
		std::vector<SDL_Rect*> getMurs() {return Murs;}
		SDL_Rect* getMur_with_index(int index) {return Murs[index];}

		char hitWall(int x, int y , int new_x, int new_y, int dim_perso);//char pour savoir de quel côté on est bloqué

	private:
		std::vector<SDL_Rect*> Murs;
};




#include "../src/map.hpp"

#endif // MAP_H //