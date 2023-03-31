#include "../inc/game.h"
#include "../inc/personnage.h"
#include "../inc/ghost.h"
#include "../inc/pacman.h"
#include "../inc/graine.h"
#include "../inc/recompense.h"

int coun;


void init_board(Board *b)
{
	pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 672, 864, SDL_WINDOW_SHOWN);
	win_surf = SDL_GetWindowSurface(pWindow);

	plancheSprites = SDL_LoadBMP("../inc/pacman_sprites.bmp");
	coun = 0;

	SDL_SetColorKey(plancheSprites, false, 0);
	SDL_BlitScaled(plancheSprites, &src_b3, win_surf, &bg);

	SDL_BlitScaled(plancheSprites, &ghost_rr1, win_surf, &ghost_rstart);
	SDL_BlitScaled(plancheSprites, &ghost_pr1, win_surf, &ghost_pstart);
	SDL_BlitScaled(plancheSprites, &ghost_cr1, win_surf, &ghost_cstart);
	SDL_BlitScaled(plancheSprites, &ghost_yr1, win_surf, &ghost_ystart);
	SDL_BlitScaled(plancheSprites, &lpacman_c, win_surf, &pacman_start);

	
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
	/*b->add_elem(g_r);
	b->add_elem(g_p);
	b->add_elem(g_c);
	b->add_elem(g_y);
	b->add_elem(p);

	cout << b->get_elem_with_index(0).get_val_elem().x << endl;*/

	b->add_perso(g_r);
	b->add_perso(g_p);
	b->add_perso(g_c);
	b->add_perso(g_y);
	b->add_perso(p);

	cout << b->get_perso_with_index(0).get_val_elem().x << endl;
	g_r.change_pos(15,16);
	cout << b->get_perso_with_index(0).get_val_elem().x << endl;
	//init_walls(b);
	SDL_SetColorKey(plancheSprites, true, 0);
	//Affichage des 4 fantomes aux centres et du pacman
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
	Game g("jojo",&gmboard,pWindow,win_surf,plancheSprites);
	

	int out_ghosts[4] = {-1};
	int ghosts_out = -1;

	gmboard.sort_gums_by_xy();
	char sens_r = 'd';
	char sens_p = 'd';
	char sens_c = 'd';
	char sens_y = 'd';
	char sens_pac = 'd';
	char *sens_ghosts[5] = {&sens_r,&sens_p,&sens_c,&sens_y,&sens_pac};//un peu overkill , on pourrais juste suppr les sens_ et mettre
	g.set_tabsens(sens_ghosts);



	int status_r = -1;
	int status_p = -1;
	int status_c = -1;
	int status_y = -1;
	int status_pac = -1;
	int *status_ghosts[5] = {&status_r,&status_p,&status_c,&status_y,&status_pac};
	g.set_tabstatus(status_ghosts);

	status_r = 3;
	cout << g.get_status(0) << endl;//fonctionne*/

	cout << g.get_board()->get_perso_with_index(0).get_val_elem().x << endl;
	g.get_board()->get_perso_with_index(0).change_pos(155,40);
	cout << g.get_board()->get_perso_with_index(0).get_val_elem().x << endl;

	//direct des 'd'/'g' dans le tableau 
	// BOUCLE PRINCIPALE
	bool quit = false;
	int cou = 0;
	int cou_g[4];
	while (!quit)
	{
		cou++;
		cou_g[0]++;
		cou_g[1]++;
		cou_g[2]++;
		cou_g[3]++;
		g.drawGums();
		g.drawGhostsAPac(*sens_ghosts,*status_ghosts);
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
		if((pac_hunt = g.get_PacHuntime()) > 0)
			g.set_PacHuntime(++pac_hunt);

		if(ghosts_out != -1)  //fonctionne
			if((capture_pac = g.updateGhosts(g.get_board()->get_perso_with_index(4).get_x(),g.get_board()->get_perso_with_index(4).get_y(),*sens_ghosts,ghosts_out,*status_ghosts)) >= 1) {
				cout << "pachunttime :: <<" << g.get_PacHuntime() << endl;
				if(g.get_PacHuntime() == 0)
					quit = true;
				else {
					g.get_board()->set_startGhost(capture_pac-1);
					g.set_status(capture_pac-1,0);
					cou_g[capture_pac-1] = 0;
					out_ghosts[capture_pac-1] = -1;
					cout << "capture d'un fantome " << endl;
					//Ok mais il faut remettre le compteur de sortie pour chaque fantome
					//afin qu'il ne ressorte pas de suite , mais sinon cela fonctionne
				}

			}
				//else
					//capture ghost 
		// Gestion du clavier        
		int nbk;
		const Uint8* keys = SDL_GetKeyboardState(&nbk);
		if (keys[SDL_SCANCODE_ESCAPE])
			quit = true;
		if (keys[SDL_SCANCODE_LEFT]) {
			g.updatePacman(-6,0,*sens_ghosts[4],'g');
		}

		if (keys[SDL_SCANCODE_RIGHT]) {
			g.updatePacman(6,0,*sens_ghosts[4],'d');
		}

		if (keys[SDL_SCANCODE_DOWN]) {
			g.updatePacman(0,6,*sens_ghosts[4],'b');
		}

		if (keys[SDL_SCANCODE_UP]) {
			g.updatePacman(0,-6,*sens_ghosts[4],'h');
		}

		//Sortie auto des fantomes 
		if((cou == 50) || (cou_g[0] == 50)) {
			cout << "gg" << g.get_board()->get_perso_with_index(0).get_val_elem().y << endl;
			//g.exit_ghost(0);
			g.get_board()->get_perso_with_index(0).change_pos(150,150);
			cout << "bfg" << g.get_board()->get_perso_with_index(0).get_val_elem().y << endl;
			out_ghosts[0]++;
			ghosts_out++;
			puts("Exit Rouge");
		}
		else if((cou == 130) || (cou_g[1] == 130)) {
			g.exit_ghost(1);
			out_ghosts[1]++;
			ghosts_out++;
			puts("Exit Rose");
		}
		else if((cou == 180) || (cou_g[2] == 180)) {
			g.exit_ghost(2);
			out_ghosts[2]++;
			ghosts_out++;
			puts("Exit Cyan");
		}
		else if((cou == 240)  || (cou_g[3] == 240)){
			g.exit_ghost(3);
			out_ghosts[3]++;
			ghosts_out++;
			puts("Exit Jaune");
		}
		SDL_SetColorKey(plancheSprites, true, 0);

		// AFFICHAGE
		//draw();
		SDL_UpdateWindowSurface(pWindow); 
		// LIMITE A 60 FPS
		SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
	}
	SDL_Quit(); // ON SORT
	return 0;
}