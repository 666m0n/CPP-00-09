#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << "===== TESTING VALID BUREAUCRATS =====" << std::endl;
	try {
		Bureaucrat high("Boss", 1);
		std::cout << high << std::endl;

		Bureaucrat medium("Manager", 75);
		std::cout << medium << std::endl;

		Bureaucrat low("Intern", 150);
		std::cout << low << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n===== TESTING INVALID BUREAUCRATS =====" << std::endl;
	try {
		Bureaucrat tooHigh("Too High", 0); // Should throw exception (too high)
		std::cout << tooHigh << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat tooLow("Too Low", 151); // Should throw exception (too low)
		std::cout << tooLow << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n===== TESTING GRADE MODIFICATION =====" << std::endl;
	try {
		Bureaucrat employee("Employee", 75);
		std::cout << "Initial: " << employee << std::endl;

		employee.incrementGrade(); // 75 -> 74
		std::cout << "After increment: " << employee << std::endl;

		employee.decrementGrade(); // 74 -> 75
		std::cout << "After decrement: " << employee << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n===== TESTING BOUNDARY CASES =====" << std::endl;
	try {
		Bureaucrat topBoss("Top Boss", 1);
		std::cout << "Initial: " << topBoss << std::endl;

		std::cout << "Trying to increment (should fail)..." << std::endl;
		topBoss.incrementGrade(); // Should throw exception (already at top grade)
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat bottomIntern("Bottom Intern", 150);
		std::cout << "Initial: " << bottomIntern << std::endl;

		std::cout << "Trying to decrement (should fail)..." << std::endl;
		bottomIntern.decrementGrade(); // Should throw exception (already at bottom grade)
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}