#ifndef LISTE_H
#define LISTE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct maillon_s{
  int numero; // Numéro de l'usager
  struct maillon_s * suiv; // Pointeur sur élément suivant
}maillon;

typedef struct{
  maillon * debut; // Pointeur sur le premier élément de la liste
  int taille; // Nombre de maillons dans la liste
}Liste;

maillon *creer_maillon (int val);

//Liste initialiser_liste ();

void ajouter_en_tete (Liste *l, int numero_client);

void afficher_liste (Liste l);

void suppression_en_fin(Liste l);

#endif