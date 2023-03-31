#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "symboles.h"
#include <string>
#include <iostream>
using namespace std;

class Personnage: public Utile_elem {
    public:
        Personnage();
        //Personnage(Personnage const& perso);
        Personnage(SDL_Rect* rect, int idx, char name);
        //Personnage(char nom);
        //Personnage(SDL_Rect rect);
        //Personnage(SDL_Rect* rect);
        ~Personnage();

        void set_nom(char name) {nom_perso = name;}
        char get_nom() {return nom_perso;}

        void set_id(int idx) {id = idx;}
        int get_id() {return id;}

        void set_statut(int new_stat) {statut = new_stat;}
        int get_statut() {return statut;}

        void set_sens(char n_sens) {sens = n_sens;}
        char get_sens() {return sens;}

        SDL_Rect* get_Skin();
        void set_Skin();

        SDL_Rect* get_Position();
        void set_Position();

        void set_start();
        void change_pos(int x, int y);
        void change_size(int w,int h);

        void exit_ghost(int idx);

    private:
        char nom_perso;
        int statut = -1;
        int id; //id pour id le perso plutôt que son nom //0=r/1=p/2=c/3=y/4=pac/
        char sens = 'd';
        int out = -1;
        SDL_Rect* Skin;
};


#include "../src/personnage.hpp"

#endif // PERSONNAGE_H //