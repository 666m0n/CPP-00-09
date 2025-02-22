#include "HumanA.hpp"
#include <iostream>

// Initialisation avec une liste d'initialisation car weapon est une référence
HumanA::HumanA(std::string const &name, Weapon& weapon)
: name(name), weapon(weapon) {
}

void HumanA::attack() const {
	std::cout << this->name << " attacks with their "
			<< this->weapon.getType() << std::endl;
}