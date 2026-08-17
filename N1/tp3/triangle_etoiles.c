#include <stdio.h>
int main() {

	int j, n, i;
	printf("Entrer le côté du triangle d'étoiles :");
	scanf("%d", &n);
	
	for (i = 1; i <= n; i = i + 1) {
		for (j = 0; j < i; j = j + 1) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
