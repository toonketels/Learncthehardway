#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include <assert.h>

/**
 * After defining the functions in header file
 * start implementing them.
 */

int Object_init(void *self)
{
	// we don't do much
	return 1;
}


void Object_destroy(void *self)
{
	// Copy the pointer on the stack
	// instead of saying it's type void?
	// we say it should be interpreted as type Object
	// which means we now how the interpret the next
	// x bytes of memory (as an "object" Struct)
	Object *obj = self;

	if(obj) {
		if(obj->description) free(obj->description);
		free(obj);
	}
}


void Object_describe(void *self)
{
	Object *obj = self;
	printf("%s.\n", obj->description);
}


void *Object_move(void *self, Direction direction)
{
	printf("You can't go that direction.\n");
	return NULL;
}


int Object_attack(void *self, int damage)
{
	printf("You can't attack that.\n");
	return 0;
}


// Will also be executed when we do
// NEW(Object, "description)
// When we call the function we automatically create an
// Object called proto used in the implementation
// Always use the NEW() since it will call the Object we 
// create proto, if we would name it differnlty we would fail.
void *Object_new(size_t size, Object proto, char *description)
{
	// setup the default functions in case they aren't set
	// these are function pointers
	if(!proto.init) proto.init = Object_init;
	if(!proto.describe) proto.describe = Object_describe;
	if(!proto.destroy) proto.destroy = Object_destroy;
	if(!proto.attack) proto.attack = Object_attack;
	if(!proto.move) proto.move = Object_move;

	// Alloc space the size of the Object
	Object *el = calloc(1, size);
	*el = proto;

	// strdup will alloc memory, so we need to free it
	el->description = strdup(description);

	if(!el->init(el)) {
		// looks like it didn't initialize properly
		el->destroy(el);
		return NULL;
	} else {
		// good, we made an object of any type
		return el;
	}
}


