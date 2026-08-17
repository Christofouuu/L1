#ifndef MATCH_H
#define MATCH_H 

#include "Equipe.h"

#define MAX_STRING 256
#define NB_MATCHS 182

typedef struct{
  Equipe *eq_hote;    /* Pointeurs sur l'équipe hôte */
  Equipe *eq_invite;  /* Pointeurs sur l'équipe invité */ 
  int score_hote;     /* Score du match pour l'hôte */
  int score_invite;   /* Score du match pour l'invité  */
} Match;


/* Affiche les donnés d'un match dont les données sont passées par copie
   sous la forme "Toulon 10 - 15 Toulouse" */
void affiche_match(Match m);

/* Calcule les statistiques de victoire, nul, défaites et bonus 
   des équipes à partir du tableau Tmatch des matchs */
void analyse_matchs(Match Tmatch[], int n);


#endif
