//gcc main.c $(sdl2-config --cflags --libs) -o prog
//gcc main.c -o prog -lSDL2 -lSDL2_image

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

//fichier perso
#include "header/constante.h"
#include "header/structure.h"
#include "header/hash.h"
#include "header/menu.h"


int main(int argc, char **argv) {
	
	
//INITIALISATION DES RESSOURCES
    
        //initialisation table de hachage
	hash_t tabh;
    cellule *elm = NULL;
    int i;
    tabh.taille = TAB_H_SIZE;/*taille de la table de hachage*/
    tabh.indice = calloc(TAB_H_SIZE, sizeof(cellule));/*memoire table de hachage*/
    
        // initialisation tableau de mot par thème
    char **tabm = malloc(NB_MOTS*sizeof(char *)); /*= tabm[NB_MOTS][50];*/
    for(i=0;i<NB_MOTS;i++){
        tabm[i]= malloc(50 * sizeof(char));
    }
    if (tabm == NULL)
    {
        printf("Échec de l'allocation\n");
        return EXIT_FAILURE;
    }
    
        //CHARGEMENT DES DONNEES
    recup_data("fichiers/mots.csv",&tabh,elm,tabm);
    printf("--------------------\n");
    affiche_table(&tabh,1,20);//on affiche la table de la ligne 1 à 20
    printf("--------------------\n");
    
        // initialise SDL
    CHECK_ERROR(SDL_Init(SDL_INIT_EVERYTHING) != 0, SDL_GetError());
    CHECK_ERROR(TTF_Init()== -1, TTF_GetError());
    
        // initialise TTF
    TTF_Font *police= NULL;
    police = TTF_OpenFont("src/font/times.ttf", 100);
    

        // Creation de la fenêtre
    SDL_Window *window = SDL_CreateWindow("Auvray-Nicolas-Jeu linguistique",
    										SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    										0, 0,
    										SDL_WINDOW_FULLSCREEN_DESKTOP);
    
    CHECK_ERROR((window == NULL), SDL_GetError());
        // dimensions fenêtre
    int width;
    int height;
    SDL_GetWindowSize(window,&width,&height);
        // création du rendu
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);    
    CHECK_ERROR(renderer == NULL, SDL_GetError());

/*DEBUT DU PROGRAMME*/
    logo(window,renderer,police,width,height);
    menu(window,renderer,police,tabh,tabm,width,height);
/*FIN DU PROGRAMME*/

        /*On Libere la mémoire*/
    for(i=0;i<NB_MOTS;i++){
        free(tabm[i]);
    }
    free(tabm);
    free(tabh.indice);

        /*On ferme les ressources*/
    TTF_CloseFont(police);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
