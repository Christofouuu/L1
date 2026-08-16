#include <stdio.h>

/* Retourne 1 si c désigne un chiffre décimal, 0 sinon */
int est_chiffre(char c);
/* Retourne 1 si c désigne une lettre minuscule, 0 sinon */
int est_minuscule(char c);
/* Retourne 1 si c désigne une lettre majuscule, 0 sinon */
int est_majuscule(char c);
/* Retourne 1 si c désigne une lettre, 0 sinon */
int est_alpha(char c);
/* Retourne 1 si c désigne un chiffre hexadécimal, 0 sinon */
int est_chiffre_hexa(char c);
/* Si c désigne une lettre minuscule, retourne la lettre majuscule associée,
 * sinon retourne c non modifié */
char en_majuscule(char c);
/* Si c désigne une lettre majuscule, retourne la lettre minuscule associée,
 * sinon retourne c non modifié */
char en_minuscule(char c);

int main()
{
	char c;
	printf("Entrer un caractère : ");
	scanf(" %c", &c);

	if (est_chiffre(c) == 1) {
		printf("Le caractère %c est un chiffre décimal.\n", c);
	} else {
		printf("Le caractère %c n'est pas un chiffre décimal.\n", c);
	}

	if (est_minuscule(c) == 1) {
		printf("Le caractère %c est une lettre minuscule.\n", c);
	} else {
		printf("Le caractère %c n'est pas une lettre minuscule.\n", c);
	}

	if (est_majuscule(c) == 1) {
		printf("Le caractère %c est une lettre majuscule.\n", c);
	} else {
		printf("Le caractère %c n'est pas une lettre majuscule.\n", c);
	}

	if (est_alpha(c) == 1) {
		printf("Le caractère %c est une lettre.\n", c);
	} else {
		printf("Le caractère %c n'est pas une lettre.\n", c);
	}

	if (est_chiffre_hexa(c) == 1) {
		printf("Le caractère %c est un chiffre hexadécimal.\n", c);
	} else {
		printf("Le caractère %c n'est pas un chiffre hexadécimal.\n", c);
	}

	printf("Le caractère %c en majuscule : %c\n", c, en_majuscule(c));
	printf("Le caractère %c en minuscule : %c\n", c, en_minuscule(c));

	return 0;
}
int est_chiffre(char c)
{
	if (c >= 48 && c <= 57) {
		c = 1;
	} else { 
		c = 0;
	}
	
	return c;
}
int est_minuscule(char c)
{
	if (c >= 97 && c <= 122) {
		c = 1;
	} else { 
		c = 0;
	}
	
	return c;
}
int est_majuscule(char c)
{
	if (c >= 65 && c <= 90) {
		c = 1;
	} else { 
		c = 0;
	}
	
	return c;
}
int est_alpha(char c)
{
	if (est_minuscule(c) == 1 || est_majuscule(c) == 1) {
		c = 1;
	} else { 
		c = 0;
	}
	
	return c;
}
int est_chiffre_hexa(char c)
{
	if (est_chiffre(c) == 1 || (c >= 'A' && c <= 'F')) {
		c = 1;
	} else { 
		c = 0;
	}
	
	return c;
}
char en_majuscule(char c)
{
	if (est_minuscule(c) == 1) {
		c = c - 'a' + 'A';
	}
	
	return c;
}
/* Si c désigne une lettre majuscule, retourne la lettre minuscule associée,
sinon retourne c non modifié */
char en_minuscule(char c)
{
	if (est_majuscule(c) == 1) {
		c = c + 'a' - 'A';
	}
	return c;
}
