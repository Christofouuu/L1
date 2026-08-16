#include <stdio.h>
#include <unistd.h> /* pour sleep */

void bonhomme(int decalage, int bras_en_haut);
void inserer_espaces(int espaces);
void effacer_lignes(int num_lignes);
void animation(int nb_images);

int main() {
	animation(5);
	return 0;
}

void bonhomme(int decalage, int bras_en_haut) {
	if (bras_en_haut % 2 == 0) {
		inserer_espaces(decalage); printf(" o\n");
		inserer_espaces(decalage); printf("\\|/\n");
		inserer_espaces(decalage); printf("/\\\n");
	} else {
		inserer_espaces(decalage); printf(" o\n");
		inserer_espaces(decalage); printf("/|\\\n");
		inserer_espaces(decalage); printf("/\\\n");
	}
}

void inserer_espaces(int espaces) {
	int i;
	for (i = 0; i < espaces; i++) {
		printf(" ");
	}
}

void effacer_lignes(int num_lignes) {
	int i;
	for (i = 0; i < num_lignes; i++) {
		printf("\033[F");
		printf("\033[2K");
	}
}

void animation(int nb_images) {
	int i, saut = 0;
	for (i = 0; i <= nb_images; i++) {
		bonhomme(saut, i);
		sleep(1); /* attendre une seconde */
		effacer_lignes(3);
		saut = saut + 3;
	}
}
