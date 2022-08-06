#ifndef GET_CONFIG_H
#define GET_CONFIG_H

#include <iostream>
#include <fstream>

namespace db_config {

    // Opening config file
    std::string getConfig(int rParam) {
        std::fstream in("../db.config" );

        if (!in.is_open()) {
            return "Failed to open config.";
        }

        int param;
        std::string value;

        // Finding config value
        while (!in.eof()) {
            in >> param;
            in >> value;

            switch (param) {
                case 1:
                    if (param == rParam) { return value; }
                    else { break; }
                case 2:
                    if (param == rParam) { return value; }
                    else { break; }
                case 3:
                    if (param == rParam) { return value; }
                    else { break; }
                case 4:
                    if (param == rParam) { return value; }
                    else { break; }
                case 5:
                    if (param == rParam) { return value; }
                    else { break; }
                default:
                    return "Fetch to find value.";
            }
        }
        in.close();
        return "Failed to fetch value.";
    }

}

#endif