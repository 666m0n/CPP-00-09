#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon* weapon; // Pointeur vers une arme - peut être nullptr
	public:
		HumanB(std::string const &name);
		void setWeapon(Weapon& weapon);
		void attack() const;
};

#endif