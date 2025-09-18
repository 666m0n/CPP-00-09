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

		void    execRPN(const std::string& args);

    private:
        std::stack<int> _stack;

        bool    isOperator(const std::string& token) const;
        bool    isValidINT(const std::string& token, int& value) const;

        int     DoOperation(int front, int latter, const std::string& op) const;
        void    applyPrintStack(const std::stack<int>& stack);
};


#endif
