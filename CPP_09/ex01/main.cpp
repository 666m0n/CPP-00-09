#include "RPN.hpp"

int main (int ac, char **av)
{
	if (ac == 2)
	{
		RPN calculatrice(av[1]);
		return 0;
	}
	return std::cerr << "Error: usage must be : ./RPN your_RPN_operation" << std::endl, 1;
}