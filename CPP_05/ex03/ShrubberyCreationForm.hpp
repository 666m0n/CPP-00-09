#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>
# include <fstream>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	virtual void execute(Bureaucrat const & executor) const;

	static const int SIGN_GRADE = 145;
	static const int EXEC_GRADE = 137;
};

#endif