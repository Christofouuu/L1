#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> // pour sleep

void nb_aleas_tab(int nb[], int valeur);
int nb_aleas(int valeur);

int main() {
    int rep_pc, rep_util, nb[3];
    
    initscr();
    curs_set(0);
    
    nb_aleas_tab(nb, 10000);
    
    rep_pc = nb_aleas(3) + 1;
    
    printw("%d\n", nb[0]);
    refresh();
    sleep(2);
    clear();
    
    printw("Quel était le nombre affiché ?\n");
    if (rep_pc == 1) {
        printw("%d) %d\n", rep_pc, nb[0]);
        printw("2) %d\n", nb[1]);
        printw("3) %d\n", nb[2]);
    } else if (rep_pc == 2) {
        printw("1) %d\n", nb[2]);
        printw("%d) %d\n", rep_pc, nb[0]);
        printw("3) %d\n", nb[1]);
    } else {
        printw("1) %d\n", nb[1]);
        printw("2) %d\n", nb[2]);
        printw("%d) %d\n", rep_pc, nb[0]);
    }
    printw("Réponse : ");
    refresh();
    scanw("%d", &rep_util);
    
    if(rep_util == rep_pc) {
        printw("oui\n");
    } else {
        printw("non\n");
    }
    
    // printw("nb1 =  %d, nb2 = %d, nb3 = %d, rep_pc = %d\n", nb[0], nb[1], nb[2], rep_pc);
    getch();
    
    endwin();
    return 0;
}

void nb_aleas_tab(int nb[], int valeur) {
    int i, multiple = valeur, entier = nb_aleas(10);
    
    srand(time(NULL));
    
    for (i = 0; i < 3; i++) {
            entier = nb_aleas(10);
            nb[i] = entier * multiple;
        }
    
    for (multiple = multiple / 10; multiple >= 1; multiple = multiple / 10) {
        for (i = 0; i < 3; i++) {
            entier = nb_aleas(10);
            nb[i] = nb[i] + (entier * multiple);
        }
    }
    
    
    /* for (i = valeur; i > 100; i = i / 10) {
        nb[1] = (rand() % 10) * i;
    }
    
    for (i = valeur; i > 100; i = i / 10) {
        nb[2] = (rand() % 10 ) * i ;
    } */
}

int nb_aleas(int valeur) {
    int nb;
    
    srand(time(NULL));
    
    nb = rand() % valeur;
    
    return nb;
}