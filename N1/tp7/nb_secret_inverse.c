#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main() {
	int nb_secret = 500, i;
	char reponse;
	
	printf("%d\n", nb_secret);
	
	/* do {
		scanf("%c", &reponse);
		
		if (reponse == 'g') {
			nb_secret = nb_secret * 2;
			printf("%d\n", nb_secret);
		} else if (reponse == 'p') {
			nb_secret = nb_secret / 1.5;
			printf("%d\n", nb_secret);
		} 
	} while (reponse != 't'); */
	
	for (i = 250; reponse != 't'; ) {
		scanf("%c", &reponse);
		
		if (reponse == 'g') {
			nb_secret = nb_secret + i;
			i = i / 2;
			printf("%d\n", nb_secret);
		} else if (reponse == 'p') {
			nb_secret = nb_secret - i;
			i = i / 2;
			printf("%d\n", nb_secret);
		}

	}
	
	return 0;
}
