#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Carnet.h"
#define MAX_SIZE 50

int main(int argc, char *argv[]){
    srand(time(NULL)); 
    int nombre_contact;
    char mot[] = "B";
    
    if (argc != 2) {
    printf("Erreur sur le nombre d'arguments !\n");
    return EXIT_FAILURE;
    }

    nombre_contact = atoi(argv[1]);

    Carnet *note1 = malloc(sizeof(Carnet));
    note1 = creer_carnet(nombre_contact);
    generation_aleatoire_contacts(note1);
    afficher_contacts(note1);
    rechercher_contact(note1, mot);


    desalloue_carnet(note1);

    return 0;
}