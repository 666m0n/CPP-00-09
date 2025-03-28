#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	std::cout << "--- Testing Animal, Dog and Cat with polymorphism ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

    std::cout << "J type: " << j->getType() << std::endl;
    std::cout << "I type: " << i->getType() << std::endl;

    i->makeSound();  // Devrait afficher le son du chat
    j->makeSound();  // Devrait afficher le son du chien
    meta->makeSound();  // Devrait afficher le son de base de l'Animal

    // Libération de la mémoire
    delete meta;
    delete j;
    delete i;

    // Test des classes WrongAnimal et WrongCat sans polymorphisme
    std::cout << "\n--- Testing WrongAnimal and WrongCat without polymorphism ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

    std::cout << "WrongI type: " << wrongI->getType() << std::endl;

    wrongI->makeSound();  // Devrait afficher le son du WrongAnimal et non du WrongCat
    wrongMeta->makeSound();

    // Libération de la mémoire
    delete wrongMeta;
    delete wrongI;

    return 0;
}