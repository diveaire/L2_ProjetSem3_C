
#ifndef _HASHTABLE_LINKED_H_
#define _HASHTABLE_LINKED_H_

#include "structure.h"


int HachageASCII(char tab[]);
void recup_data(char *link,hash_t *tabh,cellule *elm, char **tab);
void insertdata(hash_t *tabh, cellule *elm,int (*f)(char *));
int recherche_table(hash_t *tabh, char * mot_clef, char * langue, char *mot, char * theme, int (*f)(char *));
int nb_lettre_table(hash_t *tabh, char * mot, char * langue, int (*f)(char *));
void affiche_table(hash_t *tabh,int debut, int fin);

#endif