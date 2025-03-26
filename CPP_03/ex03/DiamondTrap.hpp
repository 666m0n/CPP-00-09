#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string _name; // Same name as in ClapTrap

public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& other);

	void whoAmI();

	void attack(const std::string& target);
};

#endif