#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

/**
 * http://c.learncodethehardway.org/book/learn-c-the-hard-waych18.html
 *
 * Heap & stack memory allocation.
 */

#define MAX_DATA 512
#define MAX_ROWS 100

// Define addess type
struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};


// Define database type
struct Database {
	
	// contains an array of maxum 100 adresses.
	struct Address rows[MAX_ROWS];
};


// Define connection struct
struct Connection {
	// file (descriptor?) to safe data too/read from?
	FILE *file;
	struct Database *db;
};

// Forwar declaration
void Database_close(struct Connection *conn);

// Prints error message and exists the program
void die(const char *message, struct Connection *conn)
{
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	// Free the memory
	if(conn) Database_close(conn);

	exit(1);
}


// Displays a given address
void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}


// Loads the contents of the file into a memory location
// denoted as a struct Database.
void Database_load(struct Connection *conn)
{
	// reads contents of file into memory location of db
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1) die("Failed to load database.", conn);
}


// Constructor for database and connection structs.
// Will load the database if we already have a file.
struct Connection* Database_open(const char *filename, char mode)
{
	// Create memory for connect
	// 8 bytes address pointer to db
	// 8 bytes address pointer to file
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn) die("Memory error", conn);

	// Allocate memory for the db
	conn->db = malloc(sizeof(struct Database));
	if(!conn->db) die("Memory error", conn);

	if(mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");

		if(conn->file) {
			Database_load(conn);
		}
	}

	if(!conn->file) die("Failed to open file.", conn);

	return conn;
}


// Closes file and frees database & conn memory
void Database_close(struct Connection *conn)
{
	if(conn) {
		if(conn->file) fclose(conn->file);
		if(conn->db) free(conn->db);
		free(conn);
	}
}


// Writing to the db means writing to the file
void Database_write(struct Connection *conn)
{
	// go back to the top of the file
	rewind(conn->file);
	
	// Writes the contents of the database stream to the file
	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1) die("Failed to write database.", conn);

	// Writing to file is 2 step proces, 1. write, 2 flush?
	// Flush to make it permanent?
	rc = fflush(conn->file);
	if(rc == -1) die("Cannot flush db.", conn);
}


// Actually creates an empty db. Connection holds the memory location
// were database will start (memory is already allocated).
void Database_create(struct Connection *conn)
{
	int i = 0;

	for(i = 0; i < MAX_ROWS; i++) {
		// Prototype for an empty Address struct
		// id = the record id (0 to 99)
		// set = flag to indicate if record exits (holds actual address)
		struct Address addr = {.id = i, .set = 0};
		// Assign it
		conn->db->rows[i] = addr;
	}
}


// Writes a record to the database (not the file)
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	// Load the record with the given id
	struct Address *addr = &conn->db->rows[id];
	// If flagged as set, throw error.
	if(addr->set) die("Already set, delete it first", conn);

	// Save the date in the db
	addr->set = 1;				// Flag as set
	char *res = strncpy(addr->name, name, MAX_DATA);
	// "Fix" bug in strncpy by enforing the last byte to always te zero
	// see: http://blog.liw.fi/posts/strncpy/
	addr->name[MAX_DATA - 1] = '\0';
	if(!res) die("Name copy failed", conn);

	res = strncpy(addr->email, email, MAX_DATA);
	addr->email[MAX_DATA - 1] = '\0';
	if(!res) die("Email copy failed", conn);
}


// Get a record from the database
void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if(addr->set) {
		Address_print(addr);
	} else {
		die("ID is not set?", conn);
	}
}


// To "delete" a record, mark it that it can be overridden and
// that the value no longer "can" be retrieved.
void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}


// Print all records with values
void Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;
	
	for(i = 0; i < MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];

		if(cur->set) {
			Address_print(cur);
		}
	}
}


int main(int argc, char *argv[])
{
	if(argc < 5) die("ex17 <dbfile> <action> <db_max_rows> <db_max_size> [action parameters]", NULL);

	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;
	
	// atoi converts an ASCII string to integer
	if(argc > 3) id = atoi(argv[3]);
	if(id >= MAX_ROWS) die("Too much records, we dont have that many.", conn);

	switch(action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':
			if(argc != 4) die("Need an id to get", conn);
			Database_get(conn, id);
			break;
		case 's':
			if(argc != 6) die("Need an id, name and email", conn);
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;
		case 'd':
			if(argc != 4) die("Need an id to delete", conn);
			Database_delete(conn, id);
			break;
		case 'l':
			Database_list(conn);
			break;
		default:
			die("Invalid action, only c=create, g=get, s=set, d=del, l=list", conn);
	}

	Database_close(conn);

	return 0;
}
