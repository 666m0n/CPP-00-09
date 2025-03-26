#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called for " << name << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << getName() << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "ScavTrap " << getName() << " ATTACKS " << target << ", causing "
				  << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else if (_energyPoints == 0) {
		std::cout << "ScavTrap " << getName() << " has no energy points left to attack!" << std::endl;
	} else {
		std::cout << "ScavTrap " << getName() << " has no hit points left to attack!" << std::endl;
	}
}

// Guard gate fctn
void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode!" << std::endl;
}