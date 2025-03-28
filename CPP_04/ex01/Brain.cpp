#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	// Initialiser les idées avec des valeurs par défaut si nécessaire
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = "Empty idea";
	}
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	// Copier toutes les idées
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		// Copier toutes les idées
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return this->ideas[index];
	return "Invalid index";
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}