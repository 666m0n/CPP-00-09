#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	ClapTrap clap("CL4P-TP");
	clap.attack("Enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);
	std::cout << std::endl;

	std::cout << "=== Testing ScavTrap ===" << std::endl;
	ScavTrap scav("SC4V-TP");
	scav.attack("Bandit");
	scav.guardGate();
	std::cout << std::endl;

	std::cout << "=== Testing FragTrap ===" << std::endl;
	FragTrap frag("FR4G-TP");
	frag.attack("Monster");
	frag.highFivesGuys();
	std::cout << std::endl;

	std::cout << "=== Testing DiamondTrap ===" << std::endl;
	DiamondTrap diamond("D14M0ND");

	// Display DiamondTrap stats
	std::cout << "DiamondTrap stats (should inherit from FragTrap and ScavTrap):" << std::endl;
	std::cout << "Name: " << diamond.getName() << std::endl;
	std::cout << "Hit Points (should be 100 from FragTrap): " << diamond.getHitPoints() << std::endl;
	std::cout << "Energy Points (should be 50 from ScavTrap): " << diamond.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage (should be 30 from FragTrap): " << diamond.getAttackDamage() << std::endl;
	std::cout << std::endl;

	// Test DiamondTrap specific methods
	diamond.whoAmI();
	std::cout << std::endl;

	// Test inherited abilities
	diamond.attack("Super Enemy"); // Should use ScavTrap's attack
	diamond.takeDamage(20);
	diamond.beRepaired(10);
	diamond.guardGate(); // From ScavTrap
	diamond.highFivesGuys(); // From FragTrap
	std::cout << std::endl;

	std::cout << "=== Testing Constructor/Destructor Chaining ===" << std::endl;
	{
		std::cout << "Creating a DiamondTrap inside a block scope:" << std::endl;
		DiamondTrap tempDiamond("TempDiamond");
		std::cout << "End of block scope coming..." << std::endl;
	}

	std::cout << "\n=== End of Main ===" << std::endl;
	return 0;
}