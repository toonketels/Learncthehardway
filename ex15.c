#include <stdio.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych16.html
 *
 * Pointers.
 */

int main(int argc, char *argv[])
{
	int ages[] = {12, 87, 65,38, 52, 27};
	char *names[] = {"Toon", "Dries", "Els", "Lien", "Stefaan", "Lieve"};

	// Get size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// First way - using indexing.
	for(i = 0; i < count; i++) {
		printf("%s is %d yrears old\n", names[i], ages[i]);
	}

	printf("---\n");

	// Setup pointers to the start of the arrays.
	int *cur_age = ages;
	char **cur_name = names;

	// Second way - using pointers
	for(i = 0; i < count; i++) {
		printf("%s is %d years old\n", *(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	// Third way, pointers are just arrays
	for(i = 0; i < count; i++) {
		printf("%s is %d years old\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	// Fouth way, pointers in a complex way
	for(cur_name = names, cur_age = ages; (cur_name - names) < count; cur_name++, cur_age++) {
		printf("%s is %d years old\n", *cur_name, *cur_age);
	}

	return 0;
}
