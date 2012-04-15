#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych17.html
 *
 * Structs & pointers.
 */

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};


// Return a pointer to a struct
struct Person *Person_create(char *name, int age, int height, int weight)
{
	// Allocate memory, a struct Person has a fixed size:
	// 8 bytes: addres of name String
	// 4 bytes: int age
	// 4 bytes; int height
	// 4 bytes: int weight
	// => total: 20 bytes
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}


// Free memory, returns nothing
// gets a pointer to a person struct passed
void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	// free the name seperly because is a pointer to a string
	// and that string was (copied strdup) so we are responsible
	// of freeing that one too?
	free(who->name);
	free(who);
}


void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("Age: %d\n", who->age);
	printf("Height: %d\n", who->height);
	printf("Weight: %d\n", who->weight);
}


int main(int argc, char *argv[])
{
	// make some people
	struct Person *toon = Person_create("Toon Ketels", 29, 178, 72);
	struct Person *arzu = Person_create("Arzu Cetinkaya", 24, 159, 49);

	// print them and their memory location out
	printf("toon is at memory location %p: \n", toon);
	Person_print(toon);

	printf("arzu is at memory location %p: \n", arzu);
	Person_print(arzu);

	// as we get older...
	toon->age += 20;
	arzu->age += 20;
	
	Person_print(toon);
	Person_print(arzu);

	// free memory
	Person_destroy(toon);
	Person_destroy(arzu);
	
	printf("---\n");
	printf("Size of in: %li\n", sizeof(int));
	printf("Size of struct: %li\n", sizeof(struct Person));
	printf("Size of pointer of type char: %li\n", sizeof(char *));
	return 0;
}
