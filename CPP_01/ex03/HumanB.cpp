#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string const &name) : name(name), weapon(NULL) {
	// Initialise avec un pointeur null pour indiquer pas d'arme
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() const {
	if (this->weapon) {
		std::cout << this->name << " attacks with their "
				<< this->weapon->getType() << std::endl;
	}
	else {
		std::cout << this->name << " attacks with their fists" << std::endl;
	}
}