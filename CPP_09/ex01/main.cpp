#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "Error: Usage: " << av[0] << " \"<nb1> <nb2> <operator>\" " << std::endl;
        return 1;
    }

    try
    {
        RPN rpn;
        rpn.execRPN(av[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
