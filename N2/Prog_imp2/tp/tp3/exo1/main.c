#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MaxL 1000 // Taille maximale d'une matrice en nombre de lignes
#define MaxC 1000 // Taille maximale d'une matrice en nombre de colonnes
#include "matrice.h"
#include "frequent.h"

int main() {
  int taille, alea;
  //Exemple de déclaration d'une matrice statique M
  int M[MaxL][MaxC];
  srand(time(NULL));
  
  clock_t temps_initial, temps_initial2 ; /* Temps initial en micro-secondes */
  clock_t temps_final, temps_final2 ; /* Temps final en micro-secondes */
  double temps_cpu, temps_cpu2 ; /* Temps total en seconde */
  
  printf("Choisissez le nombre de lignes et de colonnes de votre matrice : ");
  scanf("%d",&taille); 
  
  printf("Choisissez le maximum de votre matrice : ");
  scanf("%d",&alea);
  
  remplir_matrice(M, alea, taille);
  afficher_matrice(M, taille);
  
  temps_initial = clock () ;
  frequent_4(M,taille);
  temps_final = clock () ;  
  temps_cpu = (( double )( temps_final - temps_initial ))/CLOCKS_PER_SEC;
  printf("La fonction avec 4 boucles a pris %f secondes pour s'exécuter pour une taille de %dx%d.\n\n",temps_cpu, taille, taille);
    
  temps_initial2 = clock () ;
  frequent_2(M,taille,alea);
  temps_final2 = clock () ;  
  temps_cpu2 = (( double )( temps_final2 - temps_initial2 ))/CLOCKS_PER_SEC;
  printf("La fonction avec 4 boucles a pris %f secondes pour s'exécuter pour une taille de %dx%d.\n ",temps_cpu2, taille, taille);
  
  return 0;
}


