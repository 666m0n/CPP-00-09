#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	// Allocation d'un nouveau cerveau
	this->brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	// Copie profonde du cerveau
	this->brain = new Brain(*other.brain);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	// Libération de la mémoire
	delete this->brain;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);

		// Copie profonde du cerveau
		delete this->brain;  // Supprimer l'ancien cerveau
		this->brain = new Brain(*other.brain);  // Créer une copie du nouveau
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->brain;
}