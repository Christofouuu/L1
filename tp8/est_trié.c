#include <stdio.h>

/* Retourne 1 si les taille premières cases de tab sont triées (en ordre
 * croissant) et 0 sinon.
 * Précondition : tab a au moins taille éléments. */
int est_trie(int tab[], int taille);
int main()
{
	int tab[] = {1, 2, 3, 4, 5};
	printf("trié ? %d (0 pour non, 1 pour oui)\n", est_trie(tab, 5));
	tab[2] = 42;
	printf("trié ? %d (0 pour non, 1 pour oui)\n", est_trie(tab, 5));
	
	return 0;
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
