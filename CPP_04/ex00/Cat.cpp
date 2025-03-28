#include "Cat.hpp"

// Constructeur par défaut
Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";  // Initialisation du type
}

// Constructeur par copie
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

// Destructeur
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

// Opérateur d'affectation
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

// Implémentation de makeSound spécifique au chat
void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}