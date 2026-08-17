struct date {
    unsigned jour ; /* numero du jour dans le mois (1 −28 , 1 −29 , 1−30 ou 1−31 selon le mois et l’annee ) */
    unsigned mois ; /* numero du mois dans l’annee (1 −12) */
    unsigned annee ; /* millesime (toutes les dates renvoient a l’eredite " commune ", i.e. apres J.-C .) */
};

struct individu {
    char *nom ; /* nom de l’individu */
    char *prenom ; /* prenom de l’individu */
    struct date *date_naiss ; /* date de naissance de l’individu */
    struct date *date_deces; /* date de deces de l’individu , NULL si l’individu est vivant */
    char  *pays_naiss ; /* pays de naissance de l’individu */
};

struct laureat_Turing {
    struct individu *laureat; /* laureat (e) du prix Turing */
    unsigned annee_prix; /* annee d’attribution du prix */
};

struct date * allouer_date(void);
// void retirer_parentheses (char *5);
struct laureat_Turing * allouer_tab_laureat (int n);