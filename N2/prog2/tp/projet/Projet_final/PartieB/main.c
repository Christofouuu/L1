#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "grille.h"
#include "pion.h"
#define CHAR_MAX 64

int main (int argv, char *argc[]) {
    
    srand(time(NULL));
    if (argv != 1) {
        printf("Erreur sur le nombre d'arguments.\n");
        exit(2);
    } // pour vérifier que l'utilisateur n'a pas rentré d'argument à la fonction

    printf("Pour une meilleure expérience, mettez votre en Terminal en plein écran.\nAppuyez sur Entrée quand vous êtes prêt\n");
    char tmp[CHAR_MAX];
    scanf("%c", tmp); // pour attendre que l'utilisateur appuie sur Entrée pour continuter le programme
    niv_suiv();

    effacer_ecran();
    
    printf("Merci d'avoir jouée à ce jeu qui vous a été présenté par : CHEN YuanDong Théo et \33[94m\33[47mLI Christophe\33[39m\33[49m\n");
    return 0;
}