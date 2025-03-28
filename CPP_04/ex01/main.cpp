#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
	 // Test de base comme dans l'exemple du sujet
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;  // Ne devrait pas créer de fuite
		delete i;
	}

	std::cout << "\n--- Testing array of animals ---\n" << std::endl;

	// Création d'un tableau d'animaux
	const int arraySize = 10;
	Animal* animals[arraySize];

	// Remplir le tableau avec des chiens et des chats
	for (int i = 0; i < arraySize; i++) {
		if (i < arraySize / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// Utilisation des animaux
	for (int i = 0; i < arraySize; i++) {
		std::cout << "Animal " << i << " is a " << animals[i]->getType() << " and makes sound: ";
		animals[i]->makeSound();
	}

	// Libération de la mémoire
	for (int i = 0; i < arraySize; i++) {
		delete animals[i];
	}

	std::cout << "\n--- Testing deep copy ---\n" << std::endl;

	// Test de la copie profonde
	Dog* originalDog = new Dog();

	// Ajouter quelques idées au chien original
	originalDog->getBrain()->setIdea(0, "I love bones");
	originalDog->getBrain()->setIdea(1, "I want to chase cats");

	// Créer une copie
	Dog* copyDog = new Dog(*originalDog);

	// Vérifier que la copie a les mêmes idées
	std::cout << "Original dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy dog idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;

	// Modifier une idée dans la copie et vérifier que l'original ne change pas
	copyDog->getBrain()->setIdea(0, "I prefer toys over bones");

	std::cout << "After modification:" << std::endl;
	std::cout << "Original dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy dog idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;

	// Libération de la mémoire
	delete originalDog;
	delete copyDog;

	return 0;
}