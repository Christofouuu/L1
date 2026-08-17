#ifndef MATRICE_H
#define MATRICE_H
#include <stdlib.h>
#define MaxL 1000 // Taille maximale d'une matrice en nombre de lignes
#define MaxC 1000 // Taille maximale d'une matrice en nombre de colonne

void afficher_matrice(int M[MaxL][MaxC], int n);

void remplir_matrice(int M[MaxL][MaxC], int max_alea, int n);

#endif
