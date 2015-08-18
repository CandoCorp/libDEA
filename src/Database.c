#include "Database.h"
#include "ErrorHandler.h"

void Address_print(struct Address *addr)
{
}

void Database_load(Connection *conn){
    int rc = fread(conn->db, sizeof(Database), 1, conn->file);
    if(rc != 1) die("Failed to load database.");
    
}

Connection *Database_open(Connection con ,const char *filename, char mode,unsigned int max_rows,int *error_code){
    if(!con.Database_load) goto error_methods;
    if(!con.Database_write) goto error_methods;
    
    Connection *conn = CALLOC(1,Connection);
    check_mem(conn);
    
    *conn = con;
    
    conn->db = CALLOC(1,Database);

    check_mem(conn->db);

    conn->db->max_rows = max_rows;
    conn->db->rows = CALLOC(max_rows,Address);

    check_mem(conn->db->rows);
    
    if(conn->binary == true){
        if(mode == 'c') {
            conn->file = fopen(filename, "wb");
            if(!conn->file) goto error_file;
            debug("The file has been created");
        } else {
            conn->file = fopen(filename, "ab+");
            if(!conn->file) goto error_file;
            debug("The file has been opened");
            Database_load(conn);
        }
    }else{
        if(mode == 'c') {
            conn->file = fopen(filename, "w");
            if(!conn->file) goto error_file;
            debug("The file has been created");
        } else {
            conn->file = fopen(filename, "a+");
            if(!conn->file) goto error_file;
            debug("The file has been opened");
            Database_load(conn);
        }
    }
    if(!conn->file) goto error_file;
    
    return conn;
    
    error:{
        if(error_code != NULL)
            *error_code = -1;
        
        return NULL;
    }
    error_file:{
        if(error_code != NULL)
            *error_code = -2;
        return NULL;
    }
    error_methods:{
        if(error_code != NULL)
            *error_code = -3;
        return NULL;
    }
}

void Database_close(Connection *conn){
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(conn->db) free(conn->db);
        free(conn);
        conn = NULL;
        
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

int Database_create(unsigned int max_rows){
    if(max_rows <= 0){
        debug("You can't assign max rows of negative value");
        return -1;
    }
        
    if(!db_conn)
//        db_conn = Database_open(db_conn,db_file_name,'c',max_rows,NULL);
    
    ;
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


