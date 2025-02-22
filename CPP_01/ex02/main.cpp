#include <iostream>
#include <string>

int main() {
	std::string string = "HI THIS IS BRAIN";

	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "Adresses mémoire :" << std::endl;
	std::cout << "- string	: " << &string << std::endl;
	std::cout << "- stringPTR	: " << stringPTR << std::endl;
	std::cout << "- stringREF	: " << &stringREF << std::endl;

	std::cout << "\nValeurs :" << std::endl;
	std::cout << "• string	: " << string << std::endl;
	std::cout << "• stringPTR	: " << *stringPTR << std::endl; // *stringPTR déréférence le pointeur
	std::cout << "• stringREF	: " << stringREF << std::endl;

	return 0;
}
