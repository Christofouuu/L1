#ifndef PION_H
#define PION_H

typedef struct {
    int x; // Coordonnée x , ligne sur laquelle sera le pion sur la grille
    int y; // Coordonnée y , colonne sur laquelle sera le pion sur la grille
    int old_x; // Ancienne coordonnée x , ligne sur laquelle aura été le pion sur la grille
    int old_y; // Ancienne coordonnée y , ligne sur laquelle aura été le pion sur la grille
} Pion;

enum deplacement {HAUT, BAS, DROITE, GAUCHE, ECHAP, AUTRE};

Pion * initialiser_pion (Grille *G, int l, int c); // Initalise un Pion avec en coordonnée l (pour les lignes) et c (pour les colonnes)

void desallouer_pion (Pion *P); // Désalloue le pion 

void verif_pion_vide (Pion *P); // Vérifie que le pion est non vide, sinon ferme le programme

void changer_co_pion (int pos_x, int pos_y, Pion *P); // Change les coordonées du Pion P

void placer_pion (int pos_x, int pos_y, Pion *P, Grille *G); // Met les coordonées du Pion P dans la Grille G

int verif_pion (int pos_x, int pos_y, Grille *G); // Vérifie que les coordonées pos_x ou pos_y n'attérissent pas un évènement de la Grille G

void pos_pion (enum deplacement position, Pion *P, Grille *G, int *nb_point); // Traite le déplacement du pion en fonction de la touche du clavier appuyée

void lancer_jeu1 (Grille *G); // Récupère toute les données rentré manuellement pour lancer le jeu

void lancer_jeu1_fichier (Grille *G, Pion *P); // Récupère toute les données depuis un fichier pour lancer le jeu

void Fonctions_jeu1 (Pion *P, Grille *G); // Fonction de jeu principale

void defaite_jeu1 (int *nb_point, Grille *G); // Affiche un message de fin avec le nombre de point acquérie durant la partie

Pion *charger_pion_fichier(Grille *g); // Initialise le Pion via les données de la Grille

#endif