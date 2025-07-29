#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>

void testBasicFunctionality() {
	std::cout << "=== Basic Functionality Test ===" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	try {
		std::cout << "Trying to add one more number..." << std::endl;
		sp.addNumber(42);
	} catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testLargeNumbers() {
	std::cout << "\n=== Large Numbers Test (10,000 elements) ===" << std::endl;

	Span largeSpan(10000);

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < 10000; ++i) {
		largeSpan.addNumber(std::rand() % 1000000);
	}

	std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
}

void testAddRange() {
	std::cout << "\n=== Add Range Test ===" << std::endl;

	std::list<int> numbers;
	for (int i = 1; i <= 5; ++i) {
		numbers.push_back(i * 10);
	}

	Span sp(10);
	sp.addRange(numbers.begin(), numbers.end());

	sp.addNumber(1);
	sp.addNumber(100);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::list<int> moreNumbers;
	for (int i = 1; i <= 5; ++i) {
		moreNumbers.push_back(i * 5);
	}

	try {
		std::cout << "Trying to add too many numbers via range..." << std::endl;
		sp.addRange(moreNumbers.begin(), moreNumbers.end());
	} catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testEdgeCases() {
	std::cout << "\n=== Edge Cases Test ===" << std::endl;

	Span emptySpan(5);
	try {
		std::cout << "Testing spans on empty container..." << std::endl;
		emptySpan.shortestSpan();
	} catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Span singleSpan(5);
	singleSpan.addNumber(42);
	try {
		std::cout << "Testing spans on container with single element..." << std::endl;
		singleSpan.longestSpan();
	} catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main() {
	testBasicFunctionality();
	testLargeNumbers();
	testAddRange();
	testEdgeCases();

	return 0;
}