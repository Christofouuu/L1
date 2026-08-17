#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Equipe.h"
#include "Match.h"


int main(){
  Equipe Teq[NB_EQUIPES];      /* Tableau des équipes */
  Match Tmatch[NB_MATCHS];     /* Tableau des matchs */

  FILE *fic = fopen("Top14.txt", "r");

  if (!fic){
    printf("Fichier non trouvé\n");
    return EXIT_FAILURE;
  }

  /* Lecture du début du fichier pour remplir le tableau Teq des NB_EQUIPES équipes */
  /* et mise à zéros des compteurs des statistiques */

  int i,j;
  for( i = 0; i < NB_EQUIPES ; i++ ){
    if(fscanf(fic,"%s",Teq[i].nom ) != 1){ 
      fprintf(stderr,"erreur d'argument pour equipe\n");
      break;
    }
    Teq[i].nb_points=0;
    Teq[i].nb_victoires=0;
    Teq[i].nb_nuls=0;
    Teq[i].nb_defaites=0;
    Teq[i].nb_bonus=0;
  }
  
  /* Affichage pour test de la liste des équipes */

  for(j=0;j<NB_EQUIPES;j++){
    printf("%s\n",Teq[j].nom);
  } 

  /* Lecture de la 2eme partie du fichier pour remplir le tableau Tmatch des NB_MATCHS matchs */
  /* Pour cela, il faut rechercher un pointeur sur équipe dans Teq à partir de son nom */
  char tmp_invite[256],tmp_hote[256];
  
  for(i=0;i<NB_MATCHS;i++){
      if(fscanf(fic , "%s %d -" , tmp_hote, &(Tmatch[i].score_hote)) != 2){

        fprintf(stderr,"erreur argument pour match\n");
        break;

      }else if(fscanf( fic , "%d %s\n" , &(Tmatch[i].score_invite),tmp_invite) != 2){

        fprintf(stderr,"erreur argument pour match\n");
        break;

      }

      Tmatch[i].eq_invite=rech_ptr_equipe(&(Teq[0]),NB_EQUIPES,tmp_invite);
      Tmatch[i].eq_hote=rech_ptr_equipe(&(Teq[0]),NB_EQUIPES,tmp_hote);
  }
  
  analyse_matchs(&(Tmatch[0]),NB_MATCHS);
  calcul_points(&(Teq[0]),NB_EQUIPES);

  /* Affichage pour test de la liste des matchs */

  for(j=0;j<NB_MATCHS;j++){
    
    affiche_match(Tmatch[j]);

  } 
  
  fclose(fic);

  

  /* Affichage des résultats des équipes */

  for (i=0;i<NB_EQUIPES;i++)
    affiche_equipe(&(Teq[i]));
  
  /* Affichage de l'équipe première au classement */

  printf("La première équipe du classement est %s.\n",(premier_classement(&(Teq[0]),NB_EQUIPES))->nom);
  
  /* Affichage du classement trié des équipes */
  
  trier_equipes(&(Teq[0]),NB_EQUIPES);

  
  for (i=0;i<NB_EQUIPES;i++)
    affiche_equipe(&(Teq[i]));


  return EXIT_SUCCESS;
}
