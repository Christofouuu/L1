#include <ncurses.h>
#include <unistd.h> // pour sleep

//int taille_phrase(char phrase[]);
int afficher_centre(char phrase[]);

//int centre_ligne(str phrase);
 
int main() {
    //int milieu_ligne;
    
    initscr();
    curs_set(0);
    
    start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);
    
    //milieu_ligne = centre_ligne("coucou");
    
    mvprintw(LINES / 2, afficher_centre("coucou"), "coucou");
    mvprintw(LINES -1,COLS -5, "weshh");
    refresh();
    getch();
    clear();
    
    attron(A_BLINK | COLOR_PAIR(1));
	mvprintw((LINES / 2) - 1, afficher_centre("CHAPITRE 1: Les Mots"),"CHAPITRE 1: Les Mots\n");
	attroff(A_BLINK | COLOR_PAIR(1));
	attron(A_BLINK | COLOR_PAIR(2));
	mvprintw((LINES / 2) + 1, afficher_centre("CHAPITRE 2: Les Nombres"),"CHAPITRE 2: Les Nombres\n");
	attroff(A_BLINK | COLOR_PAIR(2));
	refresh();
	sleep(1.99);
	clear();
    
    getch();
    endwin();
     
    return 0;
}

/* int centre_ligne(str phrase) {
    int centre = LINES / 2;
    int milieu_ligne = centre - (phrase / 2);
    
    return milieu_ligne;
} */

/* int taille_phrase(char phrase[]) {
    int taille = 0;
    
    for (taille = 0; phrase[taille] != '\0'; taille++) {
    }
    
    taille = taille - 1;
    
    return taille;
} */

int afficher_centre(char phrase[]) {
	int taille = 0;
    int centre = COLS / 2;
    int milieu_ligne = 0;
    
    for (taille = 0; phrase[taille] != '\0'; taille++) {
    }
    
    taille = taille - 1;
    
    milieu_ligne = centre - (taille / 2);
    
    return milieu_ligne;
}
