#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "=== Testing with vector ===" << std::endl;

	try {
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 50);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);
	lst.push_back(35);

	std::cout << "\n=== Testing with list ===" << std::endl;

	try {
		std::list<int>::iterator it = easyfind(lst, 15);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 100);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::deque<int> deq;
	deq.push_back(2);
	deq.push_back(4);
	deq.push_back(6);
	deq.push_back(8);

	std::cout << "\n=== Testing with deque ===" << std::endl;

	try {
		std::deque<int>::iterator it = easyfind(deq, 6);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::deque<int>::iterator it = easyfind(deq, 10);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}