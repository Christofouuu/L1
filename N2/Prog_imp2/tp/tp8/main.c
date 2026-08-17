#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liste.h"

#define NB_MAX 200

int main(int argc, char *argv[]){
  
  if (argc >= 3) {
    printf("Nombre trop grand d'argument (le nombre d'arguments max est de 2).\n");
    return EXIT_FAILURE;
  }

  int nb_pour_maillon = atoi(argv[1]);

  srand(time(NULL));

  Liste liste1;
  //liste1 = initialiser_liste();

  liste1.debut = creer_maillon(nb_pour_maillon);
  liste1.taille=1;

  afficher_liste(liste1);
  ajouter_en_tete(&liste1, rand()%NB_MAX + 1);
  ajouter_en_tete(&liste1, rand()%NB_MAX + 1);
  ajouter_en_tete(&liste1, rand()%NB_MAX + 1);
  afficher_liste(liste1);

  suppression_en_fin(liste1);
  afficher_liste(liste1);

  return 0;
}
