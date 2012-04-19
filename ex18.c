#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych19.html
 *
 * Pointers to functions - callbacks.
 */

void die(const char *message)
{
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

// typedef to create a fake type, now for a function
// pointer
typedef int (*compare_cb) (int a, int b);

/**
 * Bubble sort function.
 * Compare_cb is passed as callback.
 *
 * Note: whenever we call bubble_sort, we allocte new memory
 * the size of our original array => we need to free it;
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int *target = malloc(sizeof(int) * count);

	if(!target) die("Memory error.");

	memcpy(target, numbers, count * sizeof(int));

	for(i = 0; i < count; i++) {
		for(j = 0; j < count - 1; j++) {
			if(cmp(target[j], target[j+1]) > 0){
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}

	return target;
}

/**
 * Different sort functions to test.
 */
int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b)
{
	return b - a;
}

int strange_order(int a, int b)
{
	if(a == 0 || b == 0) {
		return 0;
	} else {
		return a % b;
	}
}

/**
 * Print the sorts so we can see for ourselves.
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	// bubble_sort will return a sorted copy of our array
	// so we should free the allocated memory
	int *sorted = bubble_sort(numbers, count, cmp);

	if(!sorted) die("Failed to sort as requested.");

	for(i = 0; i < count; i++) {
		printf("%d ", sorted[i]);
	}
	printf("\n");

	// Fially, free it
	free(sorted);

	unsigned char *data = (unsigned char *)cmp;
	for(i = 0; i < 50; i++) {
		printf("%0x:", data[i]);
	}

	printf("\n");
}

int main(int argc, char *argv[])
{
	// We need at least two numbers to sort
	if(argc < 2) die("USAGE: ex18 5 3 1 6 5");

	int count = argc - 1;
	int i = 0;
	// since argv is a pointer, we need to ** to get
	// the actuall address of the first value.
	// we do argv + 1 since first arg is program name,
	// other arg are the integers.
	char **inputs = argv + 1;

	// Save our arguments on the heap
	int *numbers = malloc(count * sizeof(int));
	if(!numbers) die("Memory error");

	// We need ints not chars representing numbers
	for(i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
	}

	// Actually perform some sorts via test_sorting
	// so we can see what's going on.
	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	// We saved the arguments on the heap...
	free(numbers);

	return 0;
}
