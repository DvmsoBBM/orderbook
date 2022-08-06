#ifndef GET_TIME_H
#define GET_TIME_H

#include <chrono>

namespace getTime {
    uint64_t millis()
    {
        uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
        return ms;
    }
    uint64_t nanos()
    {
        uint64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
        return ns;
    }
}

namespace execTime {
    uint64_t start;

    void initExecTime() {
        start = getTime::nanos();
    }

    double getExecTime() {
        uint64_t stop = getTime::nanos();
        return (double)(stop - start) / CLOCKS_PER_SEC;
    }
}

#endif