#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> empty;
	std::cout << "Taille du tableau vide: " << empty.size() << std::endl;

	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		std::cout << "Valeur initiale de numbers[" << i << "]: " << numbers[i] << std::endl;
		numbers[i] = i * 10;
	}

	std::cout << "Valeurs après modification:" << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}

	Array<int> copy(numbers);
	Array<int> assigned;
	assigned = numbers;

	std::cout << "Vérification que les copies sont indépendantes:" << std::endl;
	numbers[0] = 999;
	std::cout << "numbers[0] = " << numbers[0] << std::endl;
	std::cout << "copy[0] = " << copy[0] << std::endl;
	std::cout << "assigned[0] = " << assigned[0] << std::endl;

	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";

	for (unsigned int i = 0; i < strings.size(); i++)
	{
		std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
	}

	try
	{
		std::cout << "Tentative d'accès à numbers[10] (hors limites):" << std::endl;
		numbers[10] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest supplémentaire:" << std::endl;

	Array<int> test(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		test[i] = value;
		mirror[i] = value;
	}

	bool success = true;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (test[i] != mirror[i])
		{
			std::cerr << "Erreur: test[" << i << "] != mirror[" << i << "]" << std::endl;
			success = false;
			break;
		}
	}

	if (success)
		std::cout << "Les valeurs sont identiques entre notre Array et un tableau classique !" << std::endl;

	delete[] mirror;

	return 0;
}