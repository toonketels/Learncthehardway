#ifndef _ex19_h
#define _ex19_h

#include "object.h"

// Define a new struct named Monster
struct Monster {
	// out new struct consists of the
	// object struct, so not points to one,
	// but is one, "extends" it - with
	// an int
	Object proto;
	int hit_points;
};

// Now, every time we say Monster we say
// a struct of type Monster
typedef struct Monster Monster;

// We wont to override the default implementations
int Monster_attack(void *self, int damage);
int Monster_init(void *self);

struct Room {
	// Our struct contains of on 'object'
	// we call proto
	// It needs to be at the top, because in Object_new
	// we get a pointer to 'an object' which means object # bytes
	// of the Room struct we know how to interpret as an object.
	Object proto;

	// Our struct points to a 'monster'
	// == struct of different type which
	// also contains tha object struct
	Monster *bad_guy;

	// A room points to 4 other rooms
	struct Room *north;
	struct Room *south;
	struct Room *east;
	struct Room *west;
};

typedef struct Room Room;

// Override default funtions.
void *Room_move(void *self, Direction direction);
int Room_attack(void *self, int damage);
int Room_init(void *self);

struct Map {
	Object proto;
	Room *start;
	Room *location;
};

typedef struct Map Map;

void *Map_move(void *self, Direction direction);
int Map_attack(void *self, int damage);
int Map_init(void *self);

#endif
