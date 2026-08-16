#include <ncurses.h>

int main()
{
	initscr();
	
	printw("1");
	 /* c) la fonction "move" permet de déplacer des éléments */
	move(2, 10);
	addch('2');
	addch('3');
	
	/* b) LINES et COLS permettent de changer la position du chiffre 4 */
	move(LINES - 1, COLS - 1);
	/* d) addch (= add charactere) ajoute un élément */
	addch('4');
	/* d) mvaddch (= move add charactere) permet de positionner un caracatère ajouté */
	mvaddch(4, 2, '5');
	/* mvprintw permet d'insérer une chaîne de caractère à une position précise */
	mvprintw(3, 3, "ABCD");
	/* printw permet de insérer une chaîne de caractère */
	printw("**");
	
	
	/* move(8, 4); */
	/* addch('4!+2!'); */
	
	/* mvaddch(8, 4, '4!+2!'); */
	
	mvprintw(8, 4, "4!+2!");
	
	refresh();
	
	getch();
	
	endwin();
	return 0;
}
