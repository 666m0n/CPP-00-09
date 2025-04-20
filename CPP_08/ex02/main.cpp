#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

void testSubjectExample() {
	std::cout << "=== Testing Subject Example with MutantStack ===" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "Stack elements: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	std::stack<int> s(mstack);
	std::cout << "Standard stack size (from mstack): " << s.size() << std::endl;
}

void testWithList() {
	std::cout << "\n=== Testing with List for comparison ===" << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Back element: " << lst.back() << std::endl;

	lst.pop_back();

	std::cout << "Size after pop: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;

	std::cout << "List elements: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void testWithDifferentContainers() {
	std::cout << "\n=== Testing MutantStack with Vector Container ===" << std::endl;

	MutantStack<int, std::vector<int> > vstack;

	vstack.push(10);
	vstack.push(20);
	vstack.push(30);

	std::cout << "Vector-backed stack elements: ";
	for (MutantStack<int, std::vector<int> >::iterator it = vstack.begin(); it != vstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void testReverseIterators() {
	std::cout << "\n=== Testing Reverse Iterators ===" << std::endl;

	MutantStack<int> mstack;

	for (int i = 1; i <= 5; ++i) {
		mstack.push(i * 10);
	}

	std::cout << "Elements in reverse order: ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << std::endl;
}

void testWithDifferentTypes() {
	std::cout << "\n=== Testing with Different Types ===" << std::endl;

	MutantStack<std::string> strstack;

	strstack.push("Hello");
	strstack.push("World");
	strstack.push("42");

	std::cout << "String stack elements: ";
	for (MutantStack<std::string>::iterator it = strstack.begin(); it != strstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main() {
	testSubjectExample();
	testWithList();
	testWithDifferentContainers();
	testReverseIterators();
	testWithDifferentTypes();

	return 0;
}