#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T const &element)
{
	std::cout << element << " ";
}

template <typename T>
void doubleValue(T &element)
{
	element *= 2;
}

void toUpperCase(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
	}
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArraySize = 5;

	std::cout << "Tableau d'entiers original: ";
	::iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;

	::iter(intArray, intArraySize, doubleValue<int>);

	std::cout << "Tableau d'entiers après doublage: ";
	::iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;

	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	size_t floatArraySize = 5;

	std::cout << "Tableau de flottants original: ";
	::iter(floatArray, floatArraySize, printElement<float>);
	std::cout << std::endl;

	std::string stringArray[] = {"hello", "world", "iter", "template", "c++"};
	size_t stringArraySize = 5;

	std::cout << "Tableau de chaînes original: ";
	::iter(stringArray, stringArraySize, printElement<std::string>);
	std::cout << std::endl;

	::iter(stringArray, stringArraySize, toUpperCase);

	std::cout << "Tableau de chaînes après majuscules: ";
	::iter(stringArray, stringArraySize, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}