#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <fstream>
#include <limits>
#include <cmath>
#include <iomanip> // precision output , fixed empeche nota scientifique

class RPN {
	private:
		std::stack<int>		_stack;
		std::string const&	_input;
		RPN();

	public:
		RPN(std::string const& string);
		RPN(RPN const& copy);
		~RPN(){}
		RPN& operator=(RPN const& rhs);

		void	checkInput();
		void	doOperation();
};