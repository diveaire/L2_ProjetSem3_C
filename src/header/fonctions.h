
#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

//fichier perso
#include "constante.h"

void affiche_image(SDL_Window * window, SDL_Renderer * renderer, char * link, SDL_Rect * rect);
int ClickDansRect(SDL_Rect rectangle,int X, int Y);
int randInt(int rmin, int rmax);
void affiche_parametre(SDL_Window * window, SDL_Renderer * renderer, TTF_Font * font, SDL_Color color, char * text, int max, SDL_Rect * rect);
void fillChar(char *chaine, int max);


#endif