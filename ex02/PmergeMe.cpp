#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe&) throw() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) throw()
{
    if (this == &other)
        return *this;
    return *this;
}

PmergeMe::~PmergeMe(void) throw() {}