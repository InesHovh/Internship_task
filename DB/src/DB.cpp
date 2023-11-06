#include "../headers/DB.hpp"

DB::DB() {}

void DB::Create() {
    const char *db_info = "host=localhost port=5432 dbname=MyDB user=myuser password=password";
    PGconn *conn = PQconnectdb(db_info);

    if(PQstatus(conn) == CONNECTION_BAD) {
        std::cerr << "Failed connection to database" << std::endl;
        PQfinish(conn);
        exit(1);
    }

    const char *db_table = "CREATE TABLE mytable ("
        "id serial PRIMARY KEY, "
        "name VARCHAR(255) NOT NULL, "
        "nickname VARCHAR(255) NOT NULL"
        ")" ;
    
    PGresult *res = PQexec(conn, db_table);

    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        std::cerr << "Failed to create the table" << std::endl;
        PQclear(res);
        PQfinish(conn);
        exit(1);
    }
    PQclear(res);

    std::cout << "Created successfully" << std::endl;

    PQfinish(conn);
}

void DB::Read() {
    const char *db_info = "host=localhost port8080 dbname=MyDB user=myuser password=password";
    PGconn *conn = PQconnectdb(db_info);

    if(PQstatus(conn) == CONNECTION_BAD) {
        std::cerr << "Failed connection to database" << std::endl;
        PQfinish(conn);
        exit(1);
    }

    const char *select_db = "SELECT * FROM mytable;";

    PGresult *res = PQexec(conn, select_db);

    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        std::cerr << "Failed to read the table" << std::endl;
        PQclear(res);
        PQfinish(conn);
        exit(1);
    }

    int rows = PQntuples(res);
    int cols = PQnfields(res);

    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col){
            std::cout << PQgetvalue(res, row, col) << "|" << std::endl;
        }
        std::cout << std::endl;
    }

    PQclear(res);

    std::cout << "Read successfully" << std::endl;


    PQfinish(conn);
}

void DB::Update() {
    const char *db_info = "host=localhost port8080 dbname=MyDB user=myuser password=password";
    PGconn *conn = PQconnectdb(db_info);

    if(PQstatus(conn) == CONNECTION_BAD) {
        std::cerr << "Failed connection to database" << std::endl;
        PQfinish(conn);
        exit(1);
    }

    const char *update_db = "UPDATE mytable SET name = 'NewName' WHERE id = 1;";

    PGresult *res = PQexec(conn, update_db);

    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        std::cerr << "Failed to update the table" << std::endl;
        PQclear(res);
        PQfinish(conn);
        exit(1);
    }

    PQclear(res);

    std::cout << "Updated successfully" << std::endl;

    PQfinish(conn);
}

void DB::Delete() {
    const char *db_info = "host=localhost port8080 dbname=MyDB user=myuser password=password";
    PGconn *conn = PQconnectdb(db_info);

    if(PQstatus(conn) == CONNECTION_BAD) {
        std::cerr << "Failed connection to database" << std::endl;
        PQfinish(conn);
        exit(1);
    }

    const char *delete_db = "DROP TABLE mytable;";
    PGresult *res = PQexec(conn, delete_db);

    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        std::cerr << "Failed to delete the table" << std::endl;
        PQclear(res);
        PQfinish(conn);
        exit(1);
    }

    PQclear(res);

    std::cout << "Deleted successfully" << std::endl;

    PQfinish(conn);
}

int main(){

    DB *db;
    db->Create();

    return 0;
}