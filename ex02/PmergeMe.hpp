#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe {
public:
    PmergeMe(void);
    PmergeMe(const PmergeMe& other) throw();
    PmergeMe& operator=(const PmergeMe& other) throw();
    ~PmergeMe(void) throw();
};

#endif