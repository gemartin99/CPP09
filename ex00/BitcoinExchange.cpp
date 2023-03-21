#include "BitcoinExchange.hpp"

exchange::exchange(void) {}

exchange::exchange(const exchange&) throw() {}

exchange& exchange::operator=(const exchange& other) throw()
{
    if (this == &other)
        return *this;
    return *this;
}

exchange::~exchange(void) throw() {}