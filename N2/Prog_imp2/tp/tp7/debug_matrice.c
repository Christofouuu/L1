
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **matrice;   // Matrice dynamique
    int lignes;
    int colonnes;
} Matrice;

Matrice* creer_matrice(int lignes, int colonnes) {
    Matrice *m = malloc(sizeof(Matrice));
    m->lignes = lignes;
    m->colonnes = colonnes;


    m->matrice = malloc(lignes * sizeof(int*));
    for (int i = 0; i <= lignes; i++) { 
        m->matrice[i] = malloc(colonnes * sizeof(int));
    }

    return m;
}

/* remplir matrice avec des valeurs cohérentes */
void remplir_matrice(Matrice *m) {
   
}

void afficher_matrice(Matrice *m) {

}

void liberer_matrice(Matrice *m) {
}

int main() {
    int n = 3, p = 3;
    Matrice *m = creer_matrice(n, p);
    remplir_matrice(m);
    afficher_matrice(m);

    liberer_matrice(m);  
    return 0;
}
