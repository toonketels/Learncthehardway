#include <stdio.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych9.html
 *
 * Sizes and Arrays.
 */

int main(int argc, char *argv[])
{
	int areas[] = {10, 12, 13, 14, 100};
	char name[] = "Toon";
	char last_name[] = {'K', 'e', 't', 'e', 'l', 's', '\0'};

	areas[1] = 'c';

	printf("The size of an int %ld.\n", sizeof(int));
	printf("The size of areas (int[]) %ld.\n", sizeof(areas));
	printf("The number of ints in areas %ld.\n", sizeof(areas) / sizeof(int));
	printf("The first area is %d, the second is %c.\n", areas[0], areas[1]);

	printf("The size of a char %ld.\n", sizeof(char));
	printf("The size of name (name[]) %ld.\n", sizeof(name));
	printf("The number of chars %ld.\n", sizeof(name) / sizeof(char));

	printf("The size of last name %ld.\n", sizeof(last_name));
	printf("The number of chars %ld.\n", sizeof(last_name) / sizeof(char));

	printf("My name is %s %s.\n", name, last_name);

	return 0;
}
