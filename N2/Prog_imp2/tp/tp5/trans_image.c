#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"

#define VAL(img,i,j) (img)->buff[(i)*(img)->w+(j)]  /* Gadget utile pour le calcul de l'emplacement du pixel i,j */

/********************************/
image_t *negatif(image_t *src)
{
  image_t *dst;


	
  return dst;
}

/********************************/

image_t *rotation(image_t *src, int angle)
{
  image_t *dst;


  return dst;
}

/********************************/

image_t *modifier_lumin(image_t *src, int pourcent)
{
  image_t *dst;

  return dst;
}

image_t *bruiter_image(image_t *src, int pourcent)
{
  image_t *dst;

  return dst;
}

/********************************/

int compare(const void *a, const void *b)
{
  return (int) *(unsigned char *)a - *(unsigned char *)b;
}

/********************************/
	
image_t *filtrer_median(image_t *src)
{
 image_t *dst;
 

 return dst;
}
