
#ifndef _JEU_H_
#define _JEU_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "structure.h"

void make_link(char link[100],char * theme, int number, char * mot);
int make_score(int temps, int nb_erreur);
void remplir_mot(char mot[50], char mot_histo[10][50]);
void update_champs(SDL_Window * window, SDL_Renderer *renderer, TTF_Font *police, int max, char * mot_aff,char * phrase, SDL_Rect fond, SDL_Rect quit, SDL_Rect choix, SDL_Rect text, SDL_Rect champ_text,SDL_Rect delete);
void remplir_champs(SDL_Window * window, SDL_Renderer *renderer, TTF_Font *police,int width, int height,int *quitter, int max, char * mot, char * phrase);
void update_jeu(SDL_Window * window, SDL_Renderer *renderer,TTF_Font * font, char link[100], char mot_aff[50], char tips_aff[50], SDL_Rect quit, SDL_Rect delete, SDL_Rect fond, SDL_Rect image, SDL_Rect frame, SDL_Rect change, SDL_Rect report_ico, SDL_Rect text, SDL_Rect champ_text, SDL_Rect mot_actuel, char mot_histo[10][50], SDL_Rect historique[10]);
int resoudre_jeu(SDL_Window * window, SDL_Renderer *renderer, TTF_Font *police,hash_t *tabh, int *quitter, char * langue, char * theme, char * difficulte,char mot_clef[50], char tips_aff[50], char link[100]);
void jeusolo(SDL_Window * window, SDL_Renderer *renderer, TTF_Font *police, char * langue, char * theme, char * difficulte, hash_t *tabh, char ** tabm);
void jeuduo(SDL_Window * window, SDL_Renderer *renderer, TTF_Font *police, hash_t *tabh, char * langue, char * theme, char * difficulte);

#endif