#include <stdio.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych12.html
 *
 * While loops and booleans.
 */

int main(int argc, char *argv[])
{
	int i = argc - 1;
	while(i > 0)
	{
		printf("Argrument %d: %s\n", i, argv[i]);
		i--;
	}

	char *provinces[] = {"Limburg", "Antwerpen", "Brussel"};
	char *prov[3];

	i = 3;
	while(i > 0)
	{
		i--;
		printf("Provincies %s\n", provinces[i]);

	}
	
	i = 0;
	while(i < 3 && i < (argc - 1))
	{
		provinces[i] = argv[i+1];
		
		printf("New provinces: %s\n", provinces[i]);

		i++;
	}

	return 0;
}
