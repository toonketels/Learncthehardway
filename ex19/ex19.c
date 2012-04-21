#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych20.html
 *
 * Simple object system.
 */

int Monster_attack(void *self, int damage)
{
	// Store a pointer to our object on the stack
	Monster *monster = self;

	// monster->_(description) macros into
	// monster->proto.description
	printf("You attack %s!\n", monster->_(description));

	monster->hit_points -= damage;

	if(monster->hit_points > 0) {
		printf("It is still alive.\n");
		return 0;
	} else {
		printf("It is dead!\n");
		return 1;
	}
}


// Default init doesn't do nuthing but return an int.
// Monster need healths points...
int Monster_init(void *self)
{
	Monster *monster = self;
	monster->hit_points = 10;
	return 1;
}


// Here we swap the default implementations with
// our custom ones.
Object MonsterProto = {
	.init = Monster_init,
	.attack = Monster_attack
};


void *Room_move(void *self, Direction direction)
{
	Room *room = self;
	Room *next = NULL;
	
	// A room points to other rooms
	// so we asign a room to next
	if(direction == NORTH && room->north) {
		printf("You go north, into:\n");
		next = room->north;
	} else if(direction == SOUTH && room->south) {
		printf("You go south, into:\n");
		next = room->south;
	} else if(direction == EAST && room->east) {
		printf("You go east, into:\n");
		next = room->east;
	} else if(direction == WEST && room->west) {
		printf("You go west, into:\n");
		next = room->west;
	} else {
		printf("You can't go that direction.");
		next = NULL;
	}
		
	if(next) {
		next->_(describe)(next);
	}

	return next;
}


int Room_attack(void *self, int damage)
{
	Room *room = self;
	Monster *monster = room->bad_guy;

	if(monster) {
		// monster->proto.attack which is a 
		// function pointer to Monster_attack
		// (or Object_attack if not overriden)
		// which we call with monster and damage
		// as args.
		monster->_(attack) (monster, damage);
		return 1;
	} else {
		printf("You flail in the air at nothin. Idiot.\n");
		return 0;
	}
}


Object RoomProto = {
	.move = Room_move,
	.attack = Room_attack
};


// int Room_init(void *self);

void *Map_move(void *self, Direction direction)
{
	Map *map = self;
	Room *location = map->location;
	Room *next = NULL;

	// We ask a room for it's room in x direction
	// and set that room as the location of the map.
	next = location->_(move)(location, direction);

	if(next) {
		map->location = next;
	}

	// To be on par we return somthing, but we
	// don't really need it.
	return next;
}


int Map_attack(void *self, int damage)
{
	Map *map = self;
	Room *location = map->location;

	return location->_(attack)(location, damage);
}


int Map_init(void *self)
{
	Map *map = self;

	// make some rooms
	Room *hall = NEW(Room, "The great Hall");
	Room *throne = NEW(Room, "The great Throne");
	Room *arena = NEW(Room, "The Arena, with the minotaur");
	Room *kitchen = NEW(Room, "Kitche, you have the knife now");

	// Put bad guy in arena
	arena->bad_guy = NEW(Monster, "The evil minotaur");

	// setup map rooms
	hall->north = throne;

	throne->west = arena;
	throne->east = kitchen;
	throne->south = hall;

	arena->east = throne;
	kitchen->west = throne;

	// start the map and character off in the hall
	map->start = hall;
	map->location = hall;

	return 1;
}


Object MapProto = {
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack
};


int process_input(Map *game)
{
	printf("\n> ");

	char ch = getchar();
	getchar();	// eat enter

	int damage = rand() % 4;

	switch(ch) {
		case 'x':
			printf("Given up? You suck.\n");
			exit(0);
			return 0;
			break;	
		case 'n':
			game->_(move) (game, NORTH);
			break;
		case 's':
			game->_(move) (game, SOUTH);
			break;
		case 'e':
			game->_(move) (game, EAST);
			break;
		case 'w':
			game->_(move) (game, WEST);
			break;
		case 'a':
			game->_(attack)(game, damage);
			break;
			
		case 'l':
			printf("You can go:\n");
			if(game->location->north) printf("NORTH\n");
			if(game->location->south) printf("SOUTH\n");
			if(game->location->east) printf("EAST\n");
			if(game->location->west) printf("WEST\n");
			break;
		default:
			printf("What?: %d\n", ch);
	}
	return 1;
}


int main(int argc, char *argv[])
{
	// simple way to setup randomness
	srand(time(NULL));

	// make our map to work with
	Map *game = NEW(Map, "The Hall of the Minotaur.");

	printf("You enter the ");
	game->location->_(describe)(game->location);

	while(process_input(game)) {
	}
	return 0;
}
