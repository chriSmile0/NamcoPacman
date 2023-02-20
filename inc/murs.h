#ifndef MURS_H 
#define MURS_H
#include <SDL2/SDL.h>


//Il faut donc s'inspirer du tracer fait via les gums
//On part donc sur un x et  en haut de gauche de 32 et 32
//On peut faire le test en mettant des gums a ces endroits là 
//sw = scale_walls
int sw = 4;
int d_p = 24; //dim_perso -> dimension de pacman

//Attention il faut aussi gérer le mur en fonction de la taille du perso
//Pour le moment si on enleve 25 sur le mur m6 cela fonctionne mais il faut trouver un moyen de 
//de le faire en automatique en fonction du perso 

//{x,y,w,h}
SDL_Rect m =  { 28,28, 154*sw,8 };  // ,  // , //-> tout en haut sur all longueur // sur le gameboard actif -> peut importe lequel 
SDL_Rect m1 = {320,28, 8,30*sw }; //  ,  //  , //-> en haut le mur qui coupe m (gauche) // ""   m1/m2/m3 à remplacer par un bloc
SDL_Rect m2 = {348,28, 8,30*sw }; //  ,  //  , //-> en haut le mur qui coupe m (droite) // "" 
SDL_Rect m3 = {315-d_p,149, (10*sw)+d_p,8 }; //  ,  //  , //-> en haut entre m1 et m2
SDL_Rect m4 = { 28,28, 8,67*sw }; //  ,  //  , //-> en haut à gauche // "" 
SDL_Rect m5 = {640,28, 8,67*sw }; //  ,  //  , //-> en haut à droite // "" 
SDL_Rect m6 = {28,25+(66*sw), 31*sw,8 }; //  ,  //  ,  //-> en bas à droite de m4// "" 
SDL_Rect m7 = {520-d_p,25+(66*sw), (30*sw)+d_p,8 }; //  ,  //  , //-> en bas à gauche de m5// "" 
SDL_Rect m8 = {153,288-d_p, 8,122+d_p }; //  ,  //  , 	//-> en bas à droite du mur m6// "" 
SDL_Rect m9 = {513,288-d_p, 8,122+d_p }; //  ,  //  , 	//-> en bas à droite du mur m7// "" 
SDL_Rect m10 = {4,411, 148,8 }; //  ,  //  ,  	//-> en bas à gauche de m8// "" 
SDL_Rect m11 = {520-d_p,411, 148+d_p,8 }; //  ,  //  , 	//-> en bas à droite de m9// "" 
SDL_Rect m12 = {4,449, 148,8 }; //  ,  //  ,  	//-> en bas de m10// ""
SDL_Rect m13 = {520-d_p,449, 148+d_p,8 }; //  ,  //  ,	//-> en bas de m11// ""
SDL_Rect m14 = {153,450-d_p, 4,122+d_p }; //  ,  //  ,  //-> en bas à droite de m12// ""
SDL_Rect m15 = {513,450-d_p, 8,122+d_p }; //  ,  //  ,  //-> en bas à gauche de m13// ""
SDL_Rect m16 = {28,571, 124,4 }; //  ,  //  ,  	//-> en bas à gauche de m14// ""
SDL_Rect m17 = {520-d_p,571, 124+d_p,8 }; //  ,  //  ,  //-> en bas à droite de m15 // ""
SDL_Rect m18 = {28,575, 4,102 }; //  ,  //  ,  	//-> en bas à gauche de m16// ""
SDL_Rect m19 = {639,575, 4,102 }; //  ,  //  ,  //-> en bas à droite de m17// ""
SDL_Rect m20 = {28,673, 61,4 }; //  ,  //  ,  	//-> en bas à droite de m18// ""
SDL_Rect m21 = {584-d_p,673, 61+d_p,8 }; //  ,  //  ,  	//-> en bas à gauche de m19// ""
SDL_Rect m22 = {89,675, 4,57 }; //  ,  //  ,  	//-> en bas à droite de m20// ""
SDL_Rect m23 = {579,673-d_p, 8,57+d_p }; //  ,  //  ,  	//-> en bas à gauche de m21// ""
SDL_Rect m24 = {28,731, 61,4 }; //  ,  //  ,  	//-> en bas à gauche de m22// ""
SDL_Rect m25 = {584-d_p,731, 61+d_p,8 }; //  ,  //  ,  	//-> en bas à droite de m23// ""
SDL_Rect m26 = {28,733, 4,105 }; //  ,  //  ,  	//-> en bas à gauche de m24// ""
SDL_Rect m27 = {639,730 , 4,105 }; //  ,  //  , //-> en bas à droite de m25// ""
SDL_Rect m28 = { 28, 835, 154*4,4 }; // , // ,	//-> le mur tout en bas// ""

//***********************************VOIR POUR COMPRESSER LES FORMES DE PLUS DE 3 MURS EN CARRÉS exemple : m20-m25 = 2 carré
//**            idem pour 6-11 et 12-17*/

/*Il s'agit maintenant de bloc , on part d'en haut à gauche (puis on précise)*/

SDL_Rect b = {64-d_p,64-d_p ,92+d_p,90+d_p }; //  ,  //  ,  //-> en haut à gauche 
SDL_Rect b1 = {192-d_p,64-d_p, 92+d_p,90+d_p }; //  ,  //  ,  //-> à droite de b
SDL_Rect b2 = {384-d_p,64-d_p, 92+d_p,90+d_p }; //  ,  //  ,  //-> à droite de b1
SDL_Rect b3 = {512-d_p,64-d_p, 92+d_p,90+d_p }; //  ,  //  ,  //-> à droite de b2

SDL_Rect b4 = {64-d_p,192-d_p, 92+d_p,58+d_p }; //  ,  //  ,  //-> en dessous de b
SDL_Rect b5 = {512-d_p,192-d_p, 92+d_p,58+d_p }; //  ,  //  ,  //-> en dessous de b3

SDL_Rect b6 = {256-d_p,192-d_p, 155+d_p,58+d_p}; //  ,  //  ,  //-> en dessous et entre b1 et b2
SDL_Rect b7 = {319-d_p,245-d_p, 27+d_p, 68+d_p }; //  ,  //  ,  //-> en dessous de b6
SDL_Rect b8 = {192-d_p,192-d_p, 25+d_p,216+d_p }; //  ,  //  ,  //-> en longueur en b4 et b6
SDL_Rect b9 = {448-d_p,192-d_p, 25+d_p,216+d_p }; //  ,  //  ,  //-> à l'opposé de b8
SDL_Rect b10 = {212-d_p,288-d_p, 68+d_p,25+d_p }; //  ,  //  ,  //-> à droite de b8
SDL_Rect b11 = {385-d_p,288-d_p, 68+d_p,25+d_p }; //  ,  //  ,  //-> à gauche de b9
SDL_Rect b12 = {192-d_p,448-d_p, 25+d_p,120+d_p }; //  ,  //  ,  //-> en dessous de b8
SDL_Rect b13 = {448-d_p,448-d_p, 25+d_p,120+d_p }; //  ,  //  ,  //-> en dessous  de b9
SDL_Rect b14 = {256-d_p,512-d_p, 153+d_p,58+d_p }; //  ,  //  ,  //-> entre b12 et b13
SDL_Rect b15 = {319-d_p,565-d_p, 27+d_p,68+d_p }; //  ,  //  ,  //-> en dessous de b6}; //  ,  //  ,  //-> en dessous de b14 (pareil que b7)
SDL_Rect b16 = {192-d_p,607-d_p, 88+d_p,27+d_p }; //  ,  //  ,  //-> à gauche de b15
SDL_Rect b17 = {384-d_p,607-d_p, 88+d_p,27+d_p }; //  ,  //  ,  //-> à droite de b16
SDL_Rect b18 = {66-d_p,607-d_p, 88+d_p,27+d_p }; //  ,  //  ,  //-> à gauche de b16
SDL_Rect b19 = {511-d_p,607-d_p, 88+d_p,27+d_p }; //  ,  //  ,  //-> à droite de b17
SDL_Rect b20 = {127-d_p,629-d_p, 27+d_p,98+d_p }; //  ,  //  ,  //-> en bas à droite de b18
SDL_Rect b21 = {511-d_p,629-d_p, 27+d_p,98+d_p }; //  ,  //  ,  //-> en bas à gauche de b19
SDL_Rect b22 = {191-d_p,673-d_p, 27+d_p,101+d_p }; // , // , //-> à droite de b20
SDL_Rect b23 = {447-d_p,673-d_p, 27+d_p,101+d_p }; // , // , //-> à gauche de b21
SDL_Rect b24 = {65-d_p,767-d_p, 215+d_p,27+d_p }; // , // , //-> en bas à gauche de b22
SDL_Rect b25 = {385-d_p,767-d_p, 215+d_p,27+d_p }; // , // , //-> en bas à droite de b23
SDL_Rect b26 = {256-d_p,672-d_p, 155+d_p,58+d_p }; // , // , //-> à droite de b22 , comme b6
SDL_Rect b27 = {319-d_p,725-d_p, 27+d_p,68+d_p }; // , // , //-> en dessous de b26 , comme b7

//Cage des fantomes 
SDL_Rect b28 = {279-d_p,447-d_p, 110+d_p,27+d_p }; // , // , //-> le bas de la cage des fantomes 
SDL_Rect b29 = {257-d_p,370-d_p, 27+d_p,100+d_p }; // , // , //-> le coté gauche
SDL_Rect b30 = {382-d_p,370-d_p, 27+d_p,100+d_p }; // , // , //-> le coté droit
SDL_Rect b31 = {258-d_p,352-d_p, 46+d_p,24+d_p }; // , // , //-> en haut à gauche
SDL_Rect b32 = {361-d_p,352-d_p, 46+d_p,24+d_p }; // , // , //-> en haut à droite

#endif // MURS_H //