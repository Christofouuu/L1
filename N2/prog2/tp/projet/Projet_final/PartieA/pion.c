#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "grille.h"
#include "pion.h"

Pion * initialiser_pion (Grille *G, int l, int c){
    Pion * res = malloc(sizeof(Pion));
    // Vérifie que l'allocation mémoire s'est déroulé sans erreur
    if ( res == NULL) {
        perror("Échec de l'allocation mémoire pour la structure \n");
        return NULL;
    }
    // Vérifie que la position du pion n'est pas hors de la Grille G
    if (l < 1 || l > G->n-1 || c < 1 || c > G->m-1){
        perror("Erreur sur la position du pion (position hors de la grille)\n");
        exit(2);
    }
    // Initialise les coordonées du Pion
    res->x = l;
    res->y = c;
    if (l == 1 || c == 1) { // Initialisation aléatoire un peu des position précédente du Pion
        res->old_x = G->n/2;
        res->old_y = G->m/2;
    } else {
        res->old_x = 1;
        res->old_y = 1;
    }

    return res;
}

void desallouer_pion (Pion *P) {
    if (P != NULL) {
        free(P);
    }
}

void verif_pion_vide (Pion *P) {
    if (P == NULL) {
        printf("Erreur sur le pion\n");
        exit(2);
    }
}

void changer_co_pion (int pos_x, int pos_y, Pion *P) {
    P->old_x = P->x; // Sauvegarde la position x précédente pour la mettre à jour
    P->x = pos_x; 
    P->old_y = P->y; // Sauvegarde la position y précédente pour la mettre à jour
    P->y = pos_y;
}

void placer_pion (int pos_x, int pos_y, Pion *P, Grille *G) {
    verif_pion_vide(P);
    // Verifie que le Pion n'est ni vide, ni hors de la Grille G
    if (pos_x < 1 || pos_x > G->n-1 || pos_y < 1 || pos_y > G->m-1) {
        printf("Erreur sur le pion\n");
        exit(2);
    }
    // Change les coordonées du Pion et change aussi dans les données de la Grille
    changer_co_pion(pos_x, pos_y, P);
    G->element[P->old_x][P->old_y] = FOND;
    G->element[P->x][P->y] = PION;
    // Actualise la Grille en la redessinant 
    grille_redessiner(G);
}

int verif_pion (int pos_x, int pos_y, Grille *G) {
    int v = 0;
    // Vérifie où se situe la nouvelle position du Pion
    if (G->element[pos_x][pos_y] == MUR) {
        v = 1; // 1 si la position est un mur
    } else if (G->element[pos_x][pos_y] == TRESOR) {
        v = 2; // 2 si la position est le trésor
    } else if (G->element[pos_x][pos_y] == PIEGE) {
        v = 3; // 3 si la position est un piege
    }

    return v;
}

void pos_pion (enum deplacement position, Pion *P, Grille *G, int *nb_point) {
    effacer_ecran();
    grille_redessiner(G);

    int coord_x, coord_y, verif;
    // Va chercher une correspondance avec la position du Pion et modifier ses coordonées en conséquence
    switch (position){
        case HAUT:
            coord_x = P->x -1;
            coord_y = P->y;
            break;      
        case BAS:
            coord_x = P->x +1;
            coord_y = P->y;
            break;      
        case DROITE:
            coord_x = P->x;
            coord_y = P->y +1;
            break;      
        case GAUCHE:
            coord_x = P->x;
            coord_y = P->y -1;
            break;
        default:
            printf("\33[41mVeuillez appuyez sur une flèche directionnel svp\33[00m\33[1E");
            break;               
    }
    if (position == HAUT || position == BAS || position == DROITE || position == GAUCHE){
        effacer_ecran();
        verif = verif_pion(coord_x, coord_y, G);
        if (verif == 0) {
            changer_co_pion(coord_x, coord_y, P);
        } else if (verif == 2) {
            changer_co_pion(coord_x, coord_y, P);
            *nb_point = *nb_point + 1;
            grille_tresor(G);
        } else if (verif == 3) {
            changer_co_pion(coord_x, coord_y, P);
        }
        G->element[P->old_x][P->old_y] = FOND;
        G->element[P->x][P->y] = PION;        
        grille_redessiner(G);
        if (verif == 3) {
            sleep(1);
            defaite_jeu1(nb_point,G);
        }
    }
}

void lancer_jeu1 (Grille *G){
    int co_l, co_c;

    printf("Saississez des coordonées pour le pion (taille de la grille de jeux %d %d) : ", G->n-2, G->m-2);
    scanf("%d %d", &co_l, &co_c);
    Pion * pion1 = initialiser_pion(G, co_l, co_c);
    sleep(1);

    placer_pion(co_l, co_c, pion1, G);
    grille_tresor(G);
    initialiser_grille_piege(5, G);

    Fonctions_jeu1(pion1, G);

    grille_vider(G);
}

void lancer_jeu1_fichier (Grille *G, Pion *P){
    grille_redessiner(G);
    Fonctions_jeu1(P, G);
    grille_vider(G);
}

void Fonctions_jeu1 (Pion *P, Grille *G) {

    enum deplacement pos;
    int test_touche, point = 0, option;
    int * pointeur_point = &point;
    

    effacer_ecran();
    grille_redessiner(G);
    printf("Vous êtes le carré \33[42mVERT\33[0m.\33[1ELes carrés \33[41mROUGES\33[00m sont les pièges.\33[1ELe carré \33[45mMAGENTA\33[00m est le trésor.\33[1ELes carrés \33[43mMARRONS\33[00m sont les murs.\n");
    printf("Comment souhaitez-vous jouer ? 1: si vous voulez jouer à un jeu pas à pas / 2: si vous voulez jouer à un jeu en continue\n");
    printf("Lorsque vous aurez validé votre choix, l'écran va s'effacer et il vous suffira d'appuyer sur une touche du clavier pour lancer le jeu.\n");
    scanf("%d", &option);

    initscr();
    raw(); // permet d'éviter les appuies accidentelles sur Ctrl + C
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    
    if (option == 2) {
        halfdelay(3);
    } else if (option != 1) {
        endwin();
        printf("Erreur sur le type d'option choisi.\n1: si vous voulez jouer à un jeu pas à pas / 2: si vous voulez jouer à un jeu en continue\n");
        grille_desallouer(G);
        effacer_ecran();
        exit(2);
    }

    do {
        test_touche = getch();
        fflush(stdout);  

        switch(test_touche) {
            case KEY_UP:   /* Ces constantes sont dans ncurses pour correspondre aux codes de touches */
                pos = HAUT;
            break;
            case KEY_DOWN: 
                pos = BAS;
            break;
            case KEY_LEFT: 
                pos = GAUCHE;
            break; 
            case KEY_RIGHT: 
                pos = DROITE;
            break;
            case 27:  /* Code de la touche ESC-Echap */
                pos = ECHAP;
            break;
            default:
                if ((pos == AUTRE && test_touche != -1) || (option == 1)){
                    pos = AUTRE;
                }
            break;
            
        }

        if (pos != ECHAP){
            pos_pion(pos, P, G, pointeur_point);

            printf("Vous êtes le carré \33[42mVERT\33[0m.\33[1ELes carrés \33[41mROUGES\33[00m sont les pièges.\33[1ELe carré \33[45mMAGENTA\33[00m est le trésor.\33[1ELes carrés \33[43mMARRONS\33[00m sont les murs.\33[1E");
            printf("Appuyez sur Echap pour quitter le jeu\33[1E");
            printf("Nombre de points : %d\33[1E", point);
        }

        fflush(stdout);

    } while (pos != ECHAP);

    effacer_ecran();

    printf("Score total durant la partie : %d point(s) !\n", point);
    
    printf("\33[1EAppuyez sur une touche pour sortir\33[1E\n");     

    do{
        test_touche = getch();
    } while(test_touche==-1);

    endwin();

}

void defaite_jeu1 (int *nb_point, Grille *G) {
    effacer_ecran();

    printf("Vous avez perdu avec un total de %d point(s) durant cette partie\n\r", *nb_point);
    sleep(2);
    printf("Appuyez sur une touche pour fermer le jeu.\n");
    
    getch();
    endwin();

    grille_desallouer(G);

    effacer_ecran();

    exit(0);
}


Pion *charger_pion_fichier(Grille *g){
    int i,j;
    Pion *p = malloc(sizeof(Pion));

    if (p == NULL) {
        perror("Échec de l'allocation mémoire pour la structure \n");
        return NULL;
    }
    for(i = 0 ; i < g->n ; i++) {
        for (j = 0; j < g->m; j++) {
            if(g->element[i][j]==PION){
                p->x=i;
                p->y=j;
                if (i == 1 || j == 1) {
                    p->old_x = g->n/2;
                    p->old_y = g->m/2;
                } else {
                    p->old_x = 1;
                    p->old_y = 1;
                }
                return p;    
            }
        }
    }
    printf("Erreur : Il n'y a pas de Pion dans la grille.\n");
    return NULL;
}