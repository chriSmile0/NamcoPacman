#include "../inc/game.h"
#include "../inc/personnage.h"
#include "../inc/ghost.h"
#include "../inc/pacman.h"
#include "../inc/graine.h"
#include "../inc/recompense.h"

SDL_Window* pWindow = nullptr;
SDL_Surface* win_surf = nullptr;
SDL_Surface* plancheSprites = nullptr;


int count;

void init_seeds()
{	
	//On évite le surplus et la superposition de graine 
	//en signifiant que les graines sont toutes à la verticales
	//Ce n'est donc que elles qui comptent 
	//On saute donc sur x toutes celle qui pourrait faire office de croisement
	
	//On fait pour le moment une version simple sans classe 
	int x = 38;
	int y = 40;
	int w = 20;
	int h = 20;
	// *********************************************Les horizontales *************************************************//
	for(int i = 0 ; i < 21 ; i++) {
		if ((i != 5) && (i != 10) && (i != 15) && (i != 20)){
			SDL_Rect seed = (lgum);// ou bgum 
			SDL_Rect emplacement{x,y,w,h};
			SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		}
		else if (i == 10) {
			x += 75;
		}


		x += 25;
	}
	//La seconde horizontale en partant d'en haut à gauche
	y = 40+(25*5); 
	x = 38+25;
	for(int i = 0 ; i < 23 ; i++) {
		if(i == 14)
			x += 5;

		if((i != 4) &&  (i != 7) && (i != 14) && (i!= 17) && (i != 22)){
			SDL_Rect seed = (lgum);// ou bgum 
			SDL_Rect emplacement{x,y,w,h};
			SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		}
		x += 25;
	}
	//La troisième horizontale en partant d'en haut à gauche
	y = 40+(25*9);
	x = 38+25;
	for(int i = 0 ; i < 23 ; i++) {
		// a opti ici -> trop de comparaison à faire 
		if((i != 4) && (i != 5) && (i != 6) && (i != 7) && (i != 10) && (i != 11) && (i != 14) &&  (i != 15) && (i != 16) && (i!= 17) && (i != 22)){
			SDL_Rect seed = (lgum);// ou bgum 
			SDL_Rect emplacement{x,y,w,h};
			SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		}
		x += 25;
	}
	//La quatrième horizontale en partant d'en haut à gauche 
	y = 50+(25*11);
	x = 63+(25*8);
	for(int i = 0 ; i < 6 ; i++) {


		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		x += 25;
	}

	//La cinquième horizontale en partant d'en haut à gauche
	y = 35+(25*22); 
	x = 38+25;
	for(int i = 0 ; i < 23 ; i++) {
		if(i == 19)
			x += 10;
		if((i != 4) &&  (i != 7) && (i != 10) && (i != 11) &&  (i != 14) && (i != 17) && (i != 22)){
			SDL_Rect seed = (lgum);// ou bgum 
			SDL_Rect emplacement{x,y,w,h};
			SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		}
		x += 25;
	}

	//La sizième horizontale en partant d'en haut à gauche
	y = 40+(25*24); 
	x = 38+25;
	for(int i = 0 ; i < 23 ; i++) {
		if(i == 18)
			x += 10;
		if((i != 2) && (i!= 3) && (i!= 4) &&  (i != 7) && (i != 14) && (i != 17) && (i != 18) && (i != 19) && (i != 22)){
			SDL_Rect seed = (lgum);// ou bgum 
			SDL_Rect emplacement{x,y,w,h};
			SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		}
		x += 25;
	}
	//La septieme horizontale en partant d'en haut à gauche
	y = 40+(25*28);
	x = 38+25;
	for(int i = 0 ; i < 23 ; i++) {
		// a opti ici -> trop de comparaison à faire 
		if(i == 19)
			x += 10;
		if((i != 4) && (i != 5) && (i != 6) && (i != 7) && (i != 10) && (i != 11) && (i != 14) &&  (i != 15) && (i != 16) && (i!= 17) && (i != 19) && (i != 22)){
			SDL_Rect seed = (lgum);// ou bgum 
			SDL_Rect emplacement{x,y,w,h};
			SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		}
		x += 25;
	}

	//La huitième horizontale en partant d'en haut à gauche
	y = 40+(25*30)+15;
	x = 38+25;
	for(int i = 0 ; i < 23 ; i++) {
		// a opti ici -> trop de comparaison à faire 
		if(i == 14)
			x += 5;
		if(i == 16)
			x -= 5;
		if((i != 2) && (i != 4) && (i != 7) && (i != 14)  && (i!= 17) && (i != 19) && (i != 22)){
			SDL_Rect seed = (lgum);// ou bgum 
			SDL_Rect emplacement{x,y,w,h};
			SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		}
		x += 25;
	}
	//L'horizontale central (sous la cage)
	y = 40+(25*18)-5;
	x = 38+(25*9);
	for(int i = 0 ; i < 6 ; i++) {
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		x += 25;
	}
	



	// ************************************Les verticales********************************************************************** //
	//La verticale en haut à gauche
	x = 38;
	y = 40;
	for(int i = 0 ; i < 10 ; i++) {
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 25;
	}


	//Verticale 2 et 5 (en partant de en haut à gauche)
	x = 38+(25*5);
	y = 40;
	//La verticale en haut à gauche numéro 2
	for(int i = 0 ; i < 30 ; i++) {
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		if(i == 20)
			y -= 5;
		if(i == 22)
			y += 5;
		if(i == 28)
			y += 40;
		y += 25;
	}
	x = 38+(25*18);
	y = 40;
	//La verticale en haut à gauche numéro 5
	for(int i = 0 ; i < 30 ; i++) {
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		if(i == 20)
			y -= 5;
		if(i == 22)
			y += 5;
		if(i == 28)
			y += 40;
		y += 25;
	}
	//La verticale en haut à droite
	x = 38+(25*23);
	y = 40;
	for(int i = 0 ; i < 10 ; i++) {
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 25;
	}
	//La verticale numéro 3 partant de haut à gauche 
	x = 38+(25*8);
	y = 40+(25*5);
	for(int i = 0 ; i < 25 ; i++) {
		if ((i==5) || (i == 15))
			y += 10;
		if (i == 17)
			y += 5;

		if(i == 24)
			y += 15;

		if ((i != 5) && (i != 17) && (i != 23)) {
			SDL_Rect seed = (lgum);// ou bgum 
			SDL_Rect emplacement{x,y,w,h};
			SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		}
		y += 25;
	}
	//La verticale numéro 6 partant de haut à gauche 
	x = 43+(25*15);
	y = 40+(25*5);
	for(int i = 0 ; i < 25 ; i++) {
		if ((i==5) || (i == 15))
			y += 10;
		if (i == 17)
			y += 5;

		if(i == 24)
			y += 15;

		if ((i != 5) && (i != 17) && (i != 23)) {
			SDL_Rect seed = (lgum);// ou bgum 
			SDL_Rect emplacement{x,y,w,h};
			SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		}
		y += 25;
	}

	//La verticale numero 7 en partant d'en bas à gauche 


	//La verticale numéro 4 partant d'en haut à gauche
	x = 38+(25*10);
	y = 40;
	for(int i = 0 ; i < 5 ; i++) {
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 25;
	}
	//La verticale numéro 6 partant d'en haut à gauche
	x = 38+(25*13);
	y = 40;
	for(int i = 0 ; i < 5 ; i++) {
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 25;
	}

	//Les verticales numéro 0 et 8 en partant d'en bas à gauche
	//0
	x = 38;
	y = 40+(25*22)-5;
	for(int i = 0 ; i < 10 ; i++) {
		if(i==2)
			y += 5;
		if(i==9)
			y -= 8;
		if(( i < 3) || (i > 5)) {
			SDL_Rect seed = (lgum);// ou bgum 
			SDL_Rect emplacement{x,y,w,h};
			SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		}
		y += 25;
	}
	//8
	x = 38+(25*23)+5;
	y = 40+(25*22)-5;
	for(int i = 0 ; i < 10 ; i++) {
		if(i==2)
			y += 5;
		if(i==9)
			y -= 8;
		if(( i < 3) || (i > 5)) {
			SDL_Rect seed = (lgum);// ou bgum 
			SDL_Rect emplacement{x,y,w,h};
			SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		}
		y += 25;
	}
	//Les verticales 1 et 8 en partant d'en bas à gauche 
	//1
	x = 38+(25*3);
	y = 40+(25*24);
	for(int i = 0 ; i < 6 ; i++) {
		if(i == 5)
			y += 40;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 25;
	}
	//8
	x = 38+(25*20)+10;
	y = 40+(25*24);
	for(int i = 0 ; i < 6 ; i++) {
		if(i == 5)
			y += 40;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 25;
	}



}

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


	//Init seeds
	init_seeds();

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
	Board gmboard{3};
	Game g("jojo",&gmboard,pWindow,win_surf,plancheSprites);
	Ghost g2{ghost_rstart};

	Ghost g3{"ghosting"};

	Pacman pocman;
	gmboard.add_elem(pocman);

	pocman.set_nom("POCMAN");

	gmboard.add_elem(g3);

	gmboard.add_elem(g2);

	SDL_Rect lgomme{1,78,8,8};
	SDL_Rect bgomme{8,78,9,9};

	Graine seed1{lgomme};

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
		if (keys[SDL_SCANCODE_DOWN]) {
			SDL_Rect *rec = nullptr;
			rec = (g.get_board()->get_elem_with_index(2).get_ptr_elem());
			g.get_board()->get_elem_with_index(2).set_x((rec->x)+5);
			g.update_pos_of_elem(2,5,0,1);
		}

		if (keys[SDL_SCANCODE_1]) {
			puts("1");
		}
		if (keys[SDL_SCANCODE_2]) {
			puts("2");
		}
		if (keys[SDL_SCANCODE_Q]) {
			puts("A in QWERTY");
			seed1.hideSeed();
		}


		// AFFICHAGE
		//draw();
		SDL_UpdateWindowSurface(pWindow); 
		// LIMITE A 60 FPS
		SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
	}
	SDL_Quit(); // ON SORT*/
	return 0;
}