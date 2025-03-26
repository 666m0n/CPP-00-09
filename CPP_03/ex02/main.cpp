#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
	scav.takeDamage(30);
	scav.beRepaired(15);
	scav.guardGate();
	std::cout << std::endl;

	std::cout << "=== Testing FragTrap ===" << std::endl;
	FragTrap frag("FR4G-TP");

	// Show inheritance from ClapTrap and different stats from ScavTrap
	std::cout << "FragTrap " << frag.getName() << " stats:" << std::endl;
	std::cout << "Hit Points: " << frag.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << frag.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << frag.getAttackDamage() << std::endl;
	std::cout << std::endl;

	// Test FragTrap methods
	frag.attack("Super Badass");
	frag.takeDamage(40);
	frag.beRepaired(25);
	frag.highFivesGuys();
	std::cout << std::endl;

	// Testing FragTrap specific scenarios
	std::cout << "=== Testing FragTrap Energy Depletion ===" << std::endl;
	for (int i = 0; i < 5; ++i) {
		frag.attack("Enemy");
		frag.beRepaired(5);
		}
	std::cout << "Energy points left: " << frag.getEnergyPoints() << std::endl;

	std::cout << "\n=== Testing Fatal Damage on FragTrap ===" << std::endl;
	FragTrap fragileFragTrap("FragileFrag");
	fragileFragTrap.takeDamage(200); // More than its hit points

	// Try to attack after being destroyed
	fragileFragTrap.attack("Enemy");

	// Try to request high five after being destroyed
	fragileFragTrap.highFivesGuys();

	std::cout << "\n=== Testing Constructors/Destructors Chaining ===" << std::endl;
	{
		std::cout << "Creating a FragTrap inside a block scope:" << std::endl;
		FragTrap tempFragTrap("TempFrag");
		std::cout << "End of block scope coming..." << std::endl;
	}

	std::cout << "\n=== Creating Multiple Types ===" << std::endl;
	{
		ClapTrap ct("Parent");
		ScavTrap st("Guard");
		FragTrap ft("Friend");

		std::cout << "\nClapTrap, ScavTrap, and FragTrap performing actions:" << std::endl;
		ct.attack("Target");
		st.guardGate();
		ft.highFivesGuys();
	}

	std::cout << "\n=== End of Main ===" << std::endl;
	return 0;
}