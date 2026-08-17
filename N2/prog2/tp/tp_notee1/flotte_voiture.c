#include "flotte_voiture.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Flotte *creer_flotte (int n) {
  int i;
  Flotte * res = malloc(sizeof(Flotte));
  if (res == NULL) {
      perror("Échec de l'allocation mémoire pour la structure 1\n");
      return NULL;
  }
  if (n <= 0) {
    exit(2);
  } else {
    res->nb_voitures = n;
  }
  
  res->TabV = malloc(sizeof(Voiture*) * n);
  if (res->TabV == NULL) {
    perror("Échec de l'allocation mémoire pour la structure 2\n");
    return NULL;
  }
    
   
  // for (i = 0; i < n; i++){
  //   if (res->TabV[i] == NULL) {
  //     perror("Échec de l'allocation mémoire pour la structure 3");
  //     return NULL;
  //   }
  //}
  
  for (i = 0; i < n; i++){
    res->TabV[i] = NULL;
  }
   return res;
}

void initialisee_random(Flotte *F){
    int pourcent, i; 
    for (i = 0; i < F->nb_voitures; i++) {
      F->TabV[i] = malloc(sizeof(Voiture));
      F->TabV[i]->immatriculation = rand() % 100000000;
      while (F->TabV[i]->immatriculation < 10000000 || F->TabV[i]->immatriculation > 100000000) {
          F->TabV[i]->immatriculation = rand() % 100000000;
      }
    }
    
    for (i = 0; i < F->nb_voitures ; i++) {
      F->TabV[i]->nb_kilometres = rand() % 200001; 
      while (F->TabV[i]->nb_kilometres < 5000 || F->TabV[i]->nb_kilometres > 200000) {
          F->TabV[i]->nb_kilometres = rand() % 200001;
      }
    }
    
    for (i = 0; i < F->nb_voitures ; i++) {
      pourcent = rand() % 101;
      if (pourcent <= 60) {
        F->TabV[i]->type = 1;
      } else {
        F->TabV[i]->type = 0;
      }
    }
}

void affiche(Flotte* F){
  int i;
  for(i = 0; i < F->nb_voitures ; i++) {
    printf("Voiture numéro %d, Immatriculation : \033[41m%d\033[0m\nNombre de Kilomètres au compteur : \033[41m%d\033[0m\n", i+1, F->TabV[i]->immatriculation, F->TabV[i]->nb_kilometres);
    if (F->TabV[i]->type == 0) {
      printf("Type : \033[41mEssence\033[0m\n\n");
    } else {
      printf("Type : \033[41mElectrique\033[0m\n\n");
    }
  }
}

void desalloue_flotte(Flotte **F){
  int i;
  
  for (i = 0; i < (*F)->nb_voitures; i++) {
    if ((*F)->TabV[i] != NULL) {
      free((*F)->TabV[i]);
    }
  }
  free(*F);
}

void affiche_plus_ancienne(Flotte* F) {
  int i, tmp_tab = -1, tmp_km=200000;  

  for (i = 0; i < F->nb_voitures ; i++) {
    if (F->TabV[i]->type == 0){
      if((tmp_km > F->TabV[i]->nb_kilometres) ) {
        tmp_tab = i;
        tmp_km = F->TabV[i]->nb_kilometres;
      }
    } 
  }

  if (tmp_tab == -1) { 
    printf("Il n'y a aucune voiture à essence dans votre Flotte.\n");
  } else {
    printf("La voiture la plus ancienne est la numéro %d avec %d km.\n", tmp_tab + 1, tmp_km);
  }
}

void tri_par_kilometrage(Flotte *F){
  int i, j, pos_min;
  for (i = 0; i < F->nb_voitures - 1; i++) {
    pos_min = i;
    for (j = i + 1; j < F->nb_voitures; j++)
      if (F->TabV[j]->nb_kilometres < F->TabV[pos_min]->nb_kilometres) pos_min = j;

      echanger(&F->TabV[i], &F->TabV[pos_min]);
  }
}

void echanger(Voiture **x, Voiture **y) {
  Voiture *tmp = *x;
  *x = *y;
  *y = tmp;
}

Voiture** extrait_essence(Flotte* F){
	int i, j = 0, compteur_essence = 0;

	for(i = 0; i < F->nb_voitures; i++) {
		if (F->TabV[i]->type == 0) {
			compteur_essence++;
		}
	}

	Voiture** TabE = malloc(sizeof(Voiture*) * compteur_essence);
    if (TabE == NULL) {
        // Gestion d'erreur en cas d'échec de l'allocation
        return NULL;
    }

	for(i = 0; i < F->nb_voitures; i++) {
		if (F->TabV[i]->type == 0) {
			TabE[j] = malloc(sizeof(Voiture));
			TabE[j]->immatriculation = F->TabV[i]->immatriculation;
			TabE[j]->nb_kilometres = F->TabV[i]->nb_kilometres;
			TabE[j]->type = 0;

			j++;
		}

	}
	return TabE;
}
