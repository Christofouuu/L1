#include <stdio.h>

int main()
{
	int a, b, c;
	
	printf("Entrer le premier nombre :");
	scanf("%d", &a);
	
	printf("Entrer le deuxième nombre :");
	scanf("%d", &b);
	
	if(b < 0) {
	b = -b;
	a = -a;
	}
	
	c = 0;
	while(b > 0) {
	c = c + a;
	b = b - 1;
	}
	
	printf("Résultat : %d\n", c);
	return 0;
}
