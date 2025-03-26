#include "ClapTrap.hpp"

int main() {
	// Test default constructor
	std::cout << "\n=== Testing Default Constructor ===" << std::endl;
	ClapTrap defaultRobot;
	std::cout << "Name: " << defaultRobot.getName() << std::endl;
	std::cout << "Hit Points: " << defaultRobot.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << defaultRobot.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << defaultRobot.getAttackDamage() << std::endl;

	// Test param constructor
	std::cout << "\n=== Testing Parameterized Constructor ===" << std::endl;
	ClapTrap robot("CL4P-TP");
	std::cout << "Name: " << robot.getName() << std::endl;
	std::cout << "Hit Points: " << robot.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << robot.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << robot.getAttackDamage() << std::endl;

	// Test copy constructor
	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	ClapTrap robotCopy(robot);
	std::cout << "Name: " << robotCopy.getName() << std::endl;
	std::cout << "Hit Points: " << robotCopy.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << robotCopy.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << robotCopy.getAttackDamage() << std::endl;

	// Test member functions
	std::cout << "\n=== Testing Member Functions ===" << std::endl;

	// Attack
	robot.attack("Enemy");

	// Take damage
	robot.takeDamage(5);
	std::cout << "Hit Points: " << robot.getHitPoints() << std::endl;

	// Be repaired
	robot.beRepaired(3);
	std::cout << "Hit Points: " << robot.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << robot.getEnergyPoints() << std::endl;

	// Test multiple attacks to deplete energy
	std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
	for (int i = 0; i < 9; ++i) {
		robot.attack("Enemy");
	}
	std::cout << "Energy Points: " << robot.getEnergyPoints() << std::endl;

	// Try to attack with no energy
	robot.attack("Enemy");

	// Test taking fatal damage
	std::cout << "\n=== Testing Fatal Damage ===" << std::endl;
	ClapTrap fragileRobot("Fragile");
	fragileRobot.takeDamage(15); // More than its hit points

	// Try to attack after being destroyed
	fragileRobot.attack("Enemy");

	// Try to repair after being destroyed
	fragileRobot.beRepaired(5);

	std::cout << "\n=== End of Tests ===" << std::endl;
	return 0;
}