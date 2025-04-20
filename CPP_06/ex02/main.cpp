#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) {
	static bool initialized = false;
	if (!initialized) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		initialized = true;
	}

	int random = std::rand() % 3;

	switch (random) {
		case 0:
			std::cout << "Création d'une instance de la classe A" << std::endl;
			return new A();
		case 1:
			std::cout << "Création d'une instance de la classe B" << std::endl;
			return new B();
		case 2:
			std::cout << "Création d'une instance de la classe C" << std::endl;
			return new C();
		default:
			return NULL; // jamais
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C" << std::endl;
	}
	else {
		std::cout << "Type inconnu" << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a; // unused variable
		std::cout << "A" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	std::cout << "Type inconnu" << std::endl;
}

int main() {
	for (int i = 0; i < 5; ++i) {
		std::cout << "\n--- Test " << i + 1 << " ---" << std::endl;

		Base* instance = generate();

		std::cout << "Identification par pointeur: ";
		identify(instance);

		std::cout << "Identification par référence: ";
		identify(*instance);

		delete instance;
	}

	return 0;
}