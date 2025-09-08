#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
#include <utility> // pair & make_pair
#include <cmath>
#include <ctime>
#include <iomanip>

class PmergeMe {
	private:
		unsigned int const			_siz;
		std::vector<unsigned int>	_vec;
		std::deque<unsigned int>	_deq;
		char **						_av;
		clock_t						_vstart;
		clock_t						_dstart;
		clock_t						_vend;
		clock_t						_dend;

		PmergeMe();

	public:
		PmergeMe(char **, int);
		PmergeMe(PmergeMe const&);
		~PmergeMe(){}
		PmergeMe& operator=(PmergeMe const&);

		bool parseInput();
		void display(std::vector<unsigned int>);

		std::vector<unsigned int>	FJVec(std::vector<unsigned int>);
		std::deque<unsigned int>	FJDeq(std::deque<unsigned int>);

		std::vector<unsigned int>	genJacob(size_t limit);
		std::vector<size_t>			orderOfInsert(size_t limit);
};