#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target);

private:
	typedef AForm* (Intern::*FormCreator)(const std::string& target) const;

	AForm* createShrubberyForm(const std::string& target) const;
	AForm* createRobotomyForm(const std::string& target) const;
	AForm* createPresidentialForm(const std::string& target) const;

	class FormNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif