//
// Created by nicolas on 08/12/22.
//

#ifndef _MENU_H_
#define _MENU_H_

void affiche_menu(SDL_Window * window, SDL_Renderer * renderer, TTF_Font * font,char langue_aff[40],char nb_joueur_aff[40],char theme_aff[40],char difficulte_aff[40], SDL_Rect start, SDL_Rect quit, SDL_Rect fond, SDL_Rect facile, SDL_Rect moyen, SDL_Rect difficile, SDL_Rect info_nb_joueur, SDL_Rect info_langue, SDL_Rect info_theme, SDL_Rect info_difficulte, SDL_Rect france, SDL_Rect anglais, SDL_Rect allemand, SDL_Rect espagnol, SDL_Rect solo, SDL_Rect duo, SDL_Rect animaux, SDL_Rect fruits, SDL_Rect legumes, SDL_Rect metiers, SDL_Rect outils, SDL_Rect sports);
void menu(SDL_Window * window, SDL_Renderer * renderer, TTF_Font * police, hash_t tabh, char ** tabm, int width,int height);
void logo(SDL_Window * window, SDL_Renderer * renderer, TTF_Font * police, int width, int height);


#endif
