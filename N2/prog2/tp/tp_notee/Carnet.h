#ifndef _CARNET_H
#define _CARNET_H

#define MAX_SIZE 50

typedef struct {
  char numero[15];     /* Numero de téléphone du contact */
  char nom[MAX_SIZE];  /* Nom Prénom */
} Contact;

typedef struct{
  int nbcontact;   /* Nb de contacts */
  Contact** tabC;  /* Tableau de pointeurs sur Contact */
} Carnet;


/* Alloue un struct Carnet contenant n Contact, chacun initialisé à NULL
   et retourne son adresse. */
Carnet * creer_carnet(int n);

/* Génère nbcontact Contact dans le carnet
   en allouant les Contact et en remplissant aléatoirement les champs
   numero est un numero à 10 chiffres groupés par 2 et séparés par un point
   le nom limité à une lettre entre A et Z.*/
void generation_aleatoire_contacts(Carnet *C);

/* Affiche toutes les données du carnet.*/
void afficher_contacts(Carnet *C);

/* Désalloue carnet
   Il n'est pas demandé de mettre la variable du main à NULL.*/
void desalloue_carnet(Carnet *C);

/* Recherche un contact à partir de son nom
   et retourne l'indice de la case le contenant s'il existe et NULL sinon*/
int rechercher_contact(Carnet *C,  char* nom);

/* Déplace le contact dont le nom est donné en paramètre
   en première place du carnet */
void deplace_en_tete_contact(Carnet *C, char *nom);

Contact echanger_contact(Contact **x, Contact **y);

/* Teste s'il existe deux contacts de même nom */
int recherche_doublon(Carnet *C);


#endif
