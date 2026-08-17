#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "image.h"

#define TMP_STR_SIZE 300 /* Taille maximale lue d'une ligne de commentaires du fichier */

image_t *creer_image()
{
  image_t *p;
  p = (image_t *) malloc(sizeof(image_t));
  if (p==NULL) {
    printf("Erreur d'allocation\n");
    exit(1);
  }
  p->w=0;
  p->h=0;
  p->path=NULL;
  p->buff=NULL;
  return p;
}

/****************************************/
image_t *copier_image(image_t *src)
{
  image_t *dst;

  dst = creer_image();
  dst->w = src->w;
  dst->h = src->h;
  dst->path = strdup(src->path);
  dst->buff = (unsigned char *) malloc(src->w * src->h *sizeof (unsigned char));
  memcpy(dst->buff, src->buff, src->w * src->h * sizeof (unsigned char));
  return dst;
}

/****************************************/
void detruire_image(image_t **p)
{
  if (*p == NULL) return;
  free((*p)->buff);
  free((*p)->path);
  free(*p);
  *p=NULL;
}

/****************************************/
image_t *charger_image_pgm(char *nom_fichier)
{
  FILE *f;
  image_t *img;
  unsigned int nb_ng;
  char tmp_str[TMP_STR_SIZE];
  enum format {BIN, ASCII} pgm_form;

  /* Ouverture du fichier en lecture */
  f=fopen(nom_fichier, "r");

  if (!f)
    {
      /* on ecrit sur le flux d'erreur */
      fprintf(stderr, "impossible d'ouvrir le fichier %s\n", nom_fichier);
      return NULL;
    }

  /* on lit une ligne en supprimant les eventuels commentaires */
  do
    fgets(tmp_str, TMP_STR_SIZE, f);
  while (*tmp_str == '#');

  /* on determine le format */
  if ( !strcmp(tmp_str, "P5\n"))
    pgm_form = BIN;
  else if ( !strcmp(tmp_str, "P2\n"))
    pgm_form = ASCII;
  else
    {
      fprintf(stderr, "format fichier non pgm\n");
      return NULL;
    }

  img = creer_image();
  img->path = strdup(nom_fichier);

  /* on lit une ligne en supprimant les eventuels commentaires */
  do
    fgets(tmp_str, TMP_STR_SIZE, f);
  while (*tmp_str == '#');

  /* on determine la largeur et la hauteur de l'image */
  if (sscanf(tmp_str, "%ld %ld\n", &(img->w), &(img->h)) != 2)
    {
      /* si le sscanf n'a pas lu les deux entiers longs attendus: */
      fprintf(stderr, "format fichier non pgm\n");
      detruire_image(&img);
      return NULL;
    }

  /* on lit une ligne en supprimant les eventuels commentaires */
  do
    fgets(tmp_str, TMP_STR_SIZE, f);
  while (*tmp_str == '#');

  /* on lit le niveau de gris */
  if (sscanf(tmp_str, " %d ", &nb_ng) != 1)
    {
      /* si le sscanf n'a pas lu l'entier attendu: */
      fprintf(stderr, "format fichier non pgm\n");
      detruire_image(&img);
      return NULL;
    }

  if (nb_ng != 255)
    {
      fprintf(stderr, "Nombre de ng different de 255: erreur\n");
      detruire_image(&img);
      return NULL;
    }

  /* on alloue l'espace pour stocker l'image */
  img->buff = (unsigned char *) malloc(img->w * img->h * sizeof (unsigned char));

  /* on lit l'image en prenant en compte le format */
  if ( pgm_form == BIN )
    {
      if (fread(img->buff, img->w, img->h, f) != img->h)
        {
          fprintf(stderr, "fichier image imcomplet!\n");
          return NULL;
        }
    }
  else
    {
      unsigned int i,j;
      unsigned char *p = img->buff;
      for ( i = 0; i < img->h; i++)
        for ( j = 0; j < img->w; j++)
          fscanf(f, "%hhu ", p++);
    }

  fclose(f);
  return img;
}

/****************************************/

int sauver_image_pgm(char *nom_fichier, image_t *img)
{
  FILE *f;

  f=fopen(nom_fichier, "w");

  if (!f)
    {
      fprintf(stderr, "impossible d'ouvrir le fichier %s\n", nom_fichier);
      return 0;
    }

  fprintf(f, "P5\n");
  fprintf(f, "#Genere par guimp UPMC.\n");
  fprintf(f, "%ld %ld\n", img->w, img->h);
  fprintf(f, "255\n");

  fwrite(img->buff, img->w, img->h, f);
  fclose(f);
  return 1;
}
