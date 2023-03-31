#include "../inc/murs.h"
#include "../inc/map.h"

Map::Map()
{
	Murs.push_back(&m);//mur du haut
	Murs.push_back(&m1);
	Murs.push_back(&m2);
	Murs.push_back(&m3);
	Murs.push_back(&m4);
	Murs.push_back(&m5);
	Murs.push_back(&m6);
	Murs.push_back(&m7);
	Murs.push_back(&m8);
	Murs.push_back(&m9);
	Murs.push_back(&m10);
	Murs.push_back(&m11);
	Murs.push_back(&m12);
	//Murs.push_back(&m13);
	Murs.push_back(&m14);
	//Murs.push_back(&m15);
	Murs.push_back(&m16);
	//Murs.push_back(&m17);
	Murs.push_back(&m18);
	Murs.push_back(&m19);
	Murs.push_back(&m20);
	//Murs.push_back(&m21);
	Murs.push_back(&m22);
	//Murs.push_back(&m23);
	Murs.push_back(&m24);
	//Murs.push_back(&m25);
	Murs.push_back(&m26);
	Murs.push_back(&m27);
	Murs.push_back(&m28);

	//Les blocs 
	Murs.push_back(&b);
	Murs.push_back(&b1);
	Murs.push_back(&b2);
	Murs.push_back(&b3);
	Murs.push_back(&b4);
	Murs.push_back(&b5);
	Murs.push_back(&b6);
	Murs.push_back(&b7);
	Murs.push_back(&b8);
	Murs.push_back(&b9);
	Murs.push_back(&b10);
	Murs.push_back(&b11);
	Murs.push_back(&b12);
	Murs.push_back(&b13);
	Murs.push_back(&b14);
	Murs.push_back(&b15);
	Murs.push_back(&b16);
	Murs.push_back(&b17);
	Murs.push_back(&b18);
	Murs.push_back(&b19);
	Murs.push_back(&b20);
	Murs.push_back(&b21);
	Murs.push_back(&b22);
	Murs.push_back(&b23);
	Murs.push_back(&b24);
	Murs.push_back(&b25);
	Murs.push_back(&b26);
	Murs.push_back(&b27);
	Murs.push_back(&b28);
	Murs.push_back(&b29);
	Murs.push_back(&b30);
	Murs.push_back(&b31);
	Murs.push_back(&b32);
	Murs.push_back(&b33);
	Murs.push_back(&b34);
}

//A AMELIORER Car soucis !!!!! avec les coins et le vers la gauche et le haut pas correct dans certains cas 

char Map::hitWall(int x , int y , int new_x, int new_y, int dim_perso) //check si la position "heurte" un mur 
{										//sens : h = haut , b = bas, g = gauche, d = droit
	int x_m_nx = new_x - x;
	int y_m_ny = new_y - y;
	int h_mur = 0; //a calc dans Utile_elem au besoin si les murs deviennent des Utile_elem
	int w_mur = 0;
	char sens = ((x_m_nx != 0) ? ((x_m_nx < 0) ? 'g': 'd') : ((y_m_ny < 0) ? 'h': 'b'));

	int nb_murs = Murs.size();
	int goon = 1;
	int i = 0;

	while((goon) && (i < nb_murs)) {
		SDL_Rect wall = *(Murs.at(i));
		h_mur = wall.h;
		w_mur = wall.w;
		if((h_mur > 16) && (w_mur > 16))//cas d'un bloc 
		{
			switch(sens) { // La pour le moment sa le fera dès le premier mur 
				case 'h': if(((y > wall.y) && (new_y <= (wall.y+h_mur))) && ((new_x > wall.x) && (new_x < (wall.x + wall.w))))
							goon = 0;
						break;
				case 'b': if(((y < wall.y) && (new_y >= wall.y)) && ((new_x > wall.x) && (new_x < (wall.x + wall.w))))
							goon = 0;
						break;
				case 'g': if(((x > wall.x) && (new_x <= (wall.x+w_mur))) && ((new_y > wall.y) && (new_y < (wall.y + wall.h))))
							goon = 0;
						break;
				case 'd': if(((x < wall.x) && (new_x >= wall.x)) && ((new_y > wall.y) && (new_y < (wall.y + wall.h))))
							goon = 0;
						break;
				default:
					break;
			}
		}
		else { // cas d'un mur
			switch(sens) { // La pour le moment sa le fera dès le premier mur 
				case 'h': if(((y > wall.y) && (new_y <= wall.y)) && ((new_x > wall.x) && (new_x < (wall.x + wall.w))))
							goon = 0;
						break;
				case 'b': wall.y -= dim_perso;
						if(((y < wall.y) && (new_y >= wall.y)) && ((new_x > wall.x) && (new_x < (wall.x + wall.w))))
							goon = 0;
						break;
				case 'g': if(((x > wall.x) && (new_x <= wall.x)) && ((new_y > wall.y) && (new_y < (wall.y + wall.h))))
							goon = 0;
						break;
				case 'd': wall.x -= dim_perso; 
						if(((x < wall.x) && (new_x >= wall.x)) && ((new_y > wall.y) && (new_y < (wall.y + wall.h))))
							goon = 0;
						break;
				default:
					break;
			}
		}
		i++;
	}
	if(!goon)
		return sens;
	else
		return 'f';//f for free
}

Map::~Map()
{
}