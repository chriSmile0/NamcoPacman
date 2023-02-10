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
		vector<SDL_Rect> getMurs() {return Murs;}
		SDL_Rect getMur_with_index(int index) {return Murs[index];}

		int hitWall(int x, int y , int new_x, int new_y);//on peut enlever sens

	private:
		vector<SDL_Rect> Murs;


};


Map::Map()
{
	Murs.push_back(m);//mur du haut
	Murs.push_back(m1);
	Murs.push_back(m2);
	Murs.push_back(m3);
	Murs.push_back(m4);
	Murs.push_back(m5);
	Murs.push_back(m6);
	Murs.push_back(m7);
	Murs.push_back(m8);
	Murs.push_back(m99);//mur du bas 
}

int Map::hitWall(int x , int y , int new_x, int new_y) //check si la position "heurte" un mur 
{										//sens : h = haut , b = bas, g = gauche, d = droit
	//on peut determiner le sens nous même maintenant avec new et old 

	//Possibilités de crées des zones de murs 
	//Comme ça en fonction de x et y on sait quel groupe de mur 
	//on doit checker 
	int x_m_nx = new_x - x;
	int y_m_ny = new_y - y;
	int hauteur_mur = 0; //a calc dans Utile_elem au besoin si les murs deviennent des Utile_elem
	int largeur_mur = 0;
	char sens = ((x_m_nx != 0) ? ((x_m_nx < 0) ? 'g': 'd') : ((y_m_ny < 0) ? 'h': 'b'));
	cout << "sens : " << sens << endl;

	int nb_murs = Murs.size();
	int goon = 1;
	int i = 0;
	int index_mur = -1;
	//On reste pour le moment sur les murs basiques
	//On verra ensuite pour les ilots , comme les carrées, les L , les T etcc
	
	//On cherche le mur qui est traverser par ce déplacement//

	while((goon) && (i < nb_murs)) {
		SDL_Rect wall = Murs.at(i);
		hauteur_mur = wall.h;
		largeur_mur = wall.w;
		cout << "wall carac : x: " << wall.x  <<", y: " << wall.y << ", h: " << hauteur_mur << ",w: " << largeur_mur << endl;
		cout << "x : " << x << ", new x:" << new_x <<  " y : " << y << ", new y:" << new_y << endl;
		switch(sens) { // La pour le moment sa le fera dès le premier mur 
			case 'h': if(((y > wall.y) && (new_y <= wall.y)) && ((new_x > wall.x) && (new_x < (wall.x + wall.w))))
						goon = 0;
					break;
			case 'b': if(((y < wall.y) && (new_y >= wall.y)) && ((new_x > wall.x) && (new_x < (wall.x + wall.w))))
						goon = 0;
					break;
			case 'g': if(((x > wall.x) && (new_x <= wall.x)) && ((new_y > wall.y) && (new_y < (wall.y + wall.h))))
						goon = 0;
					break;
			case 'd': if(((x < wall.x) && (new_x >= wall.x)) && ((new_y > wall.y) && (new_y < (wall.y + wall.h))))
						goon = 0;
					break;
			default:
				break;
		}
		i++;
	}
	index_mur = i-1;

	cout << "index mur : "<< index_mur << endl;

	/*
	int i = 0;
	while((goon) && (i < nb_murs)) {
		SDL_Rect wall = Murs.at(i);
		cout << "wall y : " << wall.y << endl;
		cout << "yy : " << y << endl;
		switch(sens) { // La pour le moment sa le fera dès le premier mur 
			case 'h': if(y < wall.y) return i; 
					break;
			case 'b': if(y > wall.y) return i;
					break;
			case 'g': if(x < wall.x) return i;
					break;
			case 'd': if(x > wall.x) return i;
					break;
			default:
				break;
		}
		i++;
	}*/
	return -1;
}

Map::~Map()
{
}

#endif // MAP_H //