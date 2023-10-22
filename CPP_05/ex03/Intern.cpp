#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

AForm	*Intern::makeForm(std::string const &name, std::string const &target)
{
	if (name == "robotomy request")
		return (new RobotomyRequestForm(target));
	else if (name == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	else if (name == "presidential pardon")
		return (new PresidentialPardonForm(target));
	else
		throw FormNotFoundException();
}

const char * Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}
