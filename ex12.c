#include <stdio.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych13.html
 *
 * If statements.
 */

int main(int argc, char *argv[]) 
{
	int i;

	if(argc == 1){
		printf("Why dont you feed me arguments? You suck!\n");
	} else if(argc > 1 && argc < 4) {
		printf("Here are your arguments:\n");

		for(i = 1; i < argc; i++){
			printf("%s\n", argv[i]);
		}
	} else {
		printf("You have too many arguments.\n");
	}

	return 0;
}
