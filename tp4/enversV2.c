#include <stdio.h>

int main() {
	
	int i, tab[5], tmp = 4, x = 0;
	/* saisie du tableau */
	for (i = 0; i < 5; i = i + 1) {
		printf("Entrer nombre numéro %d : ", i);
		scanf("%d", &tab[i]);
	}
	
	/* échange des valeurs du tableau */
	for (i = 0; i < 5; i = i + 1) {
		tab[x] = tab[i];
		tab[i] = tab[tmp];
		tab[tmp] = tab[x];
		x = x + 1;
		tmp = tmp - 1;
	}
	
	/* affichage du tableau */
	for (i = 0; i < 5; i = i + 1) {
		printf("nombre numéro %d : %d\n", i, tab[i]);
	}
	
	return 0;
}
