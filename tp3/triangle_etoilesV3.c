#include <stdio.h>
int main() {

	int j, n, i;
	printf("Entrer le côté du triangle d'étoiles :");
	scanf("%d", &n);
	
	for (i = 0; i < n; i = i + 1) {
		for (j = 0; j < n; j = j + 1) {
			if (j >= i) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
