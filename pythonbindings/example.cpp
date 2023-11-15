#include <sqlite3.h>
#include <iostream>

int main() {
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    // Execute SQL commands to create tables and perform other operations
    const char* sql = "CREATE TABLE IF NOT EXISTS Users (ID INT, Name TEXT);";
    rc = sqlite3_exec(db, sql, 0, 0, 0);
    
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    }
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO Users (ID, Name) VALUES (?, ?);";
    sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sqlite3_bind_int(stmt, 1, 1);
    sqlite3_bind_text(stmt, 2, "John Doe", -1, SQLITE_STATIC);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    const char* select_sql = "SELECT * FROM Users;";
    sqlite3_stmt* select_stmt;
    sqlite3_prepare_v2(db, select_sql, -1, &select_stmt, 0);
    
    while (sqlite3_step(select_stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(select_stmt, 0);
        const char* name = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt, 1));
        std::cout << "ID: " << id << ", Name: " << name << std::endl;
    }
    
    sqlite3_finalize(select_stmt);


    sqlite3_close(db);
    return 0;
}
