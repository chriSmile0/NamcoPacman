#include "../inc/game.h"

Game::Game()
{
    player_name = "no_name";
}

Game::Game(string name , Board* b)
{
    player_name = name;
    boar = b;

}

Game::Game(string name, Board* b, SDL_Window* w, SDL_Surface* s, SDL_Surface* pl) 
{
	player_name = name;
	boar = b;
	win = w;
	win_surface = s;
	sprites_planches = pl;
    init_seeds();
	pac_huntime_limit = 300;
	//init_walls();
    //b->sort_gums_by_xy();
}

void Game::init_walls()
{
	//Voir pour ensuite confondre la map dans le jeu en entier 
	int nb_murs = boar->getMap().getMurs().size();
	for(int i = 0 ; i < nb_murs; i++) {
		SDL_Rect seed = (lgum);// pour simuler le mur 
		SDL_Rect *mur = (boar->getMap().getMur_with_index(i));
		SDL_BlitScaled(plancheSprites, &seed, win_surf, mur);
	}
}

void Game::init_seeds()
{	
	//On évite le surplus et la superposition de graine 
	//en signifiant que les graines sont toutes à la verticales
	//Ce n'est donc que elles qui comptent 
	//On saute donc sur x toutes celle qui pourrait faire office de croisement

		
	//On fait pour le moment une version simple sans classe 

    /* il y'a 197 gums et il faut 4 grosses gums , on va en placer une toutes les 45 gums
    */


	int x = 46+(32); // reference pour les horizontales
	int y = 46;		//+32 aussi pour les verticales
	int w = 6; // *3
	int h = 6; // *3
    int i = 0;
	// *********************************************Les horizontales *************************************************//
	for(i = 0 ; i < 12 ; i++) {
		if((i == 3) || (i == 9))
			x += 32;
		if(i == 6)
			x += 96;
		boar->add_gum(Graine{x,y,w,h,0});
		x += 32;
	}
	//PLACEMENT DANS LE BOARD//

	//La seconde horizontale en partant d'en haut à gauche
	y = 46+(32*4); 
	x = 46+(32);
	for(i = 0 ; i < 11 ; i++) {
		if((i == 3) || (i == 4) || (i == 5) || (i == 6) || (i == 7) || (i == 8))
			x += 32;
		boar->add_gum(Graine{x,y,w,h,0});
		x += 32;
	}
	//La troisième horizontale en partant d'en haut à gauche
	y = 46+(32*7);
	x = 46+(32);
	for(i = 0 ; i < 8 ; i++) {
		if((i == 3) || (i == 4) || (i == 5))
			x += 96; //saut de 3 cases
		boar->add_gum(Graine{x,y,w,h,0});
		x += 32;
	}
	//La quatrieme horizontale 
	y = 46+(32*17);
	x = 46+(32);
	for(i = 0 ; i < 8 ; i++) {
		// a opti ici -> trop de comparaison à faire 
		if((i == 1) || (i == 2) || (i == 3) || (i == 5) || (i == 6) || (i == 7))
			x += 32; //saut de 1 case
		if(i == 4)
			x += 96;
		boar->add_gum(Graine{x,y,w,h,0});
		x += 32;
	}
	//La cinquieme horizontale 
	y = 46+(32*19);
	x = 46+(32);
	for(i = 0 ; i < 7 ; i++) {
		if((i == 2) || (i == 3) || (i == 4) || (i == 5))
			x += 32; //saut de 1 case
		if((i == 1) || (i == 6))
			x += 96;
		boar->add_gum(Graine{x,y,w,h,0});
		x += 32;
	}
	//La sizieme horizontale en partant d'en haut à gauche
	y = 46+(32*22);
	x = 46+(32);
	for(i = 0 ; i < 6 ; i++) {
		if((i == 2) || (i == 3) || (i == 4))
			x += 96;
		if((i == 1) || (i == 5))
			x += 32;
		boar->add_gum(Graine{x,y,w,h,0});
		x += 32;
	}	
	//La septieme 
	y = 46+(32*24);
	x = 46+(32);
	for(i = 0 ; i < 9 ; i++) {
		if((i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5) || (i == 6)
			|| (i == 7) || (i == 8))
			x += 32;
		boar->add_gum(Graine{x,y,w,h,0});
		x += 32;
	}

	// ************************************Les verticales********************************************************************** //
	//La verticale en haut à gauche
	x = 46;
	y = 46;
	for(i = 0 ; i < 14 ; i++) {
		if(i == 8)
			y += 32*9;
		if(i == 11)
			y += 64;
		 SDL_Rect emplacement{x,y,w,h};
        if((i == 2) || (i == 8)) {
            emplacement.w = 24;
            emplacement.h = 24;
            emplacement.x -= 10;
            emplacement.y -= 10;
        }
		boar->add_gum(Graine{emplacement,1});
		y += 32;
	}
	//La seconde verticale en partant de la gauche 
	x = 46+(32*4);
	y = 46;
	for(i = 0 ; i < 24 ; i++) {
		if(i == 23)
			y += 32;
		boar->add_gum(Graine{x,y,w,h,0});
		y += 32;
	}
	//La troisieme verticale en partant de la gauche 
	x = 46+(32*6);
	y = 46+(32*4);
	for(i = 0 ; i < 10 ; i++) {
		if(i == 4) 
			y += 32*9;
		if((i == 5) || (i == 9))
			y += 32;
        boar->add_gum({x,y,w,h,0});
		y += 32;
	}
	//La quatrième verticale en partant de la gauche 
	x = 46+(32*8);
	y = 46;
	for(i = 0 ; i < 12 ; i++) {
		if((i == 5) || (i == 9))
			y += 64;
		if(i == 6)
			y += 32*9;
		boar->add_gum({x,y,w,h,0});
		y += 32;
	}
	//La cinquième = quatrième verticale en partant de la gauche
	x = 46+(32*10);
	y = 46;
	for(i = 0 ; i < 12 ; i++) {
		if((i == 5) || (i == 9))
			y += 64;
		if(i == 6)
			y += 32*9;
		boar->add_gum({x,y,w,h,0});
		y += 32;
	}
	//La sizieme = troisieme verticale en partant de la gauche 
	x = 46+(32*12);
	y = 46+(32*4);
	for(i = 0 ; i < 10 ; i++) {
		if(i == 4) 
			y += 32*9;
		if((i == 5) || (i == 9))
			y += 32;
		boar->add_gum({x,y,w,h,0});
		y += 32;
	}
	//La septieme = deuxieme verticale en partant de la gauche
	x = 46+(32*14);
	y = 46;
	for(i = 0 ; i < 24 ; i++) {
		if(i == 23)
			y += 32;
		boar->add_gum({x,y,w,h,0});
		y += 32;
	}
	//La verticale en haut à droite
	x = 46+(32*18);
	y = 46;
	for(i = 0 ; i < 14 ; i++) {
		if(i == 8)
			y += 32*9;
		if(i == 11)
			y += 64;
        SDL_Rect emplacement{x,y,w,h};
        if((i == 2) || (i == 8)){
            emplacement.w = 24;
            emplacement.h = 24;
            emplacement.x -= 10;
            emplacement.y -= 7;
        }
		boar->add_gum(Graine{emplacement,1});
		y += 32;
	}
	//Verticales du bas de la MAP
	//La deuxieme en partant de la gauche
	x = 46+(32*2);
	y = 46+(32*17);
	for(i = 0 ; i < 6 ; i++) {
		if((i == 1) || (i == 5))
			y += 32;
		boar->add_gum({x,y,w,h,0});
		y += 32;
	}
	//La deuxieme en partant de la droite -> similaire à celle de la gauche 
	x = 46+(32*16);
	y = 46+(32*17);
	for(i = 0 ; i < 6 ; i++) {
		if((i == 1) || (i == 5))
			y += 32;
		boar->add_gum({x,y,w,h,0});
		y += 32;
	}
}


int Game::moveGhost(int x_pac, int y_pac, char sens, int index, int statut)
{
    int g_x = boar->get_perso_with_index(index).get_x();
    int g_y = boar->get_perso_with_index(index).get_y();
    int distance = 6;//distance de déplacement des fantomes

    int new_x = g_x;//à changer en fonction de la position de pacman
    int new_y = g_y;// "" "" 
    char sens_potentiel_x = (x_pac < g_x) ? 'g' : 'd'; 
    char sens_potentiel_y = (y_pac < g_y) ? 'h' : 'b';

    char result_hitwal = 'f';
    int i = 0;
    int rtn = 0;
    if(sens == 'b') {
        new_x = g_x;
        new_y = (statut >= 1) ? (g_y - distance/2) : (g_y + distance);
    }
    if(sens == 'd') {
        new_x = (statut >= 1) ? (g_x - distance/2) : (g_x + distance);
        new_y = g_y;
    }
    if(sens == 'g') {
        new_x = (statut >= 1) ? (g_x + distance/2) : (g_x - distance);
        new_y = g_y;
    }
    if(sens == 'h') {
        new_x = g_x;
        new_y = (statut >= 1) ? (g_y + distance/2) : (g_y - distance);
    }

    result_hitwal = boar->getMap().hitWall(g_x,g_y,new_x,new_y,24);
    
    if(result_hitwal == 'f'){ //debut
		rtn = catchPacman(new_x,new_y,x_pac,y_pac,sens);
		if((statut == 1) && (rtn)){
			cout << "maison fantme" << endl;
			rtn = 2;
		}

    }
    else {
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(0, 3);
        int valeur_random =  distrib(gen);
        char new_sens = 'f';
        switch(valeur_random) {
            case 0: new_sens = 'd';
                break;
            case 1: new_sens = 'g';
                break;
            case 2: new_sens = 'b';
                break;
            case 3: new_sens = 'h';
                break;
            default : 
                break;
        }
        new_x = g_x;
        new_y = g_y;
    
        if(sens == 'g') {
            if(new_sens == 'd')
                new_sens = sens_potentiel_y;//On influence en fonction de la position de pacman
        }
        else if(sens == 'd') {
            if(new_sens == 'g')
                new_sens = sens_potentiel_y;
        }
        else if(sens == 'h') {
            if(new_sens == 'b')
                new_sens = sens_potentiel_x;
        }
        else if(sens == 'b') {
            if(new_sens == 'h')
                new_sens = sens_potentiel_x;
        }
        sens = new_sens;
    }

	boar->set_perso_with_sens_idx(index,sens);
    boar->change_pos_perso(index,new_x,new_y);
	if(rtn == 2) boar->home_ghosts(index);
    return rtn;
}
// attaque directement Pac Man. Il suit Pac-Man comme son ombre.
/*
- 
*/
int Game::updateRedGhost(int x_pac, int y_pac)
{
	char sens = boar->get_perso_with_index(0).get_sens();
	int statut = boar->get_perso_with_index(3).get_statut();
    return moveGhost(x_pac,y_pac,sens,0,statut);
    /*Fonctionne mais ne prend pas les intervalles, c'est à dire ne fonctionne que dans les coins
        pour le moment, il faut trouver un moyen de faire aller dans un sens encore plus aléatoire
        en fonction de certain espace
    - En tout cas fonctiionne bien pour les coins de la map car on va dans une direction , on ne peut pas
    aller dans celle d'où l'on viens ni l'inverse donc on va forcément dans le dernier sens possible 
    */
}

// a tendance à se mettre en embuscade. Elle vise l'endroit où va se trouver Pac-Man.
/*
-
*/
int Game::updatePinkGhost(int x_pac, int y_pac)
{
	char sens = boar->get_perso_with_index(1).get_sens();
	int statut = boar->get_perso_with_index(1).get_statut();
    return moveGhost(x_pac,y_pac,sens,1,statut);
}

// De temps en temps, il part dans la direction opposée à Pac-Man.
/*
-
*/
int Game::updateCyanGhost(int x_pac, int y_pac)
{
	char sens = boar->get_perso_with_index(2).get_sens();
	int statut = boar->get_perso_with_index(2).get_statut();
    return moveGhost(x_pac,y_pac,sens,2,statut);
}

//De temps en temps, il choisit une direction au hasard (qui peut être celle de Pac-Man).
/*
-
*/
int Game::updateYellowGhost(int x_pac, int y_pac)
{
	char sens = boar->get_perso_with_index(3).get_sens();
	int statut = boar->get_perso_with_index(3).get_statut();
    return moveGhost(x_pac,y_pac,sens,3,statut);
}

void Game::updatePacman(int x_pac, int y_pac,char s) 
{
    int new_x = x_pac;
	int new_y = y_pac;
	char sens = boar->get_perso_with_index(4).get_sens();
    SDL_Rect add_rect = boar->get_perso_with_index(4).get_val_elem();
	new_x += add_rect.x;
	new_y += add_rect.y;
	
    char result_hitwal = 'x';
    if((result_hitwal = boar->getMap().hitWall(add_rect.x,add_rect.y,new_x,new_y,24)) != 'f') {//((new_x > 610) || (new_y > 800) || (new_y < 28) || (new_x < 28)) {//murs provisoires
        switch(result_hitwal) {//ajustement de la position de pacman lorsque l'on tape un mur (pour revenir dans droit chemin !!)
			case 'h': add_rect.y += 6;
				break;
			case 'b': add_rect.y -= 6;
				break;
			case 'g': add_rect.x += 6;
				break;
			case 'd': add_rect.x -= 6;
				break;
			default: 
				break;
		}
		new_x = add_rect.x;
        new_y = add_rect.y;
    }
    else {
        int gum_catch = boar->catch_gum(add_rect.x,add_rect.y,new_x,new_y);
        //Test du catch ball 	

		//Update des ghosts en fonction du type de gum 
		if(boar->getGum_with_index(gum_catch).get_w() == 24) {
			//bgum
			//Tout les ghosts (qui sont dehors ) en mode bleu/blanc
			for(int i = 0 ; i < 4; i++)  {
				boar->set_perso_with_statut_idx(i,1);
			}
				//set_status(i,1); //a continuer dans updateGhost aussi en fonction du statut
			
			pac_huntime = 1;
		}
		else {
			//lgum -> rien à faire de spécial juste update le score
		}
		
		sens = sens_of_walk(add_rect.x,add_rect.y,new_x,new_y,s,1);
		if((new_x < 0) && (new_y < 420+20) && (new_y > 420-20)) {
			new_x = 700;
			sens = 'g';
		}
		else if((new_x > 680) && (new_y < 420+20) && (new_y > 420-20)) {
			new_x = 0;
			sens = 'd';
		}
		boar->set_perso_with_sens_idx(4,sens);
		boar->change_pos_perso(4,new_x,new_y);
    }
}


// fonction qui met à jour la surface de la fenetre "win_surf"
int Game::updateGhosts(int x_pac, int y_pac, int ghosts_out)
{
	//Faire tourner les fantomes 
    if(updateRedGhost(x_pac,y_pac)==1)
        return 1;
    if(ghosts_out > 0)
        if(updatePinkGhost(x_pac,y_pac)==1)
            return 2;
    if(ghosts_out > 1)
        if(updateCyanGhost(x_pac,y_pac)==1)
            return 3;
    if(ghosts_out > 2)
        if(updateYellowGhost(x_pac,y_pac)==1)
            return 4;
    return 0;
}


char Game::sens_of_walk(int x_old,int y_old, int x, int y,char base_sens, int g_or_p)//g_or_p = ghost_or_pacman ; 0 pour g, 1 pour pacman
{
    int x_m_nx = x - x_old;
	int y_m_ny = y - y_old;
	char sens = ((x_m_nx != 0) ? ((x_m_nx < 0) ? 'g': 'd') : ((y_m_ny < 0) ? 'h': 'b'));
    if((x_m_nx == 0) && (y_m_ny == 0))
        sens = base_sens;//no sens
    return sens;
}

int Game::catchPacman(int x_ghost, int y_ghost, int x_pac, int y_pac, char &sens) //Mis en pause car implemter dans updateGhost
{//test après chaque update de ghost et pacman si il y'a contact entre un fantomes et pacman
    int l_box = x_pac;
    int u_box = y_pac;
    int r_box = x_pac+24;//24 = dim_perso
    int d_box = y_pac+24;// "" ""
	switch(sens) {
		case 'g': 
			return (((x_ghost <= r_box) && (x_ghost >= l_box)) && ((y_ghost >= u_box-10) && (y_ghost <= d_box+10)));
		case 'd':
			return (((x_ghost <= r_box) && (x_ghost >= l_box)) && ((y_ghost >= u_box-10) && (y_ghost <= d_box+10)));
		case 'h':
			return (((x_ghost <= r_box+10) && (x_ghost >= l_box-10)) && ((y_ghost >= u_box) && (y_ghost <= d_box)));
		case 'b':
			return (((x_ghost <= r_box+10) && (x_ghost >= l_box-10)) && ((y_ghost >= u_box) && (y_ghost <= d_box)));
		default:
			return 0;
	}
}


void Game::exit_ghost(int idx) 
{ // r,p,c,o
	ghosts_out++;
	boar->exit_ghosts(idx);
}

void Game::go_home_ghost(int idx) 
{
	ghosts_out--;
	boar->home_ghosts(idx);
}

void Game::drawGums()
{
	SDL_SetColorKey(sprites_planches, false, 0);//On efface tout 
	SDL_BlitScaled(sprites_planches, boar->get_gameboard(), win_surface, &bg);

    int nb_gums = boar->get_gums().size();
    for(int i = 0 ; i < nb_gums ; i++) {
        SDL_Rect gum = (boar->getGum_with_index(i).get_val_elem());
        if((gum.h > 0) && (gum.h < 7)) //lgum limite a 6 de taille
            SDL_BlitScaled(sprites_planches, &(lgum), win_surface, &gum);
		else if(gum.h > 6) //bgum de taille sup à 6 (> lgum)
			SDL_BlitScaled(sprites_planches,&(bgum),win_surface, &gum); 
    }
}

void Game::drawGhostsAPac()
{
	for (int i = 0 ; i < 5; i++) {
		Personnage select_p = boar->get_perso_with_index(i);
        SDL_Rect save_elem = boar->get_perso_with_index(i).get_val_elem();//boar->getGhost_with_index(i);//boar->get_elem_with_index(i).get_val_elem();
		if((select_p.get_statut() == 1) && (pac_huntime >= 0.75*pac_huntime_limit)) {
			boar->set_perso_with_statut_idx(i,2);
		}
		else if((select_p.get_statut() == 2) && (pac_huntime >= pac_huntime_limit)) {
			boar->set_perso_with_statut_idx(i,0);
			if(i == 4) //on attend la fin de la boucle pour stopper la chasse
				pac_huntime = 0;
		}
        SDL_Rect *skin_choice = boar->get_perso_with_index(i).get_Skin();//boar->getGhost_with_index(i);//ghosts.at(i);//(boar->get_elem_with_index(i).get_val_elem());
        SDL_BlitScaled(sprites_planches, skin_choice, win_surface, &save_elem);
    }
}

Game::~Game()
{

}