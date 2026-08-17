#ifndef MATRICE_H
#define MATRICE_H
#include <stdlib.h>
#define MaxL 1000 // Taille maximale d'une matrice en nombre de lignes
#define MaxC 1000 // Taille maximale d'une matrice en nombre de colonnes

// Exemple de fonction pour une matrice statique de taille nXm
void afficher_matrice(int M[MaxL][MaxC], int n, int m);

void remplir_matrice(int M[MaxL][MaxC], int max_alea, int n, int m);
#endif
