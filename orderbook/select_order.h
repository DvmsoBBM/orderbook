#ifndef SELECT_ORDER_H
#define SELECT_ORDER_H

#include "db_connect.h"

double getPrice(std::string ticker) {
    std::string query1 = "SELECT price FROM limitorders WHERE price = (SELECT MAX(price) FROM limitorders) AND ticker = '";
    std::string query2 = "' AND side = 'buy'";
    double value{};

    try {
        db_connect::init();

        // Selecting database
        db_connect::con->setSchema("orderbook");

        db_connect::prepStatement = db_connect::con->prepareStatement("SELECT MAX(price) FROM limitorders");
        db_connect::result = db_connect::prepStatement->executeQuery();
        while (db_connect::result->next()) {
            value = db_connect::result->getDouble(1);
        }
    }
    catch (sql::SQLException e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    delete db_connect::result;
    delete db_connect::prepStatement;
    delete db_connect::con;
    return value;
}

#endif