#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern	&operator=(const Intern &copy);
		virtual AForm	*makeForm(std::string const &name, std::string const &target);
	private:
		AForm	*_RobotomyRequest(std::string targetz);
		AForm	*_ShrubberyCreation(std::string target);
		AForm	*_PresidentialPardon(std::string target);
};

#endif
