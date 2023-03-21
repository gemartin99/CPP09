#ifndef RPN_HPP
# define RPN_HPP

class RPN {
public:
    RPN(void);
    RPN(const RPN& other) throw();
    RPN& operator=(const RPN& other) throw();
    ~RPN(void) throw();
};

#endif