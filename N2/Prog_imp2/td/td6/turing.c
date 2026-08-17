/** Alloue de l'espace sur la tas pour un tableau de lauréats, */
/* l'initialise avec les informations stockées dans le fichier de nom nom_fich */
/* et renvoie l'adresse du tableau ainsi initialisé */
/** NB.. l'entier pointé par le 2e paramètre d'entrée */
/* prend la valeur du nombre de lauréats référencés dans le tableau initialisé */

#include "turing.h"
#include <string.h> /* pour strcpy */
#include <stdlib.h> /* pour malloc, free, sizeof */
#include <stdio.h> /* pour printf */


struct laureat_Turing ** init_tab (const char *nom_fich, int * taille) {
    int i;
    FILE * f;
    struct laureat_Turing * tab_res;
    struct date *tmp_d_deces, *tmp_d_naiss = allouer_date();
        char *tmp_prenom, *tmp_nom, *tmp_p_naiss;
    /** Ouverture du fichier de nom n_fich en lecture */
        if ((f=fopen(nom_fich,"r")) == NULL) {
            fprintf(stderr, "fichier %s introuvable \n", nom_fich);
            exit (EXIT_FAILURE);
        }
    /* Lecture du nombre de lauréats dans le fichier (1re ligne du fichier) */
    fscanf(f, "%d\n" , taille);
    /* Allocation d'espace sur le tas pour un tableau de lauréats de taille adéquate */
    /* et pour les struct laureat_Turing référencées dans le tableau */
    tab_res = allouer_tab_laureat(*taille);
        /* NB.. On suppose que les noms, prénoms et pays d'origine */
    /* des lauréats Turing du fichier ont au plus TAILLE_MAX_CHAINE caractères */ 
        tmp_prenom = allouer_chaine(TAILLE_MAX_CHAINE);
        tmp_nom = allouer_chaine(TAILLE_MAX_CHAINE);
        tmp_p_naiss = allouer_chaine (TAILLE_MAX_CHAINE) ;
    /* Récupération des lauréats stockés dans le fichier */
    for (i =0; i < *taille; ++i) {
    /* Lecture des noms et prénoms du lauréat et de l'année du prix */
        if (fscanf(f," %s %s [%u]", tmp_prenom, tmp_nom, &(tab_res[i]->annee_prix)) != 3) {
            perror("Échec lecture fichier");
            exit (2);
        }
        /* Lecture de la date de naissance */
    if (fscanf(f," né(e) le %u/%u/%u :", &(tmp_d_naiss->jour), &(tmp_d_naiss->mois), &(tmp_d_naiss->annee)) != 3) {
        perror ("Échec lecture du fichier");
        exit (3);
    }
    /* Lecture du pays de naissance */
    if (fscanf(f,"%s", tmp_p_naiss) < 1) {
        perror ("Échec lecture du fichier");
        exit (4);
    }
    /* On retire les parenthèses autour du pays de naissance */ 
    retirer_parentheses (tmp_p_naiss);
/* Si le lauréat récupéré est décédé, on supprime l'astérisque à la fin de
son nom */
/* et on récupère sa date de décès */
    tmp_d_deces = NULL;
    if (tmp_nom[strlen(tmp_nom) - 1] == '*') {
        tmp_d_deces = allouer_date();
        if (fscanf(f," décédé(e) le %u/%u/%u", &(tmp_d_deces->jour), &(tmp_d_deces->mois), &(tmp_d_deces->annee)) != 3) {
            perror ("Échec lecture fichier");
            exit(4);
        }
    tmp_nom[strlen(tmp_nom) - 1] = '\0' ;
    }

    tab_res[i]->laureat = allouer_init_individu(tmp_prenom, tmp_nom, tmp_d_naiss, tmp_d_deces, tmp_p_naiss);
    }
/* Nettoyage : libération de la mémoire auxiliaire allouée sur la tas */ 
    detruire_date(&tmp_d_naiss);
    detruire_date(&tmp_d_deces);
    free(tmp_prenom) ;
    free (tmp_nom) ;
    free(tmp_p_naiss);
/* Fermeture du fichier */
    fclose(f);
    return tab_res;
}
/** Retire les parenthèses d'une chaîne de caractères */
/* (fonction appelée dans init_tab ci-dessous) */

void retirer_parentheses (char *5){
    int lecture = 0, ecriture = 0;
    while (s[lecture] != '\0') {
        if (s[lecture] != '()' && s[lecture] != ' ) ') {
            s[ecriture++] = s[lecture]; 
            } 
        lecture++;
    }
    s[ecriture] = '\0' ;
}

/** Fonction qui alloue l'espace mémoire sur le tas */
/* pour un tableau de n adresses de lauréats */
/* (et pour n structures laureat_Turing) */
/* et renvoie l'adresse du bloc alloué */

struct laureat_Turing * allouer_tab_laureat (int n) {
    int i;
    struct laureat_Turing ** t = malloc (sizeof(struct laureat_Turing *) * n);
    if (t == NULL) {
        perror ("Échec allocation tableau");
        exit (EXIT_FAILURE);
    }
    for (i = 0; i < n; ++i) {
        t[i] = allouer_laureat();
    }
    return t;
}
    