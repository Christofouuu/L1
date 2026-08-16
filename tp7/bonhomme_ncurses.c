#include <ncurses.h>
#include <unistd.h> /* pour sleep */

void bonhomme(int decalage, int bras_en_haut);
void inserer_espaces(int espaces);
void animation(int nb_images);

int main() {
	animation(5);
	return 0;
}

void bonhomme(int decalage, int bras_en_haut) {
	if (bras_en_haut % 2 == 0) {
		inserer_espaces(decalage); printw(" o\n");
		inserer_espaces(decalage); printw("\\|/\n");
		inserer_espaces(decalage); printw("/\\\n");
	} else {
		inserer_espaces(decalage); printw(" o\n");
		inserer_espaces(decalage); printw("/|\\\n");
		inserer_espaces(decalage); printw("/\\\n");
	}
}

void inserer_espaces(int espaces) {
	int i;
	for (i = 0; i < espaces; i++) {
		printw(" ");
	}
}

void animation(int nb_images) {
	int i, saut = 0;
	for (i = 0; i <= nb_images; i++) {
		bonhomme(saut, i);
		refresh();
		sleep(1); /* attendre une seconde */
		clear();
		saut = saut + 3;
	}
}
