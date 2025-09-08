#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int siz) : _siz(siz), _av(av){
	_vec.reserve(_siz);
	if (parseInput())
	{
		std::vector<unsigned int> vec = FJVec(_vec);
		std::deque<unsigned int> deq = FJDeq(_deq);
		display(vec); // , deq
	}
}

PmergeMe::PmergeMe(PmergeMe const& copy) : _siz(copy._siz), _vec(copy._vec), _deq(copy._deq), _av(copy._av){
}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs){
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
	}
	return *this;
}

void PmergeMe::display(std::vector<unsigned int> vec){

	std::vector<unsigned int>::iterator it = vec.begin();
	std::vector<unsigned int>::iterator ite = vec.end();

	std::cout << "Before:	  ";

	for (size_t i = 1; i < _siz; i++)
		std::cout << _av[i] << " ";
	std::cout << std::endl;


	std::cout << "After:	  ";

	for (; it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;


	// PRINT TIME
	std::cout << std::fixed << std::setprecision(6) << "Time to process a range of " << (vec.size()) << " elements with std::vector : " << static_cast<double>(_vend - _vstart) / CLOCKS_PER_SEC << std::endl;
	std::cout << "Time to process a range of " << (vec.size()) << " elements with std::deque : " << static_cast<double>(_dend - _dstart) / CLOCKS_PER_SEC << std::endl;
}

bool PmergeMe::parseInput(){
	for (size_t i = 1; i < _siz; i++)
	{
		std::stringstream ss(_av[i]);
		long long	nb;

		while (ss >> nb)
		{
			if (nb < 0 || nb > INT_MAX)
			{
				if (nb < 0)
					std::cerr << "Error: Cannot sort negative number: " << nb << std::endl, 0;
				else
					std::cerr << "Error: too big number: " << nb << std::endl;
				return 0;
			}

			std::vector<unsigned int>::iterator it = std::find(_vec.begin(), _vec.end(), nb);
			if (it != _vec.end()){
				std::cerr << "Error: Cannot handle duplicate number: " << nb << std::endl;
				return 0;
			}
			_vec.push_back(nb);
			_deq.push_back(nb);
		}
		if (!ss.eof())
		{
			ss.clear();
			std::string str;
			ss >> str;
			std::cerr << "Error: Invalid character: " << str << std::endl;
			return 0;
		}
	}
	return 1;
}

std::vector<unsigned int> PmergeMe::genJacob(size_t limit){

	std::vector<unsigned int> seq;
	seq.reserve(limit);
	seq.push_back(1);
	if (limit > 1)
		seq.push_back(3);
	for (size_t i = 2; i < limit; i++)
	{
		size_t new_elem = seq[i - 1] + 2 * seq[i - 2];
		if (new_elem >= limit)
			break;
		seq.push_back(new_elem);
	}
	return seq;
}

std::vector<size_t> PmergeMe::orderOfInsert(size_t limit){

	std::vector<size_t> index;
	std::vector<unsigned int> jacobSeq = genJacob(limit);

	index.push_back(0);

	for (size_t i = 1; i < jacobSeq.size() && jacobSeq[i] < limit; i++)
	{
		index.push_back(jacobSeq[i]);
		for (size_t j = jacobSeq[i] - 1; j > jacobSeq[i - 1]; j--)
			index.push_back(j);
	}

	for (size_t i = 0; i < limit; i++)
	{
		bool here = false;
		for (size_t j = 0; j < index.size(); j++)
		{
			if (index[j] == i)
			{
				here = true;
				break;
			}
		}
		if (!here)
			index.push_back(i);
	}

	if (index.size() > limit)
		index.resize(limit);
	return index;
}

std::vector<unsigned int>	PmergeMe::FJVec(std::vector<unsigned int> tab){
	_vstart = clock();

	// Creer les paires
	if (tab.size() <= 1)
		return tab;

	std::vector<std::pair<unsigned int, unsigned int> > pair;
	std::vector<bool> full;

	for (size_t i = 0; i < tab.size() ; i += 2)
	{
		if ((i + 1) < tab.size())
		{
			unsigned int a = tab[i];
			unsigned int b = tab[i + 1];

			if (a < b)
				std::swap(a, b);
			pair.push_back(std::make_pair(a, b));
			full.push_back(true);
		}
		else
		{
			unsigned int dft = 0;
			pair.push_back(std::make_pair(tab[i], dft));
			full.push_back(false);
		}
	}

	// Split big et small value
	std::vector<unsigned int> big;
	std::vector<unsigned int> small;

	for (size_t i = 0; i < pair.size(); i++)
	{
		big.push_back(pair[i].first);
		if (full[i] == true)
			small.push_back(pair[i].second);
	}

	// Recursive pour retrier les grands
	std::vector<unsigned int> bigSorted = FJVec(big);

	// Recup bigSorted pour le resultat
	std::vector<unsigned int> toRet = bigSorted;

	if (!small.empty())
	{
		std::vector<size_t> order = orderOfInsert(small.size());
		for (size_t i = 0; i < order.size(); i++)
		{
			unsigned int value = small[order[i]];
			size_t start = 0;
			size_t end = toRet.size();

			while (start < end)
			{
				size_t middle = start + (end - start) / 2;
				if (toRet[middle] < value)
					start = middle + 1;
				else
					end = middle;
			}
			toRet.insert(toRet.begin() + start, value);
		}
	}
	_vend = clock();
	return toRet;
}

std::deque<unsigned int>	PmergeMe::FJDeq(std::deque<unsigned int> tab){
	_dstart = clock();

	// Creer les paires
	if (tab.size() <= 1)
		return tab;

	std::deque<std::pair<unsigned int, unsigned int> > pair;
	std::vector<bool> full;

	for (size_t i = 0; i < tab.size() ; i += 2)
	{
		if ((i + 1) < tab.size())
		{
			unsigned int a = tab[i];
			unsigned int b = tab[i + 1];

			if (a < b)
				std::swap(a, b);
			pair.push_back(std::make_pair(a, b));
			full.push_back(true);
		}
		else
		{
			unsigned int dft = 0;
			pair.push_back(std::make_pair(tab[i], dft));
			full.push_back(false);
		}
	}

	// Split big et small value
	std::deque<unsigned int> big;
	std::deque<unsigned int> small;

	for (size_t i = 0; i < pair.size(); i++)
	{
		big.push_back(pair[i].first);
		if (full[i] == true)
			small.push_back(pair[i].second);
	}

	// Recursive pour retrier les grands
	std::deque<unsigned int> bigSorted = FJDeq(big);

	// Recup bigSorted pour le resultat
	std::deque<unsigned int> toRet = bigSorted;

	if (!small.empty())
	{
		std::vector<size_t> order = orderOfInsert(small.size());
		for (size_t i = 0; i < order.size(); i++)
		{
			unsigned int value = small[order[i]];
			if (toRet.empty())
				toRet.push_back(value);
			else if (value < toRet.front())
				toRet.push_front(value);
			else if (value > toRet.back())
				toRet.push_back(value);
			else
			{
				size_t start = 0;
				size_t end = toRet.size();

				while (start < end)
				{
					size_t middle = start + (end - start) / 2;
					if (toRet[middle] < value)
						start = middle + 1;
					else
						end = middle;
				}
				toRet.insert(toRet.begin() + start, value);
			}
		}
	}
	_dend = clock();
	return toRet;
}