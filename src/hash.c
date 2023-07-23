#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "header/constante.h"
#include "header/structure.h"




       /*           Fonctions
         *
         * HachageASCII-------> Fonction de hachage
         * insertdata---------> Insère un élément de type cellule dans la table de hachage
         * recup_data---------> Récupère les données du fichier csv
         * recherche_table----> Retourne vrai si l'élément est dans la table
         * nb_lettre_table----> Retourne le nombre de caractères d'un mot dans une langue
         * affiche_table------> Affiche la table de hachage de debut à fin
         *
       */




    //fonction de hachage
int HachageASCII(char tab[]){/*Attention, tab doit être allouer en variable*/
	char tabcpy[50];
	strcpy(tabcpy,tab);
	int hash=0,flag=0xFFF,i; /* 0xFFF= 1111 1111 1111 */
	float theta = 0.3819660113, entiere;
	for (i=0;i<strlen(tabcpy);i++){
		/*pour convertir chaque char en 12bits, on doit d'abord appliquer flag&tab[i]*/
		tabcpy[i] = tabcpy[i] & flag;
		tabcpy[i] = tabcpy[i] << 2; /*on équilibre a peut près les bits */
		if(i==0){
			hash = tabcpy[i];/*premier caractere*/
		}else if(tabcpy[i]%2 == 0){
			hash = hash ^ (tabcpy[i]^tabcpy[i-1]);
		}else {
			hash = hash & ((tabcpy[i]^tabcpy[i-1]));
		}
		hash = hash +((modff(tabcpy[i]*theta,&entiere) * TAB_H_SIZE));
	}
	(strlen(tabcpy) % 2 == 0) ? (hash = (hash << strlen(tabcpy) % 4)) : (hash = (hash >> strlen(tabcpy)%3));
	if(hash<0) hash = (hash * -1); /*pas d'indice négatif*/
	hash = hash % TAB_H_SIZE;
	/*modulo taille de la table pour pas depasser la taille du tableau*/
	return hash;
}

/*                   insertdata()
place la structure cellule dans la table de hachage hash_t 
grâce à l'indice de la fonction de hash en paramètre
*/
void insertdata(hash_t *tabh, cellule *elm,int (*f)(char *)){
    cellule * copy = NULL ;
    int clef = (*f)(elm->francais);
    copy = tabh->indice[clef];
    if(copy == NULL){
        tabh->indice[clef]=elm;
    }else{
        elm->suivant = copy;
        tabh->indice[clef] = elm;
    }
}


    // Recupère les éléments du fichier csv, les insèrent dans une variable de type cellule et ajoute à la table avec insertdata()
void recup_data(char *link,hash_t *tabh,cellule *elm, char **tab){
    FILE* file = fopen(link,"r");
    char ligne[SIZELINE];
    int i=0;
    if(file == NULL){
        fprintf(stderr,"erreur fichier");
        exit(EXIT_FAILURE);
    }
     while(fgets(ligne,SIZELINE,file) != NULL){
        char *morceau = strdup(ligne);
        char *element;
        elm = calloc(1,sizeof(cellule));
        element = strsep(&morceau,";");	//decoupe en morceau
        strcpy(elm->francais,element);	//enregistre mot dans table de hachage
        strcpy(tab[i],element);			//enregistre mot dans tableau de mot
        
        element = strsep(&morceau,";");	//enregistre theme
        strcpy(elm->theme,element);	
        
        element = strsep(&morceau,";");	//enregistre mot anglais
        strcpy(elm->anglais,element);
        
        element = strsep(&morceau,";");	//enregistre mot allemand
        strcpy(elm->allemand,element);
        
        element = strsep(&morceau,";");	//enregistre mot espagnol (sans le "\n" de fin de ligne)
        strncpy(elm->espagnol,element,(strlen(element)-2));
        element = NULL;
        
        elm->suivant = NULL;
        insertdata(tabh, elm, HachageASCII);
        i++;     
        free(morceau);
    }
    fclose(file);
}

    //recherche un mot dans la table de hachage grâce à son mot clef(mot_fr) dans une langue donnée retourne 1 s'il est dans la table sinon 0
int recherche_table(hash_t *tabh, char * mot_clef, char * langue, char *mot_recherche, char * theme, int (*f)(char *)){
    int clef = (*f)(mot_clef);
    cellule *elm = tabh->indice[clef];
    while (elm != NULL) {
        if(strcmp(langue,"francais") == 0) {
            printf("theme : %s %s = %s ?\n", theme, elm->francais, mot_recherche);
            if ((strcmp(elm->francais, mot_recherche) == 0) && (strcmp(elm->theme, theme) == 0)) {
                return 1;
            }
        }
        if(strcmp(langue,"anglais") == 0) {
            printf("theme : %s %s = %s ?\n", theme, elm->anglais, mot_recherche);
            if ((strcmp(elm->anglais, mot_recherche) == 0) && (strcmp(elm->theme, theme) == 0)) {
                return 1;
            }
        }
        if(strcmp(langue,"allemand") == 0) {
            printf("theme : %s %s = %s ?\n", theme, elm->allemand, mot_recherche);
            if ((strcmp(elm->allemand, mot_recherche) == 0) && (strcmp(elm->theme, theme) == 0)) {
                return 1;
            }
        }
        if(strcmp(langue,"espagnol") == 0) {
            printf("theme : %s %s = %s ?\n", theme, elm->espagnol, mot_recherche);
            if ((strcmp(elm->espagnol, mot_recherche) == 0) && (strcmp(elm->theme, theme) == 0)) {
                return 1;
            }
        }
        elm = elm->suivant;
    }
    return 0;
}

    //Retourne le nombre de caractères d'un mot dans une langue
int nb_lettre_table(hash_t *tabh, char * mot, char * langue, int (*f)(char *)){
    int clef = (*f)(mot);
    cellule *elm = tabh->indice[clef];
    while (elm != NULL) {
        if(strcmp(elm->francais,mot) == 0){
            if(strcmp(langue,"francais") == 0) {
                return strlen(elm->francais);
            }
            if(strcmp(langue,"anglais") == 0) {
                return strlen(elm->anglais);
            }
            if(strcmp(langue,"allemand") == 0) {
                return strlen(elm->allemand);
            }
            if(strcmp(langue,"espagnol") == 0) {
                return strlen(elm->espagnol);
            }
        }
        elm = elm->suivant;
    }
    return 0;
}
    //Affiche la table de hachage de debut à fin
void affiche_table(hash_t *tabh,int debut, int fin){
  cellule *elm = NULL;
  int i;
  for (i = debut-1; i < fin; i++) {
    elm = tabh->indice[i];
    printf("%s[[%d]]%s", PINK, i, EMPTY);
    while (elm != NULL) {
      printf("%s->", BLUE);
      printf("(%s, %s, %s, %s, %s)%s", elm->francais, elm->theme,elm->anglais,elm->allemand,elm->espagnol, EMPTY);
      elm = elm->suivant;
    }
    putchar('\n');
  }
}