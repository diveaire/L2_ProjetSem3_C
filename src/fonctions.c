//gcc main.c $(sdl2-config --cflags --libs) -o prog
//gcc main.c -o prog -lSDL2 -lSDL2_image

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "header/constante.h"



      /*            Fonctions
         *
         * randInt----------------> Génère un nb aléatoire entre min et max
         * affiche_image----------> Affiche une image dans un rectangle
         * fillChar---------------> Ajoute n espaces à la fin d'une chaine (pour un affichage lisible avec SDL_TTF)
         * affiche_parametre------> Affiche une chaine dans un rectangle
         * ClickDansRect----------> Retourne 1 si les coordonnées x,y sont dans le rectangle sinon 0
         *
      */




    //nombre aléatoire(min/max)
int randInt(int rmin, int rmax) {
    return rand() % (rmax-rmin) + rmin;
}
    //fonction permettant d'afficher une image dans un rectangle
void affiche_image(SDL_Window * window, SDL_Renderer * renderer, char * link, SDL_Rect * rect){
	SDL_Surface *surf = IMG_Load(link);
	SDL_Texture *img = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	CHECK_ERROR(SDL_RenderCopy(renderer,img,NULL,rect) != 0,SDL_GetError());
}
    //remplis la chaine de max char
void fillChar(char *chaine, int max){
	while (strlen(chaine) < max){
			strcat(chaine," ");
	}
}
	//Affiche une chaine dans un rectangle
void affiche_parametre(SDL_Window * window, SDL_Renderer * renderer, TTF_Font * font, SDL_Color color, char * text, int max, SDL_Rect * rect){
	fillChar(text,max);
	SDL_Surface * surface = TTF_RenderText_Solid(font,text, color);
	SDL_Texture * texte = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	CHECK_ERROR(SDL_RenderCopy(renderer,texte,NULL,rect) != 0,SDL_GetError());
}

    //Retourne 1 si les coordonnées x,y sont dans le rectangle sinon 0
int ClickDansRect(SDL_Rect rectangle,int X, int Y){
    if( Y > rectangle.y
    && Y <= rectangle.y+rectangle.h
    && X > rectangle.x
    && X <= rectangle.x+rectangle.w
    ){
        return 1;
    }else{
        return 0;
    }
}