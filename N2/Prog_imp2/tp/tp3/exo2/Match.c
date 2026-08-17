#include "Match.h"
#include <stdio.h> 

void affiche_match(Match m){
    printf("%20s %d - %d %20s\n",m.eq_hote->nom,m.score_hote,m.score_invite,m.eq_invite->nom);
}

/* Calcule les statistiques de victoire, nul, défaites et bonus 
   des équipes à partir du tableau Tmatch des matchs */
void analyse_matchs(Match Tmatch[], int n){
    int i;
    for(i=0;i<n;i++){
        if (Tmatch[i].score_hote > Tmatch[i].score_invite) {

            Tmatch[i].eq_hote->nb_victoires++;
            Tmatch[i].eq_invite->nb_defaites++;

            if (Tmatch[i].score_invite + 5 >= Tmatch[i].score_hote) {

                Tmatch[i].eq_invite->nb_bonus++;

            }
        } else if (Tmatch[i].score_invite > Tmatch[i].score_hote) {

            Tmatch[i].eq_invite->nb_victoires++;
            Tmatch[i].eq_hote->nb_defaites++;

            if (Tmatch[i].score_hote + 5 >= Tmatch[i].score_invite) {

                Tmatch[i].eq_hote->nb_bonus++;

            }
        } else if (Tmatch[i].score_hote == Tmatch[i].score_invite) {

            Tmatch[i].eq_hote->nb_nuls++ ;
            Tmatch[i].eq_invite->nb_nuls++ ;
        }
    } 
}
