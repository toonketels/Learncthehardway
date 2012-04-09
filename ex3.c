#include <stdio.h>

/** 
 * Format specifiers
 *   %d, %i int
 *   %c char
 *   %s string
 *   %f float
 *   %lf double (long float)
 *
 * Escape sequences
 *   http://www.acm.uiuc.edu/webmonkeys/book/c_guide/1.1.html
 */

int main()
{
	int age = 10;
	int height = 122;

	printf("I am %d year old and %d centimeters height!\n", age, height);

	return 0;
}
