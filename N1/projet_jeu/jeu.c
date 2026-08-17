/* Christophe LI 12205895
* Je déclare qu'il s'agit de mon propre travail */
#include <ncurses.h>
#include <unistd.h> // pour sleep
#include <stdlib.h> // pour exit
#include <time.h> // pour time
#include <string.h> // pour strlen et strcpy
#define CHAPITRE 3
#define NIVEAU_MAX 5

int afficher_centre(char phrase[]); // renvoie un texte centrer sur l'écran
void car(); // compte à rebours avant le début d'un niveau
void vie(int *nb_vie); // nombre de vie
void niv_suiv(int niveau); // attend que l'utilisateur soit prêt avant de lancer le niveau

void niveau_tuto(int *niveau);

// Chap 1
void niveau_1_1(int *nb_vie, int *niveau);
void niveau_1_2(int *nb_vie, int *niveau);
void niveau_1_3(int *nb_vie, int *niveau);
void niveau_1_4(int *nb_vie, int *niveau);
void niveau_1_5(int *nb_vie, int *niveau);

// Chap 2
void niveau_2_1(int *nb_vie, int *niveau);
void niveau_2_2(int *nb_vie, int *niveau);
void niveau_2_3(int *nb_vie, int *niveau);
void niveau_2_4(int *nb_vie, int *niveau);
void niveau_2_5(int *nb_vie, int *niveau);

// Chap 3
void niveau_3_1(int *nb_vie, int *niveau);
void niveau_3_2(int *nb_vie, int *niveau);
void niveau_3_3(int *nb_vie, int *niveau);
void niveau_3_4(int *nb_vie, int *niveau);
void niveau_3_5(int *nb_vie, int *niveau);

// Chap BONUS
void niveau_bonus_1(int *nb_vie, int *niveau); // drapeau FR

void nb_aleas_tab(int nb[], int taille, int valeur); // nombre aléatoire dans un tableau
int nb_aleas(int valeur); // nombre aléatoire
void niveau_bonus_2(); // Nombre aléatoire

void niveau_bonus_3(int *nb_vie, int *niveau); // Serpent Vert

void fin();

int main() {
	int nb_confirm, chapitre = 1, niveau = 0;
	int nb_vie = 3;

	//ouverture de la fenêtre
	initscr();
	curs_set(0);
	
	//Initialisation des couleurs
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE); //Chapitres
	init_pair(2, COLOR_BLACK, COLOR_WHITE); //Niveaux
	init_pair(3, COLOR_GREEN, COLOR_WHITE); // pour les questions dans certains niveaux
	init_pair(4, COLOR_BLUE, COLOR_WHITE); // pour les questions dans certains niveaux
	init_pair(5, COLOR_CYAN, COLOR_WHITE); // pour les questions dans certains niveaux
	init_pair(6, COLOR_YELLOW, COLOR_WHITE); // pour les questions dans certains niveaux
	init_pair(7, COLOR_WHITE, COLOR_MAGENTA); // pour les questions dans certains niveaux
	init_pair(8, COLOR_BLUE, COLOR_BLACK); // pour les questions dans certains niveaux
	init_pair(9, COLOR_RED, COLOR_BLACK); // pour les questions dans certains niveaux

	attron(A_UNDERLINE);
	printw("Bienvenue dans ce jeu qui sera constitué de %d chapitres avec %d niveaux dans chaque chapitre.\n\n", CHAPITRE, NIVEAU_MAX);
	attroff(A_UNDERLINE);
	printw("Les règles sont simples: une chaîne de caractère va apparaître sur votre écran.\nVotre objectif ? Lire cette même chaîne de caractère et la retenir le temps du niveau.\nLes chaînes de caractères des différents niveaux non pas de réels sens entre eux, alors une fois un niveau passé, il n'est pas nécessaire de se rappeler de la réponse du niveau précédent.\nAu cours de la partie vous aurez en tout %d vies. Si votre nombre de vie tombe à 0, alors vous avez perdu, pour autant après le passage d'un chapitre vous gagnerez 1 vie supplémentaire.\nPour un meilleur confort de jeu, je vous invite à mettre le jeu en plein écran, si cela n'est pas fait avant le lancement du jeu je vous invite à relancer le jeu en faisant Ctrl + C puis relancer le jeu manuellement. Si malheursement le jeu est trop dure pour vous, vous pouvez réduire manuellement la taille du terminal par 2.\nPour finir si tous est clair pour vous, je vous souhaite bonne chance et de vous amuser !\n", nb_vie);
	printw("Appuyer sur une touche pour continuer.\n\n");
	refresh();
	getch();
	
	printw("On va faire un niveau d'introduction\n");
	refresh();
	
	//demande de confirmation du tuto
	sleep(1);
	printw("Prêt ? 1 pour OUI, 2 pour passer le tutoriel, Autre pour quitter : ");
	refresh();
	scanw("%d", &nb_confirm);
	refresh();
	clear();

	if (nb_confirm == 1) {
		niv_suiv(niveau);
		niveau_tuto(&niveau); // niveau tutoriel
		printw("On va passer aux choses sérieuses maintenant avec les différents niveaux.\n");
		printw("Appuyer sur une touche pour continuer.\n");
		refresh();
		getch();
		clear();
	} else if ( nb_confirm == 2 ) {
	    niveau = 1;
	} else {
	    printw("Au revoir\n");
		refresh();
		sleep(2);
		endwin();
		return 0;
	} 
	
	attron(A_BOLD | A_STANDOUT | COLOR_PAIR(1)); //Affichage du 1er Chapitre
	mvprintw(LINES / 2, afficher_centre("CHAPITRE 1: Les Mots"),"CHAPITRE %d: Les Mots\n", chapitre); //Titre
	attroff(A_BOLD | A_STANDOUT | COLOR_PAIR(1));
	refresh();
	sleep(1.5);
	mvprintw(LINES - 2, 0, "Dans cette suite de niveau vous retrouverez des mots comme réponses.");
	refresh();
	sleep(1);
	mvprintw(LINES - 1, 0, "Appuyer sur une touche pour continuer.\n");
	refresh();
	getch();
	clear(); 
	
	niv_suiv(niveau);
	niveau_1_1(&nb_vie, &niveau); //Niveau 1.1
	
	niv_suiv(niveau); 
	niveau_1_2(&nb_vie, &niveau); //Niveau 1.2
	
	niv_suiv(niveau);
	niveau_1_3(&nb_vie, &niveau); //Niveau 1.3
	
	niv_suiv(niveau);
	niveau_1_4(&nb_vie, &niveau); //Niveau 1.4
	
	niv_suiv(niveau);
	niveau_1_5(&nb_vie, &niveau); //Niveau 1.5
	
	nb_vie = nb_vie + 1;
	printw("Félicitation , vous avez réussi tous les niveaux du Chapitre %d, vous avez donc gagné une vie supplémentaire montant votre totale à %d vies.\n", chapitre, nb_vie);
	chapitre = chapitre + 1;
	printw("On va maintenant passer au Chapitre %d.\n\n", chapitre);
	printw("Appuyer sur une touche pour continuer.\n");
	refresh();
	getch();
	clear(); //Affichage du 2nd Chapitre
	
	attron(A_BOLD | A_STANDOUT | COLOR_PAIR(1));
	mvprintw(LINES / 2 , afficher_centre("CHAPITRE 2: Les Nombres"),"CHAPITRE %d: Les Nombres\n", chapitre); //Titre
	attroff(A_BOLD | A_STANDOUT | COLOR_PAIR(1));
	
	attron(A_UNDERLINE | COLOR_PAIR(2));
	mvprintw(LINES, afficher_centre("Niveau 1"), "Niveau %d\n\n", niveau);
	attroff(A_UNDERLINE | COLOR_PAIR(2));
	refresh();
	sleep(1.5);
	mvprintw(LINES - 2, 0, "Dans cette suite de niveau vous retrouverez des nombres comme réponses.");
	refresh();
	sleep(1);
	mvprintw(LINES - 1, 0, "Appuyer sur une touche pour continuer.\n");
	refresh();
	getch();
	clear(); 
	
	niv_suiv(niveau);
	niveau_2_1(&nb_vie, &niveau); //Niveau 2.1 
	
	niv_suiv(niveau); 
	niveau_2_2(&nb_vie, &niveau); //Niveau 2.2
	
	niv_suiv(niveau);
	niveau_2_3(&nb_vie, &niveau); //Niveau 2.3 
	
	niv_suiv(niveau);
	niveau_2_4(&nb_vie, &niveau); //Niveau 2.4
	
	niv_suiv(niveau);
	niveau_2_5(&nb_vie, &niveau); //Niveau 2.5
	
	nb_vie = nb_vie + 1;
	printw("Félicitation , vous avez réussi tout les niveaux du Chapitre %d, vous avez donc gagné une vie supplémentaire montant votre totale à %d vies.\n", chapitre, nb_vie);
	chapitre = chapitre + 1;
	printw("On va maintenant passer au Chapitre %d.\n\n", chapitre);
	printw("Appuyer sur une touche pour continuer.\n");
	refresh();
	getch();
	clear(); //Affichage du 3ème Chapitre
	
	attron(A_BOLD | A_STANDOUT | COLOR_PAIR(1));
	mvprintw(LINES / 2, afficher_centre("CHAPITRE 3: Réflexes"),"CHAPITRE %d: Réflexes\n", chapitre); //Titre
	attroff(A_BOLD | A_STANDOUT | COLOR_PAIR(1));
	refresh();
	sleep(1.5);
	mvprintw(LINES - 2, 0, "Dans cette suite de niveau vous retrouverez un mélange des Chapitre 1 et 2 comme réponses.");
	refresh();
	sleep(1);
	mvprintw(LINES - 1, 0, "Appuyer sur une touche pour continuer.\n");
	refresh();
	getch();
	clear(); 
	
	niv_suiv(niveau);
	niveau_3_1(&nb_vie, &niveau); //Niveau 3.1
	
	niv_suiv(niveau); 
	niveau_3_2(&nb_vie, &niveau); //Niveau 3.2
	
	niv_suiv(niveau);
	niveau_3_3(&nb_vie, &niveau); //Niveau 3.3
	
	niv_suiv(niveau);
	niveau_3_4(&nb_vie, &niveau); //Niveau 3.4
	
	niv_suiv(niveau);
	niveau_3_5(&nb_vie, &niveau); //Niveau 3.5
	
	nb_vie = nb_vie + 1;
	printw("Félicitation , vous avez réussi tout les niveaux du Chapitre %d, vous avez donc gagné une vie supplémentaire montant votre totale à %d vies.\n", chapitre, nb_vie);
	chapitre = chapitre + 1;
	printw("Vous avez donc déverouillé les Chapitre Bonus (Chapitre %d).\n\n", chapitre);
	printw("Souhaitez faire les niveaux bonus ? (1 pour OUI, Autre pour NON).\n");
	refresh();
	
	scanw("%d", &nb_confirm);
	if (nb_confirm != 1) {
		fin();
		endwin();
		return 0;
	 }
	
	clear(); //Affichage du 4ème Chapitre
	
	attron(A_BOLD | A_STANDOUT | COLOR_PAIR(1));
	mvprintw(LINES / 2, afficher_centre("CHAPITRE 4: BONUS"),"CHAPITRE %d: BONUS\n", chapitre); //Titre
	attroff(A_BOLD | A_STANDOUT | COLOR_PAIR(1));
	refresh();
	sleep(1.5);
	mvprintw(LINES - 2, 0, "Dans cette suite de niveau vous retrouverez des niveaux bonus qui n'ont pas de rapport avec les 3 premiers chapitres.");
	refresh();
	sleep(1);
	mvprintw(LINES - 1, 0, "Appuyer sur une touche pour continuer.\n");
	refresh();
	getch();
	clear();
	
	niv_suiv(niveau);
	niveau_bonus_1(&nb_vie, &niveau); //Niveau Bonus.1

	printw("Dans le niveau bonus 2, vous aurez des nombres aléatoires qui vont apparaître à votre écran. Vous ne perdez pas de vie dans ce niveau et pouvez donc recommencer le niveau autant de fois que vous le voulez.\n\n");
	refresh();
	sleep(1);
	niv_suiv(niveau);
	do {
		niveau_bonus_2(); //Niveau Bonus.2
		
		printw("Voulez vous recommencer le niveau ? (1 pour recommencer, Autre pour continuer vers le 3ème niveau bonus) : ");
		refresh();
		scanw("%d", &nb_confirm);
		
		if (nb_confirm == 1) {
			clear();
		} else { 
		    break;
		}
	} while (nb_confirm == 1);
	niveau = niveau + 1;
	clear();
	
	niv_suiv(niveau);
	niveau_bonus_3(&nb_vie, &niveau); //Niveau Bonus.3
	
	fin();
	
	endwin(); //fermeture de la fenêtre + fin du prog
	return 0;
}

int afficher_centre(char phrase[]) {
	int taille, milieu_ligne = 0, centre = COLS / 2;
    
    taille = strlen(phrase);
    
    milieu_ligne = centre - (taille / 2); // prend le milieu de la ligne et la soustrait a la moitié de la taille de la chaîne de caractère
    
    return milieu_ligne;
}

void car() {
    int i;
    for (i = 3; i >= 1; i--) {
        printw("Début dans %d", i);
        refresh();
        sleep(1);
        clear();
    }

}

void vie(int *nb_vie) {
	if (*nb_vie > 2) {
	    *nb_vie = *nb_vie - 1;
		clear();
		printw("Dommage, vous n'avez pas trouvé la bonne réponse, Vous venez de perdre une vie.\nVous n'avez plus que %d vies.\n\n", *nb_vie);
		printw("Appuyez sur une touche du clavier pour relancer le niveau.\n");
		refresh();
		getch();
		clear();
	} else if (*nb_vie == 2 /* || *nb_vie == 1*/) {
	    *nb_vie = *nb_vie - 1;
		clear();
		printw("Dommage, vous n'avez pas trouvé la bonne réponse, vous venez de perdre une vie.\nVous n'avez plus que %d vie.\n\n", *nb_vie);
		printw("Appuyez sur une touche du clavier pour relancer le niveau.\n");
		refresh();	
		getch();
		clear();
	} else {
		clear();
		printw("Dommage, vous n'avez pas trouvé la bonne réponse. \n");
		printw("Vous n'avez plus de vie.\n");
		refresh();
		getch();
		clear();
		attron(COLOR_PAIR(1));
		mvprintw(LINES / 2, afficher_centre("GAME OVER"), "GAME OVER\n");
		attroff(COLOR_PAIR(1));
		refresh();
		getch();
		endwin();
		exit(0);
	}
}

void niv_suiv(int niveau) {
	printw("On va commencer le ");
	attron(A_UNDERLINE | COLOR_PAIR(2));
	printw("Niveau %d\n", niveau);
	attroff(A_UNDERLINE | COLOR_PAIR(2));
    printw("Appuyez sur une touche lorsque vous êtes prêts.\n");
    refresh();
    getch();
    clear();
}

void niveau_tuto(int *niveau) {
    int reponse;
    
    do {
        car();
        printw("Tutoriel"); //affichage du texte
		refresh();
		sleep(3.5); //temps d'attente avant d'être effacer
		clear();  //effaçage du texte

		printw("Quel était le texte affiché ? (Mettez le chiffre de la réponse)\n");
		printw("1) Tutoriel \n");
		printw("2) Niveau Tutoriel \n");
		printw("3) Trouble\n"); // différentes réponses
		printw("Réponse : ");
		refresh();
		
		scanw("%d", &reponse);
		if (reponse == 1) { // vérification de la réponse
		    printw("Félicitation, vous avez réussi le tutoriel !\n");
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    printw("Dommage, vous n'avez pas trouvé la réponse. Je vous donne un essai supplémentaire.\n");
		    printw("Appuyer sur une touche pour recommencer le niveau.\n");
		    refresh();
		    getch();
		    clear();
		}
	} while (reponse != 1); //continue le niveau jusqu'à que le joueur trouve la bonne réponse
}

void niveau_1_1(int *nb_vie, int *niveau) {
    int reponse;
    
    do {
        car();
		printw("accomplissement");
		refresh();
		sleep(2.3);
		clear();

		printw("Quel était le texte affiché ? (Mettez le chiffre de la réponse)\n");
		printw("1) azertyuiop \n");
		printw("2) accomplissement \n");
		printw("3) acceptation \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 2) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1; // bonne réponse, passer au niveau suivant
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie); // si la réponse n'est pas bonne baisse le nombre de vie de 1
		}
		
	}	while (reponse != 2);
}

void niveau_1_2(int *nb_vie, int *niveau) {
    int reponse;
    
    do {
        car();
		printw("attention");
		refresh();
		sleep(1.8);
		clear();

		printw("Quel était le texte affiché ?\n");
		printw("1) attention \n");
		printw("2) tentation \n");
		printw("3) attraper \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 1) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 1);
}

void niveau_1_3(int *nb_vie, int *niveau) {
    int reponse;
    
    do {
        car();
		mvprintw(6, (afficher_centre("potion magique") + 20) , "potion magique");
		refresh();
		sleep(1.4);
		clear();

		printw("Quel était le texte affiché ?\n");
		printw("1) potiron magnifique \n");
		printw("2) portion magique \n");
		printw("3) potion magique \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 3) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 3);
}

void niveau_1_4(int *nb_vie, int *niveau) {
    int reponse;
    
    do {
        car();
        attron(A_BOLD | COLOR_PAIR(2)); // change la forme de la police
		mvprintw(LINES - 1, COLS - 5 , "Coin");
		attroff(A_BOLD | COLOR_PAIR(2));
		refresh();
		sleep(1);
		clear();

		printw("Quel était le texte affiché ? (Attention à la majuscule !)\n");
		printw("1) coin \n");
		printw("2) Ouin \n");
		printw("3) Coin \n");
		printw("4) ouin \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 3) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 3);
}

void niveau_1_5(int *nb_vie, int *niveau) {
    int reponse;
    
    do {
        car();
        attron(A_BOLD | COLOR_PAIR(3));
		mvprintw(LINES - 3, 12 , "Poire"); // La bonne réponse en vert
		attroff(A_BOLD | COLOR_PAIR(3));
		attron(A_BOLD | COLOR_PAIR(4));
		mvprintw(3, COLS - 12, "Tireuse"); // la mauvaise réponse en bleu
		attroff(A_BOLD | COLOR_PAIR(4));
		refresh();
		sleep(1);
		clear();

		printw("Quel était le texte affiché ");
		attron(A_BOLD | COLOR_PAIR(3));
		printw("en vert");
		attroff(A_BOLD | COLOR_PAIR(3));
		printw(" ?\n");
		printw("1) Poire \n");
		printw("2) Trieuse \n");
		printw("3) Foire \n");
		printw("4) Tireuse \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 1) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 1);
}

void niveau_2_1(int *nb_vie, int *niveau) {
    int reponse;
    
    do {
        car();
		printw("2023");
		refresh();
		sleep(1.8);
		clear();

		printw("Quel était le nombre affiché ?\n");
		printw("1) 2022 \n");
		printw("2) 2015 \n");
		printw("3) 2023 \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 3) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 3);
}

void niveau_2_2(int *nb_vie, int *niveau) {
    int reponse;
    
    do {
        car();
		printw("7894561");
		refresh();
		sleep(1.9);
		clear();

		printw("Quel était le nombre affiché ?\n");
		printw("1) 7485961 \n");
		printw("2) 7894561 \n");
		printw("3) 9876541 \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 2) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 2);
}

void niveau_2_3(int *nb_vie, int *niveau) {
    int reponse, nb[2];
    nb_aleas_tab(nb, 2, 100); // génère 2 nombres aléatoires
    do {
        car();
    
		printw("%d + %d", nb[0], nb[1]); //affiche le calcul des 2 nombres aléatoires
		refresh();
		sleep(1.4);
		clear();

		printw("Quel était la réponse du calcul affiché ? (écrivez le résultat) \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == nb[0] + nb[1]) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != nb[0] + nb[1]);
}

void niveau_2_4(int *nb_vie, int *niveau) {
    int reponse, nb[4];
    nb_aleas_tab(nb, 4, 100);
    do {
        car();
		attron(A_STANDOUT | A_BOLD | COLOR_PAIR(1));
		mvprintw(2, COLS - 8 , "%d - %d", nb[0], nb[1]); // La bonne réponse en rouge
		attroff(A_STANDOUT | A_BOLD| COLOR_PAIR(1));
		attron(A_STANDOUT | A_BOLD | COLOR_PAIR(5));
		mvprintw(LINES - 3, (afficher_centre("00 + 00") - 5), "%d + %d", nb[2], nb[3]); // la mauvaise réponse en cyan
		attroff(A_STANDOUT | A_BOLD | COLOR_PAIR(5));
		refresh();
		sleep(1.8);
		clear();

		printw("Quel était la réponse du calcul affiché ");
		attron(A_STANDOUT | A_BOLD | COLOR_PAIR(1));
		printw("en rouge");
		attroff(A_STANDOUT | A_BOLD | COLOR_PAIR(1));
		printw(" ? (écrivez le résultat)\n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == nb[0] - nb[1]) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != nb[0] - nb[1]);
}

void niveau_2_5(int *nb_vie, int *niveau) {
    int reponse, nb[9];
    nb_aleas_tab(nb, 9, 10);
    do {
        car();
		attron(A_REVERSE | A_BOLD | COLOR_PAIR(4));
		printw("%d + %d * %d", nb[0], nb[1], nb[2]); // La bonne réponse en inversé bleu
		attroff(A_REVERSE | A_BOLD | COLOR_PAIR(4));
		attron(A_STANDOUT | A_BOLD | COLOR_PAIR(5));
		mvprintw(LINES - 3, (afficher_centre("0 * 0 - 0")), "%d * %d - %d", nb[3], nb[4], nb[5]); // la mauvaise réponse en surligné cyan
		attroff(A_STANDOUT | A_BOLD | COLOR_PAIR(5));
		attron(A_REVERSE | A_BOLD | COLOR_PAIR(3));
		mvprintw(LINES / 2, COLS - 9 ,"%d + %d * %d", nb[6], nb[7], nb[8]); // La mauvaise réponse en inversé vert
		attroff(A_REVERSE | A_BOLD | COLOR_PAIR(3));
		refresh();
		sleep(2);
		clear();

		printw("Quel était la réponse du calcul affiché en ");
		attron(A_REVERSE | A_BOLD | COLOR_PAIR(4));
		printw("inversé bleu");
		attroff(A_REVERSE | A_BOLD | COLOR_PAIR(4));
		printw(" ? (écrivez le résultat)\n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == nb[0] + nb[1] * nb[2]) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != nb[0] + nb[1] * nb[2]);
}

void niveau_3_1(int *nb_vie, int *niveau) {
    int reponse;
    
    do {
        car();
		printw("4ttention !");
		refresh();
		sleep(1.4);
		clear();

		printw("Quels étaient les caractères affiché ?\n");
		printw("1) Attention ! \n");
		printw("2) 4ttention !\n");
		printw("3) Attenti0n \n");
		printw("4) 4ttenti0n \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 2) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 2);
}

void niveau_3_2(int *nb_vie, int *niveau) {
    int reponse;
    
    do {
        car();
        attron(A_REVERSE | A_BOLD | COLOR_PAIR(6));
		mvprintw(5, 19 , "3 P0mmes"); // La bonne réponse en inversé jaune
		attroff(A_REVERSE | A_BOLD | COLOR_PAIR(6));
		attron(A_BOLD | COLOR_PAIR(4));
		mvprintw(LINES - 23, COLS - 8 , "5 POires"); // la mauvaise réponse en gras bleu 
		attroff(A_BOLD | COLOR_PAIR(4));
		refresh();
		refresh();
		sleep(1.5);
		clear();

		printw("Quels étaient les caractères affiché en ");
		attron(A_REVERSE | A_BOLD | COLOR_PAIR(6));
		printw("inversé jaune"); 
		attroff(A_REVERSE | A_BOLD | COLOR_PAIR(6));
		printw(" ?\n");
		printw("1) 3 POires \n");
		printw("2) 5 POmmes \n");
		printw("3) 5 POires \n");
		printw("4) 3 P0mmes \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 4) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 4);
}

void niveau_3_3(int *nb_vie, int *niveau) {
    int reponse;
    
    do {
        car();
        attron(COLOR_PAIR(1));
		mvprintw(LINES / 2, afficher_centre("       "), "       ");
		refresh();
		sleep(1); // pour créer un effet de clignotement (car la fonction A_BLINK fonctionne pas tout le temps)
		attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(1));
		mvprintw(LINES / 2, afficher_centre("AaA@AaA"), "AaA@AaA");
		attroff(COLOR_PAIR(1));
		refresh();
		sleep(1);
		attron(COLOR_PAIR(1));
		mvprintw(LINES / 2, afficher_centre("       "), "       ");
		attroff(COLOR_PAIR(1));
		refresh();
		sleep(1);
		clear();

		printw("Quel était le texte affiché ?\n");
		printw("1) AaA@AaA \n");
		printw("2) AAAAAAA \n");
		printw("3) aAaAaAa \n");
		printw("4) AaAaAaA \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 1) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 1);
}

void niveau_3_4(int *nb_vie, int *niveau) {
    int reponse;
    
    do {
        car();
        attron(A_BOLD | COLOR_PAIR(3));
		mvprintw(LINES / 2 - 2, afficher_centre("           "), "           "); // Bonne réponse en vert-blanc
		attroff(A_BOLD | COLOR_PAIR(3));
		attron(A_REVERSE | COLOR_PAIR(8));
		mvprintw(LINES / 2 , afficher_centre("             "), "             "); // Mauvaise réponse en noir-bleu
		attroff(A_REVERSE | COLOR_PAIR(8));
		attron(A_BOLD | COLOR_PAIR(6));
		mvprintw(LINES / 2 + 2, afficher_centre("             "), "             "); // Mauvaise réponse en jaune-rouge
		attroff(A_BOLD | COLOR_PAIR(6));
		refresh();
		sleep(1);
        attron(A_BOLD | COLOR_PAIR(3));
		mvprintw(LINES / 2 - 2, afficher_centre("Bleu - Noir"), "Bleu - Noir"); // Bonne réponse en vert-blanc
		attroff(A_BOLD | COLOR_PAIR(3));
		attron(A_REVERSE | COLOR_PAIR(8));
		mvprintw(LINES / 2 , afficher_centre("            "), "            "); // Mauvaise réponse en noir-bleu
		attroff( A_REVERSE | COLOR_PAIR(8));
		attron(A_BOLD | COLOR_PAIR(6));
		mvprintw(LINES / 2 + 2, afficher_centre("             "), "             "); // Mauvaise réponse en jaune-rouge
		attroff(A_BOLD | COLOR_PAIR(6));
		refresh();
		sleep(1);
		attron(A_BOLD | COLOR_PAIR(3));
		mvprintw(LINES / 2 - 2, afficher_centre("           "), "           "); // Bonne réponse en vert-blanc
		attroff(A_BOLD | COLOR_PAIR(3));
		attron(A_REVERSE | COLOR_PAIR(8));
		mvprintw(LINES / 2, afficher_centre("Blanc - Vert "), "Blanc - Vert "); // Mauvaise réponse en noir-bleu
		attroff(A_REVERSE | COLOR_PAIR(8));
		attron(A_BOLD | COLOR_PAIR(6));
		mvprintw(LINES / 2 + 2, afficher_centre("             "), "             "); // Mauvaise réponse en jaune-rouge
		attroff(A_BOLD | COLOR_PAIR(6));
		refresh();
		sleep(1);
		attron(A_BOLD | COLOR_PAIR(3));
		mvprintw(LINES / 2 - 2, afficher_centre("           "), "           "); // Bonne réponse en vert-blanc
		attroff(A_BOLD | COLOR_PAIR(3));
		attron(A_REVERSE | COLOR_PAIR(8));
		mvprintw(LINES / 2 , afficher_centre("            "), "            "); // Mauvaise réponse en noir-bleu
		attroff(A_REVERSE | COLOR_PAIR(8));
		attron(A_BOLD | COLOR_PAIR(6));
		mvprintw(LINES / 2 + 2, afficher_centre("Jaune - Rouge"), "Jaune - Rouge"); // Mauvaise réponse en jaune-rouge
		attroff(A_BOLD | COLOR_PAIR(6));
		refresh();
		sleep(1);
		attron(A_BOLD | COLOR_PAIR(3));
		mvprintw(LINES / 2 - 2, afficher_centre("           "), "           "); // Bonne réponse en vert-blanc
		attroff(A_BOLD | COLOR_PAIR(3));
		attron(A_REVERSE | COLOR_PAIR(8));
		mvprintw(LINES / 2 , afficher_centre("             "), "             "); // Mauvaise réponse en noir-bleu
		attroff(A_REVERSE | COLOR_PAIR(8));
		attron(A_BOLD | COLOR_PAIR(6));
		mvprintw(LINES / 2 + 2, afficher_centre("             "), "             "); // Mauvaise réponse en jaune-rouge
		attroff(A_BOLD | COLOR_PAIR(6));
		refresh();
		clear();

		printw("Quel étaient les textes affiché ");
		attron( A_BOLD | COLOR_PAIR(3));
		printw("vert sur fond blanc");
		attroff( A_BOLD | COLOR_PAIR(3));
		printw(" ?\n");
		printw("1) Blanc - Vert \n");
		printw("2) Bleu - Vert \n");
		printw("3) Blanc - Noir \n");
		printw("4) Bleu - Noir \n");
		printw("5) Jaune - Vert \n");
		printw("6) Bleu - Jaune \n");
		printw("7) Noir - Rouge \n");
		printw("8) Jaune - Rouge \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 4) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 4);
}

void niveau_3_5(int *nb_vie, int *niveau) {
    int reponse, i;
    
    do {
        car();
        for (i = -2 ; i <= 2; i++) {
    		if (i == -2) {
    		    attron(COLOR_PAIR(2));
        		mvprintw(LINES / 2, afficher_centre("CENNTRE") + i, "CENNTRE");
        		attroff(COLOR_PAIR(2));
        		attron(COLOR_PAIR(8));
        		mvprintw(LINES / 2 - 1, afficher_centre(":)") + i, ":)");
        		attroff(COLOR_PAIR(8));
        		refresh();
        		sleep(1.6);
        		clear();
    		} else if (i == 0) {
    		    attron(COLOR_PAIR(2));
        		mvprintw(LINES / 2, afficher_centre("BAWWWWW") + i, "BAWWWWW");
        		attroff(COLOR_PAIR(2));
        		attron(A_BOLD | COLOR_PAIR(2));
        		mvprintw(LINES -1, COLS - 7 , "CHIYOKO");
        		attroff(A_BOLD | COLOR_PAIR(2));
        		refresh();
        		sleep(1.6);
        		clear();
    		} else if (i == 2) {
    		    attron(COLOR_PAIR(2));
        		mvprintw(LINES / 2, afficher_centre("LETTRES") + i, "LETTRES");
        		attroff(COLOR_PAIR(2));
        		attron(A_BOLD | COLOR_PAIR(7));
        		mvprintw(LINES - 10, 7 , "OULA !");
        		attroff(A_BOLD | COLOR_PAIR(7));
        		refresh();
        		sleep(1.6);
        		clear();
    		} else {
    		    attron(COLOR_PAIR(2));
        		mvprintw(LINES / 2, afficher_centre("       ") + i, "       ");
        		attroff(COLOR_PAIR(2));
        		refresh();
        		sleep(1.5);
        		clear();
    		}
        }
		printw("Quel était le texte affiché en bas à droite de l'écran durant le 3ème rythme ?\n");
		printw("1) CH1YOK0 \n");
		printw("2) B4WWWWW \n");
		printw("3) CENNTRE \n");
		printw("4) OULA ! \n");
		printw("5) :) \n");
		printw("6) BAMMMMM \n");
		printw("7) LETTRES \n");
		printw("8) L3TTRES \n");
		printw("9) CHIYOKO \n");
		printw("10) LETTRE5 \n");
		printw("11) BAWWWWW \n");
		printw("12) C3NNTRE \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 9) {
		    printw("Félicitation, vous avez réussi le niveau %d!\n", *niveau);
		    *niveau = 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 9);
}

void niveau_bonus_1(int *nb_vie, int *niveau) {
	int reponse, i, hauteur = -8;
    
    do {
        car();
        for (i = 0; i < 16; i++) { //affichage 16 étages du drapeau FR
		    attron(COLOR_PAIR(8));
			mvprintw((LINES / 2) + hauteur , afficher_centre("*********") - 13, "*********");
			attroff(COLOR_PAIR(8));
			attron(A_REVERSE |COLOR_PAIR(2));
			mvprintw((LINES / 2) + hauteur , afficher_centre("*********") - 4, "*********");
			attroff(A_REVERSE |COLOR_PAIR(2));
			attron(COLOR_PAIR(9));
			mvprintw((LINES / 2) + hauteur , afficher_centre("*********") + 5, "*********");
			attroff(COLOR_PAIR(9));
			refresh();
			hauteur = hauteur + 1;
		}
		sleep(1.2);
		clear();

		printw("Quel était le drapeau affiché ?\n");
		printw("1) Algérie \n");
		printw("2) Belgique \n");
		printw("3) Italie \n");
		printw("4) France \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 4) {
		    printw("Félicitation, vous avez réussi le niveau bonus %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		}
		
	}	while (reponse != 4);
}

void nb_aleas_tab(int nb[],int taille, int valeur) {
    int i;
    
	srand(time(NULL));
	
	for (i = 0; i < taille; i = i + 1) { // renvoie valeur aléas TAILLE fois dans le nb
		nb[i] = rand() % valeur; // prend 1 nombre aléatoire de 0 à valeur
	}
}

int nb_aleas(int valeur) {
    int nb;
    
	srand(time(NULL));
	
	nb = rand() % valeur; // prend 1 nombre aléatoire de 0 à valeur
	
	return nb;
}

void niveau_bonus_2() {
    int reponse, nb[4], rep_pc;
    
    do {
        car();
        nb_aleas_tab(nb, 4, 1000000); // génère 4 nombres aléatoires entre 0 et 1000000
        rep_pc = nb_aleas(4) + 1; // choisie le chiffre de la bonne réponse entre 1 et 4
		printw("%d",nb[0]);
		refresh();
		sleep(1.4);
		clear();

		printw("Quel était le nombre affiché ?\n");
		if (rep_pc == 1) {
		    printw("%d) %d\n", rep_pc, nb[0]);
		    printw("2) %d\n", nb[1]);
		    printw("3) %d\n", nb[2]);
		    printw("4) %d\n", nb[3]);
		} else if (rep_pc == 2) {
		    printw("1) %d\n", nb[2]);
		    printw("%d) %d\n", rep_pc, nb[0]);
		    printw("3) %d\n", nb[1]);
		    printw("4) %d\n", nb[3]);
		} else if (rep_pc == 3) {
		    printw("1) %d\n", nb[1]);
		    printw("2) %d\n", nb[2]);
		    printw("%d) %d\n", rep_pc, nb[0]);
		    printw("4) %d\n", nb[3]);
		} else {
		    printw("1) %d\n", nb[1]);
		    printw("2) %d\n", nb[2]);
		    printw("3) %d\n", nb[3]);
		    printw("%d) %d\n", rep_pc, nb[0]);
		}
	
		printw("Réponse : ");
		refresh();
		scanw("%d", &reponse);
		if (reponse == rep_pc) {
		    printw("Félicitation, vous avez réussi le niveau");
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
			printw("Dommage vous n'avez pas réussi le niveau.\n");
			printw("Appuyez sur une touche du clavier pour relancer le niveau.\n");
    		refresh();
    		getch();
    		clear();
		}
		
	}	while (reponse != rep_pc);
}

void niveau_bonus_3(int *nb_vie, int *niveau) { // créer un serpent qui va manger le mot "manger" petit à petit
    int reponse, deplacement = 0, i;
    char tete[] = "3", corps[] = "      ", queue[] = " ", manger[] = "Manger"; // tete blanche + corps vert + queue rouge
    do {
        car();
        for (i = 1; i <= 7; i++) {
    		attron(A_BOLD | COLOR_PAIR(7));
    		mvprintw(LINES / 2, afficher_centre("Manger"), manger);
    		attroff(A_BOLD | COLOR_PAIR(7));
    		attron(A_REVERSE | COLOR_PAIR(2));
    		mvprintw(LINES / 2, (afficher_centre("Manger") - 2) + deplacement, tete); // tete blanche
    		attroff(A_REVERSE | COLOR_PAIR(2));
    		attron(A_REVERSE | COLOR_PAIR(3));
    		mvprintw(LINES / 2, (afficher_centre("Manger") - 8) + deplacement, corps); // corps vert
    		attroff(A_REVERSE | COLOR_PAIR(3));
    		attron(A_REVERSE | COLOR_PAIR(1));
    		mvprintw(LINES / 2, (afficher_centre("Manger") - 9) + deplacement , queue); // queue rouge
    		attroff(A_REVERSE | COLOR_PAIR(1));
    		refresh();
    		sleep(1);
    		clear();
    		manger[i - 1] = ' ';
    		deplacement = deplacement + 1;
        }

		printw("Quel était la couleur de la queue du serpent ? (le bloc le plus à gauche)\n");
		printw("1) Verte \n");
		printw("2) Rouge \n");
		printw("3) Blanche \n");
		printw("4) Noir \n");
		printw("Réponse : ");
		refresh();

		scanw("%d", &reponse);
		if (reponse == 2) {
		    printw("Félicitation, vous avez réussi le niveau bonus %d!\n", *niveau);
		    *niveau = *niveau + 1;
		    refresh();
		    sleep(1.5);
		    clear();
		} else {
		    vie(nb_vie);
		    deplacement = 0;
		    strcpy(manger, "Manger");
		}
		
	}	while (reponse != 2);
}

void fin() {
    int i;
    printw("Félicication ! Vous avez réussi TOUT les niveaux de ce jeu comprenant les niveaux Bonus !\nPour fêter ça je vous propose un petit pas de dance. (Appuyez sur une touche pour me voir danser c:)\n");
    refresh();
    getch();
    for (i = 0; i < 15; i++) {
        if (i % 2 == 0 && i < 4) {
            clear();
            mvprintw((LINES / 2) - 2, afficher_centre("O"), "O"); //tete 
            mvprintw((LINES / 2) - 1, afficher_centre("\\_ | _ "), "\\_ | _ "); //corps haut
            mvprintw((LINES / 2) , afficher_centre("   |  \\"), "   |  \\"); //corp bas
            mvprintw((LINES / 2) + 1 , afficher_centre("/ \\")  ,"/ \\"); //jambes
            refresh();
            sleep(1);
        } else if (i % 2 == 1 && i < 4) {
            clear();
            mvprintw((LINES / 2) - 2, afficher_centre("O"), "O");
            mvprintw((LINES / 2) - 1, afficher_centre(" _ | _/"), " _ | _/");
            mvprintw((LINES / 2), afficher_centre("/  |   "), "/  |   ");
            mvprintw((LINES / 2) + 1, afficher_centre("/ \\")  ,"/ \\");
            refresh();
            sleep(1);
        } else if (i % 2 == 0 && i >= 4) {
            clear();
            attron(A_BOLD | A_STANDOUT | COLOR_PAIR(1));
	        mvprintw((LINES / 2) -3, afficher_centre("FIN"),"FIN"); //texte de fin de jeu
	        attroff(A_BOLD | A_STANDOUT | COLOR_PAIR(1));
            mvprintw((LINES / 2) - 2, afficher_centre("O"), "O");
            mvprintw((LINES / 2) - 1, afficher_centre("\\_ | _ "), "\\_ | _ ");
            mvprintw((LINES / 2) , afficher_centre("   |  \\"), "   |  \\");
            mvprintw((LINES / 2) + 1 , afficher_centre("/ \\")  ,"/ \\");
            refresh();
            sleep(1);
        } else{
            clear();
            attron(A_BOLD | A_STANDOUT | COLOR_PAIR(1));
	        mvprintw((LINES / 2) -3, afficher_centre("FIN"),"FIN");
	        attroff(A_BOLD | A_STANDOUT | COLOR_PAIR(1));
            mvprintw((LINES / 2) - 2, afficher_centre("O"), "O");
            mvprintw((LINES / 2) - 1, afficher_centre(" _ | _/"), " _ | _/");
            mvprintw((LINES / 2), afficher_centre("/  |   "), "/  |   ");
            mvprintw((LINES / 2) + 1, afficher_centre("/ \\")  ,"/ \\");
            refresh();
            sleep(1);
        }
    }
}
