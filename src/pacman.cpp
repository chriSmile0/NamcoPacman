#include "../inc/game.h"
#include "../inc/personnage.h"
#include "../inc/ghost.h"
#include "../inc/pacman.h"
#include "../inc/graine.h"
#include "../inc/recompense.h"

int coun;
/** @brief On va ici initialiser le board , avec sa window, sa sous fenêtre
 * 			et la planche que l'on doit "découper"
 * 			Enfin on crée les 5 personnages que sont les 4 fantomes et Pacman
 * 			Et on les placent sur leur point de départ
* @param{b} le board à init
* @return{none} 
*/
void init_board(Board *b)
{
	pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 1000, SDL_WINDOW_SHOWN);
	win_surf = SDL_GetWindowSurface(pWindow);

	plancheSprites = SDL_LoadBMP("../inc/pacman_sprites.bmp");
	coun = 0;

	SDL_SetColorKey(plancheSprites, false, 0);
	SDL_BlitScaled(plancheSprites, &src_b3, win_surf, &bg);

	Personnage g_r{&ghost_r,0,'r'}; //Utile_elem par Ghost
	g_r.set_start();
	Personnage g_p{&ghost_p,1,'p'};
	g_p.set_start();
	Personnage g_c{&ghost_c,2,'c'};
	g_c.set_start();
	Personnage g_y{&ghost_y,3,'y'};
	g_y.set_start();
	Personnage p{&pacman_p,4,'a'}; //Utile_elem par Pacman
	p.set_start();
	Recompense rp(cherry_r,Cerise,"Cerise",300);
	
	b->add_perso(g_r);
	b->add_perso(g_p);
	b->add_perso(g_c);
	b->add_perso(g_y);
	b->add_perso(p);
	b->add_awards(rp);//add à chaque niveau une récompense différente
	SDL_SetColorKey(plancheSprites, true, 0);
}

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		std::cerr <<"Echec de l'initialisation de la SDL "<<SDL_GetError() << std::endl;
		return 1;
	}
	
	Board gmboard{3};
	init_board(&gmboard);
	Game g{"jojo",&gmboard,pWindow,win_surf,plancheSprites};
	// BOUCLE PRINCIPALE
	bool quit = false;
	int cou = 0;
	while (!quit)
	{
		cou++;
		g.drawGums();
		g.drawGhostsAPac();
		g.drawAward();//fonctionne mais il faut la placer dans certaines condition
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
		int pac_hunt = 0;
		int capture_pac = 0;
		int ghosts_out = -1;
		if((pac_hunt = g.get_PacHuntime()) > 0)
			g.set_PacHuntime(++pac_hunt);
		
		if((ghosts_out = g.get_ghosts_out()) != -1)  //fonctionne
			if(capture_pac = (g.updateGhosts(g.get_board()->get_perso_with_index(4).get_x(),g.get_board()->get_perso_with_index(4).get_y(),ghosts_out))>=1) {
				if(capture_pac == 1)
					quit = true;
				else {
					cout << "pacman a capturer un fantome: "<< capture_pac << endl;	
					//Compteur les points que vaut un fantome passif
				}
			}
		// Gestion du clavier        
		int nbk;
		const Uint8* keys = SDL_GetKeyboardState(&nbk);
		if (keys[SDL_SCANCODE_ESCAPE])
			quit = true;
		if (keys[SDL_SCANCODE_LEFT]) 
			g.updatePacman(-6,0,'g');
		if (keys[SDL_SCANCODE_RIGHT]) 
			g.updatePacman(6,0,'d');
		if (keys[SDL_SCANCODE_DOWN]) 
			g.updatePacman(0,6,'b');
		if (keys[SDL_SCANCODE_UP]) 
			g.updatePacman(0,-6,'h');
		//Sortie auto des fantomes 
		if((cou == 50) || (g.get_board()->get_perso_with_index(0).get_time_house()==50)) 
			g.exit_ghost(0); 
		else if((cou == 130)|| (g.get_board()->get_perso_with_index(1).get_time_house()==130))
			g.exit_ghost(1);
		else if((cou == 180) || (g.get_board()->get_perso_with_index(2).get_time_house()==180))
			g.exit_ghost(2);
		else if((cou == 240) || (g.get_board()->get_perso_with_index(3).get_time_house()==240))
			g.exit_ghost(3);
		
		SDL_SetColorKey(plancheSprites, true, 0);

		SDL_UpdateWindowSurface(pWindow); 
		// LIMITE A 60 FPS
		SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
	}
	SDL_Quit(); // ON SORT
	cout << g.get_pts() << endl;
	return 0;
}