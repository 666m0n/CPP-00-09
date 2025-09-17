#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <set>

#include <iostream>
#include <string>
#include <iomanip>   //std::setw
#include <sstream>   //std::stringstream
#include <algorithm> //std::sort //std::lower_bound
#include <iterator>  //std::iterator
#include <cstdlib>   //std::atoi
#include <exception>
#include <ctime>

#define ODD_INT 2147483647

// // Define shorthand typedefs for vector and deque of pairs of integers
typedef std::vector<std::pair<int, int> > vecPair;
typedef std::deque<std::pair<int, int> > deqPair;  


class PmergeMe
{
    protected:
        std::deque<int> _dequeData;
        std::vector<int> _vectorData;
        std::vector<std::string> _input;

        bool initContainers(int ac, char *av[]);
        bool hasDuplicate() const;
    
    public:
        PmergeMe();
        PmergeMe(PmergeMe const &src);
        PmergeMe &operator=(PmergeMe const& src);
        virtual ~PmergeMe();

        void execute(int ac, char *av[]);
};

std::vector<int> generateJacobsthal(int n);
void printTime(clock_t start, clock_t end, std::string const& containerType, int size);

#include "PmergeMe.tpp"

#endif
