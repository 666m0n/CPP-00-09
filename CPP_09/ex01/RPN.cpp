#include "RPN.hpp"

RPN::RPN() : _stack(){}
RPN::~RPN(){}

bool    RPN::isOperator(const std::string& token) const
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return true;
    return false;
}

bool RPN::isValidINT(const std::string& token, int& value) const
{
    char* end = NULL;
    errno = 0;
    long result = std::strtol(token.c_str(), &end, 10);

    if (*end != '\0' || errno == ERANGE || result > INT_MAX || result < INT_MIN)
        return false;

    value = static_cast<int>(result);
    return true;
}

int    RPN::DoOperation(int front, int latter, const std::string& op) const
{
    if (op == "+")
        return front + latter;
    else if (op == "-")
        return front - latter;
    else if (op == "*")
        return front * latter;
    else if (op == "/")
    {
        if (latter == 0)
        {
            std::cerr << "Error: division by zero." << std::endl;
            exit(1);
        }
        return front / latter;
    }
        std::cerr << "Error" << std::endl;
        return 1;

}

void    RPN::applyPrintStack(const std::stack<int>& stack)
{
    if (stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << stack.top() << std::endl;
}

void    RPN::execRPN(const std::string& args)
{
    std::istringstream iss(args);
    std::string token;
    int intMAX = std::numeric_limits<int>::max();
    int intMIN = std::numeric_limits<int>::min();
    int result = 0;

    while (iss >> token)
    {
        int nb = 0;
        if (isValidINT(token, nb))
            _stack.push(nb);

        else if (isOperator(token))
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error: RPN not respected." << std::endl;
                return;
            }

            int latter = _stack.top();
            _stack.pop();

            int front = _stack.top();
            _stack.pop();

            result = DoOperation(front, latter, token);
            _stack.push(result);

            if (result > intMAX || result < intMIN)
            {
                std::cerr << "Error: Number out of range." << std::endl;
                return;
            }
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return ;

        }
    }
    applyPrintStack(_stack);
}
