#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE, "default") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE, target) {
	std::cout << "PresidentialPardonForm target constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	this->checkExecutability(executor);

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}