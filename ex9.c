#include <stdio.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych10.html
 *
 * Arrays and strings.
 */

int main(int argc, char *argv[])
{
	int numbers[4] = {0};
	char name[4] = {'a'};

	// first, print them raw
	printf("Numbers: %d %d %d %d\n",
		numbers[0], numbers[1],
		numbers[2], numbers[3]);

	printf("Name each: %c %c %c %c\n",
		name[0], name[1], name[2], name[3]);

	printf("Name: %s\n", name);

	// setup numbers
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;
	
	// setup name
	name[0] = 'T';
	name[1] = 'o';
	name[2] = 'm';
	name[3] = '\0';

	// then print them out initialized
	printf("Numbers: %d %d %d %d\n",
		numbers[0], numbers[1],
		numbers[2], numbers[3]);

	printf("Name each: %c %c %c %c\n",
		name[0], name[1], name[2], name[3]);

	printf("Name: %s\n", name);
	
	// This is the way to go for strings
	char *another = "Tom";
	
	printf("another: %s\n", another);

	printf("another each: %c %c %c %c\n",
		another[0], another[1], another[2], another[3]);

	printf("Char as number %d\n", name);

	return 0;
}
