#include <stdio.h>

#define TAILLE_MAX 256
#define FIN_SAISIE -1

int main() {
	
	int tab[TAILLE_MAX], taille;
	int n, i = 0, trouve = 0;
	/* Saisie du tableau de départ */
	printf("Entrer les différents éléments du tableau\n");
	printf("(%d pour mettre fin à la saisiee)\n", FIN_SAISIE);
	for (taille = 0; taille < TAILLE_MAX; taille = taille + 1) {
		scanf("%d", &tab[taille]);
		if (tab[taille] == FIN_SAISIE) {
			break;
		}
	}
	
	printf("Entier à chercher dans le tableau : ");
	scanf("%d", &n);
	
	while (!trouve && i < taille) {
		if (tab[i] == n) {
			printf("Entier %d trouvé à la position %d\n", n , i);
			trouve = 1;
			/* return 0; */
		}
		i = i + 1;
	}
	if (!trouve) {
		printf("L'entier %d n'est pas dans le tableau.\n", n);
	}
	/* A Vous ! */
	return 0;
}
