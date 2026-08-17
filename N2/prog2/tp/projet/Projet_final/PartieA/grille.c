#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

Grille * grille_initialiser (int n1, int m1) {
    Grille * res = malloc(sizeof(Grille));
    int i,j;

    if (res == NULL) {
        perror("Échec de l'allocation mémoire pour la structure 1\n");
        return NULL;
    }

    if (n1 < 7 || m1 < 7) {
        printf("Erreur : Taille de la grille insuffisante\n");
        exit(2);
    } else {
        res->n = n1 +2;
        res->m = m1 +2;
    }

    res->element = malloc(sizeof(enum element_grille*) * res->n);

    for (i = 0; i < res->n; i++) {
        res->element[i] = malloc(sizeof(enum element_grille*) * res->m);
        if (res->element[i] == NULL) {
            perror("Échec de l'allocation mémoire pour la structure 2\n");
            return NULL;
        }
    }
    
    for (i = 0; i < res->n; i++) {
        for (j = 0; j < res->m; j++) {
            if ((i == 0) || (i == res->n-1) || (j == 0) || (j == res->m-1)) {
                res->element[i][j] = MUR;
            } else {
                res->element[i][j] = FOND;
            }
        }
    }
        
    return res;
}

void grille_desallouer (Grille *G) {
    if (G != NULL) {
        if(G->element !=NULL){
            int i;
            for (i = 0; i < G->n ; i++) {
                if (G->element[i] != NULL) {
                    free(G->element[i]);
                }
            }
            free(G->element);
        }
        free(G);
    }
} 

void verif_grille_vide (Grille *G) {
    if (G == NULL || G->element == NULL) {
        printf("Erreur sur la grille\n");
        exit(2);
    }
}

void afficher_couleur(enum element_grille couleur) {
    switch (couleur){
        case RIEN:
            printf("%s", "\33[00m  ");  /* Affiche un carré noir */
            break;      
        case MUR:
            printf("%s", "\33[43m  ");  /* Affiche un carré jaune pour les murs */
            break;      
        case FOND:
            printf("%s", "\33[106m  ");  /* Affiche un carré cyan (106) pour le fond */
            break;      
        case TRESOR:
            printf("%s", "\33[45m  ");  /* Affiche un carré magenta pour le trésor */
            break;
        case PIEGE:
            printf("%s", "\33[41m  ");  /* Affiche un carré rouge pour les pièges */
            break;
        case PION:
            printf("%s", "\33[42m  ");  /* Affiche un carré vert pour le joueur */
            break;
        default:
            printf("%s", "\33[00m  ");  /* Affiche un carré noir */
            break;               
        }  
 
    printf("\033[00m"); /* Declare le fond noir pour la suite */
}

void grille_vider (Grille *G) {
    verif_grille_vide (G);

    //printf("\33[2J");
    //printf("\33[H");
    int i, j;

    for (i = 0; i < G->n ; i++) {
        for (j = 0; j < G->m; j++) {
            G->element[i][j] = RIEN;
        }
    }
    grille_redessiner(G);
}

void effacer_ecran () {
    printf("\33[2J"); // Efface l'écran
    printf("\33[H"); // Met le curseur en haut à gauche de l'écran
}

void grille_redessiner (Grille *G) {
    verif_grille_vide (G);

    int i, j;
    printf("\33[H");
    for (i = 0; i < G->n; i++){
        for (j = 0; j < G->m; j++) {
            afficher_couleur(G->element[i][j]);
            // printf(" "); //pour compter le nombre de carré il y a dans la ligne
        }
        // printf("\n"); //pour compter le nombre de carré il y a dans la colonne
        printf("\n\r"); // Retour à la ligne + retour chariot
    }
}

int nb_alea (int debut, int fin) {
    int res;
    
    do {
        res = rand() % (fin-1);
    } while (res >= fin-2 || res <= debut);

    return res;
}

void grille_tresor(Grille *G) {
    verif_grille_vide(G);

    int ligne_tresor, colonne_tresor;

    do {
        ligne_tresor = nb_alea(0, G->n);
        colonne_tresor = nb_alea(0, G->m);
    } while (G->element[ligne_tresor][colonne_tresor] == PION || G->element[ligne_tresor][colonne_tresor] == PIEGE || G->element[ligne_tresor][colonne_tresor] == MUR || G->element[ligne_tresor][colonne_tresor] == TRESOR);

    G->element[ligne_tresor][colonne_tresor] = TRESOR;
    
}

void initialiser_grille_piege(int n, Grille *G) {
    verif_grille_vide(G);
    
    int i, tab_piege[n][2];
        for (i = 0; i < n; i++) {
            do {
                tab_piege[i][0] = nb_alea(0, G->n);
                tab_piege[i][1] = nb_alea(0, G->m);
                /*Empêche un piège d'apparaitre sur le trésor, une case adjacente au pion ou un piège déjà existant */
            } while (G->element[tab_piege[i][0]][tab_piege[i][1]] == PION || G->element[tab_piege[i][0]][tab_piege[i][1]] == TRESOR || G->element[tab_piege[i][0]-1][tab_piege[i][1]] == PION || G->element[tab_piege[i][0]+1][tab_piege[i][1]] == PION || G->element[tab_piege[i][0]][tab_piege[i][1]-1] == PION || G->element[tab_piege[i][0]][tab_piege[i][1]+1] == PION || G->element[tab_piege[i][0]][tab_piege[i][1]] == PIEGE);
            G->element[tab_piege[i][0]][tab_piege[i][1]] = PIEGE;
        }
    
}

Grille *Grille_charger_fichier(FILE *fichier){
    if(!fichier){
        printf("Fichier non trouver\n");
        return NULL;
    }
    
    int ligne,colonne;
    if((fscanf(fichier,"%d %d",&ligne,&colonne) )!=2){
        fprintf(stderr,"erreur d'argument pour lignes et colonnes\n");
        return NULL;
    }
    Grille *grille=grille_initialiser(ligne-2, colonne-2);
    if(!grille){
        printf("erreur allouer grille");
        grille_desallouer(grille);
        return NULL;
    } 
    int i,j;
    char tmp ;
    for(i = 0; i < ligne; i++){
        for(j = 0; j < colonne; j++){
            tmp=fgetc(fichier);
            // la fonction fgetc permet de prendre caractère un par un 
            if((tmp)==EOF){
                fprintf(stderr,"erreur argument");
                break;
            }

            if(tmp=='\n'){
                tmp=fgetc(fichier);
                // si il y a un saut de ligne on ignore 
            } 
            switch(tmp){
                case 'M':
                    grille->element[i][j]=MUR;
                    break;
                case 'P':
                    grille->element[i][j]=PION;
                    break;
                case 'Q':
                    grille->element[i][j]=PIEGE;
                    break;
                case 'B':
                    grille->element[i][j]=TRESOR;
                    break;
                case ' ':
                    grille->element[i][j]=FOND;
                    break;
                default:
                    fprintf(stderr,"Caractère inconnu");
                    break;
            } 
             
        }
    }
    return grille;
}


