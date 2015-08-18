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
#include <stdbool.h>
#include <string.h>
#include "generic.h"
#include "DataTypes.h"
    
//#define MAX_DATA 512
//#define MAX_ROWS 100

enum{ MAX_DATA = 512, MAX_ROWS = 100 };

typedef Generic Address;

typedef struct __Database{
    Address *rows;
    unsigned int max_rows;
    bool full;
}Database;

typedef struct __Connection {
    FILE *file;
    Database *db;
    int (*Database_load)(struct __Connection *self);
    int (*Database_write) (struct __Connection *self);
    bool binary;
}Connection;

static const char *db_file_name = "tmp.db";

static Connection *db_conn = NULL;

void Database_load(Connection *conn);
Connection *Database_open(Connection con ,const char *filename, char mode,unsigned int max_rows,int *error_code);
void Database_close(Connection *conn);
void Database_write(Connection *conn);
int Database_create(unsigned int max_rows);
void Database_set(Connection *conn, int id, const char *name, const char *email);
void Database_get(Connection *conn, int id);
void Database_delete(Connection *conn, int id);
void Database_list(Connection *conn);

#ifdef	__cplusplus
}
#endif

#endif	/* DATABASE_H */

