#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
	_name(other.name),
	_hitPoints