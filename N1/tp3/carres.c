#include <stdio.h>
int main() {

	int i, n;
	
	printf("Entrer le nombre de carrés désiré :");
	scanf("%d", &i);
	
	/* for (i = 0; i < n; i = i + 1) {
		printf("%d^2 = %d\n", i, i * i);
	}	*/ 
	
	n = 0;
	while (i != n) {
		printf("%d^2 = %d\n", i, i * i);
		i = i - 1;
	}
	
	return 0;
}
