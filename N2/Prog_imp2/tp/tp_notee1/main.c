#include "flotte_voiture.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    srand(time(NULL)); 
    int nb_auto;
    
    if (argc != 2) {
    printf("Erreur sur le nombre d'arguments !\n");
    return EXIT_FAILURE;
    }
    
    Flotte* grp1;
    Flotte* grp_essence;
    nb_auto = atoi(argv[1]);
    
    grp1 = creer_flotte(nb_auto);
    initialisee_random(grp1);
    affiche(grp1);
    affiche_plus_ancienne(grp1);
    tri_par_kilometrage(grp1);
    affiche(grp1);
    desalloue_flotte(&grp1);
	
	grp_essence = extrait_essence(grp1);

    return 0;
}
