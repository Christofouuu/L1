#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// #include "frequent.h"
#define MaxL 1000 // Taille maximale d'une matrice en nombre de lignes
#define MaxC 1000 // Taille maximale d'une matrice en nombre de colonnes

void element_frequent(int M[MaxL][MaxC], int n);

void remplir_matrice(int M[MaxL][MaxC], int max_alea, int n, int m);
void afficher_matrice(int M[MaxL][MaxC], int n, int m);

int M[MaxL][MaxC];

int main(){
  int taille, alea;
  //Exemple de déclaration d'une matrice statique M
  srand(time(NULL));
  
  printf("Choisissez le nombre de lignes et de colonnes de votre matrice carrée : ");
  scanf("%d",&taille); 
  
  printf("Choisissez le maximum de votre matrice : ");
  scanf("%d",&alea);

  remplir_matrice(M, alea, taille, taille);
  afficher_matrice(M, taille, taille);
  element_frequent(M, taille);
  
  return 0;
}

void element_frequent(int M[MaxL][MaxC], int n) {
  int i, j, k, minim = M[0][0], maxim = M[0][0]; 
  int compteur[n];
  
  for( i = 0; i < n; i++){
    for (j = 0; j < n; j++) {
      if ( maxim < M[i][j] ) {
        maxim = M[i][j];
      }
      if (minim > M[i][j] ) {
        minim = M[i][j];
      }
    }
  }
  
  for ( k = 0; k < n; k++) {
    for (; minim < maxim ; minim++) {
      compteur[k] = 0;
      // creer un tableau de taille maxim-minim pour accueillir toute les valeurs qui peuvent se répéter
      for( i = 0; i < n; i++){
        for (j = 0; j < n; j++) {
          if ( minim == M[i][j] ) {
            // ajouter + 1 au compteur lorsque la valeur minim est identique a la case du tableau
          }
        }
      }
    }
  }
  
  printf("min : %d \nmax: %d\n", minim, maxim);
  
  //return compteur;
}

void remplir_matrice(int M[MaxL][MaxC], int max_alea, int n, int m){
  int i, j;
  
  for (i = 0; i < n ; i++) {
    for (j = 0; j < m ; j++) {
      M[i][j] = rand() % (max_alea + 1);
    }
  }
}

void afficher_matrice(int M[MaxL][MaxC], int n, int m) {
  int i, j;
  
  for (i = 0; i < n ; i++) {
    for (j = 0; j < m ; j++) {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
}
