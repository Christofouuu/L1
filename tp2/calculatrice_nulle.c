#include <stdio.h>

int main()
{
	int a, b;
	char reponse;

	printf("Entrer le premier nombre : ");
	scanf("%d", &a);
	printf("Entrer le deuxième nombre : ");
	scanf("%d", &b);

	printf("Quelle opération (a pour addition, m pour multiplication) ? ");
	scanf(" %c", &reponse);
	if (reponse == 'a') {
		printf("Résultat : %d\n", a + b);
	} else {
		printf("Résultat : %d\n", a * b);
	}
	return 0;
}
