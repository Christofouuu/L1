#ifndef _FLOTTE_VOITURE_H_
#define _FLOTTE_VOITURE_H_


typedef struct{
  int immatriculation; /* Numéro d'immatriculation (simplifié à un entier)  */
  int nb_kilometres;   /* Nb de kilomètres au compteurs */
  int type;            /* 0: essence ; 1: electrique */
} Voiture;

typedef struct{
  int nb_voitures;  /* Nombre de voitures considérées */
  Voiture** TabV;    /* Tableau de pointeurs sur des struct Voitures */
} Flotte;


/* Alloue un struct Flotte contenant n Voiture, chacune initialisée à NULL
   et retourne son adresse */
Flotte* creer_flotte(int n);

/* Initialise aléatoirement les champs d'une flotte de Voiture
   Les numéros d'immatriculation sont des nombres entiers à 8 chiffres
   dont le premier ne peut pas être un zéro.
   Le nombre de kilomètres est entre 5000 et 200000.
   Il y a environ 60% de voitures électriques */
void initialisee_random(Flotte *F);

/* Affiche toutes les informations d'une flotte de Voiture */
void affiche(Flotte* F);

/* Désalloue un struct Flotte* dont l'adresse est passée en paramère, ainsi que toutes les données liées. A la fin, le struct Flotte est à NULL*/
void desalloue_flotte(Flotte **F);

/* Affiche une voiture à essence ayant le plus de kilomètres au compteur */
void affiche_plus_ancienne(Flotte* F);

/* Trie le tableau des pointeurs sur Ville dans l'ordre croissant du kilométrages.
Cette fonction utilise un tri par sélection, c'est-à-dire un tri qui recherche le plus petit élément à partir d'une position i=0, puis intervertit le contenu entre i et cet élément, puis qui incrémente i et recommence.*/
void tri_par_kilometrage(Flotte *F);

void echanger(int *x, int *y);

/* Crée un tableau de pointeurs sur Voiture ne contenant que les voitures
 à essence d'une flotte passée en paramètre.
 Les struct Voiture ne sont pas dupliqués, il s'agit juste de dupliquer les adresses.*/
Voiture** extrait_essence(Flotte* F);

/* Transforme les Voiture à essence du tableau passées en paramètre
   en Voiture électrique */
void transforme_electrique(Voiture** T);

/* Affiche une voiture quelconque ayant le deuxième plus grand kilomètrage au compteur, i.e. n'ayant pas le plus grand kilométrage, mais le suivant. Attention, il peut y avoir plusieurs voitures de plus grand kilométrage*/
void affiche_deuxieme_ancienne(Flotte* F);


#endif
