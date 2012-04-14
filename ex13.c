#include <stdio.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych14.html
 *
 * Switch statements ~ Jump tables,
 * only expressions that evaluate to integers.
 */


/**
 * Custom tolower function.
 */
char _tolower(char character) {
	return (character >= 'A' && character <= 'Z') ? character - ('A' - 'a') : character;
}


int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("ERROR: provide one argument!\n");
		// Abort program
		return 1;
	}

	int i = 0;
	for(i; argv[1][i] != '\0'; i++) {
		char letter = _tolower(argv[1][i]);

		switch(letter) {
			case 'a':
			//case 'A':
				printf("%d: 'A'\n", i);
				break;
			case 'e':
			//case 'E':
				printf("%d: 'E'\n", i);
				break;
			case 'i':
			//case 'I':
				printf("%d: 'I'\n", i);
				break;
			case 'o':
			//case 'O':
				printf("%d: 'O'\n", i);
				break;
			case 'u':
			//case 'U':
				printf("%d: 'U'\n", i);
				break;
			case 'y':
			//case 'Y':
				if(i > 2) {
					printf("%d: 'V'\n", i);
			 		break;
				}
			default:
				printf("%d: %c is not a vowel\n", i, letter);

		}
	}

	return 0;
}

