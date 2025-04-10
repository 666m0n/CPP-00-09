#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE, "default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE, target) {
	std::cout << "RobotomyRequestForm target constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	this->checkExecutability(executor);

	std::cout << "* DRILLING NOISES * Brrrrrr... Drrrrrr... Zzzzzzt!" << std::endl;

	static bool seedInitialized = false;
	if (!seedInitialized) {
		std::srand(std::time(NULL));
		seedInitialized = true;
	}
	if (std::rand() % 2) {
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed! " << this->getTarget() << " remains intact." << std::endl;
	}
}