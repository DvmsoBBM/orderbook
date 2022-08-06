#include <iostream>
#include "get_time.h"
#include "orderbook.h"
#include "db_connect.h"
#include "insert_order.h"

int main() {
    // Initializing Headers
    execTime::initExecTime();

    // Testing
    Order::Order makerOrder(1, "limit", "buy", "btcusdt", 21601.50, 1.8415, 0);
    insertOrder(makerOrder);

    Order::Order takerOrder(1, "market", "sell", "btcusdt", 21600.50, 1.52564, 0);
    insertOrder(takerOrder);

    // Getting execution time
    try {
        std::cerr << "Executed in " << execTime::getExecTime() << " nanoseconds." << std::endl;
    }
    catch (char const* e) {
        // Couldn't get execution time
        std::cerr << "Error: " << e << std::endl;
    }
    return 0;
}