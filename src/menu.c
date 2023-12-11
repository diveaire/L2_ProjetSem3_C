//
// Created by nicolas on 08/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


#include "header/structure.h"
#include "header/fonctions.h"
#include "header/hash.h"
#include "header/jeu.h"

const SDL_Color black = {0,0,0};
const SDL_Color bleu = {3,46,90};


       /*               Fonctions
          *
          * logo------------> Page de présentation du programme
          * affiche_menu----> Actualise l'affichage du menu
          * menu------------> Contrôle et gestion du menu
          *
       */







    //affichage de la page de présentation
void logo(SDL_Window * window, SDL_Renderer * renderer, TTF_Font * police, int width, int height){
    // couleur  bleu upjv SDL_SetRenderDrawColor(renderer, 3,46,90,255);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    SDL_Rect logo = {width * 0.425, height * 0.36, width * 0.15,height * 0.28};
    SDL_Rect nom = {width * 0.8, height*0.9, width * 0.15,height * 0.05};
    SDL_Rect titre = {width * 0.40, height*0.3, width * 0.20,height * 0.05};
    affiche_parametre(window,renderer,police,bleu,"Jeu-Linguistique",0, &titre);
    affiche_parametre(window,renderer,police,bleu,"Auvray Nicolas",0, &nom);
    affiche_image(window,renderer,"images/menu/upjv.png",&logo);
    SDL_RenderPresent(renderer);
    SDL_Delay(2500);
}

    //fonction qui actualise l'affichage du menu
void affiche_menu(SDL_Window * window, SDL_Renderer * renderer, TTF_Font * font,char langue_aff[40],char nb_joueur_aff[40],char theme_aff[40],char difficulte_aff[40], SDL_Rect start, SDL_Rect quit, SDL_Rect fond, SDL_Rect facile, SDL_Rect moyen, SDL_Rect difficile, SDL_Rect info_nb_joueur, SDL_Rect info_langue, SDL_Rect info_theme, SDL_Rect info_difficulte, SDL_Rect france, SDL_Rect anglais, SDL_Rect allemand, SDL_Rect espagnol, SDL_Rect solo, SDL_Rect duo, SDL_Rect animaux, SDL_Rect fruits, SDL_Rect legumes, SDL_Rect metiers, SDL_Rect outils, SDL_Rect sports, SDL_Rect ajoute){

    SDL_RenderClear(renderer);
    // !!!!!!!!!! menu !!!!!!!!!

    affiche_image(window,renderer,"images/menu/fond.png",&fond);
    affiche_image(window,renderer,"images/menu/start.png",&start);
    affiche_image(window,renderer,"images/menu/quit.png",&quit);
    affiche_image(window,renderer,"images/menu/ajoute.png",&ajoute);

    affiche_image(window,renderer,"images/menu/difficulte/facile.png",&facile);
    affiche_image(window,renderer,"images/menu/difficulte/moyen.png",&moyen);
    affiche_image(window,renderer,"images/menu/difficulte/difficile.png",&difficile);

    affiche_parametre(window,renderer,font,black,langue_aff,20,&info_langue);
    affiche_parametre(window,renderer,font,black,nb_joueur_aff,20,&info_nb_joueur);
    affiche_parametre(window,renderer,font,black,theme_aff,20,&info_theme);
    affiche_parametre(window,renderer,font,black,difficulte_aff,20,&info_difficulte);

    affiche_image(window,renderer,"images/menu/drapeau/france.png",&france);
    affiche_image(window,renderer,"images/menu/drapeau/anglais.png",&anglais);
    affiche_image(window,renderer,"images/menu/drapeau/allemand.png",&allemand);
    affiche_image(window,renderer,"images/menu/drapeau/espagne.png",&espagnol);
    affiche_image(window,renderer,"images/menu/1.png",&solo);
    affiche_image(window,renderer,"images/menu/2.png",&duo);
    affiche_image(window,renderer,"images/menu/theme/animaux.png",&animaux);
    affiche_image(window,renderer,"images/menu/theme/fruits.png",&fruits);
    affiche_image(window,renderer,"images/menu/theme/legumes.png",&legumes);
    affiche_image(window,renderer,"images/menu/theme/metiers.png",&metiers);
    affiche_image(window,renderer,"images/menu/theme/outils.png",&outils);
    affiche_image(window,renderer,"images/menu/theme/sports.png",&sports);
    SDL_RenderPresent(renderer);
}

    //fonction qui contrôle et gère le menu
void menu(SDL_Window * window, SDL_Renderer * renderer, TTF_Font * police, hash_t tabh, char ** tabm, int width,int height) {
        /*initialise nb_aléatoire*/
    srand((unsigned int)time(NULL));

        /*      Variables
         *
         * langue       -> Langue du jeu
         * theme        -> Thème du jeu
         * difficulte   -> Mode de difficulte
         * *_aff        -> affichage de la variable *
         * nb_j         -> nombre de joueurs dans la partie
         * ajout_mot    -> nombre de mot ajouter
         */

    char langue[20] = "sans", theme[20] = "sans", difficulte[20] = "sans";
    char langue_aff[40] = "choisir une langue", theme_aff[40] = "choisir un theme", nb_joueur_aff[40] = "Selectionner joueurs", difficulte_aff[40]="Selectionner difficulte";
    int nb_j = 0, ajout_mot=0;


    SDL_SetRenderDrawColor(renderer, 125, 25, 25, 255); //fond rouge de base

    SDL_Rect fond    = {0,0,width,height};

    SDL_Rect    quit               = {width * 0.93, height * 0.014, width * 0.060, height * 0.075};
    SDL_Rect    start              = {width * 0.50 - (width * 0.20) / 2, height * 0.50 - (height * 0.15) / 2, width * 0.20,height * 0.15};
    SDL_Rect    ajoute             = {width * 0.70, height * 0.014, width * 0.20, height * 0.10};

    SDL_Rect    solo               = {width * 0.43, height * 0.60, width * 0.04, height * 0.060};
    SDL_Rect    duo                = {width * 0.52, height * 0.59, width * 0.04, height * 0.083};

    SDL_Rect    facile             = {width * 0.11, height * 0.89, width * 0.1, height * 0.1};
    SDL_Rect    moyen              = {width * 0.22, height * 0.89, width * 0.1, height * 0.1};
    SDL_Rect    difficile          = {width * 0.33, height * 0.89, width * 0.1, height * 0.1};

    SDL_Rect    info_nb_joueur     = {width * 0.80, height * 0.20, width * 0.20, height * 0.05};
    SDL_Rect    info_langue        = {width * 0.80, height * 0.25, width * 0.20, height * 0.05};
    SDL_Rect    info_theme         = {width * 0.80, height * 0.30, width * 0.20, height * 0.05};
    SDL_Rect    info_difficulte    = {width * 0.80, height * 0.35, width * 0.20, height * 0.05};

    SDL_Rect    france             = {width * 0.75, height * 0.91, width * 0.04, height * 0.06};
    SDL_Rect    anglais            = {width * 0.80, height * 0.91, width * 0.04, height * 0.06};
    SDL_Rect    allemand           = {width * 0.85, height * 0.91, width * 0.04, height * 0.06};
    SDL_Rect    espagnol           = {width * 0.90, height * 0.91, width * 0.04, height * 0.06};

    SDL_Rect    animaux            = {width * 0.014, height * 0.014, width * 0.1, height * 0.1};
    SDL_Rect    fruits             = {width * 0.014, height * 0.125, width * 0.1, height * 0.1};
    SDL_Rect    legumes            = {width * 0.014, height * 0.236, width * 0.1, height * 0.1};
    SDL_Rect    metiers            = {width * 0.014, height * 0.347, width * 0.1, height * 0.1};
    SDL_Rect    outils             = {width * 0.014, height * 0.458, width * 0.1, height * 0.1};
    SDL_Rect    sports             = {width * 0.014, height * 0.569, width * 0.1, height * 0.1};

    affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                 info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                 metiers, outils, sports, ajoute);

    bool running = true;
    SDL_Event event;
    while (running) {
        // Process events
        while (SDL_PollEvent(&event)) {
            const char *key = NULL;
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                break;
                case SDL_KEYDOWN:   //touche appuyer
                    key = SDL_GetKeyName(event.key.keysym.sym);
                    if (strcmp(key, "C") == 0){
                        SDL_SetRenderDrawColor(renderer, randInt(0, 255), randInt(0, 255), randInt(0, 255), 255);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                break;
                case SDL_MOUSEBUTTONUP: //clic
                    if (ClickDansRect(facile, event.button.x, event.button.y)) {
                        strcpy(difficulte, "facile");
                        sprintf(difficulte_aff, "%s", difficulte);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(moyen, event.button.x, event.button.y)) {
                        strcpy(difficulte, "moyen");
                        sprintf(difficulte_aff, "%s", difficulte);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(difficile, event.button.x, event.button.y)) {
                        strcpy(difficulte, "difficile");
                        sprintf(difficulte_aff, "%s", difficulte);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(france, event.button.x, event.button.y)) {
                        strcpy(langue, "francais");
                        sprintf(langue_aff, "%s", langue);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(anglais, event.button.x, event.button.y)) {
                        strcpy(langue, "anglais");
                        sprintf(langue_aff, "%s", langue);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(allemand, event.button.x, event.button.y)) {
                        strcpy(langue, "allemand");
                        sprintf(langue_aff, "%s", langue);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(espagnol, event.button.x, event.button.y)) {
                        strcpy(langue, "espagnol");
                        sprintf(langue_aff, "%s", langue);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(solo, event.button.x, event.button.y)) {
                        nb_j = 1;
                        sprintf(nb_joueur_aff, "%d joueur", nb_j);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(duo, event.button.x, event.button.y)) {
                        nb_j = 2;
                        sprintf(nb_joueur_aff, "%d joueur", nb_j);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(animaux, event.button.x, event.button.y)) {
                        strcpy(theme, "animaux");
                        sprintf(theme_aff, "%s", theme);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(fruits, event.button.x, event.button.y)) {
                        strcpy(theme, "fruits");
                        sprintf(theme_aff, "%s", theme);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(legumes, event.button.x, event.button.y)) {
                        strcpy(theme, "legumes");
                        sprintf(theme_aff, "%s", theme);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(metiers, event.button.x, event.button.y)) {
                        strcpy(theme, "metiers");
                        sprintf(theme_aff, "%s", theme);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(outils, event.button.x, event.button.y)) {
                        strcpy(theme, "outils");
                        sprintf(theme_aff, "%s", theme);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if (ClickDansRect(sports, event.button.x, event.button.y)) {
                        strcpy(theme, "sports");
                        sprintf(theme_aff, "%s", theme);
                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                    }
                    if ((ClickDansRect(ajoute, event.button.x, event.button.y) && (strcmp(theme,"sans") != 0)) && ajout_mot<=100 ){
                        int quitter=0;
                        FILE * ajoute_mot = fopen("fichiers/mot_ajouter.csv","r+");
                        fseek(ajoute_mot,0,SEEK_END);
                        cellule elm;
                        strcpy(elm.theme,theme);
                        //selectionner - mot - anglais - allemand - espagnol
                        do{
                            remplir_champs(window,renderer,police,width,height,&quitter,50,elm.francais,"Ecrire le nouveau mot francais: ");
                        }while(recherche_table(&tabh,elm.francais,"francais",elm.francais,theme,HachageASCII) && !quitter); //le mot n'existe pas ou le joueur clic sur quitter
                        if(quitter) break;
                        remplir_champs(window,renderer,police,width,height,&quitter,50,elm.anglais,"Ecrire la traduction Anglaise: ");
                        if(quitter) break;
                        remplir_champs(window,renderer,police,width,height,&quitter,50,elm.allemand,"Ecrire la traduction Allemande: ");
                        if(quitter) break;
                        remplir_champs(window,renderer,police,width,height,&quitter,50,elm.espagnol,"Ecrire la traduction Espagnole: ");
                        if(quitter) break;
                        elm.suivant = NULL;

                        fprintf(ajoute_mot,"%s;%s;%s;%s\n",elm.francais,elm.anglais,elm.allemand,elm.espagnol);
                        insertdata(&tabh, &elm, HachageASCII); //on ajoute dans la table de hachage elm
                        ajout_mot++;

                        affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                     info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                     metiers, outils, sports, ajoute);
                        fclose(ajoute_mot);
                    }
                    if (ClickDansRect(start, event.button.x, event.button.y)) {
                        printf("START\n");
                        if (nb_j == 0 || strcmp(theme, "sans") == 0 || strcmp(langue, "sans") == 0 || strcmp(difficulte, "sans") == 0){
                            printf("selectionner nombre de joueurs, le theme et la langue\n");
                        } else if (nb_j == 1) {
                            printf("Mode 1 joueur\n");
                            printf("-difficulte: %s -theme : %s -langue : %s\n", difficulte, theme, langue);
                            jeusolo(window,renderer,police,langue,theme,difficulte,&tabh,tabm);
                            affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                         info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                         metiers, outils, sports, ajoute);
                        } else {
                            printf("Mode 2 joueur\n");
                            printf("-difficulte: %s -theme : %s -langue : %s\n", difficulte, theme, langue);
                            jeuduo(window,renderer,police,&tabh,langue,theme,difficulte);
                            affiche_menu(window, renderer, police, langue_aff, nb_joueur_aff, theme_aff,difficulte_aff, start, quit, fond, facile, moyen, difficile,
                                         info_nb_joueur,info_langue, info_theme, info_difficulte, france, anglais, allemand, espagnol, solo, duo, animaux, fruits, legumes,
                                         metiers, outils, sports, ajoute);
                        }
                    }
                    if (ClickDansRect(quit, event.button.x, event.button.y)) {
                        //click sur le bouton QUIT
                        printf("QUIT\n");
                        running = false;
                    }
                break;
            }
        }
        SDL_StopTextInput();
    }
}