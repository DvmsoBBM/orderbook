#ifndef INSERT_ORDER_H
#define INSERT_ORDER_H

#include <iostream>
#include "db_connect.h"

int insertOrder(Order::Order tOrder) {
    try {
        db_connect::init();

        // Selecting database
        db_connect::con->setSchema("orderbook");

        // Sending an INSERT request through a prepared statement
        db_connect::prepStatement = db_connect::con->prepareStatement("INSERT INTO limitorders(id, state, oTimestamp, cTimestamp, side, ticker, price, size, userID) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?)");
        try {
            db_connect::prepStatement->setInt(1, NULL);
            db_connect::prepStatement->setString(2, tOrder.state);
            db_connect::prepStatement->setInt64(3, tOrder.oTimestamp);
            db_connect::prepStatement->setInt64(4, tOrder.cTimestamp);
            db_connect::prepStatement->setString(5, tOrder.side);
            db_connect::prepStatement->setString(6, tOrder.ticker);
            db_connect::prepStatement->setDouble(7, tOrder.price);
            db_connect::prepStatement->setDouble(8, tOrder.size);
            db_connect::prepStatement->setInt(9, tOrder.userID);

            db_connect::prepStatement->execute();

            std::cout << "Order insterted." << std::endl;
        }
        catch (sql::SQLException e) {
            std::cerr << "Couldn't insert the order." << "Error message: " << e.what() << std::endl;
        }
        delete db_connect::prepStatement;
        delete db_connect::con;
        return 0;
    }
    catch (sql::SQLException e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

#endif