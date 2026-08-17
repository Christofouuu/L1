#include <stdio.h>

int main() {
	
	int i;
	double tab[4];
	
	for (i = 0; i < 4; i = i + 1) {
		printf("Saisir le nombre numéro %d : ", i);
		scanf("%lg", &tab[i]);
	}
	
	for (i = 0; i < 4; i = i + 1) {
		printf("Cube du nombre numéro %d : %lg\n", i , tab[i]*tab[i]*tab[i]);
	}

	return 0;
}
