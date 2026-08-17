#ifndef GRILLE_H
#define GRILLE_H

enum element_grille {RIEN, MUR, FOND, PION, PIEGE, TRESOR, TELEPORTATION};

typedef struct {
    int n; // Taille horizontale n de la Grille
    int m; // Taille verticale m de la Grille
    enum element_grille** element; // Tableau à 2 dimensions remplit d'éléments du jeu
} Grille ;

Grille * grille_initialiser (int n1, int m1); // Initialise une matrice/grille de taille n1 * m1

void grille_desallouer (Grille *G); // Désalloue une grille G

void verif_grille_vide (Grille *G); // Vérifie que la grille est non, sinon ferme le programme

void afficher_couleur(enum element_grille couleur); // Affiche la couleur en fonction de l'élement_grille donnée  (pion, mur, fond, etc...)

void grille_vider (Grille *G); // Initialise les valeurs la structure de grille en RIEN

void effacer_ecran (); // Efface l'écran et met le curseur en haut à gauche

void grille_redessiner (Grille *G); //Redessine la grille en fonction de la Grille G donnée

void grille_redessiner2 (Grille *G);

int nb_alea (int debut, int fin); // Renvoie un nombre aléatoire entre debut et fin

void grille_tresor(Grille *G); // Place le trésor aléatoirement sur la grille en faisant attention à ne pas le poser au même endroit que le pion

void initialiser_grille_piege(int n, Grille *G); //Initialise n piège(s) dans la Grille

Grille *Grille_charger_fichier(FILE *fichier); // Charge une grille avec toutes ses données (pièges, trésor et pion) en fonction du fichier donnée

#endif