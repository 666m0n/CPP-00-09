#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "===== TESTING FORM CREATION =====" << std::endl;
	try {
		Form highForm("Tax Return", 10, 5);
		std::cout << highForm << std::endl;

		Form mediumForm("Budget Approval", 50, 30);
		std::cout << mediumForm << std::endl;

		Form lowForm("Office Supply Request", 130, 120);
		std::cout << lowForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n===== TESTING INVALID FORMS =====" << std::endl;
	try {
		Form tooHighSign("Invalid Form", 0, 50); // Should throw exception (sign grade too high)
		std::cout << tooHighSign << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Form tooHighExec("Invalid Form", 50, 0); // Should throw exception (exec grade too high)
		std::cout << tooHighExec << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Form tooLowSign("Invalid Form", 151, 50); // Should throw exception (sign grade too low)
		std::cout << tooLowSign << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Form tooLowExec("Invalid Form", 50, 151); // Should throw exception (exec grade too low)
		std::cout << tooLowExec << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n===== TESTING SIGNING FORMS =====" << std::endl;

	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat manager("Manager", 40);
		Bureaucrat employee("Employee", 100);
		Bureaucrat intern("Intern", 150);

		Form highSecurityForm("High Security Clearance", 20, 5);
		Form standardForm("Standard Procedure", 75, 30);
		Form basicForm("Basic Request", 120, 100);

		std::cout << "\n--- Initial Form States ---" << std::endl;
		std::cout << highSecurityForm << std::endl;
		std::cout << standardForm << std::endl;
		std::cout << basicForm << std::endl;

		std::cout << "\n--- Attempting to Sign Forms ---" << std::endl;

		boss.signForm(highSecurityForm);
		boss.signForm(standardForm);
		boss.signForm(basicForm);

		Form highSecurityForm2("High Security Clearance", 20, 5);
		Form standardForm2("Standard Procedure", 75, 30);
		Form basicForm2("Basic Request", 120, 100);

		manager.signForm(highSecurityForm2); // Should fail
		manager.signForm(standardForm2);     // Should succeed
		manager.signForm(basicForm2);        // Should succeed

		Form highSecurityForm3("High Security Clearance", 20, 5);
		Form standardForm3("Standard Procedure", 75, 30);
		Form basicForm3("Basic Request", 120, 100);

		employee.signForm(highSecurityForm3); // Should fail
		employee.signForm(standardForm3);     // Should fail
		employee.signForm(basicForm3);        // Should succeed

		Form highSecurityForm4("High Security Clearance", 20, 5);
		Form standardForm4("Standard Procedure", 75, 30);
		Form basicForm4("Basic Request", 120, 100);

		intern.signForm(highSecurityForm4); // Should fail
		intern.signForm(standardForm4);     // Should fail
		intern.signForm(basicForm4);        // Should fail

	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}