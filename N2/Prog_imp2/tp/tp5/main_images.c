#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"image.h"
#include"trans_image.h"

int main() {
    char *input_filename = "test.pgm";
    char *output_filename = "output.pgm";

    image_t *img, *img2;
    
    img = charger_image_pgm(input_filename);
        
    if (!img) {
        fprintf(stderr, "Erreur lors du chargement de l'image %s\n", input_filename);
        return 1;
    }

    printf("Image chargée: largeur = %ld, hauteur = %ld\n", img->w, img->h);

    img2 =copier_image(img);  /* A commenter avant la suite, sinon fuite mémoire !! */
    
    /* img2 = negatif(img); */

    /* img2 =modifier_lumin(img, 50); */

    /* img2 = rotation(img, 90); */

    /* img2 = bruiter_image(img, 20); */

    /* img2 = modifier_lumin(img, 30); */

    /* img2 = filtrer_median(img); */


    if (!sauver_image_pgm(output_filename, img2)) {
        fprintf(stderr, "Erreur lors de la sauvegarde de l'image %s\n", output_filename);
        return 1;
    }

    printf("Image sauvegardée sous %s\n", output_filename);

    detruire_image(&img);
    detruire_image(&img2);
    
    return 0;
}
