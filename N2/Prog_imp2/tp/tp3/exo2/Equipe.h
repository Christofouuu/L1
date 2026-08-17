#ifndef EQUIPE_H
#define EQUIPE_H

#define MAX_STRING 256
#define NB_EQUIPES 14

typedef struct {
  char nom[MAX_STRING];                   /* Nom du club */
  int nb_points;                          /* Score à l'issue des poules */
  int nb_victoires, nb_nuls, nb_defaites; /* Statistiques sur les matchs */
  int nb_bonus; 
} Equipe;


/* Affiche les donnés d'une équipe dont le pointeur est passé en paramètre
   sous la forme "Racing 15 pts (G: N: P: B:)" */
void affiche_equipe(const Equipe *eq);

/* Renvoie un pointeur sur une équipe sotckée dans le tableau Teq
   et qui a le nom passé en paramètre */
Equipe* rech_ptr_equipe(Equipe Teq[], int n, char nom[]);

/* Calcul du nombre total de points pour chaque équipe */
void calcul_points(Equipe Teq[], int n);

/* Retourne un pointeur sur la premiere equipe du classement */
Equipe* premier_classement(Equipe Teq[], int n);

/* Retourne l'indice du tableau Teq de l'équipe de plus grand score 
   à partir de l'incide d */
int max_indice(Equipe Teq[], int n, int d);

/* Tri par sélection des équipes par score */
void trier_equipes(Equipe Teq[], int n);

#endif
