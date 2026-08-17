#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Carnet.h"

Carnet *creer_carnet(int n){
    int i;
    Carnet * res = malloc(sizeof(Carnet));
    if (res == NULL) {
        perror("Échec de l'allocation mémoire pour la structure 1\n");
        return NULL;
    }
    if (n <= 0) {
        exit(2);
    } else {
        res->nbcontact = n;
    }
    
    res->tabC = malloc(sizeof(Contact*) * n);
    if (res->tabC == NULL) {
        perror("Échec de l'allocation mémoire pour la structure 2\n");
        return NULL;
    }
    
    for (i = 0; i < n; i++){
        res->tabC[i] = NULL;
    }
    return res;
}

void generation_aleatoire_contacts(Carnet *C){
    int i, j;
    for (i = 0; i < C->nbcontact; i++) {
        C->tabC[i] = malloc(sizeof(Contact));
        for (j = 0; j < 15; j++) {
            if ((j == 2) || (j == 5) || (j == 8) || (j == 11) || (j == 14)){
                C->tabC[i]->numero[j] = '.';
            } else {
                C->tabC[i]->numero[j] = ('0' + (rand() % 10));
            }
        }
        for (j = 0; j < C->nbcontact; j++) {
            C->tabC[i]->nom[0]= ('A' + i);
        }
    }
}

void afficher_contacts(Carnet *C) {
    int i, j;
    for (i = 0; i < C->nbcontact; i++) {
        printf("Numéro de %s : %s \n", C->tabC[i]->nom, C->tabC[i]->numero);
    }
}

void desalloue_carnet(Carnet *C){
    int i;

    for (i = 0; i < C->nbcontact; i++) {
        if (C->tabC[i] != NULL) {
          free(C->tabC[i]);
        }
      }
      free(C);
}

int rechercher_contact(Carnet *C,  char* nom){
    int i = 0, j, rec;

    while (i != i < C->nbcontact || C->tabC[i]->nom == nom) {
        for (j == 0; C->tabC[i]->nom[j] != '\0'; j++) {
            if (C->tabC[i]->nom[j] == nom[j]){
                rec = i;
            } else {
                rec = -1;
            }
        }
        i++;
    }

   return rec;
}

void deplace_en_tete_contact(Carnet *C, char *nom){
    int i;

    for (i = 0; i < C->nbcontact; i++) {
        if (rechercher_contact(C, nom) == -1) {
            printf("Le contact n'existe pas\n");
            exit(2);
        } else {
            echanger_contact
        }

    }

}


Contact echanger_contact(Contact **x, Contact **y){
    Contact *tmp = *x;
    *x = *y;
    *y = tmp;
}