#include <stdio.h>

#define TAILLE_MAX 256

int main(){
    int i;
    char fichier[TAILLE_MAX];
    
    printf("Entrer un nom de fichier : ");
    scanf("%s", fichier);
    
    printf("Nom de base : ");
    for(i = 0; (fichier[i] >= 'a' && fichier[i] <= 'z') || (fichier[i] >= 'A' && fichier[i] <= 'Z'); i++){
        printf("%c", fichier[i]);
    }
    
    printf("\nExtension : ");
    for(; fichier[i] != '\0'; i++){
        printf("%c", fichier[i]);
    }
    printf("\n");
    return 0;
}