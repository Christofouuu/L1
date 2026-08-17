#include <stdio.h>
#include <time.h>
#include "matrice.h"
#define MaxL 1000 // Taille maximale d'une matrice en nombre de lignes
#define MaxC 1000 // Taille maximale d'une matrice en nombre de colonnes

int main() {
  int ligne, colonne, alea;
  //Exemple de déclaration d'une matrice statique M
  int M[MaxL][MaxC];
  srand(time(NULL));
  
  printf("Choisissez le nombre de lignes et de colonnes de votre matrice : ");
  scanf("%d %d",&ligne, &colonne); 
  
  printf("Choisissez le maximum de votre matrice : ");
  scanf("%d",&alea);
  
  remplir_matrice(M, alea, ligne, colonne);
  afficher_matrice(M, ligne, colonne);
  
  return 0;
}
