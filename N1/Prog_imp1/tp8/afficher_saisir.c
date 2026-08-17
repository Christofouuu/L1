#include <stdio.h>
#define TAILLE_MAX 64
/* Affiche les taille premiers éléments du tableau tab dans le terminal.
 * Précondition : tab a au moins taille éléments */
void afficher_tab(int tab[], int taille);

/* Lit taille entiers en entrée et les met, dans cet ordre, dans tab
 * Précondition : tab peut contenir au moins taille éléments */
void saisir_tab(int tab[], int taille);

/* Saisir un tableau de taille_max variable :
 * Lit (au maximum) taille_max entiers en entrée ou jusqu'à ce que l'utilisateur
 * entre la valeur fin_saisie et les met, dans cet ordre, dans tab.
 * Retourne : le nombre d'éléments saisis (sans compter l'éventuel fin_saisie).
 * Précondition : tab peut contenir au moins taille_max éléments */
int saisir_tab_tv(int tab[], int taille, int fin_saisie);
int main()
{
	int tab[TAILLE_MAX] = {10, 20, 33, 8, 47, -56}, taille;

	afficher_tab(tab, 5);
	printf("\n");
	afficher_tab(tab, 10);
	printf("\n");

	saisir_tab(tab, 4);
	afficher_tab(tab, 4);
	printf("\n");

	taille = saisir_tab_tv(tab, TAILLE_MAX, -1);
	afficher_tab(tab, taille);
	printf("\n");
	return 0;
}

void afficher_tab(int tab[], int taille) {
	int i;
	
	for (i = 0; i < taille ; i++) {
		printf("%d ", tab[i]);
	}
}

void saisir_tab(int tab[], int taille) {
	int i;
	
	printf("Saisissez 4 valeurs qui vont remplacer les 4 premières du Tableau : ");
	for (i = 0; i < taille ; i++) {
		scanf("%d", &tab[i]);
	}
}

int saisir_tab_tv(int tab[], int taille, int fin_saisie) {
	int i;
	
	printf("Saisissez des valeurs (-1 pour terminer la saisie) : ");
	for (i = 0; i < taille ; i++) {
		scanf("%d", &tab[i]);
		if (tab[i] == fin_saisie) {
			break;
		}
		printf("%d ", tab[i]);
	}
	return i;
}
