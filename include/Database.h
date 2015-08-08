/* 
 * File:   Database.h
 * Author: kevincando
 *
 * Created on July 25, 2015, 9:13 PM
 */

#ifndef DATABASE_H
#define	DATABASE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic.h"
#include <err.h>
    
//#define MAX_DATA 512
//#define MAX_ROWS 100

enum{ MAX_DATA = 512, MAX_ROWS = 100 };

struct __Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

typedef Generic Address;

typedef struct __Database{
    Address rows[MAX_ROWS];
}Database;

typedef struct __Connection {
    FILE **file;
    Database *db;
}Connection;

void Database_load(Connection *conn);
Connection *Database_open(const char *filename, char mode);
void Database_close(Connection *conn);
void Database_write(Connection *conn);
void Database_create(Connection *conn);
void Database_set(Connection *conn, int id, const char *name, const char *email);
void Database_get(Connection *conn, int id);
void Database_delete(Connection *conn, int id);
void Database_list(Connection *conn);

#ifdef	__cplusplus
}
#endif

#endif	/* DATABASE_H */

