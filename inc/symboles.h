#ifndef SYMBOLES_H 
#define SYMBOLES_H
#include <SDL2/SDL.h>

//Boards
SDL_Rect selectuu = {355,390,32,32};//g.get_board()->get_elem_with_index(2).get_val_elem();
SDL_Rect src_b1 = { 200,3, 168,216 }; // x,y, w,h (0,0) en haut a gauche
SDL_Rect src_b2 = { 370,3, 168,216 }; // x,y, w,h (0,0) en haut a gauche
SDL_Rect src_b3 = { 540,3, 168,216 }; // x,y, w,h (0,0) en haut a gauche
SDL_Rect bg = { 0,0, 672,864 }; // ici scale x4

//Ghosts 

SDL_Rect ghost_rr1 = { 3,123, 16,16 }; 
SDL_Rect ghost_rr2 = { 20,123, 16,16 };
SDL_Rect ghost_rl1 = { 37,123, 16,16 };
SDL_Rect ghost_rl2 = { 54,123, 16,16 };
SDL_Rect ghost_rd1 = { 71,123, 16,16 };
SDL_Rect ghost_rd2 = { 87,123, 16,16 };
SDL_Rect ghost_ru1 = {105,123, 16,16 };
SDL_Rect ghost_ru2 = {122,123, 16,16 };

SDL_Rect ghost_pr1 = { 3,141, 16,16 };
SDL_Rect ghost_pr2 = { 20,141, 16,16 };
SDL_Rect ghost_pl1 = { 37,141, 16,16 };
SDL_Rect ghost_pl2 = { 54,141, 16,16 };
SDL_Rect ghost_po1 = { 71,141, 16,16 };
SDL_Rect ghost_po2 = { 87,141, 16,16 };
SDL_Rect ghost_pu1 = {105,141, 16,16 };
SDL_Rect ghost_pu2 = {122,141, 16,16 }; 

SDL_Rect ghost_cr1 = { 3,159, 16,16 };
SDL_Rect ghost_cr2 = { 20,159, 16,16 };
SDL_Rect ghost_cl1 = { 37,159, 16,16 };
SDL_Rect ghost_cl2 = { 54,159, 16,16 };
SDL_Rect ghost_co1 = { 71,159, 16,16 };
SDL_Rect ghost_co2 = { 87,159, 16,16 };
SDL_Rect ghost_cu1 = {105,159, 16,16 };
SDL_Rect ghost_cu2 = {122,159, 16,16 }; 

SDL_Rect ghost_yr1 = { 3,177, 16,16 };
SDL_Rect ghost_yr2 = { 20,177, 16,16 };
SDL_Rect ghost_yl1 = { 37,177, 16,16 };
SDL_Rect ghost_yl2 = { 54,177, 16,16 };
SDL_Rect ghost_yo1 = { 71,177, 16,16 };
SDL_Rect ghost_yo2 = { 87,177, 16,16 };
SDL_Rect ghost_yu1 = {105,177, 16,16 };
SDL_Rect ghost_yu2 = {122,177, 16,16 }; 

SDL_Rect ghost_b1 = { 3,195, 16,16 };
SDL_Rect ghost_b2 = { 20,195, 16,16 };
SDL_Rect ghost_w1 = { 37,195, 16,16 };
SDL_Rect ghost_w2 = { 54,195, 16,16 };
SDL_Rect ghost_bkr = { 71,195, 16,16 };
SDL_Rect ghost_bkl = { 87,195, 16,16 };
SDL_Rect ghost_bkd = {105,195, 16,16 };
SDL_Rect ghost_bku = {122,195, 16,16 };

//In board
SDL_Rect ghost = { 34,34, 32,32 };     // ici scale x2
SDL_Rect ghost_r = (ghost_rr1);
SDL_Rect ghost_p = (ghost_pr1);
SDL_Rect ghost_c = (ghost_cr1);
SDL_Rect ghost_y = (ghost_yr1);
SDL_Rect pacman_p = { 3,89, 16,16 };
//Start 
SDL_Rect ghost_rstart = { 321,381, 32,32 };    
SDL_Rect ghost_pstart = { 291,416, 32,32 };     
SDL_Rect ghost_cstart = { 321,416, 32,32 };    
SDL_Rect ghost_ystart = { 351,416, 32,32 };
//Start pacman 
SDL_Rect pacman_start = { 321,481, 32,32 };

//Ghost Exit -> behind to front of the door
SDL_Rect ghost_free = { 321,326, 32,32 };


//Pacmans

SDL_Rect bpacman_c = { 3,218, 32,32 }; // bigpacman
SDL_Rect bpacman_co = { 36,218, 32,32 }; //bigpacman
SDL_Rect bpacman_o = { 68,218, 32,32 }; //bigpacman

SDL_Rect lpacman_c = { 3,89, 16,16 };
SDL_Rect lpacman_cor = { 20,89, 16,16 };
SDL_Rect lpacman_or = { 35,89, 12,16 };
SDL_Rect lpacman_col = { 47,89, 15,16 };
SDL_Rect lpacman_ol = { 62,89, 12,16 };
SDL_Rect lpacman_cod = { 75,89, 16,16 };
SDL_Rect lpacman_od = { 92,89, 16,16 };
SDL_Rect lpacman_cou = { 109,89, 16,16 };
SDL_Rect lpacman_ou = { 126,93, 16,13 };

//Letters 
SDL_Rect letter_a = { 11,60, 9,9 };
SDL_Rect letter_b = { 19,60, 9,9 };
SDL_Rect letter_c = { 27,60, 9,9 };
SDL_Rect letter_d = { 35,60, 9,9 };
SDL_Rect letter_e = { 43,60, 9,9 };
SDL_Rect letter_f = { 51,60, 9,9 };
SDL_Rect letter_g = { 59,60, 9,9 };
SDL_Rect letter_h = { 67,60, 9,9 };
SDL_Rect letter_i = { 75,60, 9,9 };
SDL_Rect letter_j = { 83,60, 9,9 };
SDL_Rect letter_k = { 91,60, 9,9 };
SDL_Rect letter_l = { 99,60, 9,9 };
SDL_Rect letter_m = {107,60, 9,9 };
SDL_Rect letter_n = {115,60, 9,9 };
SDL_Rect letter_o = {123,60, 9,9 };
SDL_Rect letter_p = { 3,68,  9,9 };
SDL_Rect letter_q = { 11,68, 9,9 };
SDL_Rect letter_r = { 19,68, 9,9 };
SDL_Rect letter_s = { 27,68, 9,9 };
SDL_Rect letter_t = { 35,68, 9,9 };
SDL_Rect letter_u = { 43,68, 9,9 };
SDL_Rect letter_v = { 51,68, 9,9 };
SDL_Rect letter_w = { 59,68, 9,9 };
SDL_Rect letter_x = { 67,68, 9,9 };
SDL_Rect letter_y = { 75,68, 9,9 };
SDL_Rect letter_z = { 83,68, 9,9 };
SDL_Rect letter_poi = { 91, 68, 9,9 };
SDL_Rect letter_arr = { 99, 68, 9,9 };
SDL_Rect ex_pt = { 100,51, 10,9 };
SDL_Rect comma = { 107,51, 10,9 };  
SDL_Rect dbl_quote = { 124,69, 7,8 };

//Digits 
SDL_Rect digit_0 = { 3,52,  9,9 }; 
SDL_Rect digit_1 = { 10,52, 9,9 }; 
SDL_Rect digit_2 = { 18,52, 9,9 }; 
SDL_Rect digit_3 = { 27,52, 9,9 }; 
SDL_Rect digit_4 = { 35,52, 9,9 }; 
SDL_Rect digit_5 = { 43,52, 9,9 }; 
SDL_Rect digit_6 = { 50,52, 9,9 }; 
SDL_Rect digit_7 = { 58,52, 9,9 }; 
SDL_Rect digit_8 = { 67,52, 9,9 }; 
SDL_Rect digit_9 = { 75,52, 9,9 }; 


//Ope
SDL_Rect minus = { 83,52, 9,9 };
SDL_Rect divi = { 90,52, 9,9 };

//Score = Gain of Points (Pts)
SDL_Rect sc_pts = { 176,211, 18,7 };
SDL_Rect sc_PTS = { 176,204, 18,7 };
SDL_Rect sc_10 = { 150,210, 9,8 };
SDL_Rect sc_50 = { 161,210, 9,8 };
SDL_Rect sc_100 = { 179,132, 15,9 };
SDL_Rect sc_200 = { 154,175, 16,9 };
SDL_Rect sc_300 = { 179,141, 15,9 };
SDL_Rect sc_400 = { 154,184, 16,9 };
SDL_Rect sc_500 = { 179,150, 15,9 };
SDL_Rect sc_700 = { 179,159, 15,9 };
SDL_Rect sc_800 = { 154,193, 16,9 };
SDL_Rect sc_1000 = { 176,168, 18,9 };
SDL_Rect sc_1600 = { 152,202, 18,9  };
SDL_Rect sc_2000 = { 176,177, 18,9 };
SDL_Rect sc_3000 = { 176,186, 18,9 };
SDL_Rect sc_5000 = { 176,195, 18,9 };


//Fruits 
SDL_Rect cherry_o = { 288,238, 15,13 };
SDL_Rect cherry_r = { 288,257, 15,13 };
SDL_Rect strawberry_o = { 305,238, 15,13 };
SDL_Rect strawberry_r = { 305,257, 15,13 };
SDL_Rect orange_y = { 320,238, 15,13 };
SDL_Rect orange_o = { 320,257, 15,13 };
SDL_Rect apple_b = { 336,238, 15,13 };
SDL_Rect apple_r = { 336,257, 15,13 };
SDL_Rect melon_o = { 353,236, 15,14 };
SDL_Rect melon_g = { 353,256, 15,14 };
SDL_Rect galboss_o = { 369,237, 15,13 };
SDL_Rect galboss_r = { 369,257, 15,13 };
SDL_Rect bell_y = { 386,236, 14,16 };
SDL_Rect bell_o = { 386,257, 14,16 };
SDL_Rect key_r = { 404,235, 9,15 };
SDL_Rect key_b = { 404,256, 9,15 };

//Gum 
SDL_Rect bgum = { 8,78,  9,9 };
SDL_Rect lgum = { 4,81,  2,2 };

//Logos
SDL_Rect editor = { 26,77, 64,10 };
SDL_Rect game_name = { 3,3, 182,47 };


#endif // SYMBOLES_H //