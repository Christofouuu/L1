#include "matrice.h"
#include <stdio.h>

void afficher_matrice(int M[MaxL][MaxC], int n, int m) {
  int i, j;
  
  for (i = 0; i < n ; i++) {
    for (j = 0; j < m ; j++) {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
}

void remplir_matrice(int M[MaxL][MaxC], int max_alea, int n, int m){
  int i, j;
  
  for (i = 0; i < n ; i++) {
    for (j = 0; j < m ; j++) {
      M[i][j] = rand() % (max_alea + 1);
    }
  }
}
