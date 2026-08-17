#include <stdio.h>

struct date {
    int jour;
    int mois;
    int annee;
};

struct commande {
    int numero; //identification de la commande
    float volume; //volume de bois à traiter, en mètres cubes
    struct date reception; //date de livraison des grumes à la scierie
};

unsigned nbre_jours_fev(unsigned a);
unsigned nbre_jours_mois(unsigned a, unsigned m);
int comparer_date(struct date date1, struct date date2);
struct date lendemain(struct date d);

int nbre_max_commande (struct date deb, struct commande tab[], int n);
struct date deb_travail(struct commande cmd1);

int main(){
    
    return 0;
}

unsigned nbre_jours_fev(unsigned a){
    if ((a%400 == 0) || (a%4 == 0 && a%100 == 0)){
        return 29;
    } else {
        return 28;
    }
}

unsigned nbre_jours_mois(unsigned a, unsigned m){
    if (m == 4 || m == 6 || m == 9 || m == 11){
        return 30;
    } else if (m == 2){
        return nbre_jours_fev(a);
    } else {
        return 30;
    }
}

int comparer_date(struct date date1, struct date date2){
	if(date1.annee == date2.annee){
		if(date1.mois == date2.mois){
			if(date1.jour > date2.jour){
				return 1;
			} else if (date1.jour == date2.jour){
				return 0;
			} else {
				return -1;
			}
		} else if(date1.mois > date2.mois){
			return 1;
		} else {
			return -1;
		}
	} else if(date1.annee > date2.annee){
		return 1;
	} else {
		return -1;
	}
}

struct date lendemain(struct date d){
    ++d.jour;
    if(d.jour > nbre_jours_mois(d.annee, d.mois)) {
        d.jour = 1;
        ++d.mois;
    } else if (d.mois > 12) {
        d.mois = 1;
        ++d.annee;
    }
    return d;
}

int nbre_max_commande (struct date deb, struct commande tab[], int n) {
    /* int quantité == 0;
    if (tab[].volume % 50 == 0) {
        quantité = tab[].volume / 50;
    } else {
        quantité = (tab[].volume / 50) + 1;
    } */
    
    int i, cmp;
    int nb_max = 0;
    for(i = 0;i < n; i++){
    	cmp = comparer_date(deb, tab[i].reception);
    	if((cmp == 0) || (cmp == -1)){
    		deb_travail(tab[i]); //créer une fonction deb_travail qui permet de savoir quand on peut recevoir de nouvelles commandes
    		nb_max = nb_max + 1;
    		printf("La commande de numéro %d est retenue \n", tab[i].numero);
    	}
    }
    return nb_max;
}

struct date deb_travail(struct commande cmd1){
	struct date d;
	d = cmd1.reception;
	int j;
	int i=0;
	j = cmd1.volume / 50;
	if (cmd1.volume / 50 != 0) {
		j = j + 1;
	}
	while (i < j) {
	d = lendemain(d);
	i = i + 1;
	}
	return d;
}
