#include <stdio.h>

void menu();
int est_carre(int n);
double factorielle(int n);
int saisie_entre_bornes(int min, int max);
int est_premier(int n);

int main() {
	int n, choix;
	
	choix = saisie_entre_bornes(1,3);
	
	if (choix == 1) {
		printf("Choississez votre entier à vérifier si il est un carré : ");
		scanf("%d", &n);
		if (est_carre(n) == 1) {
			printf("%d est un carré.\n", n);
		} else {
			printf("%d n'est pas un carré.\n", n);
		}
	} else if (choix == 2) {
		printf("Choississez votre entier pour sa factorielle : ");
		scanf("%d", &n);
		printf("La factorielle de %d est %g.\n", n, factorielle(n));
	} else {
		printf("Choississez votre entier pour vérifier si il est premier : ");
		scanf("%d", &n);
		if (est_premier(n) == 1) {
			printf("%d est premier.\n", n);
		} else {
			printf("%d n'est pas premier.\n", n);
		}
	}
	
	return 0;
}

void menu() {
	printf("********** arith **********\n");
	printf("Voulez-vous\n");
	printf("1) tester si un entier est un carré ?\n");
	printf("2) calculer la factorielle d'un entier ?\n");
	printf("3) tester si un entier est premier ?\n");
}

int est_carre(int n) {
	int i, reponse = 0;
	
	for (i = 0; i <= n; i++) {
		if (i * i == n) {
			reponse = 1;
			break;
		}
	}
	return reponse;
}

double factorielle(int n) {
	double res = 1.;
	while (n > 0) {
		res = res * n;
		n = n - 1;;
	}
	return res;
}
int saisie_entre_bornes(int min, int max) {
	int choix, tmp;
	
	do {
		menu();
		scanf("%d", &choix);
		if (choix >= min && choix <= max) {
			tmp = 1;
		} else { 
			tmp = 0;
		}
	} while (tmp != 1) ;
	return choix;
}

int est_premier(int n) {
	int i, verification = 0;
	
	if (n == 2) {
		verification = 1;
		return verification;
	}
	
	for (i = 3; i < n; i = i + 2) {
		if (i == n) {
		} else if (n % i != 0) {
			verification = 1;
		} else { 
			verification = 0;
			break;
		}
	}
	return verification;
}
