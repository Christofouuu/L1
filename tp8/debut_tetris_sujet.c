#include <ncurses.h>
#include <unistd.h>

/* Mettre dans lignes et colonnes les coordonnées d'un tétrimino I
 * en position horizontale, sur la ligne 1, occupant les colonnes 3 à 6 */
void creer_tetrimino_I(int lignes[4], int colonnes[4]);

/* Dessiner sur l'écran, en rouge, un tétrimino dont les coordonnées sont
 * données par les tableaux lignes et colonnes */
void dessiner_tetrimino(int lignes[4], int colonnes[4]);

/* décaler le tétrimino de coordonnées lignes et colonnes d'un cran vers la
 * droite. */
void bouger_tetrimino_droite(int lignes[4], int colonnes[4]);

/* décaler le tétrimino de coordonnées lignes et colonnes d'un cran vers la
 * gauche. */
void bouger_tetrimino_gauche(int lignes[4], int colonnes[4]);

/* décaler le tétrimino de coordonnées lignes et colonnes d'un cran vers le bas
 * */
void descendre_tetrimino(int lignes[4], int colonnes[4]);
int main()
{
	int lignes_tetrimino[4], colonnes_tetrimino[4];
	int c;

	initscr();
	noecho(); /* ne pas répéter les entrées de l'utilisateur */
	cbreak(); /* désactiver le line-buffering */
	keypad(stdscr, TRUE); /* flèches du clavier */
	nodelay(stdscr, TRUE); /* getch non bloquant */
	curs_set(0); /* ne pas voir le curseur */
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);
	
	creer_tetrimino_I(lignes_tetrimino, colonnes_tetrimino);
	
	for (;;) {
		clear();
		dessiner_tetrimino(lignes_tetrimino, colonnes_tetrimino);
		usleep(10000);
		c = getch();
		if (c == KEY_RIGHT) {
			bouger_tetrimino_droite(lignes_tetrimino, colonnes_tetrimino);
		} else if (c == KEY_LEFT) {
			bouger_tetrimino_gauche(lignes_tetrimino, colonnes_tetrimino);
		} else if (c == KEY_DOWN) {
			descendre_tetrimino(lignes_tetrimino, colonnes_tetrimino);
		}
	}


	endwin();
	return 0;
}

void creer_tetrimino_I(int lignes[4], int colonnes[4]) {
	int i;
	
	for(i = 0; i < 4; i++) {
		lignes[i] = 1;
		colonnes[i] = 3 + i;
	}
}

void dessiner_tetrimino(int lignes[4], int colonnes[4]){
	int i;
	
	for (i = 0; i < 4; i++) {
		attron(COLOR_PAIR(1));
		mvprintw(lignes[i], colonnes[i], " ");
		attroff(COLOR_PAIR(1));
	}

}

void descendre_tetrimino(int lignes[4], int colonnes[4]){
	int i;
	
	for(i = 0; i < 4; i++) {
		lignes[i] = lignes[i] + 1;
	}
}

void bouger_tetrimino_droite(int lignes[4], int colonnes[4]){
	int i;
	
	for(i = 0; i < 4; i++) {
		colonnes[i] = colonnes[i] + 1;
	}
}

void bouger_tetrimino_gauche(int lignes[4], int colonnes[4]){
	int i;
	
	for(i = 0; i < 4; i++) {
		colonnes[i] = colonnes[i] - 1;
	}
}
