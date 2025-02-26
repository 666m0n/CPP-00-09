#include "Harl.hpp"
#include <iostream>

int	main() {
	Harl	harl;

	std::cout << "Testing different complaint levels:" << std::endl;
	std::cout << "====================================" << std::endl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INVALID_LEVEL");

	return 0;
}
