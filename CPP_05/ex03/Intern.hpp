#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern : public AForm
{
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern	&operator=(const Intern &copy);
		AForm	*makeForm(std::string const &name, std::string const &target);
		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif