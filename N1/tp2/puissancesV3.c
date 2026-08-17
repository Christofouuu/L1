#include <stdio.h>

int main()
{
	double x, n;
	printf("Entrer un nombre : ");
	scanf("%lg", &x);
	
	printf("Entrer sa puissance : ");
	scanf("%lg", &n);
	
	/* if (n == 0) {
		x = 1;
		}
		
	while (n != 0) {
		if (n >= 1) {
			if (n > 1) {
				x = x * x;
				n = n - 1;
			} else {
				x = x;
				n = n - 1;
			}
		} else {
			if (n < 1) {
				x = (1/x) * (1/x);
				n = n + 1;
			} else {
			x = 1/x;
			n = n - 1;
			}
		} 
	} */
	
	
	
	printf("Résultat : %lg \n", x);
	
	return 0;
}
