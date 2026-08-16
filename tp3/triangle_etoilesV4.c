#include <stdio.h>
int main() {

	int i, j, n;
	printf("Entrer le côté du triangle d'étoiles :");
	scanf("%d", &n);
	
	for (i = 0; i < n; i = i + 1) {
		for (j = 0; j < 2 * n; j = j + 1) {
			if ( n - i <= j && j <= n + i) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("Au revoir");
	return 0;
}
