#include "ClapTrap.hpp"

//Default constructor
ClapTrap::ClapTrap() : _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called for " << this->_name << std::endl;
}

//Constructeur parametre
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor called for " << this->_name << std::endl;
}

//Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) :
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage) {
	std::cout << "ClapTrap copy constructor called for " << this->_name << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

// Assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

//fonctions membre
void ClapTrap::attack(const std::string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
				  << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left to attack!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " has no hit points left to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		if (amount >= _hitPoints) {
			_hitPoints = 0;
			std::cout << "ClapTrap " << _name << " takes " << amount << " damage and is destroyed!" << std::endl;
		} else {
			_hitPoints -= amount;
			std::cout << "ClapTrap " << _name << " takes " << amount << " damage, reducing hit points to "
					  << _hitPoints << "!" << std::endl;
		}
	} else {
		std::cout << "ClapTrap " << _name << " is already destroyed and cannot take more damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repairs itself, gaining " << amount
				  << " hit points. Now has " << _hitPoints << " hit points!" << std::endl;
		_energyPoints--;
	} else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left to repair itself!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " has no hit points left and cannot be repaired!" << std::endl;
	}
}

// Getters
std::string ClapTrap::getName() const {
	return _name;
}

unsigned int ClapTrap::getHitPoints() const {
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}