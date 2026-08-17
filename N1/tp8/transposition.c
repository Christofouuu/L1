#include <stdio.h>
#define TAILLE_MAX 64

void afficher_tab(int tab[], int taille);
int saisir_tab_tv(int tab[], int taille, int fin_saisie);

/* Échanger les éléments i et j du tableau
* Précondition : i et j doivent être des indices valides dans le tableau (la
* taille du tableau doit être assez grande) */
void transposer(int tab[], int i, int j);

int main () {
	int i, j, tab[TAILLE_MAX], taille;
	
	taille = saisir_tab_tv(tab, TAILLE_MAX, -1);
	
	printf("Entrer les indices des éléments à échanger : ");
	scanf("%d", &i);
	scanf("%d", &j);
	
	if (i >= taille || j >= taille || i < 0 || j < 0) { 
		printf("Erreur : indice i ou j non valide\n");
	} else {
		transposer(tab, i, j);
		afficher_tab(tab, taille);
	}

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
	
	printf("Entrer les différents éléments du tableau (-1 pour mettre fin à la saisie) : ");
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
