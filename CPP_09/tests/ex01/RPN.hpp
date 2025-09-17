#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <limits>
#include <cstdlib>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

class RPN
{
    
    public:
        RPN();
        ~RPN();
        
        ////MEMBER FUNCS
        void    execRPN(const std::string& args);
    
    private:
        std::stack<int> _stack;

        //checkers
        bool    isOperator(const std::string& token) const;
        bool isValidINT(const std::string& token, int& value) const;

        int     applyOperator(int front, int latter, const std::string& op) const;
        void    applyPrintStack(const std::stack<int>& stack);
};


#endif 


/* STEPS

//operator is a reserved keyword in C++! cannot use "operator" as a variable name

1. Create an empty stack of integers
2. Split the input expression into tokens
3. For each token:
    a. If it's a number:
        - Push it to the stack
    b. If it's an operator (+, -, *, /)
        - Pop the top two elements from the stack
        - Apply the operator.
        - Push the result back on the stack
    c. If it's an invalid token:
        - Print "Error" to std::cerr and exit
4. After processing:
    - If the stack has exactly one number, print it as the result
    - Else, print "Error" to std::cerr

class RPN 
{
    public:
        RPN() = default;                 // Let compiler handle this
        RPN(const RPN&) = delete;       // Forbid copying
        RPN& operator=(const RPN&) = delete; // Forbid assignment
        ~RPN() = default;               // Let compiler handle cleanup
};

*/