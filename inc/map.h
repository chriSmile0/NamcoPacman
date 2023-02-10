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
	Murs.push_back(m9);
	Murs.push_back(m10);
	Murs.push_back(m11);
	Murs.push_back(m12);
	Murs.push_back(m13);
	Murs.push_back(m14);
	Murs.push_back(m15);
	Murs.push_back(m16);
	Murs.push_back(m17);
	Murs.push_back(m18);
	Murs.push_back(m19);
	Murs.push_back(m20);
	Murs.push_back(m21);
	Murs.push_back(m22);
	Murs.push_back(m23);
	Murs.push_back(m24);
	Murs.push_back(m25);
	Murs.push_back(m26);
	Murs.push_back(m27);
	Murs.push_back(m28);

	//Les blocs 
	Murs.push_back(b);
	Murs.push_back(b1);
	Murs.push_back(b2);
	Murs.push_back(b3);
	Murs.push_back(b4);
	Murs.push_back(b5);
	Murs.push_back(b6);
	Murs.push_back(b7);
	Murs.push_back(b8);
	Murs.push_back(b9);
	Murs.push_back(b10);
	Murs.push_back(b11);
	Murs.push_back(b12);
	Murs.push_back(b13);
	Murs.push_back(b14);
	Murs.push_back(b15);
	Murs.push_back(b16);
	Murs.push_back(b17);
	Murs.push_back(b18);
	Murs.push_back(b19);
	Murs.push_back(b20);
	Murs.push_back(b21);
	Murs.push_back(b22);
	Murs.push_back(b23);
	Murs.push_back(b24);
	Murs.push_back(b25);
	Murs.push_back(b26);
	Murs.push_back(b27);
	Murs.push_back(b28);
	Murs.push_back(b29);
	Murs.push_back(b30);
	Murs.push_back(b31);
	Murs.push_back(b32);
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