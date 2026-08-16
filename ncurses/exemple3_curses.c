#include <ncurses.h>

int main()
{
	initscr();
	/* a) la fonction "attron" est le début de la chaîne de caractère qui va permettre de changer la forme de la police, et prend en entré une chaîne de caractère */
	attron(A_NORMAL);
	printw("%20s : ABCabc012\n", "Normal");
	
	attron(A_REVERSE);
	printw("%20s : ABCabc012\n", "Inverse");
	attroff(A_REVERSE);
	/* b) les lignes qui sont entre "attron" et "attroff" seront de la forme de la police REVERSE. "attron" qui sera le point de départ, et "attroff" le point d'arrivé */
	
	attron(A_BOLD);
	printw("%20s : ABCabc012\n", "Gras");
	attroff(A_BOLD);
	
	attron(A_UNDERLINE);
	printw("%20s : ABCabc012\n", "Souligné");
	attroff(A_UNDERLINE);
	
	attron(A_REVERSE | A_BOLD);
	printw("%20s : ABCabc012\n", "Inverse et Gras");
	attroff(A_REVERSE | A_BOLD);
	
	/* c) */
	attron(A_BOLD | A_UNDERLINE);
	mvprintw(0, 0, "*10*");
	attroff(A_BOLD | A_UNDERLINE);
	
	refresh();
	getch();
	endwin();
	
	return 0;
}
