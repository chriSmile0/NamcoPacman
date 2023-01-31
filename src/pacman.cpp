#include "../inc/symboles.h"
#include <iostream>
using namespace std;

SDL_Window* pWindow = nullptr;
SDL_Surface* win_surf = nullptr;
SDL_Surface* plancheSprites = nullptr;


int count;

void init()
{
	pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN);
	win_surf = SDL_GetWindowSurface(pWindow);

	plancheSprites = SDL_LoadBMP("../inc/pacman_sprites.bmp");
    count = 0;

    SDL_SetColorKey(plancheSprites, false, 0);
    SDL_BlitScaled(plancheSprites, &src_b3, win_surf, &bg);

    SDL_Rect ghost_r = (ghost_rr1);
    SDL_Rect ghost_p = (ghost_cr1);
    SDL_Rect ghost_c = (ghost_pr1);
    SDL_Rect ghost_o = (ghost_or1);

    SDL_BlitScaled(plancheSprites, &ghost_r, win_surf, &ghost_rstart);
    SDL_BlitScaled(plancheSprites, &ghost_p, win_surf, &ghost_pstart);
    SDL_BlitScaled(plancheSprites, &ghost_c, win_surf, &ghost_cstart);
    SDL_BlitScaled(plancheSprites, &ghost_o, win_surf, &ghost_ostart);
    SDL_SetColorKey(plancheSprites, true, 0);
    //Affichage des 4 fantomes aux centres 
}

void exit_ghost(char ghost_name) { // r,p,c,o
    SDL_SetColorKey(plancheSprites, false, 0);
    SDL_BlitScaled(plancheSprites, &src_b3, win_surf, &bg);
    SDL_Rect ghost_r = (ghost_rr1);
    SDL_Rect ghost_p = (ghost_cr1);
    SDL_Rect ghost_c = (ghost_pr1);
    SDL_Rect ghost_o = (ghost_or1);
    SDL_Rect* ghost_choice = nullptr;
    switch (ghost_name) {
        case 'r':
            ghost_choice = &(ghost_rr1);
            SDL_BlitScaled(plancheSprites, &ghost_p, win_surf, &ghost_pstart);
            SDL_BlitScaled(plancheSprites, &ghost_c, win_surf, &ghost_cstart);
            SDL_BlitScaled(plancheSprites, &ghost_o, win_surf, &ghost_ostart);
            break;
        case 'p':
            ghost_choice = &(ghost_pr1);
            SDL_BlitScaled(plancheSprites, &ghost_r, win_surf, &ghost_rstart);
            SDL_BlitScaled(plancheSprites, &ghost_c, win_surf, &ghost_cstart);
            SDL_BlitScaled(plancheSprites, &ghost_o, win_surf, &ghost_ostart);
            break;
        case 'c':
            ghost_choice = &(ghost_cr1);
            SDL_BlitScaled(plancheSprites, &ghost_p, win_surf, &ghost_pstart);
            SDL_BlitScaled(plancheSprites, &ghost_r, win_surf, &ghost_rstart);
            SDL_BlitScaled(plancheSprites, &ghost_o, win_surf, &ghost_ostart);
            break;
        case 'o':
            ghost_choice = &(ghost_or1);
            SDL_BlitScaled(plancheSprites, &ghost_p, win_surf, &ghost_pstart);
            SDL_BlitScaled(plancheSprites, &ghost_c, win_surf, &ghost_cstart);
            SDL_BlitScaled(plancheSprites, &ghost_r, win_surf, &ghost_rstart);
            break;
    }
    SDL_BlitScaled(plancheSprites, ghost_choice, win_surf, &ghost_free);
    SDL_SetColorKey(plancheSprites, true, 0);
    cout << "Sortie du fantome : " << ghost_name << " " << endl;

    
    /*else {
        exit(EXIT_FAILURE);
        cout << "Erreur sur le choix du fantome à sortir" << endl;
    }*/
}


// fonction qui met à jour la surface de la fenetre "win_surf"
void draw()
{
    SDL_SetColorKey(plancheSprites, false, 0);
    SDL_BlitScaled(plancheSprites, &src_b3, win_surf, &bg);

    // petit truc pour faire tourner le fantome
    SDL_Rect* ghost_in = nullptr;
    switch (count/128)
    {
        case 0:
            ghost_in = &(ghost_rr1);
            ghost.x++;
            break;
        case 1:
            ghost_in = &(ghost_rd1);
            ghost.y++;
            break;
        case 2:
            ghost_in = &(ghost_rl1);
            ghost.x--;
            break;
        case 3:
            ghost_in = &(ghost_ru1);
            ghost.y--;
            break;
    }
    count =(count+1)%(512);

    // ici on change entre les 2 sprites sources pour une jolie animation.
    SDL_Rect ghost_in2 = *ghost_in;
    if ((count/4)%2)
        ghost_in2.x += 17;
        
    // couleur transparente
    SDL_SetColorKey(plancheSprites, true, 0);
    // copie du sprite zoomé
	SDL_BlitScaled(plancheSprites, &ghost_in2, win_surf, &ghost);
}



int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
		std::cerr <<"Echec de l'initialisation de la SDL "<<SDL_GetError() << std::endl;
		return 1;
    }

	init();
    // BOUCLE PRINCIPALE
	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			default: break;
			}
		}

        // Gestion du clavier        
        int nbk;
        const Uint8* keys = SDL_GetKeyboardState(&nbk);
        if (keys[SDL_SCANCODE_ESCAPE])
            quit = true;
        if (keys[SDL_SCANCODE_LEFT])
            puts("LEFT");
        if (keys[SDL_SCANCODE_RIGHT])
            puts("RIGHT");
        if (keys[SDL_SCANCODE_DOWN])
            exit_ghost('o');

        // AFFICHAGE
		/*draw();*/
		SDL_UpdateWindowSurface(pWindow); 
        // LIMITE A 60 FPS
		SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
	}
    SDL_Quit(); // ON SORT
    return 0;
}
