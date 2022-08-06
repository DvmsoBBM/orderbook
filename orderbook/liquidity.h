#ifndef LIQUIDITY_H
#define LIQUIDITY_H

#include <exception>
#include "exceptions.h"
#include "db_connect.h"

namespace liquidityData {
    // Getting Best Bid
    double getBestBid(std::string ticker) {
        try {
            db_connect::selectOrder(ticker);
        }
        catch (exceptions::liquidityException e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        return 0.0;
    }

    // Getting Best Ask
    double getBestAsk() {

        return 0.0;
    }
}

#endif