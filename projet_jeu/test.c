#include <ncurses.h>
#include <unistd.h> // pour sleep
#include <stdlib.h> // pour exit
#include <string.h> // pour string

// void petit(a);

int main() {
	int a;
	
	initscr();
	curs_set(2);
	
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_WHITE);
	
	/* printw("aaa\n");
	sleep(1.9);
	refresh();
	
	printw("bbb\n");
	sleep(1);
	refresh();
	
	getch(); */
	
	printw("écrit : ");
	scanw("%d", &a);
	if (a > 2) {
	    mvprintw("c'est + grand que 2 : %d\n", a);
	    refresh();
	    getch();
	} /* else {
	    atexit(petit(a));
	} */
	
	mvprintw(LINES/2, COLS, "weshh c'est le centre ?");
	
	attron(COLOR_PAIR(1));
    mvprintw(LINES -1, COLS -1, "noob\n");
    attroff(COLOR_PAIR(1));
    refresh();
	getch();
	clear();
	endwin();
	
	return 0;
}

/* void petit(a) {
    printw("en dessous de 2 : %d\n", a);
} */