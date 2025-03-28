#include "Character.hpp"

Character::Character() : name("unnamed") {
	std::cout << "Character default constructor called" << std::endl;
	// Initialiser l'inventaire à NULL
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(std::string const & name) : name(name) {
	std::cout << "Character constructor with name called" << std::endl;
	// Initialiser l'inventaire à NULL
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character& other) : name(other.name) {
	std::cout << "Character copy constructor called" << std::endl;
	// Copie profonde de l'inventaire
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	// Nettoyer l'inventaire
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i]) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
}

Character& Character::operator=(const Character& other) {
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;

		// Nettoyer l'inventaire actuel
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i]) {
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
		}

		// Copie profonde de l'inventaire
		for (int i = 0; i < 4; i++) {
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Cannot equip NULL materia" << std::endl;
		return;
	}

	// Trouver le premier emplacement vide
	for (int i = 0; i < 4; i++) {
		if (!this->inventory[i]) {
			this->inventory[i] = m;
			std::cout << this->name << " equipped " << m->getType() << " at slot " << i << std::endl;
			return;
		}
	}

	// Si on arrive ici, l'inventaire est plein
	std::cout << this->name << "'s inventory is full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid inventory index" << std::endl;
		return;
	}

	if (!this->inventory[idx]) {
		std::cout << "No materia at slot " << idx << std::endl;
		return;
	}

	std::cout << this->name << " unequipped " << this->inventory[idx]->getType()
			  << " from slot " << idx << std::endl;
	this->inventory[idx] = NULL;  // Ne pas supprimer la materia, juste l'enlever de l'inventaire
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid inventory index" << std::endl;
		return;
	}

	if (!this->inventory[idx]) {
		std::cout << "No materia at slot " << idx << std::endl;
		return;
	}

	this->inventory[idx]->use(target);
}