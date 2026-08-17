#include <stdio.h>
double factorielle(int p);

int main()
{
	double res;
	int p;
	p = 5;
	res = factorielle(p);
	printf("%d!= %g\n", p, res);
	return 0;
}

double factorielle(int p) {
	double res = 1.;
	while (p > 0) {
		res = res * p;
		p = p - 1;;
	}
	return res;
}
