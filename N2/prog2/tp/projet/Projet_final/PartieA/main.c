#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "grille.h"
#include "pion.h"


int main (int argv, char *argc[]) {

    srand(time(NULL));
    int lignes,colonnes;
    if (argv != 1) {
        printf("Erreur sur le nombre d'arguments.\n");
        exit(2);
    }

    int choix;

    printf("Choisissez votre style de jeu :\n");
    printf("1- Saisie manuelle de la taille de la Grille et de la position du Pion\n");
    printf("2- Saisie par un fichier les informations de la Grille et de la position du Pion\n");
    scanf("%d", &choix);

    if (choix == 1) {
        printf("Faire une grille de minimum 7x7.\nChoisissez la dimension de votre Grille : ");
        scanf("%d %d", &lignes, &colonnes);
        
        Grille * grille1 = grille_initialiser(lignes, colonnes);
        effacer_ecran();
        grille_redessiner(grille1);
        lancer_jeu1(grille1);
        grille_desallouer(grille1);
    } else if (choix == 2) {
        //lire le fichier d'entrer en prenant la taille de la grille + les coordonées des pieges, du trésor et du pion
        FILE(*f)=fopen("grille.txt","r");
        if(!f){
            fprintf(stderr,"Fichier non trouver.\n");
            return EXIT_FAILURE;
        }
            Grille * grille1 = Grille_charger_fichier(f);
            Pion * pion1 = charger_pion_fichier(grille1);
            lancer_jeu1_fichier(grille1, pion1);

            grille_desallouer(grille1);
    } else {
        printf("Erreur sur le choix.\n");
        return EXIT_FAILURE;
    }

    effacer_ecran();
    
    return 0;
}