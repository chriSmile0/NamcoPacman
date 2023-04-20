#include "../inc/recompense.h"

Recompense::Recompense(): Utile_elem() 
{

}

Recompense::Recompense(Artefacts arte,string name,int nb_points): Utile_elem() 
{
	artefact = arte;
	nom = name;
	nb_pts = nb_points;
}

Recompense::Recompense(Recompense const& copy): Utile_elem() 
{
	artefact = copy.artefact;
	nom = copy.nom;
	nb_pts = copy.nb_pts;
}

Recompense::Recompense(SDL_Rect rect): Utile_elem(rect) 
{

}


int Recompense::arte_in_pts(Artefacts arte) const
{
	switch(arte) {
		case Cerise: return 100;
		case Fraise: return 300;
		case Orange: return 500;
		case Pomme: return 700;
		case Melon: return 1000;
		case Galboss: return 2000;
		case Cloche: return 3000;
		case Cle: return 5000;
		default:
		return 0;
	} 
}

SDL_Rect* Recompense::get_Skin()  
{
		switch(artefact) {
			case Cerise: return &(cherry_r);
			case Fraise: return &(strawberry_r);
			case Orange: return &(orange_o);
			case Pomme: return &(apple_r);
			case Melon: return &(melon_g);
			case Galboss: return &(galboss_r);
			case Cloche: return &(bell_o);
			case Cle: return &(key_b);
			default:
				break;
		}
	
}

string Recompense::arte_in_str(Artefacts arte) const
{
	switch(arte) {
		case Cerise: return "Cerise";
		case Fraise: return "Fraise";
		case Orange: return "Orange";
		case Pomme: return "Pomme";
		case Melon: return "Melon";
		case Galboss: return "Galboss";
		case Cloche: return "Cloche";
		case Cle: return "Cle";
		default:
		return "None";
	}
}

Recompense::~Recompense()
{
}