#ifndef MURS_H 
#define MURS_H
#include <SDL2/SDL.h>


//Il faut donc s'inspirer du tracer fait via les gums
//On part donc sur un x et  en haut de gauche de 32 et 32
//On peut faire le test en mettant des gums a ces endroits là 
//sw = scale_walls
int sw = 4;

//Attention il faut aussi gérer le mur en fonction de la taille du perso
//Pour le moment si on enleve 25 sur le mur m6 cela fonctionne mais il faut trouver un moyen de 
//de le faire en automatique en fonction du perso 

//{x,y,w,h}
SDL_Rect m =  { 28,28, 154*sw,4 };  // ,  // , //-> tout en haut sur all longueur // sur le gameboard actif -> peut importe lequel 
SDL_Rect m1 = {320,28, 4,30*sw }; //  ,  //  , //-> en haut le mur qui coupe m (gauche) // ""   m1/m2/m3 à remplacer par un bloc
SDL_Rect m2 = {348,28, 4,30*sw }; //  ,  //  , //-> en haut le mur qui coupe m (droite) // "" 
SDL_Rect m3 = {318,149, 10*sw,4 }; //  ,  //  , //-> en haut entre m1 et m2
SDL_Rect m4 = { 28,28, 4,67*sw }; //  ,  //  , //-> en haut à gauche // "" 
SDL_Rect m5 = {640,28, 4,67*sw }; //  ,  //  , //-> en haut à droite // "" 
SDL_Rect m6 = {28,25+(66*sw), 31*sw,4 }; //  ,  //  ,  //-> en bas à droite de m4// "" 
SDL_Rect m7 = {520,25+(66*sw), 30*sw,4 }; //  ,  //  , //-> en bas à gauche de m5// "" 
SDL_Rect m8 = {153,290, 4,122 }; //  ,  //  , 	//-> en bas à droite du mur m6// "" 
SDL_Rect m9 = {515,290, 4,122 }; //  ,  //  , 	//-> en bas à droite du mur m7// "" 
SDL_Rect m10 = {4,411, 148,4 }; //  ,  //  ,  	//-> en bas à gauche de m8// "" 
SDL_Rect m11 = {520,411, 148,4 }; //  ,  //  , 	//-> en bas à droite de m9// "" 
SDL_Rect m12 = {4,449, 148,4 }; //  ,  //  ,  	//-> en bas de m10// ""
SDL_Rect m13 = {520,449, 148,4 }; //  ,  //  ,	//-> en bas de m11// ""
SDL_Rect m14 = {153,450, 4,122 }; //  ,  //  ,  //-> en bas à droite de m12// ""
SDL_Rect m15 = {515,450, 4,122 }; //  ,  //  ,  //-> en bas à gauche de m13// ""
SDL_Rect m16 = {28,571, 124,4 }; //  ,  //  ,  	//-> en bas à gauche de m14// ""
SDL_Rect m17 = {520,571, 124,4 }; //  ,  //  ,  //-> en bas à droite de m15 // ""
SDL_Rect m18 = {28,575, 4,102 }; //  ,  //  ,  	//-> en bas à gauche de m16// ""
SDL_Rect m19 = {641,575, 4,102 }; //  ,  //  ,  //-> en bas à droite de m17// ""
SDL_Rect m20 = {28,673, 61,4 }; //  ,  //  ,  	//-> en bas à droite de m18// ""
SDL_Rect m21 = {584,673, 61,4 }; //  ,  //  ,  	//-> en bas à gauche de m19// ""
SDL_Rect m22 = {89,675, 4,57 }; //  ,  //  ,  	//-> en bas à droite de m20// ""
SDL_Rect m23 = {579,675, 4,57 }; //  ,  //  ,  	//-> en bas à gauche de m21// ""
SDL_Rect m24 = {28,731, 61,4 }; //  ,  //  ,  	//-> en bas à gauche de m22// ""
SDL_Rect m25 = {584,731, 61,4 }; //  ,  //  ,  	//-> en bas à droite de m23// ""
SDL_Rect m26 = {28,733, 4,105 }; //  ,  //  ,  	//-> en bas à gauche de m24// ""
SDL_Rect m27 = {640,733 , 4,105 }; //  ,  //  , //-> en bas à droite de m25// ""
SDL_Rect m28 = { 28, 835, 154*4,4 }; // , // ,	//-> le mur tout en bas// ""

//***********************************VOIR POUR COMPRESSER LES FORMES DE PLUS DE 3 MURS EN CARRÉS exemple : m20-m25 = 2 carré
//**            idem pour 6-11 et 12-17*/

/*Il s'agit maintenant de bloc , on part d'en haut à gauche (puis on précise)*/

SDL_Rect b = {70,70, 85,85 }; //  ,  //  ,  //-> en haut à gauche 
SDL_Rect b1 = {198,70, 85,85 }; //  ,  //  ,  //-> à droite de b
SDL_Rect b2 = {390,70, 85,85 }; //  ,  //  ,  //-> à droite de b1
SDL_Rect b3 = {518,70, 85,85 }; //  ,  //  ,  //-> à droite de b2

SDL_Rect b4 = {70,198, 85,53 }; //  ,  //  ,  //-> en dessous de b
SDL_Rect b5 = {518,198, 85,53 }; //  ,  //  ,  //-> en dessous de b3

SDL_Rect b6 = {262,198, 148,53 }; //  ,  //  ,  //-> en dessous et entre b1 et b2
SDL_Rect b7 = {325,251, 22, 63 }; //  ,  //  ,  //-> en dessous de b6
SDL_Rect b8 = {198,198, 20,211 }; //  ,  //  ,  //-> en longueur en b4 et b6
SDL_Rect b9 = {454,198, 20,211 }; //  ,  //  ,  //-> à l'opposé de b8
SDL_Rect b10 = {218,294, 63,20 }; //  ,  //  ,  //-> à droite de b8
SDL_Rect b11 = {391,294, 63,20 }; //  ,  //  ,  //-> à gauche de b9
SDL_Rect b12 = {198,454, 20,115 }; //  ,  //  ,  //-> en dessous de b8
SDL_Rect b13 = {454,454, 20,115 }; //  ,  //  ,  //-> en dessous  de b9
SDL_Rect b14 = {262,518, 148,53 }; //  ,  //  ,  //-> entre b12 et b13
SDL_Rect b15 = {325,571, 22,63 }; //  ,  //  ,  //-> en dessous de b6}; //  ,  //  ,  //-> en dessous de b14 (pareil que b7)
SDL_Rect b16 = {198,613, 83,22 }; //  ,  //  ,  //-> à gauche de b15
SDL_Rect b17 = {390,613, 83,22 }; //  ,  //  ,  //-> à droite de b16
SDL_Rect b18 = {72,613, 83,22 }; //  ,  //  ,  //-> à gauche de b16
SDL_Rect b19 = {517,613, 83,22 }; //  ,  //  ,  //-> à droite de b17
SDL_Rect b20 = {133,635, 22,93 }; //  ,  //  ,  //-> en bas à droite de b18
SDL_Rect b21 = {517,635, 22,93 }; //  ,  //  ,  //-> en bas à gauche de b19
SDL_Rect b22 = {197,679, 22,96 }; // , // , //-> à droite de b20
SDL_Rect b23 = {453,679, 22,96 }; // , // , //-> à gauche de b21
SDL_Rect b24 = {71,773, 210,22 }; // , // , //-> en bas à gauche de b22
SDL_Rect b25 = {391,773, 210,22 }; // , // , //-> en bas à droite de b23
SDL_Rect b26 = {262,678, 148,53 }; // , // , //-> à droite de b22 , comme b6
SDL_Rect b27 = {325,731, 22,63 }; // , // , //-> en dessous de b26 , comme b7

//Cage des fantomes 
SDL_Rect b28 = {285,453, 105,22 }; // , // , //-> le bas de la cage des fantomes 
SDL_Rect b29 = {263,376, 22,95 }; // , // , //-> le coté gauche
SDL_Rect b30 = {388,376, 22,95 }; // , // , //-> le coté droit
SDL_Rect b31 = {264,358, 41,19 }; // , // , //-> en haut à gauche
SDL_Rect b32 = {367,358, 41,19 }; // , // , //-> en haut à droite

#endif // MURS_H //