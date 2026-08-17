#ifndef _IMAGE_H_
#define _IMAGE_H_



typedef struct {
  unsigned long w; // largeur en pixels
  unsigned long h; // hauteur en pixels
  char *path; // le chemin absolu du fichier correspondant
  unsigned char *buff; // w x h octets correspondant aux pixels
} image_t;


/* Alloue une structure \texttt{image\_t}, initialise tous ses champs a 0 NULL 
   et retourne un pointeur sur la structure allouée. 
   Attention, cette fonction n’alloue pas le buffer correspondant à l’image. */
image_t *creer_image();


/* Crée une nouvelle image et l'initialise
   en tant que copie de l'image passée en argument.*/
image_t *copier_image(image_t *src);


void detruire_image(image_t **p);


/* Crée une nouvelle image en lisant le fichier
   dont le nom est fourni en argument.
   Cette fonction lit le format PGM ASCII
   et le format BINAIRE pour une valeur max 256 de niveaux de gris */
image_t *charger_image_pgm(char *nom_fichier);


/* Enregistre une image dans un fichier au format \texttt{.pgm} BINAIRE
   avec une valeur maximale 256 de niveaux de gris.*/
int sauver_image_pgm(char *nom_fichier, image_t *img);

#endif
