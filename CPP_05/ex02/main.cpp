#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	std::cout << "===== CREATING BUREAUCRATS =====" << std::endl;
	Bureaucrat president("President", 1);
	Bureaucrat minister("Minister", 15);
	Bureaucrat director("Director", 40);
	Bureaucrat manager("Manager", 100);
	Bureaucrat intern("Intern", 150);

	std::cout << "\n===== CREATING FORMS =====" << std::endl;
	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << "\n===== FORM INFORMATION =====" << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;

	std::cout << "\n===== ATTEMPTING TO EXECUTE UNSIGNED FORMS =====" << std::endl;
	president.executeForm(shrubbery);
	president.executeForm(robotomy);
	president.executeForm(pardon);

	std::cout << "\n===== SIGNING FORMS =====" << std::endl;
	president.signForm(shrubbery);
	president.signForm(robotomy);
	president.signForm(pardon);

	std::cout << "\n===== EXECUTING FORMS WITH DIFFERENT BUREAUCRATS =====" << std::endl;
	std::cout << "\n--- President (grade 1) ---" << std::endl;
	president.executeForm(shrubbery);
	president.executeForm(robotomy);
	president.executeForm(pardon);

	std::cout << "\n--- Minister (grade 15) ---" << std::endl;
	minister.executeForm(shrubbery);
	minister.executeForm(robotomy);
	minister.executeForm(pardon);

	std::cout << "\n--- Director (grade 40) ---" << std::endl;
	director.executeForm(shrubbery);
	director.executeForm(robotomy);
	director.executeForm(pardon);

	std::cout << "\n--- Manager (grade 100) ---" << std::endl;
	manager.executeForm(shrubbery);
	manager.executeForm(robotomy);
	manager.executeForm(pardon);

	std::cout << "\n--- Intern (grade 150) ---" << std::endl;
	intern.executeForm(shrubbery);
	intern.executeForm(robotomy);
	intern.executeForm(pardon);

	std::cout << "\n===== ATTEMPTING ALTERNATIVE SIGNING PERMISSIONS =====" << std::endl;
	ShrubberyCreationForm shrubbery2("backyard");
	RobotomyRequestForm robotomy2("C-3PO");
	PresidentialPardonForm pardon2("Han Solo");

	intern.signForm(shrubbery2);
	manager.signForm(shrubbery2);

	manager.signForm(robotomy2);
	director.signForm(robotomy2);

	director.signForm(pardon2);
	minister.signForm(pardon2);

	return 0;
}