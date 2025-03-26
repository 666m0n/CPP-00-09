#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap("default_clap_name"),
	ScavTrap(),
	FragTrap()
{
	_name = "default";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(),
	FragTrap()
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;      // 100, from FragTrap
	_energyPoints = ScavTrap::_energyPoints; // 50, from ScavTrap
	_attackDamage = FragTrap::_attackDamage; // 30, from FragTrap
	std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other)
{
	_name = other._name;
	std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

// Special capacity whoAmI
void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << _name << ", also known as ClapTrap "
			  << ClapTrap::_name << std::endl;
}

// Override attack to use ScavTrap's version
void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}