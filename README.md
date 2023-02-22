# projet_pacman
Ce projet est réalisé dans le cadre de l'UE de programmation avancée qui se voit être une  
introduction au C++ mais en version accélérée avec un projet qui demande du temps et un  
certain respect de toutes les bases et de tout les mécanismes du C++ et des facilités  
du C++ **_moderne_** que propose ce langage.  

Vous trouverez un Makefile qui permet de compiler , et d'éxécuter le jeu pacman   
recodé par mes soins dans la version la plus proche possible du pacman Namco de 1980.
Ainsi qu'une cible pour clean **_proprement_** les éxécutables C++.  

J'ai donc réalisé ce projet seul à partir du 31 Janvier 2023 jusqu'au 10 Mai 2023 -> Date de la soutenance    
Je soutiens avoir réalisé ce projet seul sans collaboration avec quiconque ni avec aucun outil d'aide   
de type communautaire (ChatGPT, GitHub Copilot).  
Si j'ai utilisé une source pour une citation pour écrire ce document elle sera écrite en bas de page.  

## Release 
Chaque merge sur main de cette branche représente une **_Étape_** symbolique du projet   
Cette branche sert donc au développement concret du projet sans impacté le travail   
qui a été fait précédemment qui est déjà validé par mes soins. 

Vous trouverez ci-après la gestion du projet avec des versions préventives de l'avancée du travail 
avec un planning en fonction de mon ressenti pour crée les fonctionnalités du jeu pacman.  

*** 

## Main 
- **V1**   
    - Découpage de l'image de sprites  
    - Compréhension du système des images qui s'effacent et réapparaissent  
    - compilation et éxécution portable  
    - Placement des fantômes dans leur case de départ  
    - 0 implémentation c++  

- **V2**   
    - Début des premiers objets -> (Utile_Elem | Map | Board | Game)  
    - Bouchon sur des objets futurs -> (Pacman | Ghost | Graine | Récompense)  
    - Création des gums + mise en place visuelle   
    - Mouvement des élements -> Pacman + Ghosts   
    - Attrape Gums (graine.h + board.h) -> symboliquement sur la map et dans le board (pas de compteur des points (bouchons))  
    - Création des murs -> murs.h + affichage -> map.h  
    - Détection des murs (hitWall -> map.h)   
    - Déplacement de Pacman de manière fluide et bloquante (hit wall)  
    - Déplacement + ou - aléatoire du fantome rouge    

- **V3**   
    - Déplacements de tout les fantomes   
    - Mise à jour à chaque tour de tout le plateau   
    - Tentative d'incrustation de bGum -> déclenchement du mode bleu/blanc des fantomes   
        - Bleu = shy -> ils veulent échapper à pacman et non plus le capturé  
        - Blanc/Bleu -> Préviens que les fantomes vont bientôt retourné dans leur état de base  
        - Si capture pendant bleu/blanc alors mode noir sur le fantome = retour à la case des fantomes  


- **V4**   
    - Mise en forme d'objet + clair , fini les SDL_Rect simple  
    - Vérification d'un c++ cohérent et MODERNE (via les TPS)

- **V5**   
    - Mise en place des points + récompense sur la map et en bas (visualisation des fruits)  
    - Visualisation du nombre de vies de pacman  
    - Mise en place des niveaux   
    - Update des comportements et de la map en fonction du niveau   

- **V6**   
    - Commentaires des fonctions  
    - Crée une simulation (qui fera office de test simple mais complet) des déplacements de pacman  
    - Check des tabs et création d'une forme de convention de codage  

- **V7**   
    - Optimatisation possible du code (sans changements trop importants)  
        - Redondance de code + ou - similaire  
        - Passage par des objets supérieurs de type hérité.
        - Maximiser les ternaires
    - Check des consignes du sujet  

- **V8**  
    - Potentielle version finale 

***

## Sources   
...  