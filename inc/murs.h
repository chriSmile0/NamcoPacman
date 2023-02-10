#ifndef MURS_H 
#define MURS_H
#include <SDL2/SDL.h>


//Il faut donc s'inspirer du tracer fait via les gums
//On part donc sur un x et  en haut de gauche de 32 et 32
//On peut faire le test en mettant des gums a ces endroits là 
//sw = scale_walls
int sw = 4;
//{x,y,w,h}
SDL_Rect m =  { 28,28, 154*sw,4 };  // 547 , 10 // 154 , 1 -> tout en haut sur all longueur // sur le gameboard actif -> peut importe lequel 
SDL_Rect m1 = {324,28, 4,30*sw }; // 620 , 10 // 1, 30  -> en haut le mur qui coupe m (gauche) // ""  
SDL_Rect m2 = {348,28, 4,30*sw }; // 627 , 10 // 1, 30  -> en haut le mur qui coupe m (droite) // "" 
SDL_Rect m3 = {323,154, 7*sw,4 }; // -> en haut entre m1 et m2
SDL_Rect m4 = { 28,28, 4,67*sw }; // 547 , 10 // 1, 66  -> en haut à gauche // "" 
SDL_Rect m5 = {640,28, 4,67*sw }; // 700 , 10 // 1, 66  -> en haut à droite // "" 
SDL_Rect m6 = { }; //  ,  //  ,  -> // "" 
SDL_Rect m7 = { }; //  ,  //  ,  -> // "" 
SDL_Rect m8 = { }; //  ,  //  ,  -> // "" 
SDL_Rect m9 = { }; //  ,  //  ,  -> // "" 
SDL_Rect m10 = { }; //  ,  //  ,  -> // "" 



SDL_Rect m99 = { 28, 835, 154*4,4 }; // 547 , 211 // 154 ,1  -> le mur tout en bas sur toute la longueur // "" 


//On va dejà test avec ces murs là 

#endif // MURS_H //