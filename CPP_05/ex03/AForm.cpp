#include "AForm.hpp"


AForm::AForm()
	: _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150), _target("default") {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute, const std::string target)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
	std::cout << "AForm parametric constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute),
	  _target(other._target) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::isSigned() const {
	return this->_signed;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

std::string AForm::getTarget() const {
	return this->_target;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::checkExecutability(Bureaucrat const & executor) const {
	if (!this->_signed)
		throw AForm::FormNotSignedException();

	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high! Cannot be higher than 1.";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low! Grade requirements not met.";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed! Cannot execute an unsigned form.";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form: " << form.getName()
	   << ", target: " << form.getTarget()
	   << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute();
	return os;
}