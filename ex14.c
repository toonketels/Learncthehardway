#include <stdio.h>
#include <ctype.h>		// isblank(), isaplha()
#include <string.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych15.html
 *
 * Functions.
 */

// Forward declarations so we can already
// use the functions, without atually defining them.
int can_print_it(char ch);
void print_letters(char arg[], int len);


void print_arguments(int argc, char *argv[])
{
	int i = 0;

	for(i = 0; i < argc; i++) {
		print_letters(argv[i], strlen(argv[i]));
	}
}


void print_letters(char arg[], int len)
{
	int i = 0;

	for(i =0; i < len; i++) {
		char ch = arg[i];

		if(can_print_it(ch)){
			printf("'%c' == %d\n", ch, ch);
		}
	}
}


int can_print_it(char ch) {
	return isalpha(ch) || isblank(ch);
}



int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}
