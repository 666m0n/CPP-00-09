#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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

	// Show inheritance from ClapTrap
	std::cout << "ScavTrap " << scav.getName() << " stats:" << std::endl;
	std::cout << "Hit Points: " << scav.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << scav.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << scav.getAttackDamage() << std::endl;
	std::cout << std::endl;

	// Test ScavTrap methods
	scav.attack("Bandit");
	scav.takeDamage(30);
	scav.beRepaired(15);
	scav.guardGate();
	std::cout << std::endl;

	// Testing ScavTrap specific scenarios
	std::cout << "=== Testing ScavTrap Energy Depletion ===" << std::endl;
	for (int i = 0; i < 50; ++i) {
		std::cout << "Energy points left: " << scav.getEnergyPoints() << std::endl;
		scav.attack("Dummy Target");
		if (scav.getEnergyPoints() == 0) {
			break;
		}
	}

	// Try to attack with no energy
	scav.attack("Bandit");

	// Try to repair with no energy
	scav.beRepaired(10);

	std::cout << "\n=== Testing Fatal Damage on ScavTrap ===" << std::endl;
	ScavTrap fragileScav("FragileScav");
	fragileScav.takeDamage(200); // More than its hit points

	// Try to attack after being destroyed
	fragileScav.attack("Enemy");

	// Try to use guardGate after being destroyed
	fragileScav.guardGate();

	std::cout << "\n=== Testing Constructors/Destructors Chaining ===" << std::endl;
	{
		std::cout << "Creating a ScavTrap inside a block scope:" << std::endl;
		ScavTrap tempScav("TempScav");
		std::cout << "End of block scope coming..." << std::endl;
	}

	std::cout << "\n=== End of Main ===" << std::endl;
	return 0;
}