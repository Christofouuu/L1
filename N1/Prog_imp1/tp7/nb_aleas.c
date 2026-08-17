#include <stdio.h>
#include <stdlib.h> /* pour rand et srand */
#include <time.h> /* pour time */
#define MAX 1000

int main()
{
	int i;
	/* On initialise le générateur de nombres aléatoires avec une "graine"
	 * (seed) égale au nombre de secondes depuis le 1er janvier 1970 00:00 */
	srand(time(NULL)); /* à faire une seule fois dans le programme */
	for (i = 0; i < 10; i = i + 1) {
		printf("%d\n", rand() % MAX);
	}
	return 0;
}
