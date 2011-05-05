#ifndef USER_H
#define USER_H

#include "type.h"
#include "lib/hash.h"
#include "protocol.h"


typedef struct 
{
    struct hash_elem elem;  // Hash elem for global user index.

    char id[USER_STR_SZ + 1];

    // Map session->event_queue
} user_t;

#include "session.h"


uint32 user_hash (struct hash_elem* e);
int user_compare (struct hash_elem* a, struct hash_elem* b, void*);

bool init_user_index ();


/**
 * Lookup and return a user in the database with the given id.  Returns NULL if
 * no such user exists. 
 * */
user_t* lookup_user (const char* id);

/**
 * Initialize a new user structure and add it to the database.  
 * Return FALSE if unsuccessful.
 * */
bool user_init (user_t*, const char* id);

/**
 * Register a session with the given user.  Return False if unsuccessful.
 * */
bool user_register (user_t*, session_t*);

#endif //USER_H

