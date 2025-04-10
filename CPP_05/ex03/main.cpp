#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	std::cout << "===== CREATING INTERN =====" << std::endl;
	Intern someRandomIntern;

	std::cout << "\n===== CREATING BUREAUCRAT =====" << std::endl;
	Bureaucrat boss("Big Boss", 1);

	std::cout << "\n===== TESTING VALID FORM CREATION =====" << std::endl;
	try {
		AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "garden");
		std::cout << *form1 << std::endl;

		boss.signForm(*form1);
		boss.executeForm(*form1);

		delete form1;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *form2 << std::endl;

		boss.signForm(*form2);
		boss.executeForm(*form2);

		delete form2;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
		std::cout << *form3 << std::endl;

		boss.signForm(*form3);
		boss.executeForm(*form3);

		delete form3;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n===== TESTING INVALID FORM CREATION =====" << std::endl;
	try {
		AForm* invalidForm = someRandomIntern.makeForm("coffee request", "office");
		std::cout << *invalidForm << std::endl;

		delete invalidForm;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}