#ifndef _object_h
#define _object_h

typedef enum {
	NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct {
	char *description;
	int (*init)(void *self);
	void (*describe)(void *self);
	void (*destroy)(void *self);
	void *(*move)(void *self, Direction direction);
	int (*attack)(void *self, int damage);
} Object;

// The functions which are pointed to from
// our "object"

int Object_init(void *self);
void Object_destroy(void *self);
void Object_destribe(void *self);
void *Object_move(void *self, Direction direction);
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);

// Marcos, code generation

// NEW(Room, "A place to live in") => Object_new(sizof(Room), RoomProto, "A place to live in");
#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
// _(Room) => proto.Room
#define _(N) proto.N

#endif
