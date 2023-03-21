#ifndef EXCHANGE_HPP
# define EXCHANGE_HPP

class exchange {
public:
    exchange(void);
    exchange(const exchange& other) throw();
    exchange& operator=(const exchange& other) throw();
    ~exchange(void) throw();
};

#endif