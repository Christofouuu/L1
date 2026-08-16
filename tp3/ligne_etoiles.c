#include <stdio.h>
int main() {

	int i, n;
	printf("Entrer la longueur de la ligne d'étoiles :");
	scanf("%d", &n);
	
	for (i = 0; n != i; i = i + 1) {
		printf("*");
	}
	printf("\n");
	
	return 0;
}
