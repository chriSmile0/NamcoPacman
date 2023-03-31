#ifndef RECOMPENSE_H
#define RECOMPENSE_H

#include <string>
#include <iostream>
#include "utile_elem.h"
using namespace std;

//Posibilité de faire une classe globale sur tout les
// elem qui peuvent rapporter des points : fantomes bleu/blancs + artefacts(recompense) + graines

enum Artefacts {Cerise,Fraise,Orange,Pomme,Melon,Galboss,Cloche,Cle};

class Recompense: public Utile_elem
{
	private:
		int nb_pts = 0;
		string nom = "no_name";
		Artefacts artefact = Cerise;

	public:
		Recompense();
		Recompense(Artefacts arte,string name,int nb_points);
		Recompense(Recompense const& copy);
		Recompense(SDL_Rect rect);
		~Recompense();

		void setArtefact(Artefacts arte) {artefact = arte;}
		void setName(string name) {nom = name;}
		void setNb_pts(int nb_points) {nb_pts = nb_points;}

		Artefacts getArtefact() {return artefact;}
		string getName() {return nom;}
		int getNb_pts() {return nb_pts;}

		int arte_in_pts(Artefacts arte);
		string arte_in_str(Artefacts arte);
		
};

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


int Recompense::arte_in_pts(Artefacts arte)
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

string Recompense::arte_in_str(Artefacts arte)
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

#endif // RECOMPENSE_H //