
#include <stdio.h>

// Fonction pour calculer x^n
float power(float x, unsigned int n) {
    float res = 1.0;
    for (unsigned int i = 0; i < n; i++)
        res *= x;
    return res;
}

// Fonction pour évaluer un polynôme donné par ses coefficients
float evalpoly(float coefficients[], int degree, float x) {
    float res = 0.0;
    for (int i = 0; i <= degree; i++)
        res += coefficients[i] * power(x, i);
    return res;
}

int main() {
    float coefficients[] = {1.5, 2.5, 2.5, 4.0};  // Coefficients du polynôme
    float x_values[] = {0, 1, 1.5, 2};           // Valeurs de x à tester
    int degree = 3;

    for (int i = 0; i < 4; i++)
        printf("P(%.1f) = %.3f\n", x_values[i], evalpoly(coefficients, degree, x_values[i]));

    return 0;
}
