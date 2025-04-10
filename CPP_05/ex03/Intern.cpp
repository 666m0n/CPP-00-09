#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubberyForm(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	struct FormType {
		std::string name;
		FormCreator creator;
	};

	FormType formTypes[3] = {
		{"shrubbery creation", &Intern::createShrubberyForm},
		{"robotomy request", &Intern::createRobotomyForm},
		{"presidential pardon", &Intern::createPresidentialForm}
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formTypes[i].name) {
			AForm* form = (this->*(formTypes[i].creator))(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}

	std::cerr << "Error: Form type '" << formName << "' not found." << std::endl;
	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form type not found! The intern doesn't know how to create this form.";
}