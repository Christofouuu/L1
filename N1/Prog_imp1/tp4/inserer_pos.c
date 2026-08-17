#include <stdio.h>

#define TAILLE_MAX 256
#define FIN_SAISIE -1

int main() {
	
	int tab[TAILLE_MAX], taille;
	int n, i,pos = 0;
	/* Saisie du tableau de départ */
	printf("Entrer les différents éléments du tableau\n");
	printf("(%d pour mettre fin à la saisiee)\n", FIN_SAISIE);
	for (taille = 0; taille < TAILLE_MAX; taille = taille + 1) {
		scanf("%d", &tab[taille]);
		if (tab[taille] == FIN_SAISIE) {
			break;
		}
	}

	printf("Entier à insérer : ");
	scanf("%d", &n);
	printf("Position pour l'insertion : ");
	scanf("%d", &pos);
	printf("Tableau de taille %d : \n", taille);
	tab[taille] = n;
	taille = taille + 1;
	
	for (i = taille - 1; i > 0; i = i - 1) {
		if (i > pos) {
			tab[i] = tab[i - 1];
		} else if (i == pos) {
			tab[i] = n;
		}
	}
	
	for (i = 0; i < taille; i = i + 1) {
		printf("%d  ",tab[i]);
	}
	
	printf("\n");
	
	/* A Vous ! */
	return 0;
}
