
#ifndef _CONSTANTE_H_
#define _CONSTANTE_H_

   /*
     * TAB_H_SIZE       --> Taille de la table de hashage
     * NB_MOTS          --> Nombre de mots dans le csv
     * SIZELINE         --> Taille Max d'une ligne
     *
     * ANIMAUX_DEBUT    --> Numéro de la ligne du premier animal dans mots.csv
     * ANIMAUX_FIN      --> Numéro de la ligne du dernier animal dans mots.csv
     *
     * CHECK_ERROR      --> Fonction qui vérifie les erreurs SDL ou TTF
     *
     * COULEUR          --> Code couleur du terminal
   */
#define TAB_H_SIZE 5000
#define NB_MOTS 1103
#define SIZELINE 1024



#define ANIMAUX_DEBUT   0
#define ANIMAUX_FIN     275
#define FRUITS_DEBUT    276
#define FRUITS_FIN      388
#define LEGUMES_DEBUT   389
#define LEGUMES_FIN     455
#define METIER_DEBUT    456
#define METIER_FIN      768
#define OUTILS_DEBUT    769
#define OUTILS_FIN      936
#define SPORT_DEBUT     937
#define SPORT_FIN       1102

//macro pour vérifier les erreurs sdl
#define CHECK_ERROR(test, message) \
    do { \
        if((test)) { \
            fprintf(stderr, "%s\n", message); \
            exit(1); \
        } \
    } while(0)


#define RED         "\033[1;31m"
#define TGREEN      "\033[2;33m"
#define BLUE        "\033[1;34m"
#define PINK        "\033[1;35m"
#define TCYAN       "\033[2;36m"
#define EMPTY       "\033[0m"

#endif
