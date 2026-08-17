#include <stdio.h>
#include "frequent.h"

void frequent_4(int M[MaxL][MaxC], int n){
  int compteur[n*n] ;
  int i, j, k, l, repetition, pos_coor;

  for(i=0;i<n*n;i++){
    compteur[i]=0;
  }

  for( i = 0; i < n; i++){
    for( j = 0; j < n; j++){
      for( k = 0; k < n; k++){
        for(l = 0; l < n; l++){
          if (M[i][j] == M[k][l]){
            compteur[(n*i)+j]++;
          }
        }
      }
    }
  }

  repetition = 0;

  for (k = 0; k < n*n; k++){
    if (repetition < compteur[k]) {
      repetition = compteur[k];
      pos_coor = k;
      //printf("repetition=%d k=%d\n",repetition,k); ligne pour vérifier : repetition étant le nombre de fois que le nombre k est répété
    }
  }
  
  printf("la valeur la plus fréquente est %d qui est répété %d fois pour 4 boucles.\n",M[pos_coor/n][pos_coor%n], repetition);
}

void frequent_2(int M[MaxL][MaxC], int n, int chiffre){

    int i, j, max_indice, max_frequent;
    int tableau[chiffre];
    
    for( i = 0; i < chiffre+1; i++){
      tableau[i]=0;
    }

    max_frequent=tableau[0];
    max_indice=0;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            tableau[(M[i][j])]++;
            if(max_frequent < tableau[(M[i][j])]) {
                max_frequent = tableau[(M[i][j])];
                max_indice = M[i][j]; 
            } 
            
            /*(pour tester les bugs)
            printf("M[%d][%d]=%d , %d\n",i,j,M[i][j],tableau[(M[i][j])]);
            */
        }
    }
    printf("La valeur la plus fréquente est %d qui est répété %d fois pour 2 boucles\n", max_indice, max_frequent);
}
