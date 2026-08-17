#include <ncurses.h>

int main()
{
	/* Initialise la fenêtre. */
	initscr();
	
	/* Imprime une chaîne de caractères. */
	printw("Bonjour !");
	
	/*Rafaîchit la fenêtre. */
	refresh();
	
	/* Attend l'appui d'une touche */
	getch();
	
	initscr();
	
	printw("Au Revoir !");
	
	getch();
	
	/* Ferme la fenêtre */
	endwin();
	
	return 0;
}

