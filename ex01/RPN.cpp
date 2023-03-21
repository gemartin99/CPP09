#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN&) throw() {}

RPN& RPN::operator=(const RPN& other) throw()
{
    if (this == &other)
        return *this;
    return *this;
}

RPN::~RPN(void) throw() {}