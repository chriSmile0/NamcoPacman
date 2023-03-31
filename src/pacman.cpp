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
	
	b->add_perso(g_r);
	b->add_perso(g_p);
	b->add_perso(g_c);
	b->add_perso(g_y);
	b->add_perso(p);

	/*for(Personnage p : b->get_tab_perso())
		p.set_start();*/ // Fait des persos trop petit 
	
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

	/*int a = 2;
	vector<int> vec;
	vec.push_back(a);
	a = 3;
	cout << "a :" << a << endl;
	cout << "vec a : " << vec.at(0) << endl;

	int aa = 2;
	vector<int*> vec_a;
	vec_a.push_back(&aa);
	aa = 3;
	cout << "aa :" << aa << endl;
	cout << "vec a : " << *(vec_a.at(0)) << endl;

	Utile_elem ue;
	cout << ue.get_x() << endl;
	ue.set_x(70);
	cout << ue.get_x() << endl;

	Board b{3};
	b.add_elem(ue);
	cout << b.get_elem_with_index(0).get_x() << endl;
	ue.set_x(120);
	cout << b.get_elem_with_index(0).get_x() << endl;
	b.set_elem_with_index(0,'x',50);
	cout << b.get_elem_with_index(0).get_x() << endl;*/

	
	Board gmboard{3};
	init_board(&gmboard);
	Game g("jojo",&gmboard,pWindow,win_surf,plancheSprites);

	gmboard.sort_gums_by_xy();
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
		g.drawGhostsAPac();
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
				else 
					cout << "pacman a capturer un fantome" << endl;	
			}
		// Gestion du clavier        
		int nbk;
		const Uint8* keys = SDL_GetKeyboardState(&nbk);
		if (keys[SDL_SCANCODE_ESCAPE])
			quit = true;
		if (keys[SDL_SCANCODE_LEFT]) {
			g.updatePacman(-6,0,'g');
		}

		if (keys[SDL_SCANCODE_RIGHT]) {
			g.updatePacman(6,0,'d');
		}

		if (keys[SDL_SCANCODE_DOWN]) {
			g.updatePacman(0,6,'b');
		}

		if (keys[SDL_SCANCODE_UP]) {
			g.updatePacman(0,-6,'h');
		}

		//Sortie auto des fantomes 
		if((cou == 50) || (cou_g[0] == 50)) {
			g.exit_ghost(0);
			//g.get_board()->change_pos_perso(0,20,100); -> fonctionne aussi 
			puts("Exit Rouge");
		}
		else if((cou == 130) || (cou_g[1] == 130)) {
			g.exit_ghost(1);
			puts("Exit Rose");
		}
		else if((cou == 180) || (cou_g[2] == 180)) {
			g.exit_ghost(2);
			puts("Exit Cyan");
		}
		else if((cou == 240)  || (cou_g[3] == 240)){
			g.exit_ghost(3);
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