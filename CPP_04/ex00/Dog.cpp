#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";  // Initialisation du type
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}