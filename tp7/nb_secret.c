#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

int main() {
	int nb_secret, reponse;
	srand(time(NULL));

	nb_secret = rand() % 1000;
	
	do {
		scanf("%d", &reponse);
		if (reponse < nb_secret) {
			printf("g\n");
		} else if (reponse > nb_secret) {
			printf("p\n");
		} else {
			printf("t\n");
		}
	} while (reponse != nb_secret);

	return 0;
}
