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
		//Constructors
		Recompense();
		Recompense(Artefacts arte,string name,int nb_points);
		Recompense(Recompense const& copy);
		Recompense(SDL_Rect rect);
		~Recompense();

		//Inline setters
		inline void setArtefact(Artefacts arte) {artefact = arte;}
		inline void setName(string name) {nom = name;}
		inline void setNb_pts(int nb_points) {nb_pts = nb_points;}

		//Inline getters
		inline Artefacts getArtefact() const {return artefact;}
		inline string getName() const {return nom;}
		inline int getNb_pts() const {return nb_pts;}

		//Getters 
		/*Conversion d'un artefacts en fonction de sa valeur en points*/
		int arte_in_pts(Artefacts arte) const ;
		/*Renvoie le nom de l'artefact*/
		string arte_in_str(Artefacts arte) const ;

		SDL_Rect* get_Skin();  
		
};

#include "../src/recompense.hpp"

#endif // RECOMPENSE_H //