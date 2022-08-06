#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <iostream>
#include <exception>
#include "select_order.h"

class liquidityException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Couldn't get a valid price.";
    }
};

namespace liquidityData {
    // Getting Best Bid
    double getBestBid(std::string ticker) {
        try {
            return getPrice(ticker);
        }
        catch (liquidityException e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        return 0.0;
    }

    // Getting Best Ask
    double getBestAsk() {

        return 0.0;
    }
}

namespace Order {

    // Defining Order Class
    class Order {
    public:
        int id;
        std::string state;
        uint64_t oTimestamp;
        uint64_t cTimestamp{};
        std::string type;
        std::string side;
        std::string ticker;
        double price;
        double size;
        int userID;

        // Order Constructor
        Order(const int oID, const std::string& oType, const std::string& oSide, const std::string& oTicker, double oPrice, double oSize, const int uID) {
            id = oID;
            state = "pending";
            oTimestamp = getTime::millis();
            type = oType;
            side = oSide;
            ticker = oTicker;
            size = oSize;
            userID = uID;

            if (type == "limit") {
                price = oPrice;
                if (side == "buy") {
                    // Limit Buy

                }
                else if (side == "sell") {
                    // Limit Sell

                }
            }
            else if (type == "market") {
                if (side == "buy") {
                    // Market Buy
                    try {
                        price = liquidityData::getBestAsk();
                    }
                    catch (liquidityException& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                        state = "cancelled";
                        cTimestamp = getTime::millis();
                    }
                    state = "filled";
                    cTimestamp = getTime::millis();
                }
                if (side == "sell") {
                    // Market Sell
                    try {
                        price = liquidityData::getBestBid(ticker);
                    }
                    catch (liquidityException& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                        state = "cancelled";
                        cTimestamp = getTime::millis();
                    }
                    state = "filled";
                    cTimestamp = getTime::millis();
                }
            }
        }
    };
}

#endif