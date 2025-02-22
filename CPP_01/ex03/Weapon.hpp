#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string type;

	public:
		Weapon(std::string const &type);
// const& permet d'éviter la copie et assure que la valeur ne sera pas modifiée
		const std::string& getType() const;
		void setType(std::string const &type);
};

#endif