#include "Span.hpp"

Span::Span() : _N(0), _numbers() {}

Span::Span(unsigned int N) : _N(N), _numbers() {
_numbers.reserve(N);
}

Span::Span(const Span &src) : _N(src._N), _numbers(src._numbers) {}

Span &Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		_N = rhs._N;
		_numbers = rhs._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_numbers.size() >= _N)
		throw FullSpanException();

	_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (_numbers.size() <= 1)
		throw NoSpanException();

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i) {
		int span = sorted[i] - sorted[i-1];
		if (span < minSpan)
			minSpan = span;
	}

	return minSpan;
}

int Span::longestSpan() const {
	if (_numbers.size() <= 1)
		throw NoSpanException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}