#include "Database.h"
#include "ErrorHandler.h"

void Address_print(struct Address *addr)
{
}

void Database_load(Connection *conn)
{
    int rc = fread(conn->db, sizeof(Database), 1, conn->file);
    if(rc != 1) die("Failed to load database.");
    
}

Connection *Database_open(const char *filename, char mode, int max_rows){
    Connection *conn = MALLOC(Connection);
    
    check_mem(conn);
    
    if(conn){
        conn->db = CALLOC(1,Database);
        
        check_mem(conn->db);
        
        conn->db->rows = max_rows;
        conn->db->rows = CALLOC(max_rows,Address);

        if(mode == 'c') {
            conn->file = fopen(filename, "w");
        } else {
            conn->file = fopen(filename, "a+");
            if(conn->file)
                Database_load(conn);
        }
    }else
        die("Failed to open the file");
    
    if(!conn->file) die("Failed to open the file");
    
    return conn;
    
    error:
        die("Memory error\n");
}

void Database_close(Connection *conn){
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(conn->db) free(conn->db);
        free(conn);
    }
}

void Database_write(Connection *conn)
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(Database), 1, conn->file);
    if(rc != 1) die("Failed to write database.");

    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.");
}

void Database_create(int max_rows){
    if(!db_conn)
        db_conn = Database_open(db_file_name,'c',max_rows);
    
}

void Database_set(Connection *conn, int id, const char *name, const char *email)
{
    Address *addr = &conn->db->rows[id];
    //if(addr->set) die("Already set, delete it first");

    //addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    //char *res = strncpy(addr->name, name, MAX_DATA);
    // demonstrate the strncpy bug
    //if(!res) die("Name copy failed");

    //res = strncpy(addr->email, email, MAX_DATA);
    //if(!res) die("Email copy failed");
}

void Database_get(Connection *conn, int id)
{
    Address *addr = &conn->db->rows[id];

    //if(addr->set) {
        Address_print(addr);
    //} else {
        die("ID is not set");
    //}
}

void Database_delete(Connection *conn, int id)
{
    Address addr;
    conn->db->rows[id] = addr;
}

void Database_list(Connection *conn)
{
    int i = 0;
    Database *db = conn->db;

    for(i = 0; i < MAX_ROWS; i++) {
        Address *cur = &db->rows[i];

        //if(cur->set) {
            Address_print(cur);
        //}
    }
}


