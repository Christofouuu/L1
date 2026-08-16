#include <stdio.h>
int main() {

	int i, n, x;
	printf("Entrer le côté du carré d'étoiles :");
	scanf("%d", &n);
	
	for (x = n; n != 0; n = n - 1) {
		for (i = 0; x != i; i = i + 1) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
