#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include <string.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "header/constante.h"
#include "header/structure.h"
#include "header/hash.h"
#include "header/fonctions.h"
extern SDL_Color black;
int quit;




       /*           FONCTIONS
         * make_link----------> Génère le lien de l'image
         * make_score---------> Génère le score en fonction du temps(s) et du nb d'erreurs
         * remplir_mot--------> Permet le bon remplissage de l'historique
         * update_champs -----> Actualise l'affichage de la saisie
         * remplir_champ------> Permet de réaliser une saisie
         * update_jeu---------> Actualise l'affichage de la resolution du jeu
         * resoudre_jeu-------> Permet de résoudre le jeu
         * jeusolo------------> Gestion du jeu solo
         * jeuduo-------------> Gestion du jeu duo
         *
       */





    //génération du lien de l'image avec theme + mot + num_img (de 1 à 5)
void make_link(char link[100],char * theme, int number, char * mot){
    sprintf(link,"images/jeu/%s/%s/%d.jpg",theme,mot,number);
}
    // Génération du score et le retourne en fonction du temps et du nb d'erreurs
int make_score(int temps, int nb_erreur){
    int score;
    if(temps<11){
        score = 10;
    }else if(temps<16){
        score = 7;
    }else if(temps<21){
        score = 5;
    }else if(temps<31){
        score = 3;
    }else{
        score = 0;
    }
    score = score-(nb_erreur);
    if(score<0) score = 0;
    return score;
}

    //met à jour l'historique des mots tapés
void remplir_mot(char mot[50], char mot_histo[10][50]){
    if(strncmp(mot_histo[1],"_",1) == 0){
        strcpy(mot_histo[1],mot);
    }else if(strncmp(mot_histo[2],"_",1) == 0){
        strcpy(mot_histo[2],mot);
    }else if(strncmp(mot_histo[3],"_",1) == 0){
        strcpy(mot_histo[3],mot);
    }else if(strncmp(mot_histo[4],"_",1) == 0){
        strcpy(mot_histo[4],mot);
    }else if(strncmp(mot_histo[5],"_",1) == 0){
        strcpy(mot_histo[5],mot);
    }else if(strncmp(mot_histo[6],"_",1) == 0){
        strcpy(mot_histo[6],mot);
    }else if(strncmp(mot_histo[7],"_",1) == 0){
        strcpy(mot_histo[7],mot);
    }else if(strncmp(mot_histo[8],"_",1) == 0){
        strcpy(mot_histo[8],mot);
    }else if(strncmp(mot_histo[9],"_",1) == 0) {
        strcpy(mot_histo[9], mot);
    }else{
        strcpy(mot_histo[1],mot_histo[2]);
        strcpy(mot_histo[2],mot_histo[3]);
        strcpy(mot_histo[3],mot_histo[4]);
        strcpy(mot_histo[4],mot_histo[5]);
        strcpy(mot_histo[5],mot_histo[6]);
        strcpy(mot_histo[6],mot_histo[7]);
        strcpy(mot_histo[7],mot_histo[8]);
        strcpy(mot_histo[8],mot_histo[9]);
        strcpy(mot_histo[9],mot);
    }
}

    //update affichage
void update_champs(SDL_Window * window, SDL_Renderer *renderer, TTF_Font *police, int max, char * mot_aff,char * phrase, SDL_Rect fond, SDL_Rect quit, SDL_Rect choix, SDL_Rect text, SDL_Rect champ_text,SDL_Rect delete){
    SDL_RenderClear(renderer);
    affiche_image(window,renderer,"images/menu/fond.png",&fond);
    affiche_image(window,renderer,"images/menu/quit.png",&quit);
    affiche_parametre(window,renderer,police,black,phrase,0, &choix);
    affiche_image(window,renderer,"images/menu/jeu/text_frame.png",&text);
    affiche_image(window,renderer,"images/menu/jeu/delete.png",&delete);
    affiche_parametre(window,renderer,police,black,mot_aff,max,&champ_text);
    SDL_RenderPresent(renderer);
}

    //Permet de réaliser une saisie
void remplir_champs(SDL_Window * window, SDL_Renderer *renderer, TTF_Font *police,int width, int height,int *quitter, int max, char * mot, char * phrase){
    char * mot_aff= calloc(sizeof(char),max);
        //on reset le mot
    strcpy(mot,"");
    //rectangles
    SDL_Rect fond = {0,0,width,height};
    SDL_Rect choix = {width*0.1,height*0.36,width*0.5,height*0.07};
    SDL_Rect quit = {width * 0.93, height * 0.014, width * 0.060, height * 0.075};
    SDL_Rect text   = {width*0.05,height*0.45,width*0.85,height*0.1};
    SDL_Rect champ_text = {width*0.06,height*0.47,width*0.80,height*0.07};
    SDL_Rect delete = {width*0.92,height*0.45,width*0.05,height*0.08};

    update_champs(window,renderer,police,max,mot_aff,phrase,fond,quit,choix,text,champ_text,delete);

    bool running = true;
    SDL_Event event;
    SDL_StartTextInput();
    while(running) {
        while (SDL_PollEvent(&event)) {
            const char *key = NULL;
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    key = SDL_GetKeyName(event.key.keysym.sym);
                    if ((strcmp(key, "A") == 0) || (strcmp(key, "E") == 0) || (strcmp(key, "I") == 0) || (strcmp(key, "O") == 0) || (strcmp(key, "U") == 0) || (strcmp(key, "Y") == 0)){
                        SDL_SetRenderDrawColor(renderer, randInt(0, 255), randInt(0, 255), randInt(0, 255), 255);
                        update_champs(window,renderer,police,max,mot_aff,phrase,fond,quit,choix,text,champ_text,delete);
                    }
                    if (strcmp(key, "Delete") == 0) {
                        strcpy(mot,"");
                        strcpy(mot_aff,mot);
                        update_champs(window,renderer,police,max,mot_aff,phrase,fond,quit,choix,text,champ_text,delete);
                    }
                    if (strcmp(key, "Backspace") == 0) {
                        if(strlen(mot)>0) {
                            char motcpy[50]="";
                            strncpy(motcpy,mot,(strlen(mot)-1));
                            printf("%s\n", motcpy);
                            strcpy(mot,motcpy);
                            strcpy(mot_aff,mot);
                            update_champs(window,renderer,police,max,mot_aff,phrase,fond,quit,choix,text,champ_text,delete);
                        }
                    }
                    if (strcmp(key, "Return") == 0) {
                        running = false;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if (ClickDansRect(quit, event.button.x, event.button.y)) {
                        //click sur le bouton QUIT
                        printf("QUIT\n");
                        *quitter = 1;
                        running = false;
                    }
                    if (ClickDansRect(delete, event.button.x, event.button.y)) {
                        strcpy(mot,"");
                        strcpy(mot_aff,mot);
                        update_champs(window,renderer,police,max,mot_aff,phrase,fond,quit,choix,text,champ_text,delete);
                    }
                    break;
                case SDL_TEXTINPUT:
                    strcat(mot,event.text.text);
                    printf("mot: %s\n", mot);
                    strcpy(mot_aff,mot);
                    update_champs(window,renderer,police,max,mot_aff,phrase,fond,quit,choix,text,champ_text,delete);
                    break;
            }
        }
    }
    free(mot_aff);
}

//mise à jour de l'écran pour trouver le nom de l'image
void update_jeu(SDL_Window * window, SDL_Renderer *renderer,TTF_Font * font, char link[100], char mot_aff[50], char tips_aff[50], SDL_Rect quit, SDL_Rect delete, SDL_Rect fond, SDL_Rect image, SDL_Rect frame, SDL_Rect change, SDL_Rect report_ico, SDL_Rect text, SDL_Rect champ_text, SDL_Rect mot_actuel, char mot_histo[10][50], SDL_Rect historique[10]){
    SDL_RenderClear(renderer);
    affiche_image(window,renderer,"images/menu/fond.png",&fond);
    affiche_image(window,renderer,"images/menu/jeu/swap.png",&change);
    affiche_image(window,renderer,"images/menu/jeu/report.png",&report_ico);
    affiche_image(window,renderer,"images/menu/quit.png",&quit);
    //affichage de l'image au centre de l'écran
    affiche_image(window,renderer,link,&image);
    //remplir le rectangle en noir
    affiche_image(window,renderer,"images/menu/jeu/frame.png",&frame);
    affiche_image(window,renderer,"images/menu/jeu/text_frame.png",&text);
    affiche_image(window,renderer,"images/menu/jeu/delete.png",&delete);

    affiche_parametre(window,renderer,font,black,mot_aff,50,&champ_text);
    affiche_parametre(window,renderer,font,black,tips_aff,50,&mot_actuel);

    //historique des mots tapés
    affiche_parametre(window,renderer,font,black,mot_histo[0],30,&historique[0]);
    affiche_parametre(window,renderer,font,black,mot_histo[1],30,&historique[1]);
    affiche_parametre(window,renderer,font,black,mot_histo[2],30,&historique[2]);
    affiche_parametre(window,renderer,font,black,mot_histo[3],30,&historique[3]);
    affiche_parametre(window,renderer,font,black,mot_histo[4],30,&historique[4]);
    affiche_parametre(window,renderer,font,black,mot_histo[5],30,&historique[5]);
    affiche_parametre(window,renderer,font,black,mot_histo[6],30,&historique[6]);
    affiche_parametre(window,renderer,font,black,mot_histo[7],30,&historique[7]);
    affiche_parametre(window,renderer,font,black,mot_histo[8],30,&historique[8]);
    affiche_parametre(window,renderer,font,black,mot_histo[9],30,&historique[9]);
    SDL_RenderPresent(renderer);
}

//Permet de résoudre le jeu
int resoudre_jeu(SDL_Window * window, SDL_Renderer *renderer, TTF_Font *police,hash_t *tabh, int *quitter, char * langue, char * theme, char * difficulte,char mot_clef[50], char tips_aff[50], char link[100]) { // hash_t *tabh, char ** tabm

        /*                  VARIABLES
             * "number"         = numéro de l'image
             * "erreur"         = nombre d'erreurs rentrée
             * "indice"         = indice aléatoire à générer
             * "width/height"   = taille de la fenêtre
             * "temps"          = temps de reussi / echec
             * "score"          = Score de la partie
             * "link"           = lien de l'image
             * "mot"            = mot tapper par l'utilisateur
             * "mot_aff"        = affichage du mot sur la fenêtre
             * "tips_aff"       = affichage du nombre de lettres pour facile/moyen
             * "aff_score"      = affichage du score en fin de partie
             * "mot_histo"      = historique des mots tapés
        */

    srand((unsigned int)time(NULL));
    FILE *report = fopen("fichiers/report.csv", "r+");
    fseek(report, 0, SEEK_END);
    clock_t t1, t2;
    int nb_erreur = 0, width, height, number = 1, score=0, temps = 0;
    SDL_GetWindowSize(window, &width, &height);
    char  mot[50]="", mot_aff[50]="", aff_score[30]="";
    char mot_histo[10][50]={
            "historique:",
            "_",
            "_",
            "_",
            "_",
            "_",
            "_",
            "_",
            "_",
            "_",
    };

        //Génération des rectangles
    SDL_Rect fond       = {0, 0, width, height};
    SDL_Rect quit       = {width * 0.93, height * 0.014, width * 0.060, height * 0.075};
    SDL_Rect image      = {width * 0.50 - (width * 0.50) / 2, height * 0.50 - (height * 0.5) / 2, width * 0.50,height * 0.5};
    SDL_Rect frame      = {width * 0.49 - (width * 0.50) / 2, height * 0.475 - (height * 0.5) / 2, width * 0.52,height * 0.55};
    SDL_Rect change     = {width * 0.60, height * 0.80, width * 0.05, height * 0.08};
    SDL_Rect report_ico = {width * 0.70, height * 0.80, width * 0.05, height * 0.07};
    SDL_Rect delete     = {width * 0.92, height * 0.91, width * 0.05, height * 0.08};
    SDL_Rect text       = {width * 0.05, height * 0.9, width * 0.85, height * 0.1};
    SDL_Rect champ_text = {width * 0.06, height * 0.92, width * 0.80, height * 0.07};
    SDL_Rect mot_actuel = {width * 0.1, height * 0.85, width * 0.60, height * 0.07};
    SDL_Rect flag       = {width*0.25,height*0.3,width*0.5,height*0.4};
    SDL_Rect score_aff  = {width*0.30,height*0.8,width * 0.60, height * 0.07};
    SDL_Rect historique[10];
    for (int i = 0; i < 10; i++) {
        historique[i].x = width * 0.80;
        historique[i].y = height * (0.25 + (0.05 * i));
        historique[i].w = width * 0.20;
        historique[i].h = height * 0.05;
    }



    //On affiche à l'écran
    update_jeu(window, renderer, police, link, mot_aff, tips_aff, quit, delete, fond, image, frame, change,
               report_ico, text, champ_text, mot_actuel, mot_histo, historique);
    //debut du chrono
    t1 = clock();
    /* Début du jeu Solo */
    bool running = true;
    SDL_Event event;
    SDL_StartTextInput();
    while (running) {
        while (SDL_PollEvent(&event)) {
            // Mode de jeu difficile = nb_erreur < 5
            if (strcmp(difficulte, "difficile") == 0 && nb_erreur >= 5) {
                printf("perdu\n");
                //Fin du chrono
                t2 = clock();
                temps = (t2 - t1) / CLOCKS_PER_SEC;
                SDL_RenderClear(renderer);
                affiche_image(window, renderer, "images/menu/fond.png", &fond);
                affiche_image(window, renderer, "images/menu/jeu/defaite.png", &flag);
                sprintf(aff_score,"Le score est de %d", score);
                running = false;
            }
            if (strcmp(difficulte, "moyen") == 0 && nb_erreur >= 10) {
                printf("perdu\n");
                t2 = clock();//Fin du chrono
                temps = (t2 - t1) / CLOCKS_PER_SEC;
                SDL_RenderClear(renderer);
                affiche_image(window, renderer, "images/menu/fond.png", &fond);
                affiche_image(window, renderer, "images/menu/jeu/defaite.png", &flag);
                sprintf(aff_score,"Le score est de %d", score);
                running = false;
            }
            const char *key = NULL;
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    key = SDL_GetKeyName(event.key.keysym.sym);
                    if (strcmp(key, "C") == 0) {
                        SDL_SetRenderDrawColor(renderer, randInt(0, 255), randInt(0, 255), randInt(0, 255), 255);
                        update_jeu(window, renderer, police, link, mot_aff, tips_aff, quit, delete, fond, image,
                                   frame, change, report_ico, text, champ_text, mot_actuel, mot_histo, historique);
                    }
                    if (strcmp(key, "Delete") == 0) {
                        strcpy(mot, "");
                        strcpy(mot_aff, mot);
                        update_jeu(window, renderer, police, link, mot_aff, tips_aff, quit, delete, fond, image,
                                   frame, change, report_ico, text, champ_text, mot_actuel, mot_histo, historique);
                    }
                    if (strcmp(key, "Backspace") == 0) {
                        if (strlen(mot) > 0) {
                            char motcpy[50] = "";
                            strncpy(motcpy, mot, (strlen(mot) - 1));
                            printf("%s\n", motcpy);
                            strcpy(mot, motcpy);
                            strcpy(mot_aff, mot);
                        }
                        update_jeu(window, renderer, police, link, mot_aff, tips_aff, quit, delete, fond, image,
                                   frame, change, report_ico, text, champ_text, mot_actuel, mot_histo, historique);
                    }
                    if (strcmp(key, "Return") == 0) {
                        remplir_mot(mot, mot_histo);
                        update_jeu(window, renderer, police, link, mot_aff, tips_aff, quit, delete, fond, image,
                                   frame, change, report_ico, text, champ_text, mot_actuel, mot_histo, historique);
                        if (recherche_table(tabh, mot_clef, langue, mot, theme, HachageASCII)) {
                            printf("c'est gagne\n");
                            //Fin du chrono
                            t2 = clock();
                            temps = (t2 - t1) / CLOCKS_PER_SEC;
                            score = make_score(temps,nb_erreur);
                            SDL_RenderClear(renderer);
                            affiche_image(window, renderer, "images/menu/fond.png", &fond);
                            affiche_image(window, renderer, "images/menu/jeu/victoire.png", &flag);
                            running = false;
                        } else {
                            nb_erreur++;
                            printf("Nb erreur : %d\n", nb_erreur);
                        }

                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if (ClickDansRect(change, event.button.x, event.button.y)) {
                        if (number == 5) number = 0;
                        number++; //on affiche l'image d'après
                        make_link(link, theme, number, mot_clef);
                        update_jeu(window, renderer, police, link, mot_aff, tips_aff, quit, delete, fond, image,
                                   frame, change, report_ico, text, champ_text, mot_actuel, mot_histo, historique);
                    }
                    if (ClickDansRect(delete, event.button.x, event.button.y)) {
                        strcpy(mot, "");
                        strcpy(mot_aff, mot);
                        update_jeu(window, renderer, police, link, mot_aff, tips_aff, quit, delete, fond, image,
                                   frame, change, report_ico, text, champ_text, mot_actuel, mot_histo, historique);
                    }
                    if (ClickDansRect(report_ico, event.button.x, event.button.y)) {
                        printf("Ce lien est report : %s\n", link);
                        fprintf(report, "%s;%s;%d\n", theme, mot_clef, number);
                    }
                    if (ClickDansRect(quit, event.button.x, event.button.y)) {
                        //click sur le bouton QUIT
                        printf("QUIT\n");
                        *quitter = 1;
                        running = false;
                        return 0;
                    }
                    break;
                case SDL_TEXTINPUT:
                    strcat(mot, event.text.text);
                    printf("mot %s\n", mot);
                    strcpy(mot_aff, mot);
                    update_jeu(window, renderer, police, link, mot_aff, tips_aff, quit, delete, fond, image, frame,
                               change, report_ico, text, champ_text, mot_actuel, mot_histo, historique);
                    break;
            }
        }
    }
    printf("Le temps mis est de %d\n", temps);
    SDL_StopTextInput();
    fclose(report);
    sprintf(aff_score,"Le score est de %d", score);
    affiche_parametre(window,renderer,police,black,aff_score,30,&score_aff);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    return score;
}



    //Mode 1joueur (image aléatoire + écran réponse (Le score est retourné)
void jeusolo(SDL_Window * window, SDL_Renderer *renderer, TTF_Font *police, char * langue, char * theme, char * difficulte, hash_t *tabh, char ** tabm){
    char nom[50]="";
    int indice = -1, score = 0, width, height,number=1;
    quit=0;
    SDL_GetWindowSize(window,&width,&height);
    char mot_clef[50] = "", tips_aff[50] = "", link[100]="";

    //Ouverture des fichiers
    FILE *F_score = fopen("fichiers/score.csv", "r+");
    fseek(F_score,0,SEEK_END);
    remplir_champs(window,renderer,police,width,height,&quit,50,nom, "Joueur 1 : Taper votre nom (max:50 caracteres)");
    for(int i=0;i<3;i++) {
        srand((unsigned int) time(NULL));


        //calcul d'un indice aléatoire en fonction du thème
        if (strcmp(theme, "animaux") == 0) {
            indice = randInt(ANIMAUX_DEBUT, ANIMAUX_FIN);
        } else if (strcmp(theme, "fruits") == 0) {
            indice = randInt(FRUITS_DEBUT, FRUITS_FIN);
        } else if (strcmp(theme, "legumes") == 0) {
            indice = randInt(LEGUMES_DEBUT, LEGUMES_FIN);
        } else if (strcmp(theme, "metiers") == 0) {
            indice = randInt(METIER_DEBUT, METIER_FIN);
        } else if (strcmp(theme, "outils") == 0) {
            indice = randInt(OUTILS_DEBUT, OUTILS_FIN);
        } else if (strcmp(theme, "sports") == 0) {
            indice = randInt(SPORT_DEBUT, SPORT_FIN);
        }
        printf("%d = indice aléatoire\n", indice);

        //génération du lien de l'image
        strcpy(mot_clef, tabm[indice]);
        make_link(link, theme, number, mot_clef);
        printf("%s\n", link);

        //affichage écran de jeu
        if (strcmp(difficulte, "facile") == 0 || strcmp(difficulte, "moyen") == 0) {
            sprintf(tips_aff, "%d caracteres", nb_lettre_table(tabh, tabm[indice], langue, HachageASCII));
        }

        score = score + resoudre_jeu(window, renderer, police,tabh,&quit,langue, theme, difficulte, mot_clef, tips_aff, link);
        if(quit == 1) break;
    }
    printf("Vous avez un score de %d pour la partie\n", score);
    fprintf(F_score,"%s;%s;%d\n", difficulte,nom,score);

    fclose(F_score);
}


    //(Mode 2joueurs) affichage de l'image du joueur 1 à trouver par le joueur 2 puis inversement / 3 résolution par joueurs
void jeuduo(SDL_Window * window, SDL_Renderer *renderer, TTF_Font *police, hash_t *tabh, char * langue, char * theme, char * difficulte){

        //Ouverture du fichier csv Score
    FILE * F_score = fopen("fichiers/score.csv","r+");
    fseek(F_score,0,SEEK_END);

    int number=1, scorej1=0, scorej2=0, width, height;
    char tips_aff[50]="", mot_clef[50]="", link[100]="", gagnant[100]="";
    SDL_GetWindowSize(window,&width,&height);

    SDL_Rect fond       = {0, 0, width, height};
    SDL_Rect flag       = {width*0.25,height*0.3,width*0.5,height*0.4};
    SDL_Rect gagnant_aff  = {width*0.30,height*0.8,width * 0.60, height * 0.07};

        //nom des joueurs
    char nom1[50]="", nom2[50]="", affichage_nom[100]="";
    remplir_champs(window,renderer,police,width,height,&quit,50,nom1, "Joueur 1 : Taper votre nom (max:50 caracteres)");
    remplir_champs(window,renderer,police,width,height,&quit,50,nom2, "Joueur 2 : Taper votre nom (max:50 caracteres)");
    printf("Nom1: %s\nNom2: %s\n",nom1,nom2);

        //début des 3 parties chacun. On alterne les Joueurs 1 et 2 à chaque partie
    for(int i=0;i<6;i++){
        quit=0;
        if(i%2 == 0) {

            do {
                sprintf(affichage_nom,"%s: Taper votre mot (en francais)",nom1);
                remplir_champs(window, renderer, police, width, height, &quit, 50, mot_clef,
                               affichage_nom);
            } while (!recherche_table(tabh, mot_clef, "francais", mot_clef, theme, HachageASCII) && !quit);
            if (quit == 1) break;
            //génération du lien de l'image
            sprintf(link, "images/jeu/%s/%s/%d.jpg", theme, mot_clef, number);
            printf("%s\n", link);
            quit = 0;
            //affichage écran de jeu
            if (strcmp(difficulte, "facile") == 0 || strcmp(difficulte, "moyen") == 0) {
                sprintf(tips_aff, "%d caracteres", nb_lettre_table(tabh, mot_clef, langue, HachageASCII));
            }
            scorej2 = scorej2 + resoudre_jeu(window, renderer, police, tabh, &quit, langue, theme, difficulte, mot_clef, tips_aff,link);
            if (quit == 1) break;
        }else{
            //revanche dans l'autre sens
            do {
                sprintf(affichage_nom,"%s: Taper votre mot (en francais)",nom2);
                remplir_champs(window, renderer, police, width, height, &quit, 50, mot_clef, affichage_nom);
            } while (!recherche_table(tabh, mot_clef, "francais", mot_clef, theme, HachageASCII) && !quit);
            if (quit == 1) break;
            //génération du lien de l'image
            sprintf(link, "images/jeu/%s/%s/%d.jpg", theme, mot_clef, number);
            printf("%s\n", link);
            quit = 0;
            //affichage écran de jeu
            if (strcmp(difficulte, "facile") == 0 || strcmp(difficulte, "moyen") == 0) {
                sprintf(tips_aff, "%d caracteres", nb_lettre_table(tabh, mot_clef, langue, HachageASCII));
            }
            scorej1 = scorej1 + resoudre_jeu(window, renderer, police, tabh, &quit, langue, theme, difficulte, mot_clef, tips_aff,link);
            if (quit == 1) break;
        }
    }
        //affichage du score
    printf("%s Vous avez un score de %d pour la partie\n", nom1, scorej1);
    printf("%s Vous avez un score de %d pour la partie\n",nom2, scorej2);
    SDL_RenderClear(renderer);
    affiche_image(window, renderer, "images/menu/fond.png", &fond);
    affiche_image(window, renderer, "images/menu/jeu/victoire.png", &flag);
        if (scorej1>scorej2){
            printf("%s a gagner\n", nom1);
            sprintf(gagnant,"Le gagnant est %s", nom1);
            affiche_parametre(window,renderer,police,black,gagnant,30,&gagnant_aff);
        }else if(scorej1<scorej2){
            printf("%s a gagner\n", nom2);
            sprintf(gagnant,"Le gagnant est %s", nom2);
            affiche_parametre(window,renderer,police,black,gagnant,30,&gagnant_aff);
        }else{
            printf("egalite");
            sprintf(gagnant,"Bravo, c'est une egalite parfaite");
            affiche_parametre(window,renderer,police,black,gagnant,30,&gagnant_aff);
        }
    SDL_RenderPresent(renderer);
    SDL_Delay(2500);
    fprintf(F_score,"%s;%s;%d;30\n", difficulte,nom1,scorej1);
    fprintf(F_score,"%s;%s;%d;30\n", difficulte,nom2,scorej2);
    fclose(F_score);
}
