#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	virtual void execute(Bureaucrat const & executor) const;

	static const int SIGN_GRADE = 72;
	static const int EXEC_GRADE = 45;
};

#endif