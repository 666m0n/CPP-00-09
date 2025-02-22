#include "Weapon.hpp"

Weapon::Weapon(std::string const &type) : type(type) {
}

const std::string& Weapon::getType() const {
	//return une ref constante vers le type
	return this->type;
}

void Weapon::setType(std::string const &type) {
	//change le type d'arme
	this->type = type;
}