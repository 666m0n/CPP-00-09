#include "Animal.hpp"

// Constructeur par défaut
Animal::Animal() : type("") {
    std::cout << "Animal default constructor called" << std::endl;
}

// Constructeur par copie
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

// Destructeur
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

// Opérateur d'affectation
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// Getter pour le type
std::string Animal::getType() const {
    return this->type;
}

// Fonction makeSound (implémentation de base)
void Animal::makeSound() const {
    std::cout << "* Generic animal sound *" << std::endl;
}