#include <stdio.h>

#define TAILLE_MAX 256
#define FIN_SAISIE -1

int main() {
	
	int tab[TAILLE_MAX], taille;
	int i = 0, min;
	/* Saisie du tableau de départ */
	printf("Entrer les différents éléments du tableau\n");
	printf("(%d pour mettre fin à la saisiee)\n", FIN_SAISIE);
	for (taille = 0; taille < TAILLE_MAX; taille = taille + 1) {
		scanf("%d", &tab[taille]);
		if (tab[taille] == FIN_SAISIE) {
			break;
		}
	}
	min = tab[0];
	for (i = 0; i < taille; i = i + 1) {
		if (tab[i] < min) {
			min = tab[i];
		}
	}
	
	printf("Minimum : %d à la position %d\n", min, tab[min]);
	
	/* A Vous ! */
	return 0;
}
