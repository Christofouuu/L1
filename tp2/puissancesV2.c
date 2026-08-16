#include <stdio.h>

int main()
{
	int puissance, n;
	double x;
	printf("Population de départ :");
	scanf("%lg", &x);
	printf("\nNombre d'années :");
	scanf("%d", &puissance);
	
	n = 0;
	
	while (n != puissance)
	{
		x = x * 1.05;
		n = n + 1;
	}
	
	if (puissance < 2)
	{
	printf("La population dans %d an sera de %lg personnes. \n", puissance, x);
	}
	
	else
	{
	printf("La population dans %d ans sera de %lg personnes. \n", puissance, x);
	}

	return 0;
}
