#include <stdio.h>

#define TAILLE_MAX 256
#define FIN_SAISIE -1

int main() {
	
	int tab[TAILLE_MAX], taille, tab2[TAILLE_MAX];
	int n, i = 0, compte = 0;
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
	
	while (i < taille) {
		if (tab[i] == n) {
			tab2[i] = i;
			compte = compte + 1;
			/* return 0; */
		}
		i = i + 1;
	}
	
	if (compte == 0) {
		printf("L'entier %d n'est pas dans le tableau.\n", n);
	} else if (compte == 1) {
		printf("L'entier %d est %d fois dans le tableau, à la position : ", n, compte);
		for (i = 0; i < taille; i = i + 1) {
			if (tab[i] == n) {
				printf("%d\n", tab2[i]);
			}
		}
	} else {
		printf("L'entier %d est %d fois dans le tableau, aux positions : ", n, compte);
		for (i = 0; i < taille && compte != 0; i = i + 1) {
			if (tab[i] == n) {
				printf("%d ", tab2[i]);
				compte = compte - 1;
			}
		}
	}
	
	printf("\n");
	
	/* A Vous ! */
	return 0;
}
