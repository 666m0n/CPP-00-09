#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
	unsigned int		_N;
	std::vector<int>	_numbers;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &src);
	Span &operator=(const Span &rhs);
	~Span();

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		unsigned int count = std::distance(begin, end);

		if (_numbers.size() + count > _N)
			throw std::out_of_range("Cannot add range: would exceed maximum capacity");

		_numbers.insert(_numbers.end(), begin, end);
	}

	class FullSpanException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Span is already full";
			}
	};

	class NoSpanException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Cannot find span: not enough numbers stored";
			}
	};
};

#endif