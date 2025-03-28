#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	// Allocation d'un nouveau cerveau
	this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	// Copie profonde du cerveau
	this->brain = new Brain(*other.brain);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	// Libération de la mémoire
	delete this->brain;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);

		// Copie profonde du cerveau
		delete this->brain;  // Supprimer l'ancien cerveau
		this->brain = new Brain(*other.brain);  // Créer une copie du nouveau
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->brain;
}