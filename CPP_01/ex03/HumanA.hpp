#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon& weapon; //reference vers une arme - doit toujours etres valide !!
	public:
	//le constructeur utilise l'arme en reference
	HumanA(std::string const &name, Weapon& weapon);

	void attack() const;
};

#endif