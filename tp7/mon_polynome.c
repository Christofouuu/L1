#include <stdio.h>
double puissance(double x, int p);
double factorielle(int p);
double mon_polynome(double x);

int main()
{
	double x, res;
	for (x = 3.; x < 3.20 ; x = x + 0.01) {
		res = mon_polynome(x);
		printf("P(%g) = %g\n", x, res);
	}
	
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

double factorielle(int p) {
	double res = 1.;
	while (p > 0) {
		res = res * p;
		p = p - 1;;
	}
	return res;
}

double mon_polynome(double x) {
	return x
		= x - (puissance (x, 3) / factorielle(3))
		+ puissance(x, 5) / factorielle(5)
		- puissance(x, 7) / factorielle(7)
		+ puissance(x, 9) / factorielle(9);
}
