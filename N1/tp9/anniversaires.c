#include <stdio.h>

#define MAX_NOM 256
#define TAILLE_MAX 190
struct etudiant {
	char prenom[MAX_NOM];
	char nom[MAX_NOM];
	int jour;
	int mois;
};

void afficher_etudiant(struct etudiant e);

struct etudiant saisir_etudiant();

int cmp_etudiants(struct etudiant e, struct etudiant f);

int saisir_tab_etudiants(struct etudiant tab[], int taille_max);

void afficher_tab_etudiant(struct etudiant tab[], int taille);

int main() {
	int tab[TAILLE_MAX], taille;
	struct etudiant e = { .prenom = "DONALD", .nom = "KNUTH", .mois = 1, .jour = 10 };
	struct etudiant f = { .prenom = "GRACE", .nom = "HOPPER" };
	struct etudiant g = { .prenom = "CHRISTOPHE", .nom = "LI", .mois = 6, .jour = 03 };
	f.mois = 12;
	f.jour = 9;
	printf("Mon ami %s est né le mois %d\n", e.prenom, e.mois);
	printf("Mon ami %s est né le mois %d\n", f.prenom, f.mois);
	afficher_etudiant(g);
	
	printf("\n");
	
	//struct etudiant h = saisir_etudiant();
	//afficher_etudiant(h);
	
	//int cmp = cmp_etudiants(e, g);
	//printf("%d\n", cmp);
	
	taille = saisir_tab_etudiants(struct etudiant tab, TAILLE_MAX);
	
	afficher_tab_etudiant(struct etudiant tab, taille);
	
	return 0;
}

void afficher_etudiant(struct etudiant e) {
	printf("%s %s, né(e) un %d/%d\n", e.prenom, e.nom, e.jour, e.mois);
}

struct etudiant saisir_etudiant() {
	struct etudiant e;
	printf("Quel est votre nom ? ");
	scanf("%s", e.nom);
	
	printf("Quel est votre prénom ? ");
	scanf("%s", e.prenom);
		
	printf("Quel est votre jour de naissance ? ");
	scanf("%d", &e.jour);
	
	printf("Quel est votre mois de naissance ? (écriver le numéro du mois) ");
	scanf("%d", &e.mois);
	
	return e;
}

int cmp_etudiants(struct etudiant e, struct etudiant f) {
	if (e.mois < f.mois) {
		return -1;
	} else if (e.mois > f.mois) {
		return 1;
	} else {
		if (e.jour < f.jour) {
			return - 1;
		} else if (e.mois > f.mois) {
			return 1;
		} else {
			return 0;
		}
	}
}

int saisir_tab_etudiants(struct etudiant tab[], int taille_max) {
	int i;
	for (i = 0; i < taille_max; i++) {
		if (scanf("%s", tab[i].nom) < 1) {
			return i;
		} else if (scanf("%s", tab[i].prenom) < 1) {
			return i;
		} else if (scanf("%d/%d", tab[i].jour, tab[i].mois) < 2) {
			return i;
		}
	}
	return i;
}

void afficher_tab_etudiant(struct etudiant tab[], int taille) {
	int i;
	for (i = 0; i < taille ; i++) {
		afficher_etudiant(tab[i]);
	}
}
