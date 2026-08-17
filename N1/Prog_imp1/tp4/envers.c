#include <stdio.h>

int main() {
	
	int i, tab[5], tmp = 4;
	/* saisie du tableau */
	for (i = 0; i < 5; i = i + 1) {
		printf("Entrer nombre numéro %d : ", i);
		scanf("%d", &tab[i]);
	}
	/* Affichage du tableau */
	for (i = 0; i < 5; i = i + 1) {
		printf("nombre numéro %d : %d\n", i, tab[tmp]);
		tmp = tmp - 1;
	}
	
	return 0;
}
