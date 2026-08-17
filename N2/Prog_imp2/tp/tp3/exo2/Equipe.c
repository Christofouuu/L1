#include <stdio.h>
#include "Equipe.h" 
#include <string.h>

void affiche_equipe(const Equipe *eq){

    printf("%s %d pts (G:%d N:%d P:%d B:%d)\n", 
    (eq->nom) , 
    (eq->nb_points) , 
    (eq->nb_victoires) , 
    (eq->nb_nuls), 
    (eq->nb_defaites), 
    (eq->nb_bonus));

} 

Equipe* rech_ptr_equipe(Equipe Teq[], int n, char nom[]){

    int i;

    for(i=0;i<n;i++){

        if(strcmp(nom,(Teq+i)->nom)==0){

            return &(Teq[i]);

        }
    } 

    return NULL;  
}

void calcul_points(Equipe Teq[], int n){
    int i;

    for(i=0;i<n;i++){

        Teq[i].nb_points = 
        ( Teq[i].nb_victoires*4 ) + 
        ( Teq[i].nb_nuls*2 ) + 
        ( Teq[i].nb_bonus );
    } 
}

Equipe* premier_classement(Equipe Teq[], int n){

    int i , premier_indice = 0 , premier_score = Teq[0].nb_points ;

    for(i=1;i<n;i++){

        if( premier_score < Teq[i].nb_points ){

            premier_score=Teq[i].nb_points;
            premier_indice=i;

        } 
    }

    return &(Teq[premier_indice]); 
} 

void trier_equipes(Equipe Teq[], int n){
    Equipe tmp;
    int i,j,max;

    for(i=0;i<n-1;i++){

        max=max_indice(&(Teq[0]),NB_EQUIPES,i);
        tmp=Teq[i] ;
        Teq[i]=Teq[max];
        Teq[max]=tmp; 

    } 
} 

int max_indice(Equipe Teq[], int n, int d){
    int i,max=d;

        for(i=d+1;i<n;i++){

            if(Teq[i].nb_points> Teq[max].nb_points){
                max=i;
            }

        } 
    return max; 
} 
