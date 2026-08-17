#include "liste.h"

maillon *creer_maillon (int val) {
  maillon * res = malloc(sizeof(maillon));
  if (res == NULL) {
    exit(1);
  }
  res->numero = val;
  res->suiv = NULL;
  
  return res;
}

// Liste initialiser_liste (){
//   Liste * res = malloc (sizeof(Liste));
//   res->debut = NULL;
//   res->taille = 0;

//   return res;
// }

void ajouter_en_tete (Liste *l, int numero_client) {
  maillon *m = creer_maillon(numero_client);
  m->suiv = l->debut;
  l->debut = m;
  l->taille++;
}

void afficher_liste (Liste l) {
  maillon * m;
  for(m = l.debut; m != NULL; m = m->suiv)
    printf("%d ", m->numero);
  printf("\n");
}

void suppression_en_fin(Liste l){
    maillon *tmp;
  
    for(tmp = l.debut; tmp != NULL; tmp = tmp->suiv) {
      if (tmp->suiv->suiv==NULL) {
        free(tmp->suiv->suiv);
        l.taille--;
        tmp->suiv = NULL;
      }
    }
}