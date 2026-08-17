#include <stdio.h>

// Fonction pour calculer x^n
float power(float x, unsigned int n) {
    float res = 1.0;
    for (unsigned int i = 0; i < n; i++)
        res *= x;
    return res;
}

// Fonction pour calculer n!
float factorial(unsigned int n) {
    float res = 1.0;
    for (unsigned int i = 1; i <= n; i++)
        res *= i;
    return res;
}

// Calcul de l'exponentielle avec une précision donnée
float exponentiel(float x) {
    const float epsilon = 1e-7;
    float res = 1.0, term;
    int i = 1;

    do {
        term = power(x, i) / factorial(i);
        res += term;
        i++;
    } while ((term / res) > epsilon);

    return res;
}

int main() {
    for (float x = 0; x < 2; x += 0.2)
        printf("%5.3f %5.3f\n", x, exponentiel(x));

    return 0;
}
