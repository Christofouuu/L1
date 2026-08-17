#include <stdio.h>

struct matrice {
    unsigned nb_lignes;
    unsigned nb_colonnes;
    int coeff[10][10];
};

void tranposer_mat (struct matrice *am_t, const struct matrice *am);

void reduire_mat (struct matrice *am);

int main() {
    //struct matrice *am = {};
    
    return 0;
}

void tranposer_mat (struct matrice *am_t, const struct matrice *am) {
    int i,j;
    am_t->nb_lignes=am->nb_colonnes;
    am_t->nb_colonnes=am->nb_lignes;
    for (i = 0; i < am->nb_lignes; i++ ) {
        for(j = 0; j< am->nb_colonnes; j++) {
            *(*(am_t -> coeff + i) + j) = *(*(am -> coeff + j) + i); //1ere parenthèse = am_t[j][i]
        //2eme parenthèse = am[i][j]
        }
    }
}

void reduire_mat (struct matrice *am){
    int i, j;
    --am -> nb_lignes;
    --am -> nb_colonnes;
    for(i = 0; i< am->nb_lignes; i++) {
        for(j = 0; j < am->nb_colonnes; j++) {
            *(*(am-> coeff+i)+ j) = *(*(am -> coeff + i + 1) + j + 1);
        }
    }
}