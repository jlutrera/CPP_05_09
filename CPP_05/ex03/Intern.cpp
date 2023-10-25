#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern	&copy)
{
	*this = copy;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

AForm *Intern::_RobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::_ShrubberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::_PresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string const &name, std::string const &target)
{
	std::string names[3] = {"robotomy request",
						    "shrubbery creation",
							"presidential pardon"};
	AForm *(Intern::*forms[3])(std::string) = {&Intern::_RobotomyRequest,
											   &Intern::_ShrubberyCreation,
											   &Intern::_PresidentialPardon};
	for (int i = 0; i < 3; i++)
		if (!names[i].compare(name))
		{
			std::cout << "Intern creates " + name << std::endl;
			return ((this->*forms[i])(target));
		}
	std::cerr << RED << "Intern cannot find " + name + " form" << RESET << std::endl;
	return (NULL);
}
