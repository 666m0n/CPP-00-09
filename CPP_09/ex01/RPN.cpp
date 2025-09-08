#include "RPN.hpp"

RPN::RPN(std::string const& string) : _input(string){
	checkInput();
}

RPN::RPN(RPN const& copy) : _stack(copy._stack), _input(copy._input){
	checkInput();
}

RPN& RPN::operator=(RPN const& rhs){
	if (this != &rhs)
	{
		this->_stack = rhs._stack;
	}
	return *this;
}

static bool isAllowed(char c){
	return ((c >= '0' && c <= '9') || c == ' ' || c == '+' || c == '-' || c == '*' || c == '/');
}

static bool isValid(std::string const& str){
	for (size_t i = 0; i < str.size(); i++)
		if (!isAllowed(str[i]))
			return 0;
	return 1;
}

void RPN::checkInput(){
	if (!isValid(_input)) {
		std::cerr << "Not a valid input." << std::endl;
		return ;
	}
	doOperation();
}

void RPN::doOperation(){
	std::string const op = "/*-+";
	std::stringstream ss(_input);
	std::string token;

	while (ss >> token)
	{
		if (op.find(token) != std::string::npos)
		{
			if (_stack.size() != 2) {
				std::cerr << "Cannot do this operation." << std::endl;
				return;
			}

			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			if (token == "-")
				_stack.push(a - b);
			else if (token == "+")
				_stack.push(a + b);
			else if (token == "*")
				_stack.push(a * b);
			else if (token == "/" && b != 0)
				_stack.push(a / b);
			else {
				std::cerr << "Cannot divide by 0." << std::endl;
				return;
			}
		}
		else
		{
			int nb = atoi(token.c_str());
			if (!(nb < 10 && nb > -1))
			{
				std::cerr << "Max value must be <= 9." << std::endl;
				return;
			}
			_stack.push(nb);
		}
	}
	if (_stack.size() != 1)
		std::cerr << "Cannot do this operation." << std::endl;
	else
		std::cout << _stack.top() << std::endl;
}