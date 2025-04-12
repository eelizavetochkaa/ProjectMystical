#include "MyForm.h"
#include "../sqlite/sqlite3.h"

namespace ProjectMystical {
    MyForm::MyForm(void) {
        InitializeComponent();
        InitializeDatabase();
    }

    void MyForm::InitializeComponent() {
    }

    void MyForm::InitializeDatabase() {
        sqlite3* db;
        String^ dbPath = "test.db";

        if (sqlite3_open("test.db", &db) == SQLITE_OK) {
            const char* sql = "CREATE TABLE IF NOT EXISTS users(id INTEGER, name TEXT);";
            sqlite3_exec(db, sql, NULL, NULL, NULL);
            sqlite3_close(db);
        }
    }
}