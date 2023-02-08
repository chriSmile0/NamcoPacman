#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include <iostream>
using namespace std;

class Personnage: public Utile_elem {
    public:
        Personnage();
        Personnage(Personnage const& perso);
        Personnage(string nom);
        Personnage(SDL_Rect rect);
        ~Personnage();

        void set_nom(string nom) {nom_perso = nom;}
        string get_nom() {return nom_perso;}

    private:
        string nom_perso;
};

Personnage::Personnage(): Utile_elem()
{
	nom_perso = "no_name";
    cout << "perso" << endl;
}

Personnage::Personnage(SDL_Rect rect): Utile_elem(rect)
{
    cout << "crea rect" << endl;
}

Personnage::Personnage(Personnage const& perso)
{
    nom_perso = perso.nom_perso;
}

Personnage::Personnage(string nom): Utile_elem()
{
    nom_perso = nom;
}


Personnage::~Personnage()
{
}

#endif // PERSONNAGE_H //