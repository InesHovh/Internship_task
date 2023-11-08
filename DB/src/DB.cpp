#include "../headers/DB.hpp"

void DB::Create() {
    try
    {
       const char *db_info = "host=localhost port=5432 dbname=mydb user=ines password=pass";
        PGconn *conn = PQconnectdb(db_info);

        if(PQstatus(conn) == CONNECTION_BAD) {
            // std::cout << "*****************" << std::endl;
            PQfinish(conn);
            std::cerr << "Connection error: " << PQerrorMessage(conn) << std::endl;
            throw std::runtime_error("");
            // exit(1);
        }


        const char *db_table = "CREATE TABLE IF NOT EXISTS mytable ("
            "id serial PRIMARY KEY, "
            "name VARCHAR(255) NOT NULL, "
            "nickname VARCHAR(255) NOT NULL"
            ")" ;
        
        PGresult *res = PQexec(conn, db_table);

        if (PQresultStatus(res) != PGRES_COMMAND_OK){
            PQclear(res);
            PQfinish(conn);
            std::cerr << "Query execution error: " << PQresultErrorMessage(res) << std::endl;
            throw std::runtime_error("Failed to create the table");
            // exit(1);
        }
        PQclear(res);


        std::cout << "Created successfully" << std::endl;

        PQfinish(conn);
    } catch(const std::exception& e) {
        std::cerr << "Database Creation error: " << e.what() << std::endl;
        // exit(1);
    } 
}

void DB::Read() {
    try
    {
        const char *db_info = "host=localhost port=5432 dbname=mydb user=ines password=pass";
        PGconn *conn = PQconnectdb(db_info);

        if(PQstatus(conn) == CONNECTION_BAD) {
            // std::cerr << "Failed connection to database" << std::endl;
            PQfinish(conn);
            throw std::runtime_error("");
            // exit(1);
        }

        const char *select_db = "SELECT * FROM mytable;";

        PGresult *res = PQexec(conn, select_db);

        // if (PQresultStatus(res) != PGRES_COMMAND_OK){
        //     // std::cerr << "Failed to read the table" << std::endl;
        //     PQclear(res);
        //     PQfinish(conn);
        //     std::cerr << "Query execution error: " << PQresultErrorMessage(res) << std::endl;
        //     throw std::runtime_error("Failed to read the table");
        //     // exit(1);
        // }

        int rows = PQntuples(res);
        int cols = PQnfields(res);

        std::cout << "\n" << "------Created table------" << std::endl;
        std::cout << "id |   name   |   nickname  " << std::endl;
        std::cout << "--------------------------" << std::endl;
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col){

                std::cout << PQgetvalue(res, row, col) << " | ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Read successfully" << std::endl;

        PQclear(res);

        PQfinish(conn);
    } catch(const std::exception& e) {
        std::cerr << "Database Reading error: " << e.what() << std::endl;
    }
}

void DB::Update() {
    try
    {
        const char *db_info = "host=localhost port=5432 dbname=mydb user=ines password=pass";
        PGconn *conn = PQconnectdb(db_info);

        if(PQstatus(conn) == CONNECTION_BAD) {
            // std::cerr << "Failed connection to database" << std::endl;
            PQfinish(conn);
            throw std::runtime_error("");
            // exit(1);
        }

        const char *update_db = "UPDATE mytable SET name = 'NewName' WHERE id = 1;";

        PGresult *res = PQexec(conn, update_db);

        if (PQresultStatus(res) != PGRES_COMMAND_OK){
            // std::cerr << "Failed to update the table" << std::endl;
            PQclear(res);
            PQfinish(conn);
            throw std::runtime_error("Failed to update the table");
            // exit(1);
        }

        PQclear(res);

        std::cout << "Updated successfully" << std::endl;

        PQfinish(conn);
    } catch(const std::exception& e) {
        std::cerr << "Database Updating error: " << e.what() << std::endl;
    }
}

void DB::Delete() {
    try
    {
        const char *db_info = "host=localhost port=5432 dbname=mydb user=ines password=pass";
        PGconn *conn = PQconnectdb(db_info);

        if(PQstatus(conn) == CONNECTION_BAD) {
            // std::cerr << "Failed connection to database" << std::endl;
            PQfinish(conn);
            throw std::runtime_error("");
            // exit(1);
        }

        const char *delete_db = "DROP TABLE mytable;";
        PGresult *res = PQexec(conn, delete_db);

        if (PQresultStatus(res) != PGRES_COMMAND_OK){
            // std::cerr << "Failed to delete the table" << std::endl;
            PQclear(res);
            PQfinish(conn);
            throw std::runtime_error("Failed to delete the table");
            // exit(1);
        }

        PQclear(res);

        std::cout << "Deleted successfully" << std::endl;

        PQfinish(conn);
    } catch(const std::exception& e) {
        std::cerr << "Database Deleting error: " << e.what() << std::endl;
    }
}

int main(){

    DB *db;
    db->Create();
    db->Read();
    db->Update();
    // db->Delete();

    return 0;
}