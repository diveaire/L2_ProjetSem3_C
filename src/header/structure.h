
#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

/*
 * La structure cellule est une structure qui va contenir toutes nos données dans la table de hachage
 * La structure hash_t est la structure de la table de hachage
 */


typedef struct cellule{
    char francais[50];
    char theme[20];
    char anglais[50];
    char allemand[50];
    char espagnol[50];
    struct cellule * suivant;
}cellule;

typedef struct hash_t{
    unsigned int taille;
    cellule **indice;
}hash_t;

#endif