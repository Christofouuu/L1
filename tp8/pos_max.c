#include <stdio.h>
#define TAILLE_MAX 64

int saisir_tab_tv(int tab[], int taille, int fin_saisie);
int pos_max(int tab[], int taille);

int main() {
	int tab[TAILLE_MAX], imax, taille;
	
	taille = saisir_tab_tv(tab, TAILLE_MAX, -1);
	
	if (taille == 0) {
		printf("Le tableau entré est vide.\n");
	} else {
		imax = pos_max(tab, taille);
		printf("Maximum : %d à la position %d\n", tab[imax], imax);
	}
	
	return 0;
}

int saisir_tab_tv(int tab[], int taille, int fin_saisie) {
	int i;
	
	printf("Entrer les différents éléments du tableau (-1 pour mettre fin à la saisie) : ");
	for (i = 0; i < taille ; i++) {
		scanf("%d", &tab[i]);
		if (tab[i] == fin_saisie) {
			break;
		}
	}
	return i;
}

int pos_max(int tab[], int taille) {
	int imax = 0, i;
	
	for (i = 0; i < taille; i++) {
		if (tab[i] > tab[imax]) {
			imax = i;
		}
	}

	return imax;
}
