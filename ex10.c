#include <stdio.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych11.html
 *
 * Arrays of Strings, Loopings.
 */

int main(int argc, char *argv[])
{
	int i;
	
	// Loops over the arguments,
	// skips arg 0 since it's the
	// program's name.
	for (i = 1; i < argc; i++)
	{
		printf("arg %d: %s\n", i, argv[i]);
	}

	char *provinces[] = {"Limbug", "Antwerpen", "Oost-Vlaanderen", "West-Vlaanderen"};

	int num_provinces = 4;

	for (i = 1; i <= num_provinces; i++)
	{
		printf("Province number %d %s\n", i, provinces[i - 1]);
	}

	return 0;
}
