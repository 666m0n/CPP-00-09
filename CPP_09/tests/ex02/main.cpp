#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <list of integers>" << std::endl;
        return 1;
    }

    PmergeMe merge_insert_sort;
    try
    {
       merge_insert_sort.execute(ac, av); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}
