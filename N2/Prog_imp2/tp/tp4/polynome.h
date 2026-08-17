#ifndef POLYNOME_H
#define POLYNOME_H

struct polynome {
	int *coefficients; /* coefficients[i] est le coeff de degré i du polynôme */
	int taille;        /* nombre de cases allouées au tableau coefficients */
	int degre;         /* plus haut degré du polynôme */
};

struct polynome * creer_polynome (int);
void detruire_polynome (struct polynome **);

struct polynome * initialiser_polynome_alea (int);
void afficher_polynome (const struct polynome *);

void scalaire_polynome (struct polynome *, int);
struct polynome * additionner_polynome (const struct polynome *, const struct polynome *);
struct polynome * multiplier_polynome (const struct polynome *, const struct polynome *);
struct polynome * deriver_polynome (const struct polynome *);

double evaluer_polynome_pow (const struct polynome *, double);
double evaluer_polynome_classique (const struct polynome *, double);
double evaluer_polynome_Horner (const struct polynome *, double);


#endif
