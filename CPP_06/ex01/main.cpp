#include "Serializer.hpp"
#include <iostream>

int main() {
	Data* original = new Data;
	original->s1 = "Bonjour";
	original->n = 42;
	original->s2 = "Monde";

	std::cout << "Original Data:" << std::endl;
	std::cout << "  Adresse: " << original << std::endl;
	std::cout << "  s1: " << original->s1 << std::endl;
	std::cout << "  n: " << original->n << std::endl;
	std::cout << "  s2: " << original->s2 << std::endl;
	std::cout << std::endl;

	uintptr_t serialized = Serializer::serialize(original);
	std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;
	std::cout << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "  Adresse: " << deserialized << std::endl;
	std::cout << "  s1: " << deserialized->s1 << std::endl;
	std::cout << "  n: " << deserialized->n << std::endl;
	std::cout << "  s2: " << deserialized->s2 << std::endl;
	std::cout << std::endl;

	std::cout << "Les pointeurs sont "
			  << (original == deserialized ? "identiques" : "différents")
			  << std::endl;


	delete original;

	return 0;
}