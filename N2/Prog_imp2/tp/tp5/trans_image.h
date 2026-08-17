#ifndef TRANS_IMAGE
#define TRANS_IMAGE

#include "image.h"

image_t *negatif(image_t *src);

image_t *modifier_lumin(image_t *src, int pourcent);

image_t *rotation(image_t *src, int angle);

image_t *bruiter_image(image_t *src, int pourcent);

image_t *modifier_lumin(image_t *src, int pourcent);

image_t *filtrer_median(image_t *src);

#endif
