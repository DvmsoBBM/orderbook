#ifndef DB_CONNECT_H
#define DB_CONNECT_H

#include <iostream>
#include <cstdlib>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "get_config.h"
#include "orderbook.h"

namespace db_connect {

    // Initializing variables
    sql::Driver* driver;
    sql::Connection* con;
    sql::PreparedStatement* prepStatement;
    sql::ResultSet* result;

    // Connecting to server
    int init() {
        try {
            driver = get_driver_instance();
            con = driver->connect(
               db_config::getConfig(1),
               db_config::getConfig(4),
               db_config::getConfig(5)
            );
        }
        catch (sql::SQLException e) {
            std::cerr << "Could not connect to server. Error message: " << e.what() << std::endl;
            system("pause");
            exit(1);
        }
        return 0;
    }
};

#endif