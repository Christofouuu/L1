#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "grille.h"
#include "pion.h"

Pion * initialiser_pion (Grille *G, int l, int c){
    Pion * res = malloc(sizeof(Pion));

    if ( res == NULL) {
        perror("Échec de l'allocation mémoire pour la structure \n");
        return NULL;
    }

    if (l < 1 || l > G->n-1 || c < 1 || c > G->m-1){
        perror("Erreur sur la position du pion (position hors de la grille)\n");
        exit(2);
    }

    res->x = l;
    res->y = c;
    if (l == 1 || c == 1) {
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
    P->old_x = P->x;
    P->x = pos_x;
    P->old_y = P->y;
    P->y = pos_y;
}

int verif_pion (int pos_x, int pos_y, Grille *G) {
    int v = 0;
    if (G->element[pos_x][pos_y] == MUR) {
        v = 1; // 1 si la position est un mur
    } else if (G->element[pos_x][pos_y] == TRESOR) {
        v = 2; // 2 si la position est le trésor
    } else if (G->element[pos_x][pos_y] == PIEGE) {
        v = 3; // 3 si la position est un piege
    } else if (G->element[pos_x][pos_y] == TELEPORTATION) {
        v = 4;
    }

    return v;
}

void pos_pion (enum deplacement position, Pion *P, Grille *G, int *nb_point) {
    effacer_ecran();
    grille_redessiner(G);

    int coord_x, coord_y, verif;

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
        } else if (verif == 4) {
            // changer_co_pion(coord_x, coord_y, P);
            int ligne_tp , colonne_tp;
            do {
                ligne_tp = nb_alea(0, G->n);
                colonne_tp = nb_alea(0, G->m);
            } while (G->element[ligne_tp][colonne_tp] == PION || G->element[ligne_tp][colonne_tp] == PIEGE || G->element[ligne_tp][colonne_tp] == MUR || G->element[ligne_tp][colonne_tp] == TRESOR|| G->element[ligne_tp][colonne_tp] == TELEPORTATION);
            G->element[P->x][P->y] = FOND;    
            G->element[ligne_tp][colonne_tp] = PION;
            changer_co_pion(ligne_tp, colonne_tp, P);
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

int lancer_jeu1_fichier (Grille *G, Pion *P){
    
    grille_redessiner(G);
    int fin = Fonctions_jeu1(P, G);
    grille_vider(G);
    return fin;
}

int Fonctions_jeu1 (Pion *P, Grille *G) {

    enum deplacement pos;
    int test_touche, point = 0, option, fin = 0;
    int * pointeur_point = &point;
    

    effacer_ecran();
    grille_redessiner(G);
    printf("Vous êtes le carré \33[42mVERT\33[0m.\33[1ELes carrés \33[41mROUGES\33[00m sont les pièges.\33[1ELe carré \33[45mMAGENTA\33[00m est le trésor.\33[1ELes carrés \33[43mMARRONS\33[00m sont les murs.\33[1ELe carré \33[100mNOIR\33[00m est un téléporteur\33[1E");
    printf("Comment souhaitez-vous jouer ? 1: si vous voulez jouer à un jeu pas à pas / 2: si vous voulez jouer à un jeu en continue\33[1E");
    printf("Lorsque vous aurez validé votre choix, l'écran va s'effacer et il vous suffira d'appuyer sur une touche du clavier pour lancer le jeu.\33[1E");
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
        printf("Erreur sur le type d'option choisi.\33[1E1: si vous voulez jouer à un jeu pas à pas / 2: si vous voulez jouer à un jeu en continue\33[1E");
        grille_desallouer(G);
        desallouer_pion(P);
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
            case 32:  /* Code de la touche Space-Espace */
                pos = ESPACE;
            break;
            case 263:  /* Code de la touche BackSpace-Retour */
                grille_tresor(G);
                pos = AUTRE;
            break;
            default:
                if (option == 1){
                    pos = AUTRE;
                }
            break;
            
        }

        if (pos != ECHAP && pos != ESPACE){
            pos_pion(pos, P, G, pointeur_point);

            printf("Vous êtes le carré \33[42mVERT\33[0m.\33[1ELes carrés \33[41mROUGES\33[00m sont les pièges.\33[1ELe carré \33[45mMAGENTA\33[00m est le trésor.\33[1ELes carrés \33[43mMARRONS\33[00m sont les murs.\33[1ELe carré \33[100mNOIR\33[00m est un téléporteur\33[1E");
            printf("Appuyez sur BackSpace pour générer un nouveau trésor en plus (en cas de disparition du trésor)\33[1E");
            printf("Appuyez sur Echap pour quitter le jeu\33[1E");
            printf("Appuyez sur Espace pour passer au niveau suivant\33[1E");
            printf("Nombre de points : %d\33[1E", point);
        }

        fflush(stdout);

    } while (pos != ECHAP && pos != ESPACE);

    effacer_ecran();

    if (pos == ECHAP) {
        printf("Score total durant la partie : %d point(s) !\n", point);
        
        printf("\33[1EAppuyez sur une touche pour sortir\33[1E\n");     

        do{
            test_touche = getch();
        } while(test_touche==-1);

        endwin();
    } else if (pos == ESPACE) {
        fin = 1;
    }
    curs_set(1);
    return fin;
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

void niv_suiv(){
    int niv_actuel = 1, continuer;
    do {
        if (niv_actuel == 1) {
            FILE(*f)=fopen("niveau1.txt","r");
            if(!f){
                fprintf(stderr,"Fichier non trouver.\n");
                exit(2);
            }
            Grille * grille1 = Grille_charger_fichier(f);
            Pion * pion1 = charger_pion_fichier(grille1);
            continuer = lancer_jeu1_fichier(grille1, pion1);

            grille_desallouer(grille1);
            desallouer_pion(pion1);
        }
        if (niv_actuel == 2) {
            FILE(*f)=fopen("niveau2.txt","r");
            if(!f){
                fprintf(stderr,"Fichier non trouver.\n");
                exit(2);
            }
            Grille * grille2 = Grille_charger_fichier(f);
            Pion * pion2 = charger_pion_fichier(grille2);
            printf("A partir de maintenant vous verrez plus les réponses que vous écrirez. Ils existeront mais ne seront juste pas visible.\n");
            printf("Si le curseur clignote, alors écrivez votre choix, sinon JOUER en vous déplaçant avec les flèches directionnel.\n");
            continuer = lancer_jeu1_fichier(grille2, pion2);

            grille_desallouer(grille2);
            desallouer_pion(pion2);
        } else if (niv_actuel == 3) {
            FILE(*f1)=fopen("niveau3_1.txt","r");
            FILE(*f2)=fopen("niveau3_2.txt","r");
            if(!f1 || !f2){
                fprintf(stderr,"Fichier non trouver.\n");
                exit(2);
            }
            Grille * grille3 = Grille_charger_fichier(f1);
            Pion * pion3 = charger_pion_fichier(grille3);
            Grille * grille4 = Grille_charger_fichier(f2);
            Pion * pion4 = charger_pion_fichier(grille4);

            continuer = lancer_jeu2_fichier(grille3, pion3, grille4, pion4);

            grille_desallouer(grille3);
            desallouer_pion(pion3);
            grille_desallouer(grille4);
            desallouer_pion(pion4);
        } else if (niv_actuel > 3) {
            printf("Malheuresement, c'était le dernier niveau ;(\nOn espère que ça vous a plu !\n");
            printf("Appuyez sur Entrée pour continuer.\n");
            char tmp[CHAR_MAX];
            scanf("%c", tmp);
            break;
        }
        niv_actuel = niv_actuel + 1;
    } while (continuer == 1);
}

int lancer_jeu2_fichier(Grille * G1, Pion *P1, Grille * G2, Pion *P2) {
    grille_redessiner(G1);
    grille_redessiner2(G2);
    int fin = Fonctions_jeu2(G1, P1 , G2 , P2);
    grille_vider(G1);
    grille_vider(G2);
    return fin;
}

int Fonctions_jeu2 (Grille * G1, Pion *P1, Grille * G2, Pion *P2) {

    enum deplacement pos;
    int test_touche, option, fin = 0;
    

    effacer_ecran();
    grille_redessiner(G1);
    grille_redessiner2(G2);
    printf("Vous êtes le carré \33[42mVERT\33[0m.\33[1ELes carrés \33[41mROUGES\33[00m sont les pièges.\33[1ELe carré \33[45mMAGENTA\33[00m est le trésor.\33[1ELes carrés \33[43mMARRONS\33[00m sont les murs.\33[1E");
    printf("Comment souhaitez-vous jouer ? 1: si vous voulez jouer à un jeu pas à pas / 2: si vous voulez jouer à un jeu en continue\33[1E");
    printf("Lorsque vous aurez validé votre choix, l'écran va s'effacer et il vous suffira d'appuyer sur une touche du clavier pour lancer le jeu.\33[1E");
    printf("Le but de ce niveau, est que les 2 Pions arrivent sur le Trésor en même temps.\33[1E");
    printf("ATTENTION !! Les déplacements des deux Pions sont synchronisées.\33[1E");
    printf("Appuyez sur Entrée pour continuer.\33[1E");
    scanf("%d", &option);

    initscr();
    // raw(); // permet d'éviter les appuies accidentelles sur Ctrl + C
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    
    if (option == 2) {
        halfdelay(3);
    } else if (option != 1) {
        endwin();
        printf("Erreur sur le type d'option choisi.\33[1E1: si vous voulez jouer à un jeu pas à pas / 2: si vous voulez jouer à un jeu en continue\33[1E");
        grille_desallouer(G1);
        grille_desallouer(G2);
        desallouer_pion(P1);
        desallouer_pion(P2);
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
            case 32:  /* Code de la touche Space-Espace */
                pos = ESPACE;
            break;
            default:
                if ((pos == AUTRE && test_touche != -1) || (option == 1)){
                    pos = AUTRE;
                }
            break;
            
        }

        if (pos != ECHAP && pos != ESPACE){
            pos_pion2(pos,P1, G1, P2, G2);

            printf("Vous êtes le carré \33[42mVERT\33[0m.\33[1ELes carrés \33[41mROUGES\33[00m sont les pièges.\33[1ELe carré \33[45mMAGENTA\33[00m est le trésor.\33[1ELes carrés \33[43mMARRONS\33[00m sont les murs.\33[1E");
            printf("Appuyez sur Echap pour quitter le jeu\33[1E");
            printf("Appuyez sur Espace pour passer au niveau suivant\33[1E");
        }

        fflush(stdout);

    } while (pos != ECHAP && pos != ESPACE);

    effacer_ecran();

    if (pos == ECHAP) {        
        printf("\33[1EAppuyez sur une touche pour sortir\33[1E\n");     

        do{
            test_touche = getch();
        } while(test_touche==-1);

        endwin();
    } else if (pos == ESPACE) {
        fin = 1;
    }
    curs_set(1);
    return fin;
}

void pos_pion2 (enum deplacement position, Pion *P1, Grille *G1, Pion *P2, Grille *G2) {
    effacer_ecran();
    grille_redessiner(G1);
    grille_redessiner2(G2);

    int coord_x1, coord_y1, coord_x2, coord_y2, verif1, verif2;

    switch (position){
        case HAUT:
            coord_x1 = P1->x -1;
            coord_y1 = P1->y;
            coord_x2 = P2->x -1;
            coord_y2 = P2->y;
            break;      
        case BAS:
            coord_x1 = P1->x +1;
            coord_y1 = P1->y;
            coord_x2 = P2->x +1;
            coord_y2 = P2->y;
            break;      
        case DROITE:
            coord_x1 = P1->x;
            coord_y1 = P1->y +1;
            coord_x2 = P2->x;
            coord_y2 = P2->y +1;
            break;      
        case GAUCHE:
            coord_x1 = P1->x;
            coord_y1 = P1->y -1;
            coord_x2 = P2->x;
            coord_y2 = P2->y -1;
            break;
        default:
            printf("\33[41mVeuillez appuyez sur une flèche directionnel svp\33[00m\33[1E");
            break;               
    }
    if (position == HAUT || position == BAS || position == DROITE || position == GAUCHE){
        effacer_ecran();
        verif1 = verif_pion(coord_x1, coord_y1, G1);
        verif2 = verif_pion(coord_x2, coord_y2, G2);
        if (verif1 == 0 && verif2 == 0) {
            changer_co_pion(coord_x1, coord_y1, P1);
            changer_co_pion(coord_x2, coord_y2, P2);
        } else if (verif1 == 2 && verif2 == 2) {
            changer_co_pion(coord_x1, coord_y1, P1);
            changer_co_pion(coord_x2, coord_y2, P2);
                
            message_fin(G1, G2, P1, P2);
        }else if (verif1 == 3 || verif2 == 3) {
            changer_co_pion(coord_x1, coord_y1, P1);
            changer_co_pion(coord_x2, coord_y2, P2);
        } else if (verif1 == 1 && verif2 !=1 ) {
            changer_co_pion(coord_x2, coord_y2, P2);
        } else if (verif2 == 1 && verif1 !=1) {
            changer_co_pion(coord_x1, coord_y1, P1);
        }
        G1->element[P1->old_x][P1->old_y] = FOND;
        G1->element[P1->x][P1->y] = PION;        
        G2->element[P2->old_x][P2->old_y] = FOND;
        G2->element[P2->x][P2->y] = PION;        
        grille_redessiner(G1);
        grille_redessiner2(G2);
        if (verif1 == 3 || verif2 == 3) {
            sleep(1);
            defaite_jeu2(G1, G2, P1, P2);
        }
    }
}

void defaite_jeu2 (Grille *G1, Grille *G2, Pion *P1, Pion *P2) { 
    effacer_ecran();

    printf("Appuyez sur une touche pour fermer le jeu.\n");
    
    getch();
    endwin();

    grille_desallouer(G1);
    grille_desallouer(G2);
    desallouer_pion(P1);
    desallouer_pion(P2);

    effacer_ecran();

    exit(0);
}

void message_fin(Grille *G1, Grille *G2, Pion *P1, Pion *P2) {
    endwin();

    grille_desallouer(G1);
    grille_desallouer(G2);
    desallouer_pion(P1);
    desallouer_pion(P2);

    printf("Merci d'avoir jouée à notre jeu !\nC'est malheureusement la fin de notre jeu.\n");
    printf("Ce jeu qui vous aura été présenté par : CHEN YuanDong Théo et \33[94m\33[47mLI Christophe\33[39m\33[49m\n");

    exit(0);
}