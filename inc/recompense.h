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
		int visible = 0;

	public:
		//Constructors
		Recompense();
		Recompense(SDL_Rect rect, Artefacts arte,string name,int nb_points);
		Recompense(Artefacts arte,string name,int nb_points);
		Recompense(SDL_Rect r, Artefacts arte);
		~Recompense();

		//Inline setters
		inline void setArtefact(Artefacts arte) {artefact = arte;}
		inline void setName(string name) {nom = name;}
		inline void setNb_pts(int nb_points) {nb_pts = nb_points;}
		inline void setVisible(int vis) {visible = vis;}

		//Inline getters
		inline Artefacts getArtefact() const {return artefact;}
		inline string getName() const {return nom;}
		inline int getNb_pts() const {return nb_pts;}
		inline int getVisible() const {return visible;}

		//Getters 
		/**
		* @brief Conversion d'un artefact en sa valeur en points
		* @param{arte} : {/}
		* @return le nombre de points associés
		**/
		int arte_in_pts(Artefacts arte) const ;
		/**
		* @brief Conversion d'un artefact en son nom 
		* @param{arte} : {/}
		* @return le nom de l'artefact 
		**/
		string arte_in_str(Artefacts arte) const ;
		/**
		* @brief Renvoie le Skin en fonction de l'artefact de l'objet
		* @param{none}
		* @return L'adresse qui correspond au skin sur la bitmap 
		**/
		SDL_Rect get_Skin();  
		
};

#include "../src/recompense.hpp"

#endif // RECOMPENSE_H //