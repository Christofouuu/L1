#include <stdio.h>

#define TAILLE_MAX 256
#define FIN_SAISIE -1

int main() {
	
	int tab[TAILLE_MAX], taille;
	int i = 0;
	/* Saisie du tableau de départ */
	printf("Entrer les différents éléments du tableau\n");
	printf("(%d pour mettre fin à la saisiee)\n", FIN_SAISIE);
	for (taille = 0; taille < TAILLE_MAX; taille = taille + 1) {
		scanf("%d", &tab[taille]);
		if (tab[taille] == FIN_SAISIE) {
			break;
		}
	}
	
	/* Affichage du tableau */
	printf("Tableau de taille %d : \n", taille);
	while (i < taille) {
		printf("%d ", tab[i]);
		i = i + 1;
	}
	printf("\n");
	
	/* A Vous ! */
	return 0;
}
