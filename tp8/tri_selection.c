#include <stdio.h>
#define TAILLE_MAX 64

void afficher_tab(int tab[], int taille);
int saisir_tab_tv(int tab[], int taille, int fin_saisie);
void transposer(int tab[], int i, int j);
int pos_max(int tab[], int taille);
void tri_selection(int tab[], int taille);
int est_trie(int tab[], int taille);

int main() {
	int taille, tab[TAILLE_MAX];
	
	taille =  saisir_tab_tv(tab, TAILLE_MAX, -1);
	
	tri_selection(tab, taille);
	
	afficher_tab(tab, taille);
	
	printf("Tableau trié ? %d (0 pour non, 1 pour oui)\n", est_trie(tab, taille));
	
	return 0;
}

void afficher_tab(int tab[], int taille) {
	int i;
	
	for (i = 0; i < taille ; i++) {
		printf("tab[%d] = %d\n", i, tab[i]);
	}
}

int saisir_tab_tv(int tab[], int taille, int fin_saisie) {
	int i;
	
	printf("Entrer les différents éléments du tableau (-1 pour mettre fin à la saisie) : \n");
	for (i = 0; i < taille ; i++) {
		scanf("%d", &tab[i]);
		if (tab[i] == fin_saisie) {
			break;
		}
	}
	return i;
}

void transposer(int tab[], int i, int j) {
	int tmp;
	
	tmp = tab[i];	
	tab[i] = tab[j];
	tab[j] = tmp;
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

void tri_selection(int tab[], int taille) {
	int valeur_max;
	for (; taille > 0; taille--) {
		valeur_max = pos_max(tab,  taille);
		if (valeur_max != taille) {
			transposer(tab, valeur_max, taille - 1);
		}
	}
}

int est_trie(int tab[], int taille) {
	int i;
	for (i = 1; i < taille; i++) {
		if (tab[i] < tab[i - 1]) {
			return 0;
		}
	}
	return 1;
}
