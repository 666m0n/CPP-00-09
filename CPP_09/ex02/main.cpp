#include "PmergeMe.hpp"

int main (int ac, char **av)
{
	if (ac >= 2)
	{
		PmergeMe mergeMe(av, ac);
		return 0;
	}
	return std::cerr << "Error: Three elements required to start sorting." << std::endl, 1;
}