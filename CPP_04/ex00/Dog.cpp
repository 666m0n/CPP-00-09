#include "Dog.hpp"

// Constructeur par défaut
Dog::Dog() {
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";  // Initialisation du type
}

// Constructeur par copie
Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
}

// Destructeur
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

// Opérateur d'affectation
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

// Implémentation de makeSound spécifique au chien
void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}