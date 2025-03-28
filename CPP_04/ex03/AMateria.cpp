#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << "AMateria constructor with type called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

std::string const & AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* AMateria of type " << this->type << " used on "
			  << target.getName() << " *" << std::endl;
}