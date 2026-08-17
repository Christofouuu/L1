#include <stdio.h>

void echanger (int *A, int *B) {
     int tmp = *A;
     *A = *B;
     *B = tmp;
}

void tri_a_bulle (int *T, int N) {
     int i, j;
     for (i=0; i<N; i++) {
          for (j=0; j<N-i; j++) { 
               if (T[j] > T[j+1]) {
                    echanger (T+j, T+j+1);
               }
          }
     }
}

int main() {
     int tableau[10];
     int i;

     /* Saisir le tableau */
     for (i=0; i<10; i++) {
          printf("Donnez la case %d : ", i);
          scanf("%d", &tableau[i]); 
     }

     /* Trier le tableau */
     printf("Tri du tableau\n");
     tri_a_bulle(tableau, 10);

     /* Afficher le tableau */
     printf("Le tableau trié : ");
     for (i=0; i<10; i++) {
          printf("%d ", tableau[i]);
     }
     printf("\n");

     return 0;
}
