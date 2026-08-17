#include <stdio.h>
/* retourne x à la puissance p */
double puissance(double x, int p);

int main()
{
	double x, res;
	int p;
	x = 2.;
	p = 2;
	res = puissance(x, p);
	printf("%g^%d = %g\n", x, p, res);
	return 0;
}

double puissance(double x, int p)
{
	double res = 1.;
	while (p != 0) {
		if ( p > 0 ) {
			res = res * x;
			p = p - 1;
		} else {
			res = res / x;
			p = p + 1;;
		}
	}
	return res;
}
