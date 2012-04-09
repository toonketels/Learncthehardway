#include <stdio.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych7.html
 *
 * Different variable types.
 */

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 8765.9876;
	char initial = 'A';
	char first_name[] = "Toon";
	char last_name[] = "Ketels";

	printf("You are %i kilometers away.\n", distance);
	printf("You have %f powers,\nwhile I have %lf!\n", power, super_power);
	printf("My name is %s %s, and %c is not my initial.\n", first_name, last_name, initial);


	return 0;
}
